#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

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
            // get the numbers out of the string, pita
            int a=0, b=0, c=0, d=0;
            char chars[] = "(),";
            for(int i = 0; i < strlen(chars); ++i)
                lineBuffer.erase(std::remove(lineBuffer.begin(), lineBuffer.end(), chars[i]), lineBuffer.end());
            vector<string> nums = split(lineBuffer, ' ');
            a = atoi(nums[0].c_str());
            b = atoi(nums[1].c_str());
            c = atoi(nums[2].c_str());
            d = atoi(nums[3].c_str());
            int left = pow((a-c), 2);
            int right = pow((b-d), 2);
            int result = sqrt(left + right);
            cout << result << endl;
        }
    }
}