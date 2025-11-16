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

    friend std::ostream &operator<<(std::ostream &os, const String &s);
};