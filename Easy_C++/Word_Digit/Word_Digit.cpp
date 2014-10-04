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
            for(vector<string>::iterator i = fields.begin(); i < fields.end(); ++i)
            {
                if((*i).compare("zero") == 0)
                    cout << '0';
                else if((*i).compare("one") == 0)
                    cout << '1';
                else if((*i).compare("two") == 0)
                    cout << '2';
                else if((*i).compare("three") == 0)
                    cout << '3';
                else if((*i).compare("four") == 0)
                    cout << '4';
                else if((*i).compare("five") == 0)
                    cout << '5';
                else if((*i).compare("six") == 0)
                    cout << '6';
                else if((*i).compare("seven") == 0)
                    cout << '7';
                else if((*i).compare("eight") == 0)
                    cout << '8';
                else if((*i).compare("nine") == 0)
                    cout << '9';
            }
            cout << endl;
        }
    }
}












