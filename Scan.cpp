#include "Scan.h"

string isReserved(string s) {
    map<string, string> reserved;
    reserved["if"] = "IF";
    reserved["then"] = "THEN";
    reserved["else"] = "ELSE";
    reserved["end"] = "END";
    reserved["repeat"] = "REPEAT";
    reserved["until"] = "UNTIL";
    reserved["read"] = "READ";
    reserved["write"] = "WRITE";
    return reserved[s];
}