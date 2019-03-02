#include <iostream>
#include "./Source/Vector.h"
#include "./Tests/tests.h"
#include <vector>
#include <typeinfo>

int main()
{
    std::vector<std::string> a;
    a.push_back("a");
    std::cout << typeid(a[0]).name() << '\n';

    Tests newTests;
    newTests.runAllTests();

    return 0;
}