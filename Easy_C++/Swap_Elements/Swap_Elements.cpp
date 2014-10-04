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
            vector<string> fields = split(lineBuffer, ':');
            vector<string> values = split(fields[0], ' ');
            vector<string> ops = split(fields[1], ',');
            for(int i = 0; i < ops.size(); ++i)
            {
                int a = atoi(ops[i].c_str());
                int pos = ops[i].find("-");
                pos++;
                string temp = ops[i].substr(pos);
                int b = atoi(temp.c_str());
                string temp1 = values[a];
                values[a] = values[b];
                values[b] = temp1;
            }
            for(int i = 0; i < values.size(); ++i)
                cout << values[i] << ' ';
            cout << endl;
        }
    }
}









