#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool happy(int number) 
{
    static map<int, bool> cache;
    set<int> cycle;
    
    while (number != 1 && !cycle.count(number)) 
    {
        if (cache.count(number)) 
        {
            number = cache[number] ? 1 : 0;
            break;
        }
        cycle.insert(number);
        int newnumber = 0;
        while (number > 0) 
        {
            int digit = number % 10;
            newnumber += digit * digit;
            number /= 10;
        }
        number = newnumber;
    }
    bool happiness = number == 1;
    for (std::set<int>::const_iterator it = cycle.begin(); it != cycle.end(); it++)
    {
        cache[*it] = happiness;
    }
    return happiness;
}

int main(int argc, char *argv[])
{
    ifstream file;
    file.open(argv[1]);
    string lineBuffer;
    while (!file.eof()) 
    {
        getline(file, lineBuffer);
        if (lineBuffer.length() == 0)
        {
            continue; //ignore all empty lines
        }
        else 
        {
            //do something here
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\r'), lineBuffer.end());
            int number = atoi(lineBuffer.c_str());
            if(happy(number))
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}