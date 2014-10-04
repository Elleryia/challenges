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
            int count = 1;
            if(fields.size() == 1)
                cout << count << ' ' << fields[0];
            else
            {
                for(int i = 1; i < fields.size(); ++i)
                {
                    if(fields[i] == fields[i-1])
                    {
                        count ++;
                    }
                    else
                    {
                        cout << count << ' ' << fields[i-1] << ' ';
                        count = 1;
                    }
                }
                cout << count << ' ' << fields[fields.size() - 1];
            }
            cout << endl;
        }
    }
}














