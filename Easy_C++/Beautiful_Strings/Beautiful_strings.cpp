#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

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
            for(int i = 0, len = lineBuffer.size(); i < len; i++)
            {
                if((ispunct(lineBuffer[i])) || (isspace(lineBuffer[i])))
                {
                    lineBuffer.erase(i--, 1);
                    len = lineBuffer.size();
                }
            }
            transform(lineBuffer.begin(), lineBuffer.end(), lineBuffer.begin(), ::tolower);
            int freq[26] = {};
            for(int i = 0; i < lineBuffer.size(); i++)
            {
                ++(freq[lineBuffer[i] - 'a']);
            }
            sort(freq, freq + 26);
            int beauty = 0;
            for(int i = 0; i < 26; i++)
            {
                beauty += (freq[i] * (i + 1));
            }
            cout << beauty << endl;
        }
    }
}