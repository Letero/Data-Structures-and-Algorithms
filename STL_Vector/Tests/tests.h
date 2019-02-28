#ifndef TESTS_H
#define TESTS_H
#include "../Source/Vector.h"
#include <iostream>

template <class T>
class Tests : public Vector<T>
{
  public:
    Tests(Vector<T> vec)
    {
        testVec = vec;
    }
    /*constructors*/
    void test_constructor();
    void test_copyConstructor();
    void test_constructorInitializerList();
    void test_deconstructor();

    /*regular public members*/
    void test_clear();     //clear contents of vector
    void test_assign();    //todo
    void test_erase();     //remove element from given position
    void test_push_back(); //add element at the end of vec
    void test_pop_back();  //remove element from the end of vec
    void test_size();      //return size of vec
    void test_begin();     //return pointer to first elem
    void test_end();       //return pointer to place after last elem
    void test_at();        //return element from given pos
    void test_front();     // return value of first elem in vector
    void test_back();      //return value of last elem in vector
    void test_empty();     //check if vector is empty

    /*operators*/
    void test_assignmentOperator();   //assign operator
    void test_randomAccessOperator(); //random access operator
    void runAllTests();

  private:
    Vector<T> testVec;
};

template <class T>
void Tests<T>::runAllTests()
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
    this->test_assignmentOperator();
    this->test_randomAccessOperator();
}

template <class T>
void Tests<T>::test_constructor() {}

template <class T>
void Tests<T>::test_copyConstructor() {}

template <class T>
void Tests<T>::test_constructorInitializerList() {}

template <class T>
void Tests<T>::test_deconstructor() {}

template <class T>
void Tests<T>::test_clear()
{
    Vector<T> nVec = testVec;
    nVec.clear();
    if (nVec.size() == 0)
    {
        std::cout << "test_clear: SUCCESSFUL" << std::endl;
    }
    else
    {
        std::cout << "test_clear: FAILED" << std::endl;
    }
}

template <class T>
void Tests<T>::test_assign() {}

template <class T>
void Tests<T>::test_erase() {}

template <class T>
void Tests<T>::test_push_back() {}

template <class T>
void Tests<T>::test_pop_back() {}

template <class T>
void Tests<T>::test_size() {}

template <class T>
void Tests<T>::test_begin() {}

template <class T>
void Tests<T>::test_end() {}

template <class T>
void Tests<T>::test_at() {}

template <class T>
void Tests<T>::test_front() {}

template <class T>
void Tests<T>::test_back() {}

template <class T>
void Tests<T>::test_empty() {}

/*operators*/
void test_assignmentOperator();
void test_randomAccessOperator();
#endif //TESTS_H