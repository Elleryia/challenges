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
        lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\r'), lineBuffer.end());
        if (lineBuffer.length() == 0)
        {
            continue; //ignore all empty lines
        }
        else 
        {
            //do something here
            string label ("Label");
            int location = 0;
            int total = 0;
            while(location >= 0)
            {
                location = lineBuffer.find(label, location + 1);
                string sub = lineBuffer.substr(location + 6);
                total += atoi(sub.c_str());
            }
            cout << total << endl;
        }
    }
}