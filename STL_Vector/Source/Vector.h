#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <climits> //max size of size_t

template <class T>
class Vector
{
  public:
    //constructors
    Vector();                                     //default
    Vector(const Vector &other);                  //copy constructor
    Vector(const std::initializer_list<T> ilist); //constructor with initializer list
    Vector(Vector &&other);                       //move constructor
    ~Vector();                                    //deconstructor

    //Iterator
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef T *reverse_iterator;
    typedef const T *const_reverse_iterator;

    iterator begin();                 //return pointer to first elem
    const_iterator cbegin();          //return const pointer to first elem
    iterator end();                   //return pointer to place after last elem
    const_iterator cend();            //return const pointer to place after last elem
    reverse_iterator rbegin();        //return pointer to place after last elem
    const_reverse_iterator crbegin(); //return const pointer to place after last elem
    reverse_iterator rend();          //return pointer to first elem
    const_reverse_iterator crend();   //return const pointer to first elem

    //non-constructor members
    void clear();                                          //clear contents of vector
    void assign(size_t count, const T &value);             //assigns new contents to the vector
    void assign(std::initializer_list<T> ilist);           //assing using initializer list
    void assign(iterator first, iterator last);            //assing using range
    void erase(const_iterator pos);                        //remove element from given position
    void erase(const_iterator first, const_iterator last); //remove element from given position
    void push_back(const T &elem);                         //add element at the end of vec
    void pop_back();                                       //remove element from the end of vec
    T at(const size_t pos) const;                          //return element from given pos
    T &front() const;                                      //return value of first elem in vector
    T &back() const;                                       //return value of last elem in vector
    bool empty() const;                                    //check if vector is empty
    void reserve(const size_t &newCap);                    //change vector capacity to given size
    void resize(size_t count);
    void resize(size_t count, const T &value);
    size_t size() const;     //return size of vec
    size_t max_size() const; //return max size of vector
    size_t capacity() const; //return actual capacity of vector

    //operators
    Vector &
    operator=(const Vector &other);                          //copy assignment operator
    Vector &operator=(Vector &&other);                       //move assignment operator
    Vector &operator=(const std::initializer_list<T> ilist); //assign initializier list
    T &operator[](const size_t pos);                         //random access operator

  private:
    T *_arr;
    size_t _capacity;
    size_t _size;
    void allocMoreMemory();
};

template <class T>
Vector<T>::Vector() : _capacity(0), _size(0)
{
    _arr = nullptr;
}

template <class T>
Vector<T>::Vector(const Vector &other)
{
    try
    {
        _size = other._size;
        _capacity = other._capacity;
        T *nArr = new T[_capacity];
        memcpy(nArr, other._arr, (sizeof(other._arr) * _capacity));
        _arr = nArr;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
}

template <class T>
Vector<T>::Vector(Vector &&other)
{
    try
    {
        _arr = other._arr;
        _size = other._size;
        _capacity = other._capacity;
        other._arr = nullptr;
        other._size = 0;
        other._capacity = 0;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
}

template <class T>
Vector<T>::Vector(const std::initializer_list<T> ilist)
    : Vector()
{
    for (auto a : ilist)
    {
        push_back(a);
    }
}
//deconstructor
template <class T>
Vector<T>::~Vector()
{
    clear();
}

template <class T>
void Vector<T>::clear() //clear the contents of vector
{
    _size = 0;
    _capacity = 0;
    if (_arr != nullptr)
    {
        delete[] _arr;
        _arr = nullptr;
    }
}

template <class T>
void Vector<T>::assign(size_t count, const T &value)
{
    clear();
    while (count--)
    {
        push_back(value);
    }
}

template <class T>
void Vector<T>::assign(std::initializer_list<T> ilist)
{
    clear();
    for (auto a : ilist)
    {
        push_back(a);
    }
}

template <class T>
void Vector<T>::assign(iterator first, iterator last)
{
    clear();
    Vector<T>::iterator it;

    for (it = first; it != last; ++it)
    {
        push_back(*it);
    }
}

template <class T>
void Vector<T>::erase(const_iterator pos)
{
    if (begin() == end())
    {
        return;
    }

    const size_t index = (pos - begin());

    if (index < _size)
    {
        for (int i = index; i < _size; ++i)
        {
            _arr[i] = _arr[i + 1];
        }
        --_size;
    }
    else
    {
        throw "erase() : Position out of range\n";
    }
}

template <class T>
void Vector<T>::erase(const_iterator first, const_iterator last)
{

    if (begin() == end())
    {
        return;
    }
    const int indexA = first - begin();
    const int indexB = last - begin();
    const int diff = indexB - indexA;
    _size -= diff;
    for (int i = indexA; i < _size; ++i)
    {
        _arr[i] = _arr[i + diff];
    }
}

template <class T>
void Vector<T>::push_back(const T &elem)
{
    if (_size >= _capacity)
    {
        allocMoreMemory();
    }
    _arr[_size] = elem;
    ++_size;
}

template <class T>
void Vector<T>::pop_back()
{
    if (_size > 0)
    {
        --_size;
    }
}

template <class T>
size_t Vector<T>::size() const
{
    return _size;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return _arr;
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::cbegin()
{
    return _arr;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return &_arr[_size];
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::cend()
{
    return &_arr[_size];
}

template <class T>
typename Vector<T>::reverse_iterator rbegin()
{
}

template <class T>
typename Vector<T>::const_reverse_iterator crbegin()
{
}

template <class T>
typename Vector<T>::reverse_iterator rend()
{
}

template <class T>
typename Vector<T>::const_reverse_iterator rend()
{
}

template <class T>
T Vector<T>::at(const unsigned int pos) const
{
    if (pos >= _size)
    {
        throw "at() : Position out of range\n";
    }
    return _arr[pos];
}

template <class T>
T &Vector<T>::front() const
{
    return _arr[0];
}

template <class T>
T &Vector<T>::back() const
{
    if (_size > 0)
    {
        return _arr[_size - 1];
    }
    return _arr[_size];
}

template <class T>
bool Vector<T>::empty() const
{
    if (_size == 0)
    {
        return true;
    }
    return false;
}

/*operators*/
template <class T>
Vector<T> &Vector<T>::operator=(const Vector &other)
{
    if (this != &other) // check if
    {
        if (_arr)
        {
            delete[] _arr;
        }
        _size = other._size;
        _capacity = other._capacity;
        _arr = new T[_size];
        _arr = other._arr;
    }
    return *this;
}
template <class T>
Vector<T> &Vector<T>::operator=(const std::initializer_list<T> ilist)
{
    for (auto a : ilist)
    {
        push_back(a);
    }
    return *this;
}

template <class T>
Vector<T> &Vector<T>::operator=(Vector &&other)
{
    if (this != &other)
    {
        _arr = other._arr;
        _size = other._size;
        _capacity = other._capacity;

        other._arr = nullptr;
        other._size = 0;
        other._capacity = 0;
    }
    return *this;
}

template <class T>
T &Vector<T>::operator[](const size_t pos)
{
    return _arr[pos];
}

template <class T>
void Vector<T>::allocMoreMemory()
{
    if (_capacity == 0)
    {
        _capacity = 1;
    }
    else
    {
        _capacity *= 2;
    }

    try
    {
        T *nArr = new T[_capacity];

        if (_arr != nullptr)
        {
            memcpy(nArr, _arr, (_capacity) * sizeof(T));
            delete[] _arr;
        }
        _arr = nArr;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
}

template <class T>
void Vector<T>::reserve(const size_t &new_cap)
{
    if (new_cap <= _capacity)
    {
        return;
    }
    else
    {
        if (new_cap > max_size())
        {
            throw "reserve(): New capacity is larger than max_size()!";
        }
        else
        {
            _capacity = new_cap;
        }
    }
    try
    {
        T *nArr = new T[_capacity];

        if (_arr != nullptr)
        {
            memcpy(nArr, _arr, (_capacity) * sizeof(T));
            delete[] _arr;
        }
        _arr = nArr;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
}

template <class T>
size_t Vector<T>::max_size() const
{
    return UINT_MAX;
}

template <class T>
size_t Vector<T>::capacity() const
{
    return _capacity;
}

template <class T>
void Vector<T>::resize(size_t count)
{
    if (count > _size)
    {
        while (count > _capacity)
        {
            allocMoreMemory();
        }
        _size = count;
        T *nArr = new T[_size];

        if (_arr != nullptr)
        {
            memcpy(nArr, _arr, (_size) * sizeof(T));
            delete[] _arr;
        }
        _arr = nArr;
    }
}

template <class T>
void Vector<T>::resize(size_t count, const T &value)
{
    if (count > _size)
    {
        while (count > _capacity)
        {
            allocMoreMemory();
        }
        size_t oldSize = _size;
        _size = count;
        T *nArr = new T[_size];

        if (_arr != nullptr)
        {
            memcpy(nArr, _arr, (_size) * sizeof(T));
            delete[] _arr;
        }

        _arr = nArr;
        for (size_t i = oldSize; i < _size; ++i)
        {
            _arr[i] = value;
        }
    }
}

#endif //VECTOR_H