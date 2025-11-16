#pragma once
#include <iostream>

class String
{
    int size;
    char *str;

    void clear();
    void intialize();
    int get_length(const char *);

public:
    String();
    String(const char *);
    String(const String &s);
    ~String();

    String &operator=(const String &);
    String &operator=(const char *);
    String operator+(const String &s);
    String operator+(const char *);
    String &operator+=(const char *);
    String &String::operator+=(const String &);

    friend std::ostream &operator<<(std::ostream &, const String &);
};