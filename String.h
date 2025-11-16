#pragma once
#include <iostream>

class String
{
    int size;
    char *str;

    void clear();
    void intialize();
    int get_length(const char *c);

public:
    String();
    String(const char *c);
    String(const String &s);
    ~String();

    String &operator=(const String &s);
    String &operator=(const char *c);
    String operator+(const String &s);
    String operator+(const char *c);
    String &operator+=(const char *c);
    String &operator+=(const String &s);
    bool operator==(const String& s);

    String upper();
    String lower();
    String reverse();
    String capitalize();
    String reverse_case();
    String ltrim();
    String rtrim();
    String trim();
    String sort(bool reverse = false, bool skip_spaces = true);
    int len();
    bool is_palindrome();
    bool anagram(const String& s);

    friend std::ostream &operator<<(std::ostream &os, const String &s);
};