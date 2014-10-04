#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elms)
{
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim))
    {
        elms.push_back(item);
    }
    return elms;
}

vector<string> split(const string &s, char delim)
{
    vector<string> elms;
    split(s, delim, elms);
    return elms;
}

bool foundPeriod(string line, int width)
{
    string test = line.substr(0, width);
    bool found = true;
    for(int i = 0; i < line.length(); i += width)
    {
        if(test.compare(line.substr(i, width)) != 0)
            found = false;
    }
    return found;
}

int main(int argc, char *argv[])
{
    ifstream file;
    file.open(argv[1]);
    string lineBuffer;
    while (!file.eof()) 
    {
        getline(file, lineBuffer);
        lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\r'), lineBuffer.end());
        if (lineBuffer.length() == 0)
        {
            continue; //ignore all empty lines
        }
        else 
        {
            //do something here
            int length = lineBuffer.length();
            vector<int> factors;
            int count = 0;
            for(int i = 1; i <= length; ++i)
            {
                if(length % i == 0)
                    factors.insert(factors.end(), i);
            }
            vector<int>::iterator it = factors.begin();
            while(true)
            {
                // loop through the string 
                if(it == factors.end())
                    break;
                if(foundPeriod(lineBuffer, (*it)))
                {
                    cout << (*it) << endl;
                    break;
                }
                it++;
            }
        }
    }
}