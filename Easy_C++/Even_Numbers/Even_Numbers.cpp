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
            int value = atoi(lineBuffer.c_str());
            int result = value % 2;
            if(result == 1)
                cout << '0' << endl;
            else if(result == 0)
                cout << '1' << endl;
        }
    }
}