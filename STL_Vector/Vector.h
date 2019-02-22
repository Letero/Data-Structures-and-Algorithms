#ifndef VECTOR_H
#define VECTOR_H

const int RESERVE = 50; //we don't  want to resive vector every time we add new elem

template <class T>
class Vector
{
public:
  /*member functions*/
  Vector() : reserve(RESERVE)
  {
    arr = new T[reserve];
    _size = 0;
  }
  ~Vector()
  {
    delete[] arr;
  }
  void clear() //clear the contents of vector
  {
  }
  void assign() {}                //
  void erase(unsigned int pos) {} //
  void push_back(T elem)
  {
    arr[_size] = elem;
    _size++;
  }
  void pop_back() { --_size; }
  unsigned int size() { return _size; }

  T *begin() { return &arr[0]; }

  T *end() { return &arr[_size]; }

private:
  T *arr;
  const unsigned int reserve;
  unsigned int _size;
  void reallocateMem(); //probably using move operator?
};

#endif //VECTOR_H