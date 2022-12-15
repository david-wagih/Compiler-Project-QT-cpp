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
void initMap(void);
Token getToken();
string readFileIntoString(const string& path);
void fileOut(queue<Token> s);
queue<Token> scan(string file_content);
