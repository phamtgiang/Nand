// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(INPUT)

	@KBD                   // Keyboard address
	D=M                    // save value of KBD into D

	@color                 // Declare color variable
	M=0                    // default color is white

	@FILL_SCREEN
	D;JEQ                  // if keyboard == 0, goto FILL_SCREEN
 
	@COLOR_BLACK
	0;JMP                  // else, goto COLOR_BLACK

@INPUT
0;JMP                          // jump to INPUT

(COLOR_BLACK)
@color
M=-1                           // set color black

(FILL_SCREEN)
	                       // if @color == -1 then pixels becomes black
	                       // else if @color == 0, pixels becomes white           
	@SCREEN
	D=A

	@pixels               
	M=D                   // address : 16384 --> 24576

(FILL_LOOP)

	        @color
	        D=M           // save value of color into D

		@pixels
		A=M
		M=D           // MEM[MEM[pixels]] = color

		@pixels
		M=M+1         // MEM[pixels] += 1

		@24576        
		D=A

		@pixels
		D=D-M         // D = 24576 - pixels

	@FILL_LOOP
	D;JGT                 // if D > 0 goto FILL_LOOP

@INPUT
0;JMP                         // Infinite loop