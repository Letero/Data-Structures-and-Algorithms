#include <iostream>
#include "Vector.h"
#include <vector>
int main(int argc, char *argv[])
{
    Vector<std::string> vec;
    vec.push_back("5");
    vec.pop_back();
    std::cout << vec.size() << std::endl;
    std::cout << *vec.begin() << std::endl;

    std::vector<std::string> v;
    v.push_back("5");
    v.pop_back();
    std::cout << v.size() << std::endl;
    std::cout << *v.begin() << std::endl;

    return 0;
}