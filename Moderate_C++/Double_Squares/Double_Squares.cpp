#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

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

int main(int argc, char *argv[])
{
    ifstream file;
    file.open(argv[1]);
    string lineBuffer;
    bool first = true;
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
            if(first)
                first = false;
            else
            {
                int value = atoi(lineBuffer.c_str());
                int count = 0;
                for(int x = 0; x < (sqrt(value) + 1); ++x)
                {
                    double y = sqrt(value - x * x);
                    double intpart;
                    if(modf(y, &intpart) == 0.0)
                    {
                        if(x*x == y)
                            count += 2;
                        else    
                            count++;
                    }
                }
                count /= 2;
                cout << count << endl;
            }
        }
    }
}









