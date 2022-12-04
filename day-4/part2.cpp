#include <iostream>

#include <string>

#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Syntax: " << argv[0] << " <FileName>";
    }

    std::string line, pair1, pair2;

    std::ifstream file(argv[1]);

    unsigned int position,x1,x2,y1,y2, counter = 0;

    while (std::getline(file, line))
    {
        position = line.find(",");
        pair1 = line.substr(0, position);
        pair2 = line.substr(position+1);
        
        position = pair1.find("-");
        x1 = std::stoi(pair1.substr(0, position));
        x2 = std::stoi(pair1.substr(position+1));
        
        position = pair2.find("-");
        y1 = std::stoi(pair2.substr(0, position));
        y2 = std::stoi(pair2.substr(position+1));
        if(x2 >= y1 and x1 <= y2){
            counter++;
        }
    }

    std::cout << "Number of lines: " << counter << std::endl;
    
}