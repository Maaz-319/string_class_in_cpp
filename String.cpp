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

String &String::operator=(const char *c)
{
    if (!c)
        return *this;
    this->clear();
    this->size = get_length(c);
    this->str = new char[this->size + 1];
    for (int i = 0; i < this->size; i++)
        this->str[i] = c[i];
    this->str[this->size] = '\0';
    return *this;
}

String String::operator+(const String &s)
{
    String result = *this;
    result += s;
    return result;
}

String String::operator+(const char *c)
{
    if (!c)
        return *this;

    String result = *this;
    result += c;
    return result;
}

String &String::operator+=(const char *c)
{
    if (!c)
        return *this;

    int len = get_length(c);
    if (len == 0)
        return *this;

    int newSize = this->size + len;
    char *newStr = new char[newSize + 1];

    for (int i = 0; i < this->size; i++)
        newStr[i] = this->str[i];

    for (int j = 0; j < len; j++)
        newStr[this->size + j] = c[j];

    newStr[newSize] = '\0';

    delete[] this->str;

    this->str = newStr;
    this->size = newSize;

    return *this;
}

String &String::operator+=(const String &s)
{
    if (s.size == 0)
        return *this;

    int newSize = this->size + s.size;
    char *newStr = new char[newSize + 1];

    for (int i = 0; i < this->size; i++)
        newStr[i] = this->str[i];

    for (int j = 0; j < s.size; j++)
        newStr[this->size + j] = s.str[j];

    newStr[newSize] = '\0';

    delete[] this->str;

    this->str = newStr;
    this->size = newSize;

    return *this;
}

String String::upper()
{
    String temp = *this;
    for (int i = 0; i < temp.size; i++)
    {
        char c = temp.str[i];
        if (c >= 'a' && c <= 'z')
            temp.str[i] = c & ~32;
    }
    return temp;
}

String String::lower()
{
    String temp = *this;
    for (int i = 0; i < temp.size; i++)
    {
        char c = temp.str[i];
        if (c >= 'A' && c <= 'Z')
            temp.str[i] = c | 32;
    }
    return temp;
}

String String::reverse()
{
    String temp = *this;
    for (int i = 0; i < temp.size / 2; i++)
    {
        std::swap(temp.str[i], temp.str[temp.size - i - 1]);
    }
    return temp;
}

String String::capitalize()
{
    String temp = *this;
    if (temp.size > 0 && temp.str[0] >= 'a' && temp.str[0] <= 'z')
        temp.str[0] &= ~32;

    for (int i = 1; i < temp.size; i++)
    {
        if ((temp.str[i - 1] == ' ' || temp.str[i - 1] == '\n') &&
            (temp.str[i] >= 'a' && temp.str[i] <= 'z'))
        {
            temp.str[i] &= ~32;
        }
    }
    return temp;
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
