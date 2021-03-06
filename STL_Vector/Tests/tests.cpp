#include <iostream>
#include "tests.h"
#include <climits>

Tests::Tests() {}

Tests::~Tests() {}

void Tests::runAllTests()
{
    //constructors
    this->test_constructor();
    this->test_copyConstructor();
    this->test_constructorInitializerList();
    this->test_moveConstructor();
    this->test_deconstructor();

    //regular member functions
    this->test_clear();
    this->test_assign();
    this->test_erase();
    this->test_push_back();
    this->test_pop_back();
    this->test_size();
    this->test_begin();
    this->test_cbegin();
    this->test_end();
    this->test_cend();
    this->test_rbegin();
    this->test_crbegin();
    this->test_rend();
    this->test_crend();
    this->test_at();
    this->test_front();
    this->test_back();
    this->test_empty();
    this->test_max_size();
    this->test_capacity();
    this->test_reserve();
    this->test_resize();

    //operators
    this->test_copyAssignmentOperator();
    this->test_assignWithInitializerListOperator();
    this->test_randomAccessOperator();
    this->test_moveAssignmentOperator();

    //iterators
    this->test_iterator();
    this->test_constIterator();
}

/*constructors*/
void Tests::test_constructor()
{
    Vector<int> newVec;
    if (newVec.size() == 0)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_copyConstructor()
{
    Vector<int> x{1, 2, 3};
    Vector<int> newVec(x);
    if (newVec.size() == 3)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_constructorInitializerList()
{
    bool flag = 1; // no error
    Vector<double> a{1.1, 2.2, 3.3, 4.4};
    Vector<int> b({1, 2, 3, 4});
    Vector<char> c{'a', 1, 'b', 5};

    if ((a.size() != 4) || (b.size() != 4) || (c.size() != 4))
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_moveConstructor()
{
    Vector<int> x{1, 2, 3};
    Vector<int> y(std::move(x));
    if ((x.size() == 0) && (y.size() == 3))
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_deconstructor()
{
}

void Tests::test_clear()
{
    Vector<int> nVec{1, 2, 3};
    nVec.clear();
    if (nVec.size() == 0)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_assign()
{
    bool flag = 1;
    //assign - count and value
    Vector<int> vec;
    vec.assign(5, 6);

    if (!((vec.at(4) == 6) && vec.size() == 5))
    {
        flag = 0;
    }
    //assign - initializer list
    vec.assign({6, 6, 6, 6, 6});

    if (!((vec.at(4) == 6) && vec.size() == 5))
    {
        flag = 0;
    }
    //assign range
    int arr[5] = {1, 2, 3, 4, 5};
    vec.assign(arr, arr + 5);
    if (!((vec.at(4) == 5) && vec.size() == 5))
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_erase()
{
    bool flag = 1;
    Vector<int> nVec = {1, 2, 3, 4, 5};
    Vector<int>::iterator x = nVec.begin();
    nVec.erase(x);

    if (nVec[0] == 1)
    {
        flag = 0;
    }

    nVec.erase(x, x + 3);
    if (nVec[0] != 5)
    {
        flag = 0;
    }
    nVec.erase(x);
    nVec.erase(x);

    if (nVec.size() != 0)
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_push_back()
{
    Vector<int> a;
    for (int i = 0; i < 50; ++i)
    {
        a.push_back(33);
    }
    if (a[20] == 33)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_pop_back()
{
    Vector<int> a{1, 2, 3};
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();
    if (a.size() == 0)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_size()
{
    int flag = 1;
    Vector<int> a{1, 2, 3};

    if (a.size() != 3)
    {
        flag = 0;
    }

    a.push_back(5);
    if (a.size() != 4)
    {
        flag = 0;
    }

    a.pop_back();
    if (a.size() != 3)
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_begin()
{
    int flag = 1;
    Vector<int> a{1, 2, 3};

    if (*a.begin() != 1)
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_cbegin()
{
    int flag = 1;
    Vector<int> a{1, 2, 3};

    if (*a.cbegin() != 1)
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_end()
{
    int flag = 1;
    Vector<int> a;

    if (a.end() == (a.cbegin() + a.size() + 1)) //should point to memory after last element
    {
        flag = 0;
    }
    a = {4, 3, 2};

    if (a.end() == (a.cbegin() + a.size() + 1)) //should point to memory after last element
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_cend()
{
    int flag = 1;
    Vector<int> a;

    if (a.cend() == (a.begin() + a.size() + 1)) //should point to memory after last element
    {
        flag = 0;
    }
    a = {4, 3, 2};

    if (a.cend() == (a.begin() + a.size() + 1)) //should point to memory after last element
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_rbegin()
{
}

void Tests::test_crbegin()
{
}

void Tests::test_rend()
{
}

void Tests::test_crend()
{
}

void Tests::test_at()
{
    int flag = 1;
    Vector<int> a{1, 23};

    if (a.at(0) != 1)
    {
        flag = 1;
    }
    try
    {
        a.at(3); //should throw exception
    }
    catch (const char *s)
    {
        if (!s) //exception was not caught
        {
            flag = 0;
        }
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_front()
{
    Vector<int> a{1};
    if (a.front() == (a.back() == 1))
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_back()
{
    Vector<int> a{1};

    if (a.front() == (a.back() == 1))
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_empty()
{
    int flag = 1;
    Vector<int> a{1};

    if (a.empty())
    {
        flag = 0;
    }

    a.pop_back();
    if (!a.empty())
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_max_size()
{
    Vector<int> a;
    if (a.max_size() == UINT_MAX)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_capacity()
{
    bool flag = 1;
    Vector<int> a;

    if (a.capacity() != 0)
    {
        flag = 0;
    }

    a.push_back(5);
    if (a.capacity() != 1)
    {
        flag = 0;
    }

    a.push_back(5);
    if (a.capacity() != 2)
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_reserve()
{
    int flag = 1;
    Vector<int> a;

    if (a.capacity() != 0)
    {
        flag = 0;
    }

    a.reserve(400);
    if (a.capacity() != 400)
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_resize()
{
    bool flag = 1;
    Vector<int> x{1, 2, 3};
    x.resize(5);

    if (x.size() != 5)
    {
        flag = 0;
    }

    x.resize(10, 55);

    if (x[8] != 55)
    {
        flag = 0;
    }

    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

//helper functions
void Tests::testSuccessful(const char *funcName)
{
    std::cout << funcName << ": Success" << std::endl;
}
void Tests::testFailure(const char *funcName)
{
    std::cout << funcName << ": Failure" << std::endl;
}

/*operators*/
void Tests::test_copyAssignmentOperator()
{
    int flag = 1;
    Vector<int> a{1, 2, 3};
    Vector<int> b = a;
    for (unsigned int i = 0; i < b.size(); ++i)
    {
        if (a[i] != b[i])
        {
            flag = 0;
        }
    }
    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_randomAccessOperator()
{
    int flag = 1;
    Vector<int> a{1, 2, 3};
    Vector<int> b = a;
    for (unsigned int i = 0; i < b.size(); ++i)
    {
        if (a[i] != b[i])
        {
            flag = 0;
        }
    }
    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_assignWithInitializerListOperator()
{
    Vector<int> a = {1, 2, 3};
    if (a.size() == 3)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_moveAssignmentOperator()
{
    Vector<int> x{1, 2, 3};
    Vector<int> y;
    y = std::move(x);
    if ((x.size() == 0) && (y.size() == 3))
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

/*iterators*/
void Tests::test_iterator()
{
    bool flag = 1;
    Vector<int>::iterator iter;
    Vector<int> v{3, 3, 3, 3};
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        if (*iter != 3)
        {
            flag = 0;
        }
    }
    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_constIterator()
{
    bool flag = 1;
    Vector<int>::const_iterator iter;
    Vector<int> v{3, 3, 3, 3};
    for (iter = v.cbegin(); iter != v.cend(); iter++)
    {
        if (*iter != 3)
        {
            flag = 0;
        }
    }
    if (flag)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}
