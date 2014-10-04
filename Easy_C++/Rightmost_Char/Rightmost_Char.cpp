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
            //cout << lineBuffer << endl;
            vector<string> fields = split(lineBuffer, ',');
            int pos_count = 0;
            int position = 0;
            int found = 0;
            string::iterator comp = fields[1].begin();
            //cout << *comp << endl;
            for(string::iterator it = fields[0].begin(); it != fields[0].end(); ++it)
            {
                if(*it == *comp)
                {
                    position = pos_count;
                    found = 1;
                }
                //cout << *it << endl;
                pos_count++;
            }
            if(found == 1)
            {
                cout << position << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }
}