//#include "stdafx.h" // might be required for the older versions of Visual Studio
//#include "stdafx.h" // might be required for the older versions of Visual Studio
#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif
//A variant must be obtained by calculating: (2nd + 8th) mod 4 (e.g., 2 + 5 mod 4 = 7 mod 4 -> 3)
//211ADB106 Task I -> For each row calculate the sum of negative values.
void solution_for_grade_6(const int arr[], size_t arr_rows, size_t arr_cols, int result[])
{
    __asm
    {
        mov esi, arr; ESI points to the current element in arr
        mov ebx, result; EBX points to the current element in result
        mov ecx, arr_rows; ECX is the row counter

        row_loop :
        test ecx, ecx; Check if there are more rows to process
            jz end_loop; If not, jump to end_loop

            xor edx, edx; EDX will hold the sum of negative values for the current row
            mov edi, arr_cols; EDI is the column counter for the current row

            col_loop :
        test edi, edi; Check if there are more columns in the current row
            jz next_row; If not, jump to next_row

            lodsd; Load the next integer from arr into EAXand increment ESI
            cmp eax, 0; Compare the value in EAX with 0
            jge skip_neg; If the value is non - negative, skip to skip_neg

            add edx, eax; Add the negative value to EDX

            skip_neg :
        dec edi; Decrement the column counter
            jmp col_loop; Jump back to the beginning of col_loop

            next_row :
        mov[ebx], edx; Store the sum of negative values in the current element of result
            add ebx, 4; Move to the next element in result
            dec ecx; Decrement the row counter
            jmp row_loop; Jump back to the beginning of row_loop

            end_loop :
    }

    return;
}


//211ADB106  1 + 6 MOD 4 = 3 == For each column count the number of odd values (value mod 2 <> 0).
void solution_for_grade_8(const int arr[], size_t arr_rows, size_t arr_cols, int result[])
{
    __asm
{
        //In the solution for grade 9 function, the answer is written from bottom to top, that is, the bottom number in the answer comes from our first column.
    mov esi, arr; ESI points to the current element in arr
    mov ebx, result; EBX points to the current element in result
    mov ecx, arr_cols; ECX is the column counter

    col_loop :
    test ecx, ecx; Check if there are more columns to process
        jz end_loop; If not, jump to end_loop

        xor edx, edx; EDX will hold the count of odd values for the current column
        mov edi, arr_rows; EDI is the row counter for the current column

        row_loop :
    test edi, edi; Check if there are more rows in the current column
        jz next_col; If not, jump to next_col

        mov eax, edi; Move edi into eax
        dec eax; Decrement eax because array indices start from 0
        imul eax, arr_cols; Multiply eaxand arr_cols
        add eax, ecx; Add ecx to the result
        dec eax; Decrement eax because array indices start from 0
        mov eax, [esi + eax * 4]; Load the integer at the current rowand column into EAX
        and eax, 1; Perform bitwise AND operation with 1 to check if the value is odd
        jz skip_odd; If the value is even, skip to skip_odd

        inc edx; Increment the count of odd values

        skip_odd :
    dec edi; Decrement the row counter
        jmp row_loop; Jump back to the beginning of row_loop

        next_col :
    mov[ebx], edx; Store the count of odd values in the current element of result
        add ebx, 4; Move to the next element in result
        dec ecx; Decrement the column counter
        jmp col_loop; Jump back to the beginning of col_loop

        end_loop :
}
return ;
}
//211ADB106 0 + 6  MOD 4 = 2 == In each row find the minimal positive value.


void solution_for_grade_10(const int arr[], size_t arr_rows, size_t arr_cols, int result[])
{
    __asm
    {
        mov eax, arr_rows
        mov ebx, result
        mov edi, arr
        row_loop :
        cmp eax, 0
            je end_loop

            mov edx, 0x7FFFFFFF  // INT_MAX for a 32-bit integer
            mov ecx, arr_cols
            col_loop :
        cmp ecx, 0
            je next_row

            mov esi, [edi]; Load the value from the array
            cmp esi, 0
            jle next_col
            cmp esi, edx
            jge next_col
            mov edx, esi

            next_col :
        add edi, 4
            dec ecx
            jmp col_loop

            next_row :
        cmp edx, 0x7FFFFFFF
            je no_positive
            mov[ebx], edx
            jmp end_row
            no_positive :
        mov[ebx], 0
            end_row :
            add ebx, 4
            dec eax
            jmp row_loop

            end_loop :
    }
    return;
}



const size_t ROWS = 2;
const size_t COLS = 3;

int main()
{
    const int data1[ROWS][COLS] = { { 150, -150, 25 }, { 35, 35, -550 }};
    int result1[ROWS]{};
    int result2[COLS]{};
    int resulta[ROWS]{};
    solution_for_grade_6((const int*)data1, ROWS, COLS, result1);
    solution_for_grade_8((const int*)data1, ROWS, COLS, result2);
    solution_for_grade_10((const int*)data1, ROWS, COLS, resulta);

    const int assert1[ROWS]{ -150, -550 };
    //For each row calculate the sum of negative values.
    printf(" Solution for grade 6 : \n");

    for (auto i{ 0U }; i < ROWS; i++)
    {
        printf("%d \n", result1[i]);
       assert(result1[i] == assert1[i]);
    }
    // In the solution for grade 9 function, the answer is written from bottom to top, that is, the bottom number in the answer comes from our first column.
    printf(" Solution for grade 8 :  \n");
    const int assert2[COLS]{ 1,1,1 };
    for (auto i{ 0U }; i < COLS; i++)
    {
        printf("%d \n", result2[i]);
        assert(result2[i] == assert2[i]);
    }
    puts("");

    printf(" Solution for grade 10 :  \n");
    const int assert3[COLS]{ 25,35 };
    for (auto i{ 0U }; i < ROWS; i++)
    {
        printf("%d \n", resulta[i]);
        assert(resulta[i] == assert3[i]);
    }
   

    // Other input array definitions and test cases can be added here

    return 0;
}

