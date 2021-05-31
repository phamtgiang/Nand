#include "parse.h"

using namespace std;

Parse::Parse(string &file) {
    _in.open(file);
    _command['@'] = 'A';
    _command['A'] = 'C';
    _command['D'] = 'C';
    _command['M'] = 'C';
    _command['0'] = 'C';
    _command['1'] = 'C';
    _command['-'] = 'C';
    _command['!'] = 'C';
    _command['('] = 'L';
}
bool Parse::hasMoreCommands() { return !_in.eof();}
void Parse::advance() {
    string curLine;
    unsigned long commentI;
    bool Found = false;
    while (!Found && getline(_in, curLine)) {
        curLine.erase(remove_if(curLine.begin(), curLine.end(), ::isspace), curLine.end());
        commentI = curLine.find("//");
        if (commentI != string::npos) curLine.erase(commentI, curLine.length() - commentI);
        Found = !curLine.empty();
    } _curCommand = curLine;
}
char Parse::commandType() { if(_command.find(_curCommand[0]) != _command.end()) return _command[_curCommand[0]]; }
string Parse::symbol() {
    unsigned long openBracketI = _curCommand.find('('), closeBracketI = _curCommand.find(')');
    if (_curCommand[0] == '@') return _curCommand.substr(1, _curCommand.length() - 1);
    else if (openBracketI != string::npos && closeBracketI != string::npos) return _curCommand.substr(openBracketI + 1, closeBracketI - openBracketI - 1);
    return "";
}
string Parse::dest(){
    unsigned long equalI = _curCommand.find('=');
    if (equalI != string::npos) return _curCommand.substr(0, equalI);
    return "";
}
string Parse::comp(){
    unsigned long equalI = _curCommand.find('='), semiColonI = _curCommand.find(';');
    if (equalI != string::npos) {
        if (semiColonI != string::npos) return _curCommand.substr(equalI + 1, semiColonI - equalI - 1);
        return _curCommand.substr(equalI + 1, _curCommand.length() - equalI - 1);
    }
    else if (semiColonI != string::npos) return _curCommand.substr(0, semiColonI);
    return "";
}
string Parse::jump(){
    unsigned long semiColonI = _curCommand.find(';');
    if (semiColonI != string::npos) return _curCommand.substr(semiColonI + 1, _curCommand.length() - semiColonI - 1);
    return "";
}