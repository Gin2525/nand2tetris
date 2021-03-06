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



(LOOP)
    @blue
    @24576
    D=M // Dレジスタにキーボードから受け取ったASCIIコードを確保
    @FILL_WHITE
    D;JEQ
    @FILL_BLACK
    D;JGT
    (CONTINUE)
    @LOOP
    0;JMP

(FILL_WHITE)
    @white_i //16?
    M=0 // i=0
    (WHITE_I_LOOP)
    @white_i 
    D=M
    @256
    D=D-A // i=i-256
    @FILL_WHITE_END // if D==0 then terminate
    D;JEQ
    @white_j //17?
    M=0 // j=0
        (WHITE_J_LOOP)
        @white_j
        D=M // D=white_j
        @32 //20?
        D=D-A // D=white_j - 32
        @WHITE_J_END
        D;JEQ
        // write to the screen
        // 1.掛け算を実装しないといけない
        //   このループではある行を塗りつぶしたいので、i*32を実装したい
        //   そして、変数に入れ込む
        //   掛け算サブルーチン化したい。なので、変数に戻り行を記録しなければならない。
        //   オペランドは変数x 変数yに記録する。　答えは変数zに記録する。
        @32
        D=A // D=32
        @x //18?
        M=D // x=D
        @white_i
        D=M // D=white_i
        @y // 現在の行数を表すwhite_iをyに 19?
        M=D // y=D
        @RETURN_WHITE // 戻るアドレスの記録 20? 32ぎょうめ？？？
        D=A // D=(RETURN_WHITE)
        @return_position //21?
        M=D // return_position=D
        @MULT //55?
        0;JMP
        (RETURN_WHITE)
        @white_j //38ぎょうめ？？？？　ここに掛け算したときに戻ってきたい。
        D=M
        @z
        D=M+D

        @16384
        A=A+D
        M=0

        @white_j
        M=M+1
        @WHITE_J_LOOP
        0;JMP
        (WHITE_J_END)
    @white_i
    M=M+1 // white_i++
    @WHITE_I_LOOP
    0;JMP
(FILL_WHITE_END)
    @CONTINUE
    0;JMP


(FILL_BLACK)
    @black_i //16?
    M=0 // i=0
    (BLACK_I_LOOP)
    @black_i 
    D=M
    @256
    D=D-A // i=i-256
    @FILL_BLACK_END // if D==0 then terminate
    D;JEQ
    @black_j //17?
    M=0 // j=0
        (BLACK_J_LOOP)
        @black_j
        D=M // D=black_j
        @32 //20?
        D=D-A // D=black_j - 32
        @BLACK_J_END
        D;JEQ
        // write to the screen
        // 1.掛け算を実装しないといけない
        //   このループではある行を塗りつぶしたいので、i*32を実装したい
        //   そして、変数に入れ込む
        //   掛け算サブルーチン化したい。なので、変数に戻り行を記録しなければならない。
        //   オペランドは変数x 変数yに記録する。　答えは変数zに記録する。
        @32
        D=A // D=32
        @x //18?
        M=D // x=D
        @black_i
        D=M // D=black_i
        @y // 現在の行数を表すblack_iをyに 19?
        M=D // y=D
        @RETURN_BLACK // 戻るアドレスの記録 20? 32ぎょうめ？？？
        D=A // D=(RETURN_BLACK)
        @return_position //21?
        M=D // return_position=D
        @MULT //55?
        0;JMP
        (RETURN_BLACK)
        @black_j //38ぎょうめ？？？？　ここに掛け算したときに戻ってきたい。
        D=M
        @z
        D=M+D

        @16384
        A=A+D
        M=-1

        @black_j
        M=M+1
        @BLACK_J_LOOP
        0;JMP
        (BLACK_J_END)
    @black_i
    M=M+1 // black_i++
    @BLACK_I_LOOP
    0;JMP
(FILL_BLACK_END)
    @CONTINUE
    0;JMP

(MULT)
    @z //22?
    M=0
    @x
    D=M
    @MULT_END //81
    D;JEQ
    @y
    D=M
    @MULT_END
    D;JEQ
    @mult_i
    M=0
(MULT_START)
    @y
    D=M //Dにyの値を保持
    @mult_i
    D=D-M // D にはy MはM[mult_i]を期待するため、初回は0が入っているはず
    @MULT_END
    D;JEQ
    // iをインクリメント
    @mult_i
    M=M+1
    // z に xを一回足す
    @x
    D=M
    @z
    M=M+D
    @MULT_START
    0;JMP
(MULT_END)
    @return_position
    A=M
    0;JMP