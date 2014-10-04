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
            vector<string> fields = split(lineBuffer, ';');
            //vector<int> values;
            int value[fields.size()];
            //for(vector<string>::iterator it = fields.begin(); it != fields.end(); ++it)
            //{
            //    vector<string> temp = split(*it, ',');
            //    values.insert(values.end(), atoi(temp[1].c_str()));
            //}
            for(int i = 0; i < fields.size(); ++i)
            {
                vector<string> temp = split(fields[i], ',');
                value[i] = atoi(temp[1].c_str());
            }
            ::sort(value, value + fields.size());
            cout << value[0] << ',';
            for(int i = 1; i < fields.size(); ++i)
            {
                int temp = value[i] - value[i-1];
                if(i != (fields.size() - 1))
                    cout << temp << ',';
                else
                    cout << temp;
            }
            cout << endl;
        }
    }
}