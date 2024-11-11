#pragma once
#include <iostream>
#include <stdexcept>
#include "string_builder.hpp"

string_builder::string_builder()
{
    current_string = "";
}

string_builder::string_builder(std::string string)
{
    current_string = string;
}

size_t string_builder::capacity()
{
    return current_string.capacity();
}

size_t string_builder::size()
{
    return current_string.size();
}

void string_builder::trim_white_space()
{
    for (int i = current_string.size() - 1; i >= 0 && current_string[i] == ' '; i--)
    {
        current_string.pop_back();
    }
    while (current_string[0] == ' ')
    {
        current_string.erase(0, 1);
    }
}

void string_builder::remove_extra_whitespace()
{
    int count_white_space_left = 0, count_white_space_right = 0;
    for (int i = current_string.size() - 1; i >= 0 && current_string[i] == ' '; i--)
    {
        current_string.pop_back();
        count_white_space_right++;
    }
    while (current_string[0] == ' ')
    {
        current_string.erase(0, 1);
        count_white_space_left++;
    }
    for (int i = 0, j; i < current_string.size() - 1; i++)
    {
        if (current_string[i] == ' ')
        {
            if (current_string[i + 1] == ' ')
            {
                for (j = i + 1; current_string[j] == ' ';)
                {
                    current_string.erase(j, 1);
                }
                i = j;
            }
        }
    }
    for (; count_white_space_left > 0; count_white_space_left--)
    {
        current_string.insert(current_string.begin(), ' ');
    }
    for (; count_white_space_right > 0; count_white_space_right--)
    {
        current_string.push_back(' ');
    }
}

void string_builder::to_upper_case()
{
    for (int i = 0; i < current_string.size(); i++)
    {
        if (current_string[i] >= 'a' && current_string[i] <= 'z')
            current_string[i] -= 32;
    }
}

void string_builder::to_lower_case()
{
    for (int i = 0; i < current_string.size(); i++)
    {
        if (current_string[i] >= 'A' && current_string[i] <= 'Z')
            current_string[i] += 32;
    }
}

void string_builder::append(std::string append_string, int pos)
{
    if (pos < 0)
    {
        throw std::out_of_range("pos must be more than or equal to 0");
    }
    if (pos > current_string.size())
    {
        throw std::out_of_range("pos must be less than or equal to string size");
    }
    current_string.insert(pos, append_string);
}

void string_builder::extract_right_string(int size)
{
    if (size < 0)
    {
        throw std::out_of_range("size must be more than or equal to 0");
    }
    if (size > current_string.size())
    {
        throw std::out_of_range("size must be less than or equal to string size");
    }
    current_string = current_string.substr(current_string.size() - size, size);
}

void string_builder::extract_left_string(int size)
{
    if (size < 0)
    {
        throw std::out_of_range("size must be more than or equal to 0");
    }
    if (size > current_string.size())
    {
        throw std::out_of_range("size must be less than or equal to string size");
    }
    current_string = current_string.substr(0, size);
}

void string_builder::extract_string(int pos, int size)
{
    if (pos < 0)
    {
        throw std::out_of_range("pos must be more than or equal to 0");
    }
    if (pos > current_string.size())
    {
        throw std::out_of_range("pos must be less than or equal to string size");
    }
    if (size < 0)
    {
        throw std::out_of_range("size must be more than or equal to 0");
    }
    if (size > current_string.size())
    {
        throw std::out_of_range("size must be less than or equal to string size");
    }
    if (pos + size > current_string.size())
    {
        throw std::out_of_range("sum of pos and size must be less than or equal to string size");
    }
    current_string = current_string.substr(pos, size);
}

void string_builder::input()
{
    std::cout << "Nhap xau: ";
    getline(std::cin, current_string);
}

void string_builder::output()
{
    std::cout << current_string;
}

std::string string_builder::to_string()
{
    return current_string;
}
