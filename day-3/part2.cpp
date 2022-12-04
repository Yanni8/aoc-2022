#include <iostream>

#include <fstream>

#include <map>

#include <chrono>

const std::map<char, unsigned int> CHAR_TO_INT = {
    {'a', 1},
    {'A', 27},
    {'b', 2},
    {'B', 28},
    {'c', 3},
    {'C', 29},
    {'d', 4},
    {'D', 30},
    {'e', 5},
    {'E', 31},
    {'f', 6},
    {'F', 32},
    {'g', 7},
    {'G', 33},
    {'h', 8},
    {'H', 34},
    {'i', 9},
    {'I', 35},
    {'j', 10},
    {'J', 36},
    {'k', 11},
    {'K', 37},
    {'l', 12},
    {'L', 38},
    {'m', 13},
    {'M', 39},
    {'n', 14},
    {'N', 40},
    {'o', 15},
    {'O', 41},
    {'p', 16},
    {'P', 42},
    {'q', 17},
    {'Q', 43},
    {'r', 18},
    {'R', 44},
    {'s', 19},
    {'S', 45},
    {'t', 20},
    {'T', 46},
    {'u', 21},
    {'U', 47},
    {'v', 22},
    {'V', 48},
    {'w', 23},
    {'W', 49},
    {'x', 24},
    {'X', 50},
    {'y', 25},
    {'Y', 51},
    {'z', 26},
    {'Z', 52}};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Syntax: " << argv[0] << " <FileName>";
    }

    auto startTime = std::chrono::high_resolution_clock::now();   

    std::string line, secondLine, thirdLine;
    std::ifstream file(argv[1]);
    char character;
    unsigned int points;

    while (std::getline(file, line) && std::getline(file, secondLine) && std::getline(file, thirdLine))
    {
        for (int i = 0; i < line.length(); i++)
        {
            character = line[i];
            if (secondLine.find(character) != std::string::npos && thirdLine.find(character) != std::string::npos)
            {
                points += CHAR_TO_INT.at(character);
                break;
            }
        }
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();

    file.close();
    std::cout << "Result: " << points << " Time to execute in μs: " << (endTime - startTime) / std::chrono::microseconds(1) << std::endl;
}