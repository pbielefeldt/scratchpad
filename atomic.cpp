/*
some test for atomic variables in threads

compile with
g++ -std=c++23 -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors main.cpp -lm -latomic
*/
#include <iostream>
#include <string>
#include <cmath>

#include <random>
#include <chrono>

#include <atomic>

#include <vector>
#include <thread>

std::random_device rd;
std::mt19937 gen(rd());

std::atomic_int some_number;
std::mutex some_mutex;

void some_func()
{
    const int my_number = some_number+=2;
    
    std::uniform_int_distribution<int> sleep_dist(20, 400);
    int sleep_duration = sleep_dist(gen);
    // sleeping for a random duration
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration));
    const double three = pow(static_cast<double>(my_number), 3.000);

    // print result (use mutex to make sure all info is in order)
    some_mutex.lock();
    std::cout << my_number << "^3 = " << three << std::endl;
    some_mutex.unlock();
}

int main()
{
    std::vector<std::jthread> pool;
    for (size_t i=0; i<10; i++)
    {
        pool.emplace_back(some_func);
    }
    
    return 0;
}
