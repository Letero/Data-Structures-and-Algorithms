#ifndef TESTS_H
#define TESTS_H
#include "../Source/Vector.h"

struct Tests
{
  Tests();
  ~Tests();
  /*constructors to test */
  void test_constructor();
  void test_copyConstructor();
  void test_constructorInitializerList();
  void test_moveConstructor();
  void test_deconstructor();

  /*regular public members to test*/
  void test_clear();     //clear contents of vector
  void test_assign();    //fill vector with new set of data
  void test_erase();     //remove element from given position
  void test_push_back(); //add element at the end of vec
  void test_pop_back();  //remove element from the end of vec
  void test_begin();     //return pointer to first elem
  void test_cbegin();    //return pointer to first elem
  void test_end();       //return pointer to place after last elem
  void test_cend();      //return pointer to place after last elem
  void test_at();        //return element from given pos
  void test_front();     // return value of first elem in vector
  void test_back();      //return value of last elem in vector
  void test_empty();     //check if vector is empty
  void test_size();      //return actual size of vec
  void test_max_size();
  void test_capacity();
  void test_reserve();
  void test_resize();
  /*operators to test*/
  void test_copyAssignmentOperator(); //assign operator
  void test_randomAccessOperator();   //random access operator
  void test_assignWithInitializerListOperator();
  void test_moveAssignmentOperator();

  /* iterator test*/
  void test_iterator();
  void test_constIterator();

  /*test aid functions*/
  inline void testSuccessful(const char *funcName);
  inline void testFailure(const char *funcName);
  void runAllTests();
};
#endif //TESTS_H