#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Stack
{
    public:
    Stack();
    void Push(int data);
    int Pop();
    int Size();
    private:
    int data_array[1024];
    int counter;
};

Stack::Stack(void)
{
    counter = 0;
}

void Stack::Push(int data)
{
    data_array[counter] = data;
    counter++;
}

int Stack::Pop(void)
{
    if(counter == 0) return 0;
    -- counter;
    return data_array[counter];
}

int Stack::Size(void)
{
    return counter;
}

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
            Stack stack;
            vector<string> fields = split(lineBuffer, ' ');
            // push the data in
            for(int i = 0; i < fields.size(); ++i)
            {
                int data = atoi(fields[i].c_str());
                stack.Push(data);
            }
            int size = stack.Size();
            for(int i = 0; i < size; ++i)
            {
                int data = stack.Pop();
                if(i % 2 == 0)
                    cout << data << ' ';
            }
            cout << endl;
        }
    }
}












