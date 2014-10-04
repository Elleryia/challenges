#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

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
            int numDigits = lineBuffer.size();
            int number = atoi(lineBuffer.c_str());
            int check = number;
            int armstrong = 0;
            int result = 0;
            for(int i = 0; number != 0; i++)
            {
                armstrong = number % 10;
                number = number / 10;
                armstrong = pow(armstrong, numDigits);
                result = result + armstrong;
            }
            if(result == check)
                cout << "True\n";
            else
                cout << "False\n";
        }
    }
}