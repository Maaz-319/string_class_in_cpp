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

bool String::operator==(const String &s)
{
    for (int i = 0; i < this->size; i++)
    {
        if (s.str[i] != this->str[i])
            return false;
    }
    return true;
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

String String::reverse_case()
{
    String temp = *this;

    for (int i = 0; i < temp.size; i++)
    {
        char c = temp.str[i];

        if (c >= 'a' && c <= 'z')
            temp.str[i] &= ~32;
        else if (c >= 'A' && c <= 'Z')
            temp.str[i] |= 32;
    }

    return temp;
}

String String::ltrim()
{
    String temp = *this;

    int i = 0;
    while (i < temp.size && temp.str[i] == ' ')
        i++;

    int new_size = temp.size - i;

    char *new_array = new char[new_size + 1];

    for (int j = 0; j < new_size; j++)
        new_array[j] = temp.str[i + j];

    new_array[new_size] = '\0';

    delete[] temp.str;
    temp.str = new_array;
    temp.size = new_size;

    return temp;
}

String String::rtrim()
{
    String temp = *this;

    int end = temp.size - 1;

    while (end >= 0 && temp.str[end] == ' ')
        end--;

    int newSize = end + 1;

    char *new_array = new char[newSize + 1];

    for (int i = 0; i < newSize; i++)
        new_array[i] = temp.str[i];

    new_array[newSize] = '\0';

    delete[] temp.str;
    temp.str = new_array;
    temp.size = newSize;

    return temp;
}

String String::trim()
{
    return this->ltrim().rtrim();
}

String String::sort(bool reverse, bool skip_spaces)
{
    String temp = *this;

    for (int i = 0; i < temp.size - 1; i++)
    {
        if (skip_spaces && temp.str[i] == ' ')
            continue;

        int target = i;

        for (int j = i + 1; j < temp.size; j++)
        {
            if (skip_spaces && temp.str[j] == ' ')
                continue;

            if (!reverse)
            {
                if (temp.str[j] < temp.str[target])
                    target = j;
            }
            else
            {
                if (temp.str[j] > temp.str[target])
                    target = j;
            }
        }

        if (target != i)
            std::swap(temp.str[i], temp.str[target]);
    }

    return temp;
}

int String::len()
{
    return this->size;
}

bool String::is_palindrome()
{
    return *this == this->reverse();
}

bool String::anagram(const String &s)
{
    char freq1[256] = {0};
    char freq2[256] = {0};
    for(int i=0; i<this->size; i++) freq1[this->str[i]]++;
    for(int i=0; i<s.size; i++) freq2[s.str[i]]++;
    for(int i=0; i<256; i++) if(freq1[i] != freq2[i]) return false;
    return true;
}

bool String::is_empty()
{
    return this->size == 0;
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
