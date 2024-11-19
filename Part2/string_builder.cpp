#pragma once
#include <iostream>
#include <string.h>
#include <stdexcept>
#include "string_builder.hpp"
void string_builder::remove_char(int pos)
{
    if (pos < 0)
    {
        throw std::out_of_range("pos must be more than or equal to 0");
    }
    if (pos >= strlen(current_string))
    {
        throw std::out_of_range("pos must be less than string size");
    }
    int i = pos;
    for (; current_string[i + 1] != '\0'; i++)
    {
        current_string[i] = current_string[i + 1];
    }
    current_string[i] = '\0';
}

void string_builder::append_char(char append_char, int pos)
{
    size_t length = size();
    if (pos < 0)
    {
        throw std::out_of_range("pos must be more than or equal to 0");
    }
    if (pos > length)
    {
        throw std::out_of_range("pos must be less than or equal to string size");
    }
    if (length + 1 >= cap)
    {
        char *temp = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            temp[i] = current_string[i];
        }
        for (int i = length; i > pos; i--)
        {
            temp[i] = current_string[i - 1];
        }
        temp[pos] = append_char;
        temp[length + 1] = '\0';
        cap++;
        delete current_string;
        current_string = temp;
    }
    else
    {
        for (int i = length; i > pos; i--)
        {
            current_string[i] = current_string[i - 1];
        }
        current_string[pos] = append_char;
        current_string[length + 1] = '\0';
    }
}

string_builder::string_builder()
{
    current_string = new char[1];
    current_string[0] = '\0';
    cap = 1;
}

string_builder::string_builder(std::string string)
{
    cap = string.size() + 1;
    current_string = new char[cap];
    for (int i = 0; string[i] != '\0' && i < cap - 1; i++)
    {
        current_string[i] = string[i];
    }
    current_string[cap - 1] = '\0';
}

int string_builder::capacity()
{
    return cap;
}

int string_builder::size()
{
    int length = 0;
    while (current_string[length] != '\0')
    {
        length++;
    }
    return length;
}

void string_builder::trim_white_space()
{
    int left_i = 0, right_i = size() - 1;
    for (; current_string[left_i] != '\0' && current_string[left_i] == ' '; left_i++)
    {
    }
    for (; current_string[right_i] != '\0' && current_string[right_i] == ' '; right_i--)
    {
    }
    for (int i = left_i; i <= right_i; i++)
    {
        current_string[i - left_i] = current_string[i];
    }
    current_string[right_i - left_i + 1] = '\0';
}

void string_builder::remove_extra_whitespace()
{
    int left_i = 0, right_i = strlen(current_string) - 1;
    int count_white_space_left = 0, count_white_space_right = 0;
    for (; current_string[left_i] != '\0' && current_string[left_i] == ' '; left_i++)
    {
        count_white_space_left++;
    }
    for (; current_string[right_i] != '\0' && current_string[right_i] == ' '; right_i--)
    {
        count_white_space_right++;
    }
    for (int i = left_i; i <= right_i; i++)
    {
        current_string[i - left_i] = current_string[i];
    }
    current_string[right_i - left_i + 1] = '\0';
    for (int i = 0, j; i < ((int)size()) - 1; i++)
    {
        if (current_string[i] == ' ')
        {
            if (current_string[i + 1] == ' ')
            {
                for (j = i + 1; current_string[j] == ' ';)
                {
                    remove_char(j);
                }
                i = j;
            }
        }
    }
    for (; count_white_space_left > 0; count_white_space_left--)
    {
        append_char(' ', 0);
    }
    for (; count_white_space_right > 0; count_white_space_right--)
    {
        append_char(' ', size());
    }
}

void string_builder::to_upper_case()
{
    for (int i = 0; current_string[i] != '\0'; i++)
    {
        if (current_string[i] >= 'a' && current_string[i] <= 'z')
            current_string[i] -= 32;
    }
}

void string_builder::to_lower_case()
{
    for (int i = 0; current_string[i] != '\0'; i++)
    {
        if (current_string[i] >= 'A' && current_string[i] <= 'Z')
            current_string[i] += 32;
    }
}

void string_builder::append(std::string append_string, int pos)
{
    int cstring_initial_length = size();
    if (pos < 0)
    {
        throw std::out_of_range("pos must be more than or equal to 0");
    }
    if (pos > size())
    {
        throw std::out_of_range("pos must be less than or equal to string size");
    }
    int append_initial_string_length = append_string.size();
    for (int i = 0; i < append_initial_string_length; i++)
    {
        append_char(append_string[i], pos + i);
    }
    current_string[cstring_initial_length + append_initial_string_length] = '\0';
}

void string_builder::extract_right_string(int size)
{
    size_t length = this->size();
    if (size < 0)
    {
        throw std::out_of_range("size must be more than or equal to 0");
    }
    if (size > length)
    {
        throw std::out_of_range("size must be less than or equal to string size");
    }
    for (int i = 0; i < size; i++)
    {
        current_string[i] = current_string[length - size + i];
    }
    current_string[size] = '\0';
}

void string_builder::extract_left_string(int size)
{
    if (size < 0)
    {
        throw std::out_of_range("size must be more than or equal to 0");
    }
    if (size > this->size())
    {
        throw std::out_of_range("size must be less than or equal to string size");
    }
    current_string[size] = '\0';
}

void string_builder::extract_string(int pos, int size)
{
    int length = this->size();
    if (pos < 0)
    {
        throw std::out_of_range("pos must be more than or equal to 0");
    }
    if (pos > length)
    {
        throw std::out_of_range("pos must be less than or equal to string size");
    }
    if (size < 0)
    {
        throw std::out_of_range("size must be more than or equal to 0");
    }
    if (size > length)
    {
        throw std::out_of_range("size must be less than or equal to string size");
    }
    if (pos + size > length)
    {
        throw std::out_of_range("sum of pos and size must be less than or equal to string size");
    }
    for (int i = pos; i < pos + size; i++)
    {
        current_string[i - pos] = current_string[i];
    }
    current_string[size] = '\0';
}

void string_builder::input()
{
    std::string temp;
    std::cout << "Nhap xau: ";
    getline(std::cin, temp);
    cap = temp.size() + 1;
    current_string = new char[cap];
    for (int i = 0; temp[i] != '\0' || i < cap - 1; i++)
    {
        current_string[i] = temp[i];
    }
    current_string[cap - 1] = '\0';
}

void string_builder::output()
{
    std::cout << current_string;
}

std::string string_builder::to_string()
{
    std::string temp;
    for (int i = 0; current_string[i] != '\0'; i++)
    {
        temp.push_back(current_string[i]);
    }
    return temp;
}
