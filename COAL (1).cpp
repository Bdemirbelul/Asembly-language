#ifdef __cplusplus
#include <cstdio>
#include <cassert>


#else
#include <stdio.h>
#include <assert.h>
#include <stdafx.h>
#endif

short solution_for_grade_5(short x, short y, short z)
{
    //Memory 1 EAX = AF6BFD76 EBX = 00580320 ECX = 0000000A EDX = 0000001E ESI = 00861023 EDI = 006FF644 EIP = 0086198A ESP = 006FF550 EBP = 006FF644 EFL = 00010283 

    // Selected variant and expression: Variant 1: X + Y - Z
    short resultA;
    __asm
    {
        // Obtain expression A variant by calculating: (2nd + 8th) mod 4
        mov AX, x
        add AX, y
        add AX, 0; Replace 8 with the 8th digit of your student ID
        mov BX, 4
        mov BX, AX; store the result in BX for later use
        Variant1 :
        // Variant 1: X + Y - Z
        mov AX, x
            add AX, y
            sub AX, z
            jmp Done
            Done :
        mov[resultA], AX; save the result



    }
    return resultA;
}
short solution_for_grade_6(short x, short y, short z)
// Variant 3 : 5X - 4YZ

{
    // Selected variant and expression: Variant 3: 5X - 4YZ
    short resultB;
    __asm
    {

        // Obtain expression B variant by calculating: (2nd + 9th) mod 4
        mov AX, x
        add AX, y
        add AX, 6; // Replace 6 with the 9th digit of your student ID
        mov BX, 4
            xor DX, DX; Clear DX before division
            div BX
            mov BX, AX; store the result in BX for later use
            Variant3 :
        // Variant 3 : 5X - 4YZ
        mov AX, x
            mov CX, z
            mov BX, y
            imul AX, 5
            imul BX, 4
            imul BX, CX
            sub AX, BX
            jmp Done
            Done :
        mov resultB, AX; save the result



    }
    return resultB;
}
short solution_for_grade_7(short x, short y, short z)
{
    short resultA;
    short resultB;
    short resultC;

    // Variant 1: X + Y - Z
    __asm
    {
        mov AX, x
        add AX, y
        sub AX, z
        mov resultA, AX
    }

    // Variant 3: 5X - 4YZ
    __asm
    {
        mov AX, x
        mov CX, z
        mov BX, y
        imul AX, 5
        imul BX, 4
        imul BX, CX
        sub AX, BX
        mov resultB, AX
    }

    // Compute B - A (Variant3 - Variant1) using stack operations
    __asm
    {
        mov AX, resultA
        push AX
        mov AX, resultB
        push AX
        pop AX
        pop BX
        sub BX, AX
        mov resultC, BX
    }

    return resultC;
}

short solution_for_grade_8(short x, short y, short z)
{
    short resultA;
    short resultC;
    short resultD;

    // Variant 1: X + Y - Z
    __asm
    {
        mov AX, x
        add AX, y
        sub AX, z
        mov resultA, AX
    }

    // Variant 3: 5X - 4YZ
    __asm
    {
        mov AX, x
        mov CX, z
        mov BX, y
        imul AX, 5
        imul BX, 4
        imul BX, CX
        sub AX, BX
        mov resultC, AX
    }

    // Compute A * B (Variant1 * Variant3) using stack operations
    __asm
    {
        mov AX, resultA
        push AX
        mov AX, resultC
        push AX
        pop AX
        pop BX

        // Compute A * B
        imul AX, BX
        mov resultD, AX
    }

    return resultD;
}

short solution_for_grade_9(short x, short y, short z)
{
    short resultA;
    short resultB;
    short resultE;

    // Variant 1: X + Y - Z
    __asm
    {
        mov AX, x
        add AX, y
        sub AX, z
        mov resultA, AX
    }

    // Variant 3: 5X - 4YZ
    __asm
    {
        mov AX, x
        mov CX, z
        mov BX, y
        imul AX, 5
        imul BX, 4
        imul BX, CX
        sub AX, BX
        mov resultB, AX
    }

    // Compute B / A (Variant3 / Variant1) using stack operations
    __asm
    {
        mov AX, resultA
        push AX
        mov AX, resultB
        push AX
        pop AX
        pop BX

        // Perform division B / A
        xor DX, DX; Clear DX before division
        idiv BX
        mov resultE, AX
    }

    return resultE;
}

int main() {
    short solution_for_grade_5(short a, short b, short c);
    short solution_for_grade_6(short a, short b, short c);
    short solution_for_grade_7(short a, short b, short c);
    short solution_for_grade_8(short a, short b, short c);
    short solution_for_grade_9(short a, short b, short c);
    short x = 420;
    short y = -50;
    short z = 122;
    short resultA = solution_for_grade_5(x, y, z);
    short resultB = solution_for_grade_6(x, y, z);
    short resultC = solution_for_grade_7(x, y, z);
    short resultD = solution_for_grade_8(x, y, z);
    short resultE = solution_for_grade_9(x, y, z);
    // solution_for_grade_10 Replace the comments with the expected results for each grade
    assert(resultA == x+y-z);
    assert(resultB == (5*x)-4*y*z);
    assert(-resultC == resultB-resultA);
    short expectedD = 18400;
    assert(resultD == expectedD);
    short expectedE = 106;
    assert(resultE == expectedE);
    //If the expected values are diffrent - crash 
    // Use the C / C++ function assert() or similar high - level language methods, to demonstrate the testing of your solutions.

    printf("solution_for_grade_5(%d, %d, %d) = %d\n", x, y, z, resultA);
    printf("solution_for_grade_6(%d, %d, %d) = %d\n", x, y, z, resultB);
    printf("solution_for_grade_7(%d, %d, %d) = %d\n", x, y, z, -resultC);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", x, y, z, resultD);
    printf("solution_for_grade_9(%d, %d, %d) = %d\n", x, y, z, resultE);
    printf("All of the expected results are correct ! \n");
    //Each next level task assumes that you retain all lower-level solutions. However, you must not reuse lower grade solutions as function calls from higher level solutions. Instead copy reusable part(s) into higher lever task solution.
    return 0;
}