#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
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
            vector<pair<char, int> > data;
            for(int i = 0; i < lineBuffer.length(); ++i)
            {
                bool found = false;
                for(int j = 0; j < data.size(); ++j)
                {
                    if(data[j].first == lineBuffer[i])
                    {
                        found = true;
                        data[j].second++;
                    }
                }
                if(found == false)
                    data.insert(data.end(), pair<char, int>(lineBuffer[i], 1));
            }
            for(int i = 0; i < data.size(); ++i)
            {
                if(data[i].second == 1)
                {
                    cout << data[i].first << endl;
                    break;
                }
            }
        }
    }
}









