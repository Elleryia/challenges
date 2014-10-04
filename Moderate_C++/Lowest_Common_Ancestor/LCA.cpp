#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
    struct node* parent;
    struct node* left;
    struct node* right;
    int data;
};

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
    // hardcode BST stuff
    struct node* root;
    struct node data[7];
    data[0].parent = NULL;
    data[0].left = &data[1];
    data[0].right = &data[2];
    data[0].data = 30;
    data[1].parent = &data[0];
    data[1].left = &data[3];
    data[1].right = &data[4];
    data[1].data = 8;
    data[2].parent = &data[0];
    data[2].left = NULL;
    data[2].right = NULL;
    data[2].data = 52;
    data[3].parent = &data[1];
    data[3].left = NULL;
    data[3].right = NULL;
    data[3].data = 3;
    data[4].parent = &data[1];
    data[4].left = &data[5];
    data[4].right = &data[6];
    data[4].data = 20;
    data[5].parent = &data[4];
    data[5].left = NULL;
    data[5].right = NULL;
    data[5].data = 10;
    data[6].parent = &data[4];
    data[6].left = NULL;
    data[6].right = NULL;
    data[6].data = 29;
    root = &data[0];
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
            vector<string> fields = split(lineBuffer, ' ');
            int first_data = atoi(fields[0].c_str());
            int second_data = atoi(fields[1].c_str());
            // find the node
            struct node* first = root;
            struct node* second = root;
            while(true)
            {
                if(first->data == first_data)
                {
                    break;
                }
                else if(first_data > first->data && first->right != NULL)
                {
                    first = first->right;
                }
                else if(first_data < first->data && first->left != NULL)
                {
                    first = first->left;
                }
                else // not found, bad thing
                {
                    break;
                }
            }
            while(true)
            {
                if(second->data == second_data)
                {
                    break;
                }
                else if(second_data > second->data && second->right != NULL)
                {
                    second = second->right;
                }
                else if(second_data < second->data && second->left != NULL)
                {
                    second = second->left;
                }
                else // not found, bad thing
                {
                    break;
                }
            }
            struct node* test = first;
            vector<int> leftp;
            vector<int> rightp;
            leftp.push_back(test->data);
            while(test->parent != NULL)
            {
                leftp.push_back(test->parent->data);
                test = test->parent;
            }
            test = second;
            rightp.push_back(test->data);
            while(test->parent != NULL)
            {
                rightp.push_back(test->parent->data);
                test = test->parent;
            }
            if(leftp.size() > rightp.size())
            {
                int extra = leftp.size() - rightp.size();
                for(int i = 0; i < extra; ++i)
                    leftp.erase(leftp.begin());
            }
            if(leftp.size() < rightp.size())
            {
                int extra = rightp.size() - leftp.size();
                for(int i = 0; i < extra; ++i)
                    rightp.erase(rightp.begin());
            }
            for(int i = 0; i < leftp.size(); ++i)
            {
                if(leftp[i] == rightp[i])
                {
                    cout << leftp[i] << endl;
                    break;
                }
            }
        }
    }
}












