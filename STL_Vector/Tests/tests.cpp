#include <iostream>
#include "tests.h"
#include <typeinfo>
Tests::Tests()
{
    testVec = {1, 2, 3, 4, 5};
}

void Tests::runAllTests()
{
    /*constructors*/
    this->test_constructor();
    this->test_copyConstructor();
    this->test_constructorInitializerList();
    this->test_deconstructor();
    /*regular member functions*/
    this->test_clear();
    this->test_assign();
    this->test_erase();
    this->test_push_back();
    this->test_pop_back();
    this->test_size();
    this->test_begin();
    this->test_end();
    this->test_at();
    this->test_front();
    this->test_back();
    this->test_empty();
    /*operators*/
    this->test_copyAssignmentOperator();
    this->test_assignWithInitializerListOperator();
    this->test_randomAccessOperator();
}

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
    Vector<int> newVec(testVec);
    if (newVec.size() == 5)
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

void Tests::test_deconstructor()
{
}

void Tests::test_clear()
{
    Vector<int> nVec = testVec;
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

void Tests::test_assign() {}

void Tests::test_erase()
{

    Vector<int> nVec = {1, 2, 3, 4, 5};
    nVec.erase(0);
    nVec.erase(0);
    nVec.erase(0);
    nVec.erase(0);
    nVec.erase(0);
    if (nVec.size() == 0)
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        std::cout << nVec.size();
        testFailure(__FUNCTION__);
    }
}

void Tests::test_push_back()
{
    Vector<int> a{33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33};
    Vector<Vector<int>> nVec;
    nVec.push_back(a);
    if ((nVec[0][20] == 33))
    {
        testSuccessful(__FUNCTION__);
    }
    else
    {
        testFailure(__FUNCTION__);
    }
}

void Tests::test_pop_back() {}

void Tests::test_size() {}

void Tests::test_begin() {}

void Tests::test_end() {}

void Tests::test_at() {}

void Tests::test_front() {}

void Tests::test_back() {}

void Tests::test_empty() {}

void Tests::testSuccessful(const char *funcName)
{
    std::cout << funcName << ": Success" << std::endl;
}
void Tests::testFailure(const char *funcName)
{
    std::cout << funcName << ": Failure" << std::endl;
}

/*operators*/
void Tests::test_copyAssignmentOperator() {}
void Tests::test_randomAccessOperator() {}
void Tests::test_assignWithInitializerListOperator() {}
