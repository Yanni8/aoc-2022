
#include <iostream>

#include <string>

#include <fstream>

#include <map>

#include <chrono>

const std::map<std::string, unsigned int> POINTS = {
    {"A X", 3},
    {"A Y", 4},
    {"A Z", 8},
    {"B X", 1},
    {"B Y", 5},
    {"B Z", 9},
    {"C X", 2},
    {"C Y", 6},
    {"C Z", 7}};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Syntax: " << argv[0] << " <FileName>";
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    std::string line;
    std::ifstream file(argv[1]);
    unsigned int score;

    while (std::getline(file, line))
    {
        score += POINTS.at(line);
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();

    file.close();
    std::cout << "Score: " << score << " Time to execute in μs: " << (endTime - startTime) / std::chrono::microseconds(1) << std::endl;
}