/**

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.
     Group #: 12 (2 digits)

    MANGAHAS, EOWYN SABRINA  S13
    LUMBANG, VAUGHN S14
    TAN, JEAN EMMANOEL S13

    PURPOSE OF THIS FILE: to show an example of a C source file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!

*/

#include <stdio.h>
#include <stdlib.h>

// include your own stack header file
#include "stack.h"


/*
    EACH FUNCTION DEFINITION MUST BE PRECEDED BY A INLINE DOCUMENTATION CONTAINING THE FOLLOWING:

    a. Name of Programmer(s)
    b. Name of Tester(s) -- for an unbiased black box testing, the tester should NOT be the same person as the programmer.
    c. Code Type -- indicate EXPLICITLY if the code is one of the following: 100% Human Generated code, 100% AI Generated code
       or a modified AI generated code.  If it is a modified AI generated code, indicate explicitly which lines were 
       modified and the reason why a line of code had to be modified.
    d. Purpose -- indicate the purpose of the function
    e. Return -- indicate what will be returned (type None for void functions)
    f. Parameters -- indicate the nature of the parameters

    An example is shown below.  

    Remove the Sample() function in your own C source code.
*/


/*
    a. Name of Programmer(s):  Juan de la Cruz, Anna Santos
    b. Name of Tester(s)    :  Ichiro Makino
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will ....
    e. Return: None
    f. Parameters: x is the ...    
*/

void EXIT()
{
    return EXIT_FAILURE;
}

void CREATE (Stack *S)
{
    (*S).top = -1;
}

void PUSH (Stack *S, Point elem)
{
    if(ISFULL(S))
    {
        fprintf(stderr, "STACK OVERFLOW!");
        exit(EXIT);
    }
        (*S).top++;
        (*S).data[S->top] = elem;
}

Point POP (Stack *S)
{
    if(ISEMPTY(S))
    {
        fprintf(stderr, "STACK EMPTY!");
        exit(EXIT);
    }
    Point elem = (*S).data[S->top];
    (*S).top--;
    return elem;
}

Point TOP (Stack *S)
{
    if(ISEMPTY(S))
    {
        fprintf(stderr, "STACK EMPTY!");
        exit(EXIT);
    }
    else 
    {
        return (*S).data[S->top];
    }
}

int ISFULL(Stack *S)
{
    return ((*S).top == MAX - 1);
}

int ISEMPTY(Stack *S)
{
    return((*S).top == -1);
}

Point NEXT_TO_TOP(Stack *S)
{
    if((*S).top > 1)
    {
        fprintf(stderr, "NOT ENOUGH ELEMENTS\n");
        exit(EXIT);
    }
    return (*S).data[(*S).top - 1]; 
}




