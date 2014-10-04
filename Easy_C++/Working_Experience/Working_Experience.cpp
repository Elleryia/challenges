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
            int time[360] = {};
            string array[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
            vector<string> lookup(array, array+12);
            vector<string> fields = split(lineBuffer, ';');
            for(int i = 0; i < fields.size(); ++i)
            {
                if(fields[i][0] == ' ')
                    fields[i].erase(0,1);
                vector<string> span = split(fields[i], '-');
                vector<string> start = split(span[0], ' ');
                vector<string> end = split(span[1], ' ');
                int start_pos = find(lookup.begin(), lookup.end(), start[0]) - lookup.begin();
                int end_pos = find(lookup.begin(), lookup.end(), end[0]) - lookup.begin();
                int start_year = atoi(start[1].c_str()) - 1990;
                int end_year = atoi(end[1].c_str()) - 1990;
                int begin = start_year * 12 + start_pos;
                int finish = end_year * 12 + end_pos + 1;
                for(int j = begin; j < finish; ++j)
                    time[j] = 1;
            }
            int total = 0;
            for(int i = 0; i < 360; ++i)
            {
                if(time[i] == 1)
                    total += 1;
            }
            cout << total/12 << endl;
        }
    }
}














