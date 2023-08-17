#include <iostream>
#include <fstream>
// #include <filesystem>
#include <boost/filesystem.hpp>
#include <string>
#include <vector>

/* (C) Philipp Bielefeldt, 2023
 * Small example programme to test how to shorten a string, or a text file, to the last n lines.
 * Compile with:
g++ -Wall --pedantic -std=gnu++11 -lboost_system -lboost_filesystem -o crop_text.o crop_text.cpp
 *
 * Available under the conditions of the Mozilla Public License 2.0
 */

using namespace std;
// namespace fs = std::filesystem;
namespace fs = boost::filesystem;

std::string cropStringToLastNLines(const std::string &input, int n)
{
    std::vector<size_t> lineStarts;
    size_t pos = 0;

    // Find the start positions of each line
    while ((pos = input.find('\n', pos)) != std::string::npos) {
        lineStarts.push_back(pos + 1);
        ++pos;
    }

    // Check if there are fewer lines than n
    if (lineStarts.size() <= static_cast<size_t>(n)) {
        return input;
    }

    // Calculate the starting position of the last n lines
    size_t start = lineStarts[lineStarts.size() - n - 1];

    // Return the cropped string
    return input.substr(start);
}

// create a file with the last n lines of the input file, so that the total size of the file is less
// than crop_to bytes
void cropFileToLastNLines(const fs::path &input_path, const fs::path &output_path, int n,
                          float crop_to)
{
    std::ifstream input_file(input_path.string());
    if (!input_file.is_open()) {
        std::cerr << "Error opening input file: " << input_path << std::endl;
        return;
    }

    std::ofstream output_file(output_path.string());
    if (!output_file.is_open()) {
        std::cerr << "Error opening output file: " << output_path << std::endl;
        return;
    }

    std::cout << "cropFileToLastNLines (input=" << input_path.string()
              << ", output=" << output_path.string() << ", n=" << n << ", crop_to=" << crop_to
              << ")" << std::endl;

    std::string line;
    std::vector<std::string> lines;

    // Read all lines from the input file
    while (std::getline(input_file, line)) {
        lines.push_back(line);
    }

    // Calculate the number of lines to write to the output file
    int num_lines = std::min(n, static_cast<int>(lines.size()));

    // Calculate the starting position of the last n lines
    int start = lines.size() - num_lines;

    // Write the last n lines to the output file
    for (int i = start; i < static_cast<int>(lines.size()); ++i) {
        output_file << lines[i] << '\n';
    }

    // Close the input and output files
    input_file.close();
    output_file.close();

    // If the output file is still too large, crop it again
    const unsigned int output_size = fs::file_size(output_path);
    std::cout << "output_size=" << output_size << std::endl;

    if (output_size > crop_to && num_lines > 3) {

        // gauge the number of lines to crop to
        const float crop_to_ratio = crop_to / static_cast<float>(output_size);
        int crop_to_lines = static_cast<int>(crop_to_ratio * 0.95 * num_lines);
        crop_to_lines = std::max(3, crop_to_lines);

        cropFileToLastNLines(input_path, output_path, crop_to_lines, crop_to);
    }
}

int main()
{
    // test cropStringToLastNLines
    std::string input =
            "Line 1\nLine 2\nLine 3\nLine 4\nLine 5\nLine 6\nLine 7\nLine 8\nLine 9\nLine 10";
    int n = 3;

    std::string cropped = cropStringToLastNLines(input, n);
    std::cout << cropped << std::endl;

    // test cropFileToLastNLines
    fs::path input_file_path = "test_file.txt";
    fs::path output_file_path = input_file_path.parent_path()
            / (input_file_path.stem().string() + "_cropped" + input_file_path.extension().string());
    n = 300;
    float crop_to = 400;

    cropFileToLastNLines(input_file_path, output_file_path, n, crop_to);

    return 0;
}

/*
 * create a file called test_file.txt with the following content:
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
50 ---
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
100 ---
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
150 ---
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
200 ---
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
250 ---
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
300 ---
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
350 ---
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
400 ---

*/
