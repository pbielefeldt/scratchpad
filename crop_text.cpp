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
void cropFileToLastNLines(const fs::path &input, const fs::path &output, int n, float crop_to)
{
    std::cout << "cropFileToLastNLines (input=" << input.string() << ", output=" << output.string()
              << ", n=" << n << ", crop_to=" << crop_to << ")" << std::endl;
    std::ifstream in(input.string());
    std::ofstream out(output.string());

    std::string line;
    std::vector<std::string> lines;

    std::cout << "input file size: " << fs::file_size(input) << std::endl;

    // Read all lines from the input file
    while (std::getline(in, line)) {
        lines.push_back(line);
    }

    // Calculate the number of lines to write to the output file
    int numLines = std::min(n, static_cast<int>(lines.size()));

    // Calculate the starting position of the last n lines
    int start = lines.size() - numLines;

    // Write the last n lines to the output file
    for (int i = start; i < static_cast<int>(lines.size()); ++i) {
        out << lines[i] << std::endl;
    }

    // write to file
    in.close();

    // If the output file is still too large, crop it again
    if (out.tellp() > crop_to && numLines > 1) {
        cropFileToLastNLines(input, output, numLines / 2, crop_to);
    }
    out.close();
    std::cout << "Cropped file to " << numLines << " lines." << std::endl;
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
