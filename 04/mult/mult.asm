// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.


// CODE IN C++ : x*y
// 
// int res = 0;
// int i = 0;                // set counter i = 0
// while(i < x){
// res += y ;
// i++;
// }
// return res;


@res
M=0                          // set result = 0

@i
M=0                          // set counter i = 0

(LOOP)

       @i
       D=M                   // save value of counter i into D

       @R0
       D=M-D                 // save value of (MEM[R0] - counter i) into D

       @STOP
       D;JEQ                 // [if D == 0 , then goto STOP] means counter i == MEM[R0] goto STOP

       @R1
       D=M                   // Save value of R1 into D

       @res
       M=D+M                 // result += MEM[R1]

       @i
       M=M+1                 // i++

       @LOOP
       0;JMP                 // goto LOOP

(STOP)
@res
D=M                          // save value of resutl into D

@R2
M=D                          // set value of R2 = res , MEM[R2] = res

(END)
@END 
0;JMP                        