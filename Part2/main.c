
#include <stdio.h>
#include "char_builder.h"
int main()
{
    int n;
    char s[100];
    printf("Nhap so n: ");
    scanf("%d", &s); // Input "2" | Nhap "2"
    fflush(stdin);
    input(s); // Input "Input Test" | Nhap "Input Test"
    printf("Ket qua: %s", s);
}

/*
Result (Ket qua):

Nhap so n: 2
Nhap xau: Input Test
Ket qua: Input Test
*/