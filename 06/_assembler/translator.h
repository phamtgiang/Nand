#ifndef _ASSEMBLER_TRANSLATOR_H
#define _ASSEMBLER_TRANSLATOR_H

#include <string>
#include <unordered_map>
using namespace std;

class Translator{
    unordered_map<string,string> _dest, _comp, _jump;
public:
    Translator();
    string comp(string mnemonic); // (7 bits) return the binary code of the dest mnemonic
    string dest(string mnemonic); // (3 bits) return thr binary code of the comp mnemonic
    string jump(string mnemonic); // (3 bits)return the binary code of the jump mnemonic
};
#endif //_ASSEMBLER_TRANSLATOR_H
