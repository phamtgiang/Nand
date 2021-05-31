#ifndef _ASSEMBLER_SYMBOL_H
#define _ASSEMBLER_SYMBOL_H

#include <string>
#include <unordered_map>
using namespace std;

class Symbol{
    unordered_map<string,int> _symbol;
public:
    Symbol();
    void addEntry(string symbol, int address); // Adds the pair(symbol,address) to the table
    bool contains(string symbol);// Does the symbol table contain the given symbol ?
    int getAddress(string symbol);// Returns the address associated with the symbol
};
#endif //_ASSEMBLER_SYMBOL_H
