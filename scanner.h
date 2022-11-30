#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
using namespace std;

struct Token
{
    string type;
    string value;
};

//Function Prototypes
string readFileIntoString(const string& path);
Token getToken();
void fileOut(queue<Token> s);
queue<Token> scanFile();
