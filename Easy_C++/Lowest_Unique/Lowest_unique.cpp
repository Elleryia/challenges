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
            vector<string> fields = split(lineBuffer, ' ');
            int int_array[fields.size()];
            int frequency[10] = {};
            int unique_index = 0;
            for(int i = 0; i < fields.size(); ++i)
            {
                int_array[i] = atoi(fields[i].c_str());
                frequency[int_array[i]]++;
            }
            for(int i = 0; i < 10; ++i)
            {
                if(frequency[i] == 1)
                {
                    unique_index = i;
                    break;
                }
            }
            if(unique_index == 0)
                cout << "0" << endl;
            else
            {
                for(int i = 1; i <= fields.size(); ++i)
                {
                    if(unique_index == atoi(fields[i-1].c_str()))
                    {
                        cout << i << endl;
                        break;
                    }
                }
            }
        }
    }
}