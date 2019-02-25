#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

const int RESERVE = 50; //we don't want to resive vector every time we add new elem

template <class T>
class Vector
{
public:
  /*constructors*/
  Vector() : reserve(RESERVE) //default
  {
    try
    {
      arr = new T[reserve];
      _size = 0;
    }
    catch (std::bad_alloc &ba)
    {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
  }
  Vector(const Vector &cpy) : reserve(RESERVE) //copy constructor
  {
    this->arr = cpy.arr;
    this->_size = cpy._size;
  }
  ~Vector() //deconstructor
  {
    delete[] arr;
  }

  void clear() //clear the contents of vector
  {
    _size = 0;
    delete[] arr;
    try
    {
      T *nArr = new T[reserve];
      arr = nArr;
    }
    catch (std::bad_alloc &ba)
    {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
  }
  /*non-constructor members*/
  void assign() {} //
  void erase(unsigned int pos)
  {
  }
  void push_back(T elem)
  {
    arr[_size] = elem;
    _size++;
    if (_size % RESERVE == 0)
    {
      this->reallocateMem();
    }
  }
  void pop_back() { --_size; }

  unsigned int size() { return _size; }

  T *begin() { return &arr[0]; }

  T *end() { return &arr[_size]; }

  T at(long long int pos)
  {
    if (pos > 0 && pos < _size)
      return arr[pos];
    else
      throw "at() : Position out of range\n";
  }

  /*operators*/
  Vector &operator=(const Vector &old)
  {
    if (this->arr)
    {
      delete[] arr;
    }
    this->_size = old._size;
    this->arr = new T[_size];
    this->arr = old.arr;
    return *this;
  }

private:
  T *arr;
  const unsigned int reserve;
  unsigned int _size;
  void reallocateMem()
  {
    try
    {
      T *nArr = new T[_size + RESERVE];
      memcpy(nArr, arr, (_size + RESERVE) * sizeof(T));
      delete[] arr;
      arr = nArr;
    }
    catch (std::bad_alloc &ba)
    {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
  }
};

#endif //VECTOR_H