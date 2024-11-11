#pragma once
#include <stdio.h>
#include "char_builder.h"
#include <string.h>
#include <stdlib.h>

void trim_white_space(char *cstring)
{
    int left_i = 0, right_i = strlen(cstring) - 1;
    for (; cstring[left_i] != '\0' && cstring[left_i] == ' '; left_i++)
    {
    }
    for (; cstring[right_i] != '\0' && cstring[right_i] == ' '; right_i--)
    {
    }
    for (int i = left_i; i <= right_i; i++)
    {
        cstring[i - left_i] = cstring[i];
    }
    if (right_i - left_i + 1 < 0)
    {
        cstring[0] = '\0';
        return;
    }
    cstring[right_i - left_i + 1] = '\0';
}

void remove_extra_whitespace(char *cstring)
{
    int left_i = 0, right_i = strlen(cstring) - 1;
    int count_white_space_left = 0, count_white_space_right = 0;
    for (; cstring[left_i] != '\0' && cstring[left_i] == ' '; left_i++)
    {
        count_white_space_left++;
    }
    for (; cstring[right_i] != '\0' && cstring[right_i] == ' '; right_i--)
    {
        count_white_space_right++;
    }
    for (int i = left_i; i <= right_i; i++)
    {
        cstring[i - left_i] = cstring[i];
    }
    cstring[right_i - left_i + 1] = '\0';
    for (int i = 0, j; i < ((int)strlen(cstring)) - 1; i++)
    {
        if (cstring[i] == ' ')
        {
            if (cstring[i + 1] == ' ')
            {
                for (j = i + 1; cstring[j] == ' ';)
                {
                    remove_char(cstring, j);
                }
                i = j;
            }
        }
    }
    for (; count_white_space_left > 0; count_white_space_left--)
    {
        append_char(cstring, ' ', 0);
    }
    for (; count_white_space_right > 0; count_white_space_right--)
    {
        append_char(cstring, ' ', strlen(cstring));
    }
}

void remove_char(char *cstring, int pos)
{
    int i = pos;
    for (; cstring[i + 1] != '\0'; i++)
    {
        cstring[i] = cstring[i + 1];
    }
    cstring[i] = '\0';
}

void append_char(char *cstring, char append_char, int pos)
{
    int length = strlen(cstring);
    for (int i = length; i > pos; i--)
    {
        cstring[i] = cstring[i - 1];
    }
    cstring[pos] = append_char;
    cstring[length + 1] = '\0';
}

void to_upper_case(char *cstring)
{
    for (int i = 0; cstring[i] != '\0'; i++)
    {
        if (cstring[i] >= 'a' && cstring[i] <= 'z')
            cstring[i] -= 32;
    }
}

void to_lower_case(char *cstring)
{
    for (int i = 0; cstring[i] != '\0'; i++)
    {
        if (cstring[i] >= 'A' && cstring[i] <= 'Z')
            cstring[i] += 32;
    }
}

void append(char *cstring, const char *append_string, int pos)
{
    int cstring_initial_length = strlen(cstring);
    int append_length = strlen(append_string);
    for (int i = cstring_initial_length; i >= pos; i--)
    {
        cstring[i + append_length] = cstring[i];
    }
    for (int i = pos; i < pos + append_length; i++)
    {
        cstring[i] = append_string[i - pos];
    }
    cstring[cstring_initial_length + append_length] = '\0';
}

void extract_right_char(char *cstring, int size)
{
    int length = strlen(cstring);
    for (int i = 0; i < size; i++)
    {
        cstring[i] = cstring[length - size + i];
    }
    cstring[size] = '\0';
}

void extract_left_char(char *cstring, int size)
{
    cstring[size] = '\0';
}

void extract_char(char *cstring, int pos, int size)
{
    for (int i = pos; i < pos + size; i++)
    {
        cstring[i - pos] = cstring[i];
    }
    cstring[size] = '\0';
}

void input(char *cstring)
{
    printf("Nhap xau: ");
    fgets(cstring, 1000, stdin);
}

void output(const char *cstring)
{
    printf("%s", cstring);
}