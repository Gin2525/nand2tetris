// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
    @2
    M=0
    @0
    D=M
    @END
    D;JEQ
    @1
    D=M
    @END
    D;JEQ
    @i
    M=0
(LOOP)
    @1
    D=M //DにR1の値を保持
    @i
    D=D-M // D にはR1 MはM[16]を期待するため、初回は0が入っているはず
    @END
    D;JEQ
    // iをインクリメント
    @i
    M=M+1
    // R2 に R0を一回足す
    @0
    D=M
    @2
    M=M+D
    @LOOP
    0;JMP   
(END)
    @END
    0;JMP