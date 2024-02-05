//#include "stdafx.h" // might be required for the older versions of Visual Studio
#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

// C++ built-in data types mapping to assembler data types:
//   char  data type is signed  8-bit integer (DB in assembler)
//   short data type is signed 16-bit integer (DW in assembler)
//   int   data type is signed 32-bit integer (DD in assembler)

// You must use integer data type for input values.

// Update the given template code appropriately.

int solution_for_grade_6(int base_length, int triangle_height)
{
    // Calculate the area of the triangle: A = (1/2) * base_length * height
    int result1;

    __asm
    {
        mov   EAX, [base_length]
        imul  EAX, [triangle_height]
        shr   EAX, 1; Divide by 2 using shift - right operation
        mov[result1], EAX
    }

    return result1;
}
int solution_for_grade_8(int radius, int cylinder_height)
{
    // Calculate the surface area of the cylinder: A = 2πr(r + h)
    //π=3
    int result2;

    __asm


    {

        mov   ECX, [cylinder_height]
        mov   EAX, [radius]
        add ECX,EAX; Add radius to height(r + h)

        imul  EAX, 2; Multiply radius by 2
        imul  EAX, 3;


       imul  EAX, ECX; Multiply the sum by 6r


        mov[result2], EAX
    }

    return result2;
}




// :::

int main()
{
    // Note the 32-bit signed int value range is –2’147’483’648 .. 2’147’483’647
    
    int base_length = 10;
    int triangle_height = 5;



    int result1 = solution_for_grade_6(base_length, triangle_height);
    printf("Area of the triangle with base %d and height %d = %d\n", base_length, triangle_height, result1);
    assert(result1 == (base_length * triangle_height) / 2);

    int radius = 5;
    int cylinder_height = 10;



    int result2 = solution_for_grade_8(radius, cylinder_height);
    printf("Surface area of the cylinder with radius %d and height %d = %d\n", radius, cylinder_height, result2);
    assert(result2 == 2 * 3 * radius * (radius + cylinder_height));

    // You might want to invoke solution_for_grade_X() functions several times 
    // with different parameter values (e.g., to demonstrate branching).
    // :::
    return 0;
}
