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
            string test1 = "a";
            string test2 = "ab";
            string test3 ("Test string");
            cout << lineBuffer.size() << endl;
            vector<string> fields = split(lineBuffer, ',');
            int major_threshold = fields.size() / 2;
            ::sort(fields.begin(), fields.end());
            int count = 1;
            int highest_freq = 0;
            string highest_value = "";
            for(int i = 1; i < fields.size(); ++i)
            {
                if(fields[i].compare(fields[i-1]) != 0)
                {
                    if(count > highest_freq)
                    {
                        highest_freq = count;
                        highest_value = fields[i-1];
                    }
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            if(highest_freq >= major_threshold)
                cout << highest_value << endl;
            else
                cout << "None" << endl;
        }
    }
}














