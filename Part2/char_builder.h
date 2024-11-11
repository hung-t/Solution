#pragma once

// In char_builder.h
void trim_white_space(char *cstring);
void remove_extra_whitespace(char *cstring);
void remove_char(char *cstring, int pos);
void append_char(char *cstring, char append_char, int pos);
void to_upper_case(char *cstring);
void to_lower_case(char *cstring);
void append(char *cstring, const char *append_string, int pos);
void extract_right_char(char *cstring, int size);
void extract_left_char(char *cstring, int size);
void extract_char(char *cstring, int pos, int size);
void input(char *cstring);
void output(const char *cstring);

#include "char_builder.c"
