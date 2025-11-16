#pragma once

class String
{
    int size;
    char *str;

public:
    String();
    String(const char *);
    String(const String& s);
    ~String();

    String& operator=(const String& s);
    String operator+(const String& s);
    String operator+(const char *);

    void clear();
    void intialize();
    int get_length(const char *);
};