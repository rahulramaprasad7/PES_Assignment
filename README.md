# PES Project 1 Readme

> **Team Members:** 
> - Rahul Ramaprasad 
> - Prayag Milan Desai

**Description of repository contents:**

**Problem1:**  
This folder contains the C code and the output file for the first problem of the first PES project.  
It is a C program takes as input a numeric value, a radix, and an operand size, and outputs a table containing the following values:
- Binary (abs)
- Octal (abs)
- Decimal (abs) Hexadecimal (abs)
- Signed One’s Compliment
- Signed Two’s Compliment Sign-Magnitude

**Problem2:**  
This folder contains the C code and the output file for the second problem of the first PES project.  
It is a C program that uses a logical expression that tests whether a given character code is
- Lower case
- Upper case
- Digit
- White space (like null, backspace, space, tabs, etc.)
- Special character (like ! or >)

Infromation about segregating the input ASCII codes into different categories can be found in the Problem2 folder

**Problem3:**  
This folder contains the C code and the output file for the third problem of the first PES project.
In the C program, given the starting integer value 0xCAFE, the program performs a combination of the following functions to the starting integer, and outputs the result of each finction to the command line
- Printing in binary, hexadecimal
- Testing if last 3 bits of the result are on, and printing the result of that test
- Byte order reversal
- Bit rotation

---

**Installation/execution notes for the C code in this repository:**  
All the code in this repository should be executed using the following command:  
`gcc -std=c99 -Wall -Werror -o ProgramXXX.out ProblemX.c`  
This project has the following requirements, that are fulfilled using the aforementioned command:
- GCC C99 complier: the -std=c99 flag uses the C99 compiler to complie the code
- No errors and warnings: The -Wall flag enables a set of warnings, and the -Werror flag treats the warnings as errors. Since the output of the compiler shows no error, the code is without any compiler warnings and errors
- Output file name: The -o flag and the name after the flag specifies the output file
