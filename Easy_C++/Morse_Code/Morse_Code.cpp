#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

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
            map <string, char> morse_map;
            morse_map["-----"] = '0';
            morse_map[".----"] = '1';
            morse_map["..---"] = '2';
            morse_map["...--"] = '3';
            morse_map["....-"] = '4';
            morse_map["....."] = '5';
            morse_map["-...."] = '6';
            morse_map["--..."] = '7';
            morse_map["---.."] = '8';
            morse_map["----."] = '9';
            morse_map[".-"] = 'A';
            morse_map["-..."] = 'B';
            morse_map["-.-."] = 'C';
            morse_map["-.."] = 'D';
            morse_map["."] = 'E';
            morse_map["..-."] = 'F';
            morse_map["--."] = 'G';
            morse_map["...."] = 'H';
            morse_map[".."] = 'I';
            morse_map[".---"] = 'J';
            morse_map["-.-"] = 'K';
            morse_map[".-.."] = 'L';
            morse_map["--"] = 'M';
            morse_map["-."] = 'N';
            morse_map["---"] = 'O';
            morse_map[".--."] = 'P';
            morse_map["--.-"] = 'Q';
            morse_map[".-."] = 'R';
            morse_map["..."] = 'S';
            morse_map["-"] = 'T';
            morse_map["..-"] = 'U';
            morse_map["...-"] = 'V';
            morse_map[".--"] = 'W';
            morse_map["-..-"] = 'X';
            morse_map["-.--"] = 'Y';
            morse_map["--.."] = 'Z';
            vector<string> fields = split(lineBuffer, ' ');
            for(vector<string>::iterator it = fields.begin(); it != fields.end(); ++it)
            {
                if(morse_map.find(*it) != morse_map.end()) // if its in the map
                {
                    cout << morse_map[(*it)];
                }
                else
                    cout << ' ';
            }
            cout << endl;
        }
    }
}

















