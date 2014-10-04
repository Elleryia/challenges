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
            bool add = true;
            int index = fields[1].find("+");
            if(index < 0)
            {
                index = fields[1].find("-");
                add = false;
            }
            string left = fields[0].substr(0, index);
            string right = fields[0].substr(index);
            int left_int = atoi(left.c_str());
            int right_int = atoi(right.c_str());
            int result = 0;
            if(add)
                result = left_int + right_int;
            else
                result = left_int - right_int;
            cout << result << endl;
        }
    }
}














