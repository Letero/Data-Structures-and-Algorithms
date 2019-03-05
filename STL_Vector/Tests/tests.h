#ifndef TESTS_H
#define TESTS_H
#include "../Source/Vector.h"

class Tests
{
public:
  Tests();
  /*constructors to test */
  void test_constructor();
  void test_copyConstructor();
  void test_constructorInitializerList();
  void test_deconstructor();

  /*regular public members to test*/
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

  /*operators to test*/
  void test_copyAssignmentOperator(); //assign operator
  void test_randomAccessOperator();   //random access operator
  void test_assignWithInitializerListOperator();
  void runAllTests();

  /* iterator test*/
  void test_iterator();

  /*test aid functions*/
  inline void testSuccessful(const char *funcName);
  inline void testFailure(const char *funcName);

private:
  Vector<int> testVec;
};
#endif //TESTS_H