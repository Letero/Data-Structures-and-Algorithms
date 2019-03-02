#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <typeinfo>

const int RESERVE = 1; //we don't want to resize vector every time we add new elem

template <class T>
class Vector
{
public:
    /*constructors*/
    Vector();                                      //default
    Vector(const Vector &old);                     //copy constructor
    Vector(const std::initializer_list<T> values); // constructor with initializer list
    ~Vector();                                     //deconstructor

    /*non-constructor members*/
    void clear();                  //clear contents of vector
    void assign();                 //todo
    void erase(const size_t pos);  //remove element from given position
    void push_back(const T &elem); //add element at the end of vec
    void pop_back();               //remove element from the end of vec
    size_t size();                 //return size of vec
    T *begin();                    //return pointer to first elem
    T *end();                      //return pointer to place after last elem
    T at(const size_t pos);        //return element from given pos
    T &front();                    // return value of first elem in vector
    T &back();                     //return value of last elem in vector
    bool empty();                  //check if vector is empty
    /*operators*/
    Vector &operator=(const Vector &old);                     //copy assignment operator
    Vector &operator=(const std::initializer_list<T> values); //assign initializier list
    T &operator[](const size_t pos);                          //random access operator
    /*Iterator *
    typedef T *iterator;
    iterator begin();
    iterator end();*/

private:
    T *arr;
    const size_t _reserve;
    size_t _memSize;
    size_t _size;
    void allocMoreMemory();
    void reserve(size_t newCap);
};

template <class T>
Vector<T>::Vector() : _reserve(RESERVE), _memSize(RESERVE)
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

template <class T>
Vector<T>::Vector(const Vector &old) : _reserve(RESERVE)
{
    try
    {
        arr = new T[old._memSize];
        arr = old.arr;
        _size = old._size;
        _memSize = old._memSize;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
}

template <class T>
Vector<T>::Vector(const std::initializer_list<T> values)
    : Vector()
{
    for (auto a : values)
    {
        push_back(a);
    }
}
//deconstructor
template <class T>
Vector<T>::~Vector()
{
    delete[] arr;
}

template <class T>
void Vector<T>::clear() //clear the contents of vector
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

template <class T>
void Vector<T>::assign() {} //

template <class T>
void Vector<T>::erase(unsigned int pos)
{
    if (_size == 0)
    {
        return;
    }
    if (pos < _size)
    {
        try
        {
            T *nArr = new T[_size - 1];
            for (int i = 0; i < pos; ++i)
            {
                nArr[i] = arr[i];
            }
            for (int i = pos; i < _size - 1; ++i)
            {
                nArr[i] = arr[i + 1];
            }
            delete[] arr;
            arr = nArr;
            --_size;
        }
        catch (std::bad_alloc &ba)
        {
            std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    }
    else
    {
        throw "erase() : Position out of range\n";
    }
}

template <class T>
void Vector<T>::push_back(const T &elem)
{
    arr[_size] = elem;
    _size++;
    if (_size >= _memSize || (_size % RESERVE == 0))
    {
        allocMoreMemory();
    }
}

template <class T>
void Vector<T>::pop_back()
{
    --_size;
}

template <class T>
size_t Vector<T>::size()
{
    return _size;
}

template <class T>
T *Vector<T>::begin()
{
    return &arr[0];
}

template <class T>
T *Vector<T>::end()
{
    return &arr[_size];
}

template <class T>
T Vector<T>::at(const unsigned int pos)
{
    if (pos >= _size)
    {
        throw "at() : Position out of range\n";
    }
    return arr[pos];
}

template <class T>
T &Vector<T>::front()
{
    return arr[0];
}

template <class T>
T &Vector<T>::back()
{
    if (_size > 0)
    {
        return arr[_size - 1];
    }
    return arr[_size];
}

template <class T>
bool Vector<T>::empty()
{
    if (_size == 0)
    {
        return true;
    }
    return false;
}

/*operators*/
template <class T>
Vector<T> &Vector<T>::operator=(const Vector &old)
{
    if (this != &old) // check if
    {
        if (arr)
        {
            delete[] arr;
        }
        _size = old._size;
        _memSize = old._memSize;
        arr = new T[_size];
        arr = old.arr;
    }
    return *this;
}
template <class T>
Vector<T> &Vector<T>::operator=(const std::initializer_list<T> values)
{
    for (auto a : values)
    {
        push_back(a);
    }
    return *this;
}

template <class T>
T &Vector<T>::operator[](const size_t pos)
{
    return arr[pos];
}

template <class T>
void Vector<T>::allocMoreMemory()
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

#endif //VECTOR_H