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
            vector<string> fields = split(lineBuffer, ';');
            vector<string> words = split(fields[0], ' ');
            vector<string> position = split(fields[1], ' ');
            int size = words.size();
            vector<string> solution(size);
            int location[size - 1];
            for(int i = 0; i < position.size(); ++i)
            {
                location[i] = atoi(position[i].c_str());
                solution[location[i]-1] = words[i];
            }
            for(int i = 0; i < solution.size(); ++i)
            {
                if(solution[i].empty())
                    solution[i] = words[size - 1];
            }
            for(int i = 0; i < solution.size() - 1; ++i)
                cout << solution[i] << ' ';
            cout << solution[size - 1] << endl;
        }
    }
}













