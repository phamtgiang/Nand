#ifndef _ASSEMBLER_PARSE_H
#define _ASSEMBLER_PARSE_H

#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Parse{
    ifstream _in;
    string _curCommand;
    unordered_map<char,char> _command;
public:
    Parse(string &file);// open inputFile and specify command
    bool hasMoreCommands();// are there more lines in the input ?
    void advance();
    // reads the next command from the input and makes it the current command
    // remove whitespace and comment (not important because all *.asm in source file do not have whitespace or comment)
    // be called only if hasMoreCommands() is true
    char commandType();
    // return the type of the current command
    // A-instruction (@xxx) , C-instruction (dest=comp;jump) , L-instruction ((LOOP))
    string symbol();// return the symbol or decimal xxx of the current command (A,C - command)
    string dest();// return the dest mnemonic in the current command
    string comp();// return the comp mnemonic in the current command
    string jump();// return the jump mnemonic in the current command
};
#endif //_ASSEMBLER_PARSE_H
