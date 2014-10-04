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
            string hidden = "abcdefghij";
            //cout << hidden << endl;
            string result = "";
            map <char, char> convert;
            convert['a'] = '0';convert['b'] = '1';convert['c'] = '2';convert['d'] = '3';convert['e'] = '4';
            convert['f'] = '5';convert['g'] = '6';convert['h'] = '7';convert['i'] = '8';convert['j'] = '9';
            for(string::iterator it = lineBuffer.begin(); it != lineBuffer.end(); ++it)
            {
                if(::isdigit(*it) != 0)
                {
                    result += (*it);
                }
                else 
                {
                    int index = hidden.find(*it);
                    if(index != string::npos)
                    {
                        result += convert[(*it)];
                    }
                }
            }
            if(result.size() == 0)
                cout << "NONE" << endl;
            else
                cout << result << endl;
        }
    }
}

















