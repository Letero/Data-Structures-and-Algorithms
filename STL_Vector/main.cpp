#include <iostream>
#include "./Source/Vector.h"
#include "./Tests/tests.h"
#include <vector>

int main()
{
    Tests newTests;
    newTests.runAllTests();
    std::vector<int> nvec;
    nvec = {1, 2, 3, 5};
    return 0;
}