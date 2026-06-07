//Wyn

/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

     Group #: 12 (2 digits)

    MANGAHAS, EOWYN SABRINA  S13
    LUMBANG, VAUGHN S14
    TAN, JEAN EMMANOEL S13


    PURPOSE OF THIS FILE: to show an example of a test driver program.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.c" 
int main()
{
    Stack S;    /* the stack under test */
    Point p;   /* temporary point for receiving return values */
    int   i;   /* loop counter */
 
    printf("=============================================\n");
    printf("        STACK MODULE TEST DRIVER\n");
    printf("=============================================\n\n");
    
    printf("--- Test 1: CREATE ---\n");
    CREATE(&S);
    printf("  ISEMPTY after CREATE : %d  (expected: 1)\n\n", ISEMPTY(&S));
 
    printf("--- Test 2: PUSH (10,10), (20,20), (30,30) ---\n");
 
    p.x = 10.0;  p.y = 10.0;  PUSH(&S, p);
    p.x = 20.0;  p.y = 20.0;  PUSH(&S, p);
    p.x = 30.0;  p.y = 30.0;  PUSH(&S, p);
 
    p = TOP(&S);
    printf("  TOP         : (%.0f, %.0f)  (expected: 30, 30)\n", p.x, p.y);
 
    p = NEXT_TO_TOP(&S);
    printf("  NEXT_TO_TOP : (%.0f, %.0f)  (expected: 20, 20)\n\n", p.x, p.y);

    printf("--- Test 3: POP twice ---\n");
 
    p = POP(&S);
    printf("  POP returned : (%.0f, %.0f)  (expected: 30, 30)\n", p.x, p.y);
 
    p = POP(&S);
    printf("  POP returned : (%.0f, %.0f)  (expected: 20, 20)\n", p.x, p.y);
 
    p = TOP(&S);
    printf("  TOP after 2 pops : (%.0f, %.0f)  (expected: 10, 10)\n\n", p.x, p.y);

    printf("--- Test 4: POP last element ---\n");
    p = POP(&S);
    printf("  POP returned : (%.0f, %.0f)  (expected: 10, 10)\n", p.x, p.y);
    printf("  ISEMPTY      : %d  (expected: 1)\n\n", ISEMPTY(&S));
 
    printf("--- Test 5: Fill stack to MAX (%d elements) ---\n", MAX);
    CREATE(&S);
 
    for (i = 0; i < MAX; i++) {
        p.x = (double)i;
        p.y = (double)(i * 2);
        PUSH(&S, p);
    }
 
    printf("  ISFULL after %d pushes : %d  (expected: 1)\n", MAX, ISFULL(&S));
 
    p = TOP(&S);
    printf("  TOP  : (%.0f, %.0f)  (expected: %d, %d)\n",
           p.x, p.y, MAX - 1, (MAX - 1) * 2);
 
    p = NEXT_TO_TOP(&S);
    printf("  NEXT_TO_TOP : (%.0f, %.0f)  (expected: %d, %d)\n\n",
           p.x, p.y, MAX - 2, (MAX - 2) * 2);
    POP(&S);
    printf("  ISFULL after one POP : %d  (expected: 0)\n\n", ISFULL(&S));
 
    printf("=============================================\n");
    printf("        ALL STACK TESTS COMPLETE\n");
    printf("=============================================\n");
 
    return 0;
}
