#include <iostream>
#include "./Source/Vector.h"
#include "./Tests/tests.h"
#include <vector>

int main()
{
    Vector<int> vec{1, 2, 3, 4};
    Tests<int> newTests(vec);
    newTests.runAllTests();

    return 0;
}