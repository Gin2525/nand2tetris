    // １〜１００までの総和を求めるプログラム
    @i
    M=1
    @sum
    M=0
(LOOP)
    @i
    D=M
    @100
    D=D-A
    @END
    D;JGT // AレジスタはENDラベルを指している。
    // JGT　つまりはDレジスタの値が正の値であればAレジスタの地点まで飛ぶ。
    @i
    D=M // i を Dレジスタに保管
    @sum
    M=D+M // 今、Aレジスタはsumを持っている。これにDレジスタ、つまりはiをたしこむ
    @i
    M=M+1
    @LOOP
    0;JMP
(END)
    @END
    0;JMP