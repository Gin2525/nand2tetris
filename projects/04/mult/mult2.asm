    @0
    D=M
    @x
    M=D
    @1
    D=M
    @y
    M=D
    @2
    D=M
    @z
    M=D
(MULT)
    @z
    M=0
    @x
    D=M
    @MULT_END
    D;JEQ
    @y
    D=M
    @MULT_END
    D;JEQ
    @mult_i
    M=0
(MULT_START)
    @y
    D=M //DにR1の値を保持
    @mult_i
    D=D-M // D にはR1 MはM[16]を期待するため、初回は0が入っているはず
    @MULT_END
    D;JEQ
    // iをインクリメント
    @mult_i
    M=M+1
    // R2 に R0を一回足す
    @x
    D=M
    @z
    M=M+D
    @MULT_START
    0;JMP   
(MULT_END)
    @return_position
    0;JMP