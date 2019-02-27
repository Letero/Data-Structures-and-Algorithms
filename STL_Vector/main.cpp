#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{
    Vector<int> vec{1, 2, 3};
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    try
    {
        vec.erase(3);
        vec.erase(3);
    }
    catch (const char *e)
    {
        std::cerr << e;
    }
    Vector<int> vec2(vec);
    for (int i = 0; i < vec2.size(); ++i)
    {
        try
        {
            std::cout << vec2.at(i) << " ";
        }
        catch (const char *e)
        {
            std::cerr << e;
        }
    }

    //for (auto a : vec2)
    {
        //  std::cout << a << " ";
    }
    try
    {
    }
    catch (const char *e)
    {
        std::cerr << e;
    }
    //Vector<int> vec2(vec);

    //std::cout << *vec.begin() << std::endl;

    std::vector<std::string> v;
    v.push_back("5");
    //std::cout << v.size() << std::endl;
    //std::cout << v.begin() << std::endl;

    return 0;
}