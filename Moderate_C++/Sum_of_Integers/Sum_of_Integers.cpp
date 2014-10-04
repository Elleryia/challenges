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
            vector<string> fields = split(lineBuffer, ',');
            vector<int> data;
            for(int i = 0; i < fields.size(); ++i)
                data.push_back(atoi(fields[i].c_str()));
            int max_sum = data[0];;
            for(int i = 0; i < data.size(); ++i)
            {
                for(int j = i; j < data.size(); ++j)
                {
                    int sub_sum = 0;
                    for(int k = j; k >= (j-i); --k)
                        sub_sum += data[k];
                    if(sub_sum > max_sum)
                        max_sum = sub_sum;
                }
            }
            cout << max_sum << endl;
        }
    }
}









