#pragma once
#include <ostream>
#include <iostream>

class String
{
    int size;
    char *str;

public:
    String();
    String(const char *);
    String(const String &s);
    ~String();

    String &operator=(const String &s);
    String operator+(const String &s);
    String operator+(const char *);

    friend std::ostream &operator<<(std::ostream &, const String &);

    void clear();
    void intialize();
    int get_length(const char *);
};