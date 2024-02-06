# Project 1 - COP4020

## Info
- University of West Florida
- Student Name: Regan O'Donnell
- Professor: Dr. OK
- Language: C++

## Summarized Description
The goal of this project is to write a scanner and parser for a very basic program language.
Syntax for the program language is up to the student. However, comments must
be denoted by ~ key, and eol denoted by ;

## Project Desc. Given By Prof.
1. Project Description

    Implement a scanner and parser for a very simple PL in C or C++.
    I will build and run it under gcc/g++ 11.4.0 in the course VM - it's pre-installed.
    If you don't have access to the VM, it needs to run under gcc/g++ 8.5.0 under the ssh server (ssh.cs.uwf.edu).
    In this case I need a note in the submission telling me to use the old compiler!
    You must provide a makefile

1.1 Input specification

Your application must take one command-line argument, the name of the file to be checked.

    The file will contain several assignment statements.
        Each assignment statement is terminated by a semicolon (;).
        Furthermore, the group of assignment statements must be delimited by the reserved words "begin"  and "end" with a dot/period (.) after the "end" token.

    Source code is in free format, meaning that
        indentations do not matter,
        multiple statements are permitted on a line,
        a statement may appear on multiple lines (with no continuation character).
            in this case identifiers and numerical literals are not broken into two lines!
    Finally, your program must include the capability to provide comments. Comments
        begin with the tilde "~" character
        can appear anywhere and they will have effect until the end of the input line:

        ~ this is a comment
        i = 5 ~ this statement stores the value of 5 on the variable named "i"

1.2 Parser

    analyzes the source code by accepting the token stream from the Scanner
    reports whether or not the input program is legal. After processing the input file it will report either
        The program is legal: "success".
        Line <integer> contains error <errormsg> (missing ']', missing ')', expected assignment operator, expected operator, etc)

If all statements are legal, you must report all the identifiers that were used. Therefore, you will need a symbol table. Your symbol table can be implemented however you wish, but a hashtable is a good choice. If the program is illegal, you do not need to list the identifiers. An identifier that is used multiple times needs to be reported only once. Remember that identifiers are case-sensitive!

Implement scanner and a parser separately. Note that there's a distinct possibility you will need at least the Scanner again for another assignment! Also note that this scanner might need to be extended for another assignment. So program it well!



2.1 Syntax details: Numbers

    The Scanner must detect numerical literals (aka numerical constants). These literals are just unsigned ints: 123, 1234567, 456789, etc.



2.2 Syntax details: Identifiers

    A legal <identifier> will start with a letter followed by combinations of letters, numbers, and underscores, subject to the following two rules:
        You cannot have consecutive underscores
        An identifier cannot end with an underscore.
        Identifiers are case-sensitive.
    These are valid identifiers: e123, e, qwert5yuio, a_b_7
    These are not: e__7, abc_,  7yght, _iuh



2.3 Syntax details: Statements

The only type of statements are standard assignment statement with an identifier on the left side and an arbitrary expression on the right.

Examples:

a = b;
a=af+= illegal
a=; illegal
a_5 = 2;
6 = j; illegal
a=d* illegal
dd5=((3+5*8);
%iii=0 illegal
a=b2-(((x_yz + 99)* abc)*d);
qwerty=((6 - abcd)*(a + b));
xyz = (9*8*7*6)/(a+b+c);



2.4 Syntax details: Programs

A typical, minimal legal program - just a sequence of statements terminated by a semicolon between the reserved words "begin" and "end" with a period at the end.
begin
qwerty=((6 - ab_cd)*(a + b));
            xyz = (9*8*7765*6)/(a+b+c);
end.



3. Deliverables

3.1 Parser documentation

A PDF document containing

3.1.1 The formal specification of the programming language (use the spreadsheet of Exercise 1):

    Description of tokens and lexemes
    EBNF for the syntax of programs and assignment statements.

3.1.2 Documentation of the structure (in one pdf together with 3.1.3)

    Modules or classes
    Public scanner/parser interfaces

3.1.3 Documentation of the parser use

    command to run it under linux
    explanation of the error messages



3.2 Scanner and parser source code

They need to be separate modules/classes. You might need to Scanner part again, so don't mix it into the parser code!

3.3 makefile

3.4 The eight programs provided with the assignment.

3.5. A script "run" to execute all eight programs
