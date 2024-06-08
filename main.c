#include <stdio.h>

void fun(int* arr1, int* arr2, int n){
    __asm__(
            ".intel_syntax noprefix;"
            "while_start:;"
            "cmp    ecx, %[n];"
            "je     while_end;"
            "mov    r8d, [rax + rcx * 4];"
            "mov    [rbx + rcx * 4], r8d;"
            "inc    ecx;"
            "jmp    while_start;"
            "while_end:;"
            ".att_syntax;"
            :
            :
            [n] "S" (n), "a"(arr1), "b"(arr2), "c"(0)
            );
}

int main() {
    int arr1[2] = {1, 2};
    int arr2[2];
    int n;
    fun(arr1, arr2, 2);
    return 0;
}
