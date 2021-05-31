#include "symbol.h"

Symbol::Symbol() {
    _symbol["SP"]     = 0;
    _symbol["LCL"]    = 1;
    _symbol["ARG"]    = 2;
    _symbol["THIS"]   = 3;
    _symbol["THAT"]   = 4;
    _symbol["R0"]     = 0;
    _symbol["R1"]     = 1;
    _symbol["R2"]     = 2;
    _symbol["R3"]     = 3;
    _symbol["R4"]     = 4;
    _symbol["R5"]     = 5;
    _symbol["R6"]     = 6;
    _symbol["R7"]     = 7;
    _symbol["R8"]     = 8;
    _symbol["R9"]     = 9;
    _symbol["R10"]    = 10;
    _symbol["R11"]    = 11;
    _symbol["R12"]    = 12;
    _symbol["R13"]    = 13;
    _symbol["R14"]    = 14;
    _symbol["R15"]    = 15;
    _symbol["SCREEN"] = 16384;
    _symbol["KBD"]    = 24576;
}
void Symbol::addEntry(string symbol, int address) { if(_symbol.find(symbol) == _symbol.end()) _symbol[symbol] = address; }
bool Symbol::contains(string symbol) { return _symbol.find(symbol) != _symbol.end(); }
int Symbol::getAddress(string symbol) { return _symbol[symbol]; }