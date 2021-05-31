#include <iostream>
#include <bitset>
#include  "parse.h"
#include  "symbol.h"
#include  "translator.h"

using namespace std;

int main(int argc, char *argv[]) {
    string inFile, outFile;
    int lineNum, address;
    ofstream out;
    if(argc == 2 || argc == 3) {
        inFile = argv[1];
        outFile = inFile.substr(0, inFile.length() - 4) + ".hack";
        if (argc == 3) {
            outFile = argv[2];
        }
        out.open(outFile);
        Parse source(inFile);
        Symbol symbol;
        lineNum = 0;
        while (true) {
            source.advance();
            if (!source.hasMoreCommands()) break;
            if (source.commandType() == 'A' || source.commandType() == 'C') lineNum++;
            if (source.commandType() == 'L' && !symbol.contains(source.symbol())) symbol.addEntry(source.symbol(), lineNum);
        }
        Parse assembler(inFile);
        Translator translator;
        address = 16;
        while (true) {
            assembler.advance();
            if (!assembler.hasMoreCommands()) break;
            if (assembler.commandType() == 'A') {
                out << '0';
                if (assembler.symbol().find_first_not_of("0123456789") == string::npos) out << bitset<15>(stoull(assembler.symbol(), nullptr)).to_string();
                else {
                    if (!symbol.contains(assembler.symbol())) symbol.addEntry(assembler.symbol(), address++);
                    out << bitset<15>(static_cast<unsigned long long>(symbol.getAddress(assembler.symbol()))).to_string();
                }
                out << endl;
            } else if (assembler.commandType() == 'C') out << "111" << translator.comp(assembler.comp()) << translator.dest(assembler.dest()) << translator.jump(assembler.jump()) << endl;
        }
    }
    else{
            cout << "Error : too much argument or no argument";
            exit(1);
        }
    out.close();
    return 0;
}
