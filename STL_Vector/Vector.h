#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

const int RESERVE = 2; //we don't want to resive vector every time we add new elem

template <class T>
class Vector
{
public:
  /*constructors*/
  //default
  Vector() : _reserve(RESERVE), _memSize(RESERVE)
  {
    try
    {
      arr = new T[_reserve];
      _size = 0;
    }
    catch (std::bad_alloc &ba)
    {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
  }
  //copy constructor
  Vector(const Vector &old) : _reserve(RESERVE)
  {
    try
    {
      arr = new T[old._memSize];
      this->arr = old.arr;
      this->_size = old._size;
      this->_memSize = old._memSize;
    }
    catch (std::bad_alloc &ba)
    {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
  }
  //deconstructor
  ~Vector()
  {
    delete[] arr;
  }

  /*non-constructor members*/

  void clear() //clear the contents of vector
  {
    _size = 0;
    _memSize = _reserve;
    delete[] arr;
    try
    {
      T *nArr = new T[_memSize];
      arr = nArr;
    }
    catch (std::bad_alloc &ba)
    {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
  }
  void assign() {} //
  void erase(unsigned int pos)
  {
    if (pos >= 0 && pos < _size)
    {
    }
    else
      throw "erase() : Position out of range\n";
  }
  void push_back(T elem)
  {
    arr[_size] = elem;
    _size++;
    if (_size % _reserve == 0)
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
    if (pos >= 0 && pos < _size)
      return arr[pos];
    else
      throw "at() : Position out of range\n";
  }

  /*operators*/
  //assign operator
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
  //random access operator
  int &operator[](const int pos)
  {
    return arr[pos];
  }

private:
  T *arr;
  const unsigned int _reserve;
  unsigned int _memSize;
  unsigned int _size;
  void reallocateMem()
  {
    try
    {
      _memSize += _reserve;
      T *nArr = new T[_memSize];
      memcpy(nArr, arr, (_memSize) * sizeof(T));
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