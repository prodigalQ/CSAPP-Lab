/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~(~x&y)&~(x&~y));    /*  x^y=(~x&y)|(x&~y)--->����ȡ��
  			     				    x^y=~~[(~x&y)|(x&~y)]--->ȥ��һ��~��[],
							        �м��|��Ϊ&(���˽�ʲô������)
  			     			     	x^y=~(~(~x&y)&~(x&~y)).   */
  			     
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;   //�ʼд����1<<31+1(����100...01��ԭ��111...11)��
  	              //����������ȡֵ��Χ�ǲ�һ���ģ�-2^31~2^31-1
  	              //������С����(����100...00����ԭ��)	

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int temp=x+1;   //  ���ã������ԣ�����!0=1,��������!����
  x=x+temp;	   //  ������0��������취��011...11���000...00
  x=~x;            // (�����Ĺ���ֻ�ܶ�011...11����)��ʱ
 	           // return !0 �������1�ˡ�
  
  temp=!temp;     //������һ������0xFFF...FF,��������������
  x=x+temp;       //���ҲΪ0x000...00,��Ҫ�������ر����
  return !x;      //ֻ��0xFFF...FF+1��õ�ȫ0�����Զ�����!�Ӹ�
  		  //x,�����0xFFF...FF�õ���000...00�ټ�1��������
  		  //����011...11
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int temp=0xAA+(0xAA<<8)+(0xAA<<16)+(0xAA<<24);  //temp=0xAAAAAAAA ---> 10101010...1010 
  return !((temp&x)^temp);                        //temp&x,ȡ��x��������λ(2����η�λ), ���temp��������λ��Ϊ1
  												  //��ôtemp&x�Ľ������temp��ͬ����ô�����������Ϊ0 
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;       //���෴��--->����ȡ����һ 
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int lower=0x2f+(~x+1);  //��������ʱ(���ڵ���0x30)����λΪ1
  int upper=0x39+(~x+1);  //��������ʱ(С�ڵ���0x39)����λΪ0
  int min=!!(lower>>31);  //��ȡ����λ 
  int max=!(upper>>31);
  return min&max;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int temp=!x;             //��0���1�������������0 
  temp=~temp+1;            //0ȡ����һ��Ϊ0 , 1ȡ����һ��Ϊ0xFFFFFFFF 
  return (~temp&y)|(temp&z);  //tempΪȫ0ʱ��Ӧ����ֵy,��x!=0ʱ����y,���򷵻�z 
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int bitx,bity;
  int first_neg=~x+1+y;    //-x+y,����λ��0����x<=y.
  first_neg=first_neg>>31;
  bitx=(x>>31)&1;      //��x,y����λ��ͬʱ,bitxΪ1(��),��x��С
  bity=(y>>31)&1;
  return (!first_neg&(!(bitx^bity)))|((bitx^bity) & bitx); //��Ӧ����������� (����λ��ͬ��ͬ) 
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int temp=(~x+1)|x;       //ֻ��x=0ʱtemp=0 , ��������� temp=0xFFFFFFFF 
  return (~temp>>31)&1;   
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int bit_16,bit_8,bit_4,bit_2,bit_1,bit_0;
  int sign=x>>31;
  x=(sign&~x)|(~sign&x); //���xΪ���򲻱�,Ϊ����λȡ��.
  
  bit_16=!!(x>>16)<<4;  //��ʮ��λ�Ƿ���1
  x=x>>bit_16; //�����(����������Ҫ16λ),��ԭ������16λ
  bit_8=!!(x>>8)<<3;  //ʣ�µĸ߰�λ�Ƿ���1
  x=x>>bit_8;  //�����(������Ҫ16+8=24λ)�������ư�λ
  bit_4=!!(x>>4)<<2;
  x=x>>bit_4;
  bit_2=!!(x>>2)<<1;
  x=x>>bit_2;
  bit_1=!!(x>>1);
  x=x>>bit_1;
  bit_0=x;
  return bit_16+bit_8+bit_4+bit_2+bit_1+bit_0+1; //+1�����Ϸ���λ 
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int exp=(uf&0x7f800000)>>23;  //ȡ����
  int sign=uf&(1<<31);  //ȡ����
  if(exp==0xFF) return uf; //NAN�������ʱ
  if(exp==0) return (uf<<1)|sign;  //�ǹ��ʱ
  exp++;
  if(exp==0xFF) return 0x7f800000|sign;
  return (exp<<23)|(uf&0x807fffff);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int s,exp,E,frac,M;    //s�Ƿ���λ, exp�ǽ���, E��exp-bias(���)  1-bias(�ǹ��), 
  						//frac��β��, M��1.frac(���)  0.frac(�ǹ��)
  s=(uf>>31);
  exp=(uf&0x7f800000)>>23;
  frac=(uf&0x007fffff);
  
  if(exp==0){   //�ǹ�� 
    E=-126;
    M=frac;
  }
  else if(exp==0xFF){  //������NAN 
    return 0x80000000;
  }
  else{
    E=exp-127;
    M=frac|0x00800000;  //������1
  }
  
  if(E<0) return 0;
  if(E>31) return 0x80000000;
  
  if(E>23) M <<= (E-23);    
  else M >>= (23-E);
  
  if(!((M>>31)^s)) return M;  //�����ԭ������ͬ��ֱ�ӷ���
  else if(M>>31) return 0x80000000;  //����������Ϊ����ԭ��Ϊ�������������Խ��ָ��ֵ0x80000000u
  else return ~M+1;  //����ԭ��Ϊ�������Ϊ��������Ҫ�����䲹�루�෴����

}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    int exp=x+127;  //2.0�Ķ����Ʊ�ʾΪ0 00000001 000...00
    if(exp<=0) return 0; //exp=0ʱ���Ϊ��,��Ϊfrac����Ϊ0
    if(exp>=255) return 0x7f800000;  //exp>255Խ��������
    return exp<<23;
}
