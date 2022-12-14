#include <iostream>

#include <fstream>

#include <list>

#include <vector>

using namespace std;

class Monkey
{
private:
    list<int> items;
    char operater;
    int value;
    int ifTrue;
    int ifFalse;
    int testCase;
    int counter = 0;

public:
    Monkey(string items, char operater, int value, int ifTrue, int ifFalse, int testCase);
    int throwNextItem();
    bool hasItem();
    int getNextItem();
    void addNewItem(int item);
    int getCounter();
};

int Monkey::getCounter()
{   
    return this->counter;
}
void Monkey::addNewItem(int item)
{
    this->items.push_back(item);
}

int Monkey::throwNextItem()
{
    this->counter++;
    int item = this->items.front();
    if(this->value == -1){
        item *= item;
    }
    else  if (this->operater == '+')
    {
        item += this->value;
    }
    else
    {
        item *= this->value;
    }
    item /= 3;
    this->items.pop_front();
    this->items.push_front(item);
    if (item % this->testCase != 0)
    {
        return this->ifTrue;
    }

    return this->ifFalse;
}

bool Monkey::hasItem()
{
    return this->items.size() > 0;
}

int Monkey::getNextItem()
{
    int item = this->items.front();
    this->items.pop_front();
    return item;
}

Monkey::Monkey(string items, char operater, int value, int ifTrue, int ifFalse, int testCase)
{
    this->operater = operater;
    this->value = value;
    this->ifFalse = ifFalse;
    this->ifTrue = ifTrue;
    this->testCase = testCase;

    list<int> itemList;
    auto start = 0U;
    auto end = items.find(',');
    while (end != string::npos)
    {
        itemList.push_back(stoi(items.substr(start, end - start)));
        start = end + 1;
        end = items.find(',', start);
    }
    itemList.push_back(stoi(items.substr(start, end - start)));
    this->items = itemList;
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cout << "Syntax: " << argv[0] << " <FileName>" << endl;
        return -1;
    }

    fstream file(argv[1]);

    string line, items;
    char operater;
    int multiplier, testCase, trueCase, falseCase;
    vector<Monkey> monkeys;
    do
    {
        for (int i = 0; i < 6; i++)
        {
            getline(file, line);

            switch (i)
            {
            case 0:
                continue;
            case 1:
                items = line.substr(18);
                break;
            case 2:
                operater = line.at(23);
                if (line.substr(25) == "old")
                {
                    multiplier = -1;
                }
                else
                {
                    multiplier = stoi(line.substr(25));
                }
                break;
            case 3:
                testCase = stoi(line.substr(21));
                break;
            case 4:
                trueCase = stoi(line.substr(29));
                break;
            case 5:
                falseCase = stoi(line.substr(30));
                break;
            default:
                break;
            }
        }
        Monkey monkey(items, operater, multiplier, falseCase, trueCase, testCase);
        monkeys.push_back(monkey);
    } while (getline(file, line));
    cout << "Starting now" << endl;
    for (int i = 0; i < 19; i++)
    {
        for (int i = 0; i < monkeys.size(); i++)
        {
            Monkey monkey = monkeys.at(i);

            while (monkey.hasItem())
            {
                int position = monkey.throwNextItem();
                int nextItem = monkey.getNextItem();
                monkeys.at(position).addNewItem(nextItem);
                monkeys.at(i) = monkey;
            }
        }
    }
    int mostActive = 0, secondActive = 0;
    for (Monkey monkey : monkeys)
    {
        if (monkey.getCounter() > mostActive)
        {
            secondActive = mostActive;
            mostActive = monkey.getCounter();
        }
        else if(monkey.getCounter() > secondActive){
            secondActive = monkey.getCounter();
        }
        cout << monkey.getCounter() << endl;
        
    }
    cout << mostActive * secondActive << endl;
}