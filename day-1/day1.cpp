#include <iostream>

#include <string>

#include <fstream>

#include <chrono>

int main(int argc, char * argv[]) {
  if (argc < 3) {
    std::cout << "Syntax" << argv[0] << " <FileName>  <Task[0,1]>\n";
    return 1;
  }

  auto startTime = std::chrono::high_resolution_clock::now();
  
  std::ifstream file(argv[1]);
  std::string line;

  unsigned int first = 0, second = 0, third = 0, counter = 0, modi = std::stoi(argv[2]);

  if (!file.is_open()) {
    std::cout << "File has error";
    return -1;
  }
  while (std::getline(file, line)) {
    
    if (!line.empty()) {
      counter += std::stoi(line);
      continue;
    }

    if (modi) {
      if (counter > first) {
        third = second;
        second = first;
        first = counter;
      } else if (counter > second) {
        third = second;
        second = counter;
      } else if (counter > third) {
        third = counter;
      }

    } else {
      if (counter > first) {
        first = counter;
      }
    }

    counter = 0;
  }
  auto endTime = std::chrono::high_resolution_clock::now();

  file.close();
  std::cout << first << " + " << second << " + " << third << " = " << first + second + third << " Time to execute in μs: " << (endTime - startTime) / std::chrono::microseconds(1) << std::endl;

  return 0;
}
