#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define BIT_32(x) (0x00000001 << (x-1))
#define SET_BIT(ADDRESS, BIT) ((ADDRESS) |= (BIT))

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
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\r'), lineBuffer.end());
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\n'), lineBuffer.end());
            vector<string> fields = split(lineBuffer, ',');
            
            vector<string>::iterator it = fields.begin() + 0;
            vector<string>::iterator fir = fields.begin() + 1;
            vector<string>::iterator sec = fields.begin() + 2;
            unsigned int base = strtoul((*it).c_str(), NULL, 10);
            unsigned int first = 0x0;
            unsigned int second = 0x0;
            SET_BIT(first, BIT_32(atoi((*fir).c_str())));
            SET_BIT(second, BIT_32(atoi((*sec).c_str())));
            //fprintf(stdout, "Base is: 0x%08x\n", base);
            //fprintf(stdout, "First is 0x%08x, Second is: 0x%08x\n", first, second);
            if(((base & first) && (base & second)) || (!(base & first) && !(base & second)))
                fprintf(stdout, "true\n");
            else
                fprintf(stdout, "false\n");
        }
    }
}