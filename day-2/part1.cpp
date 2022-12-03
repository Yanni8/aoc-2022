
#include <iostream>

#include <string>

#include <fstream>

#include <map>

std::map<std::string, unsigned int> points = {
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

    std::string line;
    std::ifstream file(argv[1]);
    unsigned int score;

    while (std::getline(file, line))
    {
        score += points.at(line);
    }
    file.close();
    std::cout << "Score: " << score << std::endl;
}