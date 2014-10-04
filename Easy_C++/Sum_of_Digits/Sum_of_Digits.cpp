#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

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
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\n'), lineBuffer.end());
            int sum = 0;
            for(string::iterator it = lineBuffer.begin(); it != lineBuffer.end(); ++it)
            {
                //cout << *it << endl;
                sum += int((*it) - '0');
            }
            cout << sum << endl;
        }
    }
}