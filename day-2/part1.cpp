
#include <iostream>

#include <string>

#include <fstream>

#include <map>

#include <chrono>

const std::map<std::string, unsigned int> POINTS = {
    {"A X", 4},
    {"A Y", 8},
    {"A Z", 3},
    {"B X", 1},
    {"B Y", 5},
    {"B Z", 9},
    {"C X", 7},
    {"C Y", 2},
    {"C Z", 6}};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Syntax: " << argv[0] << " <FileName>";
    }

    auto startTime = std::chrono::high_resolution_clock::now();   

    std::string line;
    std::ifstream file(argv[1]);
    unsigned int score = 0;

    while (std::getline(file, line))
    {
        score += POINTS.at(line);
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();
    
    file.close();
    std::cout << "Score: " << score << " Time to execute in μs: " << (endTime - startTime) / std::chrono::microseconds(1) << std::endl;
}