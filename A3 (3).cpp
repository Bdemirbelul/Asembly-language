//#include "stdafx.h" // might be required for the older versions of Visual Studio
#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

//My school ID is 211ADB106 in the solution for grade 6 part( 2nd + 8th ) 2+0 mod 4 =2 
//Find the maximal value among the elements.
int solution_for_grade_6(int const* arr, unsigned int arr_size) {
    int result;
    __asm {
        mov ecx, arr_size
        mov esi, arr
        mov eax, -2147483648; 
        loop_start :
        cmp ecx, 0
            je loop_end; 
            mov edx, [esi]; 
            cmp edx, eax
            jle not_greater
            mov eax, edx;
            not_greater :
        add esi, 4
            loop loop_start; 
            loop_end :
        mov[result], eax; 
    }
    return result;
}
//B variant must be obtained by calculating: (2nd + 9th) mod 4 (1 + 6 mod 4 = 7 mod 4 -> 3)
//Calculate the total of even values of elements (…, -2, 0, 2, 4, …).
int solution_for_grade_7(int const* arr, unsigned int arr_size) {
    int result;
    __asm {
        // Initialize variables
        mov ecx, arr_size
        mov esi, arr
        xor eax, eax
        sum_loop :
        mov ebx, dword ptr[esi]
            test ebx, 1
            jnz skip_even
            add eax, ebx
            skip_even :
        add esi, 4
            dec ecx
            jnz sum_loop
            mov result, eax
    }

    return result;
}
//C variant must be obtained by calculating: (8nd + 9th) mod 4 (0+ 6 mod 4 = 6 mod 4 -> 2)
// Find the position of minimal positive value.
int solution_for_grade_9(const int* arr, unsigned int arr_size) {
    int min_positive = 0x7FFFFFFF; // Initialize min value to a large positive number
    int min_position = -1;
    __asm {
        mov esi, arr
        mov ecx, arr_size
        mov ebx, 0
        loop_start:
        mov eax, [esi + ebx * 4]
            test eax, eax
            jle not_positive
            cmp eax, min_positive
            jge not_min_positive
            mov min_positive, eax
            mov min_position, ebx
            not_min_positive :
    not_positive:
        inc ebx
            cmp ebx, ecx
            jl loop_start
    }
    return min_position;
}

// :::
int main() {
    int test_result;
    int test_result2;
    int test_result3;
    int test_arr1[] = { 90000, 1000, 2250, -3000, 4444, 5678, 66543, 70, -80000, 0 };
    //  first element of an array is accessed using index 0 !!!!
    int test_arr2[] = { -9, -1, 2, -3, 4, -5, 6, -7, 8, 10 };
    // Hello dear professor, I used two different arrays here so that I could operate with small numbers more easily. I hope you like it.
    test_result = solution_for_grade_6(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0]));
    test_result2 = solution_for_grade_7(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
    test_result3 = solution_for_grade_9(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
    assert(test_result == 90000);
    assert(test_result2 == 30);
    assert(test_result3 == 2);
    printf("Grade max 6 result :  = %d\n", test_result);
    printf("Grade max 7 result :  = %d\n", test_result2);
    printf("Grade max 9 result :  = %d\n", test_result3);
    printf("All of the expected results are correct ! \n");
    return 0;
}
