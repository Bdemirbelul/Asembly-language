#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

int solution_for_grade_4(int x, int y, int z)
{
    int resultA;
    __asm
    {
        mov EAX, x
        add EAX, y
        sub EAX, z
        mov[resultA], EAX
    }
    return resultA;
}

int solution_for_grade_5(int x, int y, int z)
{
    int resultB;
    __asm
    {
        mov EAX, x
        imul EAX, 5

        mov EBX, y
        imul EBX, z
        imul EBX, 4

        sub EAX, EBX
        mov[resultB], EAX
    }
    return resultB;
}



int solution_for_grade_6(int x, int y, int z)
{
    int resultC;
    __asm
    {
        // Calculate (Y - 1)^3
        mov eax, y


        sub eax, 1
        mov ebx, y;
        sub ebx, 1
            imul eax, eax
            imul eax, ebx;

        mov edx, x
            mov ebx, z
            test ebx, ebx
            jz division_by_zero
            cdq
            //Perform(X - (Y - 1) ^ 3) / Z
            idiv ebx
            jmp end_calculation
            division_by_zero :
    end_calculation:
        sub eax, x



            mov[resultC], eax
    }
    return resultC;
}


int solution_for_grade_7(int x, int y, int z)
{
    int resultD;
    int resultA;
    __asm
    {
        // Calculate expression A once
        mov EAX, x
        add EAX, y
        sub EAX, z
        mov resultA, EAX

        // Check condition A > 0


        cmp[resultA], 0
        jle else_branch

        // Calculate and save C * A
        mov eax, y;
        sub eax, 1
            mov ebx, y;
        sub ebx, 1
            imul eax, eax
            imul eax, ebx;
        mov edx, x
            mov ebx, z
            cdq
            idiv ebx
            sub eax, x
            imul resultA
            mov[resultD], eax
            jmp end_if

            else_branch :
        // Calculate and save B * A

        mov ECX, x
            imul ECX, 5
            mov EDX, y
            imul EDX, z
            imul EDX, 4
            sub ECX, EDX
            imul ECX, resultA
            mov[resultD], ECX
            end_if :
    }
    return resultD;
}

int solution_for_grade_8(int x, int y, int z)
{
    int resultE;
    int resultA;

    __asm
    {
        // Calculate expression A once
        mov EAX, x
        add EAX, y
        sub EAX, z
        mov resultA, EAX

        // Check condition A <= 0
        cmp resultA, 0
        jg else_branch

        // C/A

        mov EAX, y
        sub EAX, 1
        mov EBX, y
        sub EBX, 1
        imul EAX, EAX
        imul EAX, EBX
        mov EDX, x
        mov EBX, z
        cdq
        idiv EBX
        cdq
        sub EAX, x

        idiv resultA
        mov resultE, EAX

        jmp end_if




        mov resultE, eax

        jmp end_if

        else_branch :
        // Calculate B / A and save the result in resultE
        mov EAX, x
            imul EAX, 5
            mov EBX, y
            imul EBX, z
            imul EBX, 4
            sub EAX, EBX
            cdq
            idiv resultA
            mov resultE, EAX

            end_if :
    }

    return resultE;
}



int solution_for_grade_9(int x, int y, int z)
{
    int resultG;
    int resultA;
    int resultB;
    int resultC;
    int resultE;

    __asm
    {
        // Calculate expression A once
        mov EAX, x
        add EAX, y
        sub EAX, z
        mov resultA, EAX

        // Check if A < 0
        cmp resultA, 0
        jl less_than_zero

        // Check if A > 0
        jg greater_than_zero

        // A is exactly 0, save -1
        mov EAX, -1
        mov resultE, EAX
        jmp end_if

        less_than_zero :
        // Calculate and save C / A
        mov EAX, y
            sub EAX, 1
            mov EBX, y
            sub EBX, 1
            imul EAX, EAX
            imul EAX, EBX
            mov EDX, x
            mov EBX, z
            cdq
            idiv EBX
            cdq
            sub EAX, x

            idiv resultA
            mov resultG, EAX
            jmp end_if




            mov resultG, eax

            greater_than_zero :
        // Calculate B / A and save the result in resultE
        mov EAX, x
            imul EAX, 5
            mov EBX, y
            imul EBX, z
            imul EBX, 4
            sub EAX, EBX
            cdq
            idiv resultA

            mov resultG, EAX

            end_if :
    }

    return resultG;
}





int main()
{
    // Note the 32-bit signed int value range is –2’147’483’648 .. 2’147’483’647
    int X = 320000;
    int Y = -250000;
    int Z = 122000;


    int resultA = solution_for_grade_4(X, Y, Z);
    int resultB = solution_for_grade_5(X, Y, Z);
    int resultC = solution_for_grade_6(X, Y, Z);
    int resultD = solution_for_grade_7(X, Y, Z);
    int resultE = solution_for_grade_8(X, Y, Z);
    int resultG = solution_for_grade_9(X, Y, Z);


    // If user wants to change the x, y ,z values the code will generate different number and assert command will block the code !!!!

    // solution_for_grade_10 Replace the comments with the expected results for each grade
    assert(resultA == X + Y - Z);
    assert(resultB == (5 * X) - 4 * Y * Z);
    int expectedC = -336300;
    assert(resultC == expectedC);
    int expectedD = 108019712;
    assert(resultD == expectedD);
    int expectedE = 6;
    assert(resultE == expectedE);
    int expectedG = 6;
    assert(resultG == expectedG);



    // Demonstrate tests using assert()


    printf("solution_for_grade_4(%d, %d, %d) = %d\n", X, Y, Z, resultA);
    printf("solution_for_grade_5(%d, %d, %d) = %d\n", X, Y, Z, resultB);
    printf("solution_for_grade_6(%d, %d, %d) = %d\n", X, Y, Z, resultC);
    printf("solution_for_grade_7(%d, %d, %d) = %d\n", X, Y, Z, resultD);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", X, Y, Z, resultE);
    printf("solution_for_grade_9(%d, %d, %d) = %d\n", X, Y, Z, resultG);
    printf("All of the expected results are correct ! \n");



    return 0;
}