#include <cstdio>
#include <cstring>
#include <cassert>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>




// Function for grade 6: Sum the numeric values in the input string
int solution_for_grade_6(const char* arr)
{
    if (!arr) return 0;

    int result = 0;
    __asm
    {
        mov eax, 0; // Initialize result to 0
        mov edi, arr; // Load the address of arr into edi
        xor ecx, ecx; // Clear ecx to use it as a counter

    loop_start:
        movzx edx, byte ptr[edi + ecx]; // Load the current character into edx
        test  edx, edx; // Check if it's null (end of string)
        jz    done; // Jump to the end if it is

        cmp   edx, '0'
            jl    not_digit
            cmp   edx, '9'
            jg    not_digit
            sub   edx, '0'; // Convert ASCII to integer
        add   eax, edx; // Add the digit to the result

    not_digit:
        inc   ecx; // Move to the next character
        jmp   loop_start; // Repeat the loop

    done:
        mov result, eax; // Store the result in the variable
    }

    return result;
}

// Function for grade 9: Convert lowercase letters to uppercase in the input string
void solution_for_grade_9(const char* arr, char* result) {
    if (!arr || !result) return;

    __asm {
        mov EDI, arr      // Source string address
        mov ESI, result   // Destination string address

        next_char :
        movzx EAX, byte ptr[EDI] // Load the current character into EAX
            test EAX, EAX             // Check if it's null (end of string)
            jz finish

            cmp EAX, 'a'              // Compare with lowercase 'a'
            jl not_lowercase
            cmp EAX, 'z'
            jg not_lowercase

            sub EAX, 32               // Convert to uppercase by subtracting 32
            jmp copy_char

            not_lowercase :
        cmp EAX, '0'              // Check if it's a digit
            jl copy_char
            cmp EAX, '9'
            jg copy_char

            jmp skip_char

            copy_char :
        mov[ESI], AL             // Copy the character to the result string
            inc ESI                  // Move to the next position in the result string

            skip_char :
        inc EDI                  // Move to the next character in the source string
            jmp next_char

            finish :
        mov byte ptr[ESI], 0     // Null-terminate the result string
    }
}



int main()
{
    int n_result;
    char s_result[256];

    // Additional test cases for solution_for_grade_6 can be added here

        // Test for grade 6

    n_result = solution_for_grade_6("4A 78 B");
    assert(19 == n_result);
    printf("Result for grade 6: EXAMPLE = (4A 78 B) = %d\n", n_result);

    // Test for grade 6
    n_result = solution_for_grade_6("A2A4A6BB8");
    assert(20 == n_result);
    printf("Result for grade 6: EXAMPLE = (A 2 A 4 A 6 B B 8) = %d\n", n_result);


    n_result = solution_for_grade_6("Hi Iam 9 years old ");
    printf("Result for grade 6: EXAMPLE = (Hi I am 9 years old) =  %d\n", n_result);
    assert(9 == n_result);

    // Additional test cases for solution_for_grade_9 can be added here

    // Test for grade 9

    solution_for_grade_9("a 3Bc 2d.", s_result);
    printf("Result for grade 9 : EXAMPLE =(a 3Bc 2d.) = %s\n", s_result);
    assert(!strcmp("A BC D.", s_result));

    solution_for_grade_9("123A456B789C", s_result);
    printf("Result for grade 9 : EXAMPLE = (123ABC456) =  %s\n", s_result);
    assert(!strcmp("ABC", s_result));
    solution_for_grade_9("R23T45U", s_result);
    printf("Result for grade 9 : EXAMPLE = (R23T45U) =  %s\n", s_result);
    assert(!strcmp("RTU", s_result));
    return 0;
}

