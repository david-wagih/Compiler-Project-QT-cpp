#include "scanner.h"

string tiny;

void initMap() {
	reserved["if"] = "IF";
	reserved["then"] = "THEN";
	reserved["else"] = "ELSE";
	reserved["end"] = "END";
	reserved["repeat"] = "REPEAT";
	reserved["until"] = "UNTIL";
	reserved["read"] = "READ";
	reserved["write"] = "WRITE";
}

string isReserved(string s) {
	return reserved[s];
}

Token getToken() {
	static int i = 0;
	Token token;

	while (isspace(tiny[i]) || tiny[i] == '{') {
		if (tiny[i] == '{') {
			while (tiny[i] != '}') {
				i++;
			}
		}
		i++;
	}

	if (tiny[i] == '\0') {
		token.type = "EOF";
		token.value = "\0";
		return token;
	}

	string str = "";
	if (isdigit(tiny[i])) {
		while (isdigit(tiny[i])) {
			str += tiny[i++];
		}
		token.type = "NUMBER";
		token.value = str;
	}
	else if (isalpha(tiny[i])) {
		while (isalpha(tiny[i])) {
			str += tiny[i++];
		}
		token.value = str;
		if (!isReserved(str).empty())	token.type = isReserved(str);
		else							token.type = "IDENTIFIER";
	}
	else if (tiny[i]==':' && tiny[i+1]=='=') {
		token.type = "ASSIGN";
		token.value = ":=";
		i += 2;
	}
	else if (tiny[i] == '+') {
		token.type = "PLUS";
		token.value = tiny[i++];
	}
	else if (tiny[i] == '-') {
		token.type = "MINUS";
		token.value = tiny[i++];
	}
	else if (tiny[i] == '*') {
		token.type = "MULT";
		token.value = tiny[i++];
	}
	else if (tiny[i] == '/') {
		token.type = "DIV";
		token.value = tiny[i++];
	}
	else if (tiny[i] == '=') {
		token.type = "EQUAL";
		token.value = tiny[i++];
	}
	else if (tiny[i] == '<') {
		token.type = "LESSTHAN";
		token.value = tiny[i++];
	}
	else if (tiny[i] == '(') {
		token.type = "OPENBRACKET";
		token.value = tiny[i++];
	}
	else if (tiny[i] == ')') {
		token.type = "CLOSEDBRACKET";
		token.value = tiny[i++];
	}
	else if (tiny[i] == ';') {
		token.type = "SEMICOLON";
		token.value = tiny[i++];
	}

	return token;
}

string readFileIntoString(const string& path) {
	ifstream input_file(path);
	if (!input_file.is_open()) {
		cerr << "Could not open the file - '"
			<< path << "'" << endl;
		exit(EXIT_FAILURE);
	}
	return string((istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}
