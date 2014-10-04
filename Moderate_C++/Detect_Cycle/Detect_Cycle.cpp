#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct match
{
    int index;
    int distance;
};

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
            vector<int> data;
            vector<string> fields = split(lineBuffer, ' ');
            vector<match> matches;
            for(int i = 0; i < fields.size(); ++i)
                data.insert(data.end(), atoi(fields[i].c_str()));
            for(int i = 0; i < data.size(); ++i)
            {
                for(int j = i + 1; j < data.size(); ++j)
                {
                    if(data[i] == data[j]) // they are the same, check if its a sequence
                    {
                        int distance = j - i;
                        struct match temp = {i, distance};
                        matches.push_back(temp);
                    }
                }
            }
            for(int i = 0; i < matches.size(); ++i)
            {
                bool found = false;
                bool temp = true;
                for(int j = matches[i].index; j < (matches[i].index + matches[i].distance); ++j)
                {
                    if(data[j] != data[j + matches[i].distance])
                        temp = false;
                }
                found = temp;
                if(found)
                {
                    for(int j = matches[i].index; j < (matches[i].index + matches[i].distance); ++j)
                        cout << data[j] << ' ';
                    break;
                }
            }
            cout << endl;
        }
    }
}












