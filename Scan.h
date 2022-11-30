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

queue<Token> string_parse(string tiny);

string readFileIntoString(const string& path);

void fileOut(queue<Token> s);

queue<Token> scanFile();
