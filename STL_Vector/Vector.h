#ifndef VECTOR_H
#define VECTOR_H

const int RESERVE = 50; //we don't want to resive vector every time we add new elem

template <class T>
class Vector
{
public:
  /*constructors*/
  Vector() : reserve(RESERVE) //default
  {
    arr = new T[reserve];
    _size = 0;
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
    T *nArr = new T[reserve];
    arr = nArr;
  }
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

private:
  T *arr;
  const unsigned int reserve;
  unsigned int _size;
  void reallocateMem()
  {
    T *nArr = new T[_size + RESERVE];
    memcpy(nArr, arr, (_size + RESERVE) * sizeof(T));
    delete[] arr;
    arr = nArr;
  }
};

#endif //VECTOR_H