#include "String.h"

String::String()
{
    this->intialize();
}

String::String(const char *c)
{
    int len = get_length(c);
    this->size = len;
    this->str = new char[this->size + 1];
    for (int i = 0; i < this->size; i++)
        this->str[i] = c[i];
    this->str[this->size] = '\0';
}

String::String(const String &s)
{
    this->str = nullptr;
    this->size = 0;
    *this = s;
}

String::~String()
{
    clear();
}

String &String::operator=(const String &s)
{
    if (this == &s)
        return *this;
    this->clear();
    this->size = s.size;
    this->str = new char[this->size + 1];
    for (int i = 0; i <= this->size; i++)
        this->str[i] = s.str[i];
    return *this;
}

String String::operator+(const String &s)
{
    String result;
    result.size = this->size + s.size;
    result.str = new char[result.size + 1];

    int i = 0;

    for (; i < this->size; i++)
        result.str[i] = this->str[i];

    for (int j = 0; j < s.size; j++)
        result.str[i++] = s.str[j];

    result.str[result.size] = '\0';

    return result;
}

String String::operator+(const char *c)
{
    if (!c)
        return *this;

    String result;
    int len = get_length(c);
    result.size = this->size + len;
    result.str = new char[result.size + 1];

    int i = 0;

    for (; i < this->size; i++)
        result.str[i] = this->str[i];

    for (int j = 0; j < len; j++)
        result.str[i++] = c[j];

    result.str[result.size] = '\0';

    return result;
}

void String::clear()
{
    this->size = 0;
    if (this->str)
        delete[] this->str;
    this->str = nullptr;
}

void String::intialize()
{
    this->size = 0;
    this->str = new char[1];
    this->str[0] = '\0';
}

int String::get_length(const char *c)
{
    if (!c)
        return 0;
    int i;
    for (i = 0; c[i] != '\0'; i++)
        ;
    return i;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s.str;
    return os;
}
