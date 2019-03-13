#include <iostream>
#include <vector> // using this to compare with my Vector
#include "./Source/Vector.h"
#include "./Tests/tests.h"

int main()
{
    try
    {
        Tests newTests;
        newTests.runAllTests();
    }
    catch (const char *s)
    {
        std::cout << s;
    }

    return 0;
}