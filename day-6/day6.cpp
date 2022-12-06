#include <iostream>

#include <fstream>

#include <chrono>

#include <set>

bool hasUniqueCharacters(std::string str)
{
    std::set<char> charSet;
 
    for(char c : str)
    {
        charSet.insert(c);
    }
 
    // If length of set is equal to len of string
    // then it will have unique characters
    return charSet.size() == str.size();
}


int main(int argc, char * argv[])
{


    if (argc != 3)
    {
        std::cout << "Syntax: " << argv[0] << " <FileName> <ReaderLenght>" << std::endl;
        return -1;        
    }

    const int readerLenght = std::stoi(argv[2]);

    auto startTime = std::chrono::high_resolution_clock::now();
    char byte;
    std::string reader;    
    std::ifstream file(argv[1]);
    int counter = readerLenght;

    for (int i = 0; i < readerLenght; i++)
    {
        file.get(byte);
        reader += byte;
    }
    

    while (file.get(byte))
    {
        counter++;
        reader = reader.substr(1, readerLenght) + byte;

        if (hasUniqueCharacters(reader))
        {
            auto endTime = std::chrono::high_resolution_clock::now();
            std::cout << "First Index found on: " << counter << " Time to execute in μs: " << (endTime - startTime) / std::chrono::microseconds(1) << std::endl;
            return 0;
        }
        
    }
    



}