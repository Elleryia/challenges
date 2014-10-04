#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>

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
            vector<string> fields = split(lineBuffer, ' ');
            //for(vector<string>::iterator it = fields.begin(); it != fields.end(); ++it)
            //{
            //    cout << *it << endl;
            //}
            vector<string>::iterator F = fields.begin() + 0;
            vector<string>::iterator B = fields.begin() + 1;
            vector<string>::iterator index = fields.begin() + 2;
            //cout << *index << endl;
            for(int i = 1; i <= atoi((*index).c_str()); ++i)
            {
                if((i % atoi((*F).c_str())) == 0)
                {
                    cout << "F";
                    if((i % atoi((*B).c_str())) == 0)
                    {
                        cout << "B ";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else if((i % atoi((*B).c_str())) == 0)
                {
                    cout << "B ";
                }
                else
                {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }
}





