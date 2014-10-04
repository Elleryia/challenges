#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    unsigned int data[48];
    data[0] = 0;
    data[1] = 1;
    for(int i = 2; i < 48; ++i)
    {
        data[i] = data[i - 1] + data[i - 2];
        //fprintf(stdout, "Data[%u]: %u\n", i, data[i]);
    }
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
            int number = data[atoi(lineBuffer.c_str())];
            fprintf(stdout, "%d\n", number);
        }
    }
}