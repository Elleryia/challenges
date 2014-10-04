#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include <vector>
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
            stringstream stream;
            stream << hex << lineBuffer;
            unsigned int y = 0;
            stream >> y;
            cout << y << endl;
        }
    }
}