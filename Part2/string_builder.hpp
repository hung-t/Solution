#pragma once

class string_builder
{
private:
    std::string current_string;

public:
    string_builder();
    string_builder(std::string string);
    size_t capacity();
    size_t size();
    void trim_white_space();
    void remove_extra_whitespace();
    void to_upper_case();
    void to_lower_case();
    void append(std::string append_string, int pos);
    void extract_right_string(int size);
    void extract_left_string(int size);
    void extract_string(int pos, int size);
    void input();
    void output();
    std::string to_string();
};

#include "string_builder.cpp"
