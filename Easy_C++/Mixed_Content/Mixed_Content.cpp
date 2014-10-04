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
            vector<string> words;
            vector<string> digits;
            for(vector<string>::iterator it = fields.begin(); it != fields.end(); ++it)
            {
                string::iterator first_char = (*it).begin();
                if(::isdigit(*first_char))
                {
                    digits.insert(digits.end(), *it);
                }
                else
                {
                    words.insert(words.end(), *it);
                }
            }
            if(words.size() > 0 && digits.size() > 0)
            {
                for(int i = 0; i < words.size() - 1; ++i)
                    cout << words[i] << ',';
                cout << words[words.size() - 1] << '|';
                for(int i = 0; i < digits.size() - 1; ++i)
                    cout << digits[i] << ',';
                cout << digits[digits.size() - 1] << endl;
            }
            else if(words.size() > 0)
            {
                for(int i = 0; i < words.size() - 1; ++i)
                    cout << words[i] << ',';
                cout << words[words.size() - 1] << endl;
            }
            else if(digits.size() > 0)
            {
                for(int i = 0; i < digits.size() - 1; ++i)
                    cout << digits[i] << ',';
                cout << digits[digits.size() - 1] << endl;
            }
        }
    }
}

















