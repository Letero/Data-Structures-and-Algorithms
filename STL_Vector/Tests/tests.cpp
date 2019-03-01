#include <iostream>
#include "tests.h"

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

Tests::Tests()
{
    testVec = {1, 2, 3, 4, 5};
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
    std::cout << testVec.size();
    Vector<int> newVec(testVec);

    if (newVec.size() > 0)
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
    Vector<std::string> a{"a", "b", "c", "d"};
    Vector<std::string> b({"a", "b", "c", "d"});

    if ((a.size() != 4) || (b.size() != 4))
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

void Tests::test_erase() {}

void Tests::test_push_back() {}

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
