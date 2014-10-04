#include <iostream>
#include <fstream>
using namespace std;

ifstream::pos_type filesize(const char *filename)
{
    ifstream in(filename, ifstream::in | ifstream::binary);
    in.seekg(0, ifstream::end);
    return in.tellg();
}

int main(int argc, char *argv[])
{
    ifstream::pos_type size = filesize(argv[1]);
    cout << size << endl;
}