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
    int board[256][256] = {};
    /* for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 256; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    } */
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
            vector<string> fields = split(lineBuffer, ' ');
            //vector<string>::iterater it = fields.begin + 0;
            //cout << fields[0] << endl;
            if(fields[0].compare("SetRow") == 0)
            {
                int row = atoi(fields[1].c_str());
                int value = atoi(fields[2].c_str());
                //cout << row << " " << value << endl;
                for(int i = 0; i < 256; i++)
                    board[row][i] = value;
            }
            else if(fields[0].compare("SetCol") == 0)
            {
                int col = atoi(fields[1].c_str());
                int value = atoi(fields[2].c_str());
                //cout << col << " " << value << endl;
                for(int i = 0; i < 256; i++)
                    board[i][col] = value;
            }
            else if(fields[0].compare("QueryRow") == 0)
            {
                int row = atoi(fields[1].c_str());
                //cout << row << endl;
                int sum = 0;
                for(int i = 0; i < 256; i++)
                    sum += board[row][i];
                cout << sum << endl;
            }
            else if(fields[0].compare("QueryCol") == 0)
            {
                int col = atoi(fields[1].c_str());
                //cout << col << endl;
                int sum = 0;
                for(int i = 0; i < 256; i++)
                    sum += board[i][col];
                cout << sum << endl;
            }
        }
    }
}






