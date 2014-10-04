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
        if (lineBuffer.length() == 0)
        {
            continue; //ignore all empty lines
        }
        else 
        {
            //do something here
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\r'), lineBuffer.end());
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\n'), lineBuffer.end());
            vector<string> fields = split(lineBuffer, ',');
            vector<string>::iterator iter = unique(fields.begin(), fields.end());
            fields.erase(iter, fields.end());
            for(vector<string>::iterator it = fields.begin(); it != fields.end(); ++it)
            {
                cout << *it;
                if(it + 1 != fields.end())
                    cout << ',';
            }
            result.resize(result.size() - 1);
            cout << endl;
        }
    }
}