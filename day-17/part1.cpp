#include <iostream>

#include <vector>

#include <fstream>

#include <string>

struct Point
{
    int x, y, z;

    inline bool operator==(Point other)
    {
        return ((this->x >= other.x - 1 && this->x <= other.x + 1) &&
                (this->y == other.y) && (this->z == other.z)) ||
               ((this->x == other.x) && (this->y == other.y) &&
                (this->z >= other.z - 1 && this->z <= other.z + 1)) ||
               ((this->x == other.x) &&
                (this->y >= other.y - 1 && this->y <= other.y + 1) &&
                (this->z == other.z));
    }

    Point(std::string xyz);
};

Point::Point(std::string xyz)
{
    size_t pos = 0;
    std::string token;
    int c = 0;
    while ((pos = xyz.find(',')) != std::string::npos)
    {
        switch (c)
        {
        case 0:
            this->x = std::stoi(xyz.substr(0, pos));
            break;

        case 1:
            this->y = std::stoi(xyz.substr(0, pos));
            break;
        }
        xyz.erase(0, ++pos);
        c++;
    }
    this->z = std::stoi(xyz.substr(0));
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cout << "Syntax: " << argv[0] << " <FileName>" << std::endl;
        return -1;
    }

    std::fstream file(argv[1]);

    std::string line;

    std::vector<Point> passed;

    int connected = 0, lines = 0;
    while (std::getline(file, line))
    {
        Point point(line);
        for (Point p : passed)
        {
            if (point == p)
            {
                connected++;
            }
        }
        passed.push_back(point);
        lines++;
    }
    

    std::cout << lines*6 - connected*2 << std::endl;
}