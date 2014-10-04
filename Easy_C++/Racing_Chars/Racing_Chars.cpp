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

int main(int argc, char *argv[])
{
    ifstream file;
    file.open(argv[1]);
    string lineBuffer;
    int pos = -1;
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
            int index = lineBuffer.find('C');
            if(index < 0)
                index = lineBuffer.find('_');
            if(pos == -1) // first barrier
            {
                lineBuffer.replace(index, 1, "|");
            }
            else if(index == pos)
            {
                lineBuffer.replace(index, 1, "|");
            }
            else if(index > pos)
            {
                lineBuffer.replace(index, 1, "\\");
            }
            else if(index < pos)
            {
                lineBuffer.replace(index, 1, "/");
            }
            pos = index;
            cout << lineBuffer << endl;;
        }
    }
}














