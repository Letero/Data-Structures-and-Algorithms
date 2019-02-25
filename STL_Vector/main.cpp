#include <iostream>
#include "Vector.h"
#include <vector>

int main(int argc, char *argv[])
{
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(23);

    //Vector<int> vec2(vec);
    for (auto a : vec)
    {
        std::cout << a << " ";
    }
    //std::cout << *vec.begin() << std::endl;

    std::vector<std::string> v;
    v.push_back("5");

    //std::cout << v.size() << std::endl;
    //std::cout << v.begin() << std::endl;

    return 0;
}