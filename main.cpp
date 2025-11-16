#include "String.h"

int main()
{
    String s1("TESTING"), s2(s1);
    std::cout << s1.find("ti");
}