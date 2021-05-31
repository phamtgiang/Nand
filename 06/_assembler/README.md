* Student ID   : 1812004

<Note>

1. All functions and classes in source file is implemented by instructions in CHAPTER 6

* Example (main.cpp) - The assembly process *
[
**Initialization:
+ Construct an empty symbol table
+ Add the pre-defined symbols to the symbol table
**First pass:
+ Scan the entire program;
+ For each “instruction” of the form (xxx):
+ Add the pair (xxx, address) to the symbol table, where address is the number of the instruction following (xxx)
**Second pass:
+ Set n to 16
+ Scan the entire program again; for each instruction:
+ If the instruction is @symbol, look up symbol in the symbol table;
+ If (symbol, value) is found, use value to complete the instruction’s translation;
+ If not found:
- Add (symbol, n) to the symbol table,
- Use n to complete the instruction’s translation,
- n++
+ If the instruction is a C-instruction, complete the instruction’s translation
+ Write the translated instruction to the output file
]

2. compile source in terminal (C++ 14)

   <Type in terminal> cd <Directory_source_file>
   <Type in terminal> g++ -o main main.cpp parse.cpp translator.cpp symbol.cpp

3. convert *.asm to *.hack :

   <Type in terminal> main fileName.asm
   <result> : < fileName.hack >