#include <iostream>
#include <vector> // using this to compare with my Vector
#include "./Source/Vector.h"
#include "./Tests/tests.h"

int main()
{
    Tests newTests;
    //newTests.runAllTests();
    //newTests.test_erase();

    std::vector<int> x{1, 2, 3};
    std::vector<int>::iterator y = x.begin();

    x.erase(y + 1, x.end());
    for (auto &a : x)
    {
        std::cout << a << " ";
    }
    std::cout << "\n";

    return 0;
}