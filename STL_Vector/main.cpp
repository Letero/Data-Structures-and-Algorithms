#include <iostream>
#include "./Source/Vector.h"
#include "./Tests/tests.h"
#include <vector>
#include <typeinfo>

int main()
{
    Tests newTests;
    newTests.runAllTests();
    Vector<int> x{1, 2, 3};
    Vector<int> y = std::move(x);
    return 0;
}