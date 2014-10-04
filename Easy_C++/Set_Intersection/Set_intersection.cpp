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
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\n'), lineBuffer.end());
            //cout << lineBuffer << endl;
            vector<string> fields = split(lineBuffer, ';');
            vector<string>::iterator left = fields.begin();
            vector<string>::iterator right = fields.begin() + 1;
            
            vector<string> left_fields = split(*left, ',');
            vector<string> right_fields = split(*right, ',');
            string result;
            for(vector<string>::iterator it1 = left_fields.begin(); it1 != left_fields.end(); ++it1)
            {
                for(vector<string>::iterator it2 = right_fields.begin(); it2 != right_fields.end(); ++it2)
                {
                    if(*it1 == *it2)
                        result += (*it1 + ',');
                }
            }
            if(result.size() > 0) result.resize(result.size() - 1);
            cout << result << endl;
        }
    }
}