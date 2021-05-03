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
  return ~(~(~x&y)&~(x&~y));    /*  x^y=(~x&y)|(x&~y)--->两次取反
  			     				    x^y=~~[(~x&y)|(x&~y)]--->去掉一个~和[],
							        中间的|变为&(忘了叫什么定律了)
  			     			     	x^y=~(~(~x&y)&~(x&~y)).   */
  			     
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;   //最开始写成了1<<31+1(补码100...01，原码111...11)，
  	              //但正负数的取值范围是不一样的，-2^31~2^31-1
  	              //负数最小的是(补码100...00，无原码)	

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
  int temp=x+1;   //  利用！的特性，除了!0=1,其他数作!运算
  x=x+temp;	   //  都等于0，我们想办法把011...11变成000...00
  x=~x;            // (这个变的过程只能对011...11适用)此时
 	           // return !0 结果就是1了。
  
  temp=!temp;     //但还有一个例外0xFFF...FF,进行上述操作后
  x=x+temp;       //结果也为0x000...00,需要对其作特别操作
  return !x;      //只有0xFFF...FF+1会得到全0，所以对其作!加给
  		  //x,它会把0xFFF...FF得到的000...00再加1，以区分
  		  //它和011...11
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
  return !((temp&x)^temp);                        //temp&x,取出x所有奇数位(2的奇次方位), 如果temp满足奇数位都为1
  												  //那么temp&x的结果将与temp相同，那么二者异或结果将为0 
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;       //求相反数--->补码取反加一 
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
  int lower=0x2f+(~x+1);  //符合条件时(大于等于0x30)符号位为1
  int upper=0x39+(~x+1);  //符合条件时(小于等于0x39)符号位为0
  int min=!!(lower>>31);  //获取符号位 
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
  int temp=!x;             //将0变成1，其他数都变成0 
  temp=~temp+1;            //0取反加一仍为0 , 1取反加一变为0xFFFFFFFF 
  return (~temp&y)|(temp&z);  //temp为全0时对应返回值y,即x!=0时返回y,否则返回z 
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
  int first_neg=~x+1+y;    //-x+y,符号位是0，则x<=y.
  first_neg=first_neg>>31;
  bitx=(x>>31)&1;      //当x,y符号位不同时,bitx为1(负),则x更小
  bity=(y>>31)&1;
  return (!first_neg&(!(bitx^bity)))|((bitx^bity) & bitx); //对应上述两种情况 (符号位相同或不同) 
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
  int temp=(~x+1)|x;       //只有x=0时temp=0 , 其他情况下 temp=0xFFFFFFFF 
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
  x=(sign&~x)|(~sign&x); //如果x为正则不变,为负则按位取反.
  
  bit_16=!!(x>>16)<<4;  //高十六位是否有1
  x=x>>bit_16; //如果有(代表至少需要16位),则将原数右移16位
  bit_8=!!(x>>8)<<3;  //剩下的高八位是否有1
  x=x>>bit_8;  //如果有(至少需要16+8=24位)，则右移八位
  bit_4=!!(x>>4)<<2;
  x=x>>bit_4;
  bit_2=!!(x>>2)<<1;
  x=x>>bit_2;
  bit_1=!!(x>>1);
  x=x>>bit_1;
  bit_0=x;
  return bit_16+bit_8+bit_4+bit_2+bit_1+bit_0+1; //+1是算上符号位 
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
  int exp=(uf&0x7f800000)>>23;  //取阶码
  int sign=uf&(1<<31);  //取符号
  if(exp==0xFF) return uf; //NAN或无穷大时
  if(exp==0) return (uf<<1)|sign;  //非规格化时
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
  int s,exp,E,frac,M;    //s是符号位, exp是阶码, E是exp-bias(规格化)  1-bias(非规格化), 
  						//frac是尾数, M是1.frac(规格化)  0.frac(非规格化)
  s=(uf>>31);
  exp=(uf&0x7f800000)>>23;
  frac=(uf&0x007fffff);
  
  if(exp==0){   //非规格化 
    E=-126;
    M=frac;
  }
  else if(exp==0xFF){  //无穷大或NAN 
    return 0x80000000;
  }
  else{
    E=exp-127;
    M=frac|0x00800000;  //隐含的1
  }
  
  if(E<0) return 0;
  if(E>31) return 0x80000000;
  
  if(E>23) M <<= (E-23);    
  else M >>= (23-E);
  
  if(!((M>>31)^s)) return M;  //如果和原符号相同则直接返回
  else if(M>>31) return 0x80000000;  //否则如果结果为负（原来为正）则溢出返回越界指定值0x80000000u
  else return ~M+1;  //否则原来为负，结果为正，则需要返回其补码（相反数）

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
    int exp=x+127;  //2.0的二进制表示为0 00000001 000...00
    if(exp<=0) return 0; //exp=0时结果为零,因为frac部分为0
    if(exp>=255) return 0x7f800000;  //exp>255越界或无穷大
    return exp<<23;
}
