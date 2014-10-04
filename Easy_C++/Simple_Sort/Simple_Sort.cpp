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
            vector<string> fields = split(lineBuffer, ' ');
            
            double values[fields.size()];
            for(int i = 0; i < fields.size(); i++)
            {
                values[i] = ::atof(fields[i].c_str());
            }
            sort(values, values + fields.size());
            for(int i = 0; i < (fields.size() - 1); i++)
            {
                printf("%2.3f ", values[i]);
            }
            printf("%2.3f\n", values[fields.size() - 1]);
        }
    }
}