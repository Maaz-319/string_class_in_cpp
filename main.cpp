#include "String.h"

int main()
{
    String s1 = "Hey this is Maaz", s2 = s1, s3;
    s3 = "\nThis is a separate string\n";
    s3+=s2;
    std::cout << (s1 + "\n" + s2 + s3);
}