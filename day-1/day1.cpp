#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    if(argc < 3){
        std::cout << "Syntax" << argv[0] << " <FileName>  <Task[0,1]>\n";  
        return 1;
    }

    std::ifstream file(argv[1]);
    std::string line;

    unsigned int first = 0, second = 0, third = 0, counter = 0, modi = std::stoi(argv[2]);

    if(file.is_open()){
        while (file)
        {
            std::getline(file, line);
            if(!line.empty()){
                counter += std::stoi(line);
                continue;
            }

            if(modi){
                if(counter > first){
                    third = second;
                    second = first;
                    first = counter;
                } else if (counter > second)
                {
                    third = second;
                    second = counter;
                } else if(counter > third){
                    third = counter;
                }
                
            } else{
                if(counter > first){
                    first = counter;
                }
            }
            
            counter = 0;
        }
        
    }

    std::cout << first << " + " << second << " + " << third <<  " = " << first + second + third << std::endl; 

    return 0;
}
