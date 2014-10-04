#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

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
    while (!file.eof()) 
    {
        getline(file, lineBuffer);
        if (lineBuffer.length() == 0)
        {
            continue; 
        }
        else 
        {
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\r'), lineBuffer.end());
            vector<string> fields = split(lineBuffer, ',');
            vector<string>::iterator first = fields.begin() + 0;
            vector<string>::iterator last = fields.begin() + 1;
            int multiple = atoi((*last).c_str());
            int total = multiple; 
            while(total < atoi((*first).c_str()))
            {
                total += multiple;
            }
            fprintf(stdout, "%d\n", total);
        }
    }
}