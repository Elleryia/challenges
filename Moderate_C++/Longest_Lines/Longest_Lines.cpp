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
    vector<string> data;
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
            data.insert(data.end(), lineBuffer);
        }
    }
    int num_lines = atoi(data[0].c_str());
    for(int i = 0; i < num_lines; ++i)
    {
        int index = 0;
        int length = 0;
        for(int j = 1; j < data.size(); ++j)
        {
            if(data[j].size() > length)
            {
                index = j;
                length = data[j].length();
            }
        }
        cout << data[index] << endl;
        data.erase(data.begin() + index);
    }
}












