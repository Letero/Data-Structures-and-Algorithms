#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <class T>
class Vector
{
  public:
    /*constructors*/
    Vector();                                     //default
    Vector(const Vector &other);                  //copy constructor
    Vector(const std::initializer_list<T> ilist); //constructor with initializer list
    Vector(Vector &&other);                       //move constructor
    ~Vector();                                    //deconstructor

    /*Iterator*/
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef T *reverse_iterator;
    typedef const T *const const_reverse_iterator;

    /*non-constructor members*/
    void clear();                                //clear contents of vector
    void assign(size_t count, const T &value);   //assigns new contents to the vector
    void assign(std::initializer_list<T> ilist); //assing using initializer list
    //template <class iterator>
    //void assign(iterator first, iterator last); //assing using range
    void erase(const size_t pos);  //remove element from given position
    void push_back(const T &elem); //add element at the end of vec
    void pop_back();               //remove element from the end of vec
    size_t size() const;           //return size of vec
    iterator begin();              //return pointer to first elem
    const_iterator cbegin();       //return const pointer to first elem
    iterator end();                //return pointer to place after last elem
    const_iterator cend();         //return const pointer to place after last elem

    T at(const size_t pos) const; //return element from given pos
    T &front() const;             //return value of first elem in vector
    T &back() const;              //return value of last elem in vector
    bool empty() const;           //check if vector is empty
    /*operators*/
    Vector &operator=(const Vector &other);                  //copy assignment operator
    Vector &operator=(Vector &&other);                       //move assignment operator
    Vector &operator=(const std::initializer_list<T> ilist); //assign initializier list
    T &operator[](const size_t pos);                         //random access operator
  private:
    T *_arr;
    size_t _capacity;
    size_t _size;
    void allocMoreMemory();
    void reserve(size_t newCap);
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
    if (_arr != nullptr)
    {
        delete[] _arr;
        _arr = nullptr;
    }
}

template <class T>
void Vector<T>::clear() //clear the contents of vector
{
    _size = 0;
    _capacity = 0;
    delete[] _arr;
    _arr = nullptr;
}

template <class T>
void Vector<T>::assign(size_t count, const T &value)
{
    unsigned int c = count;
    while (c--)
    {
        push_back(value);
    }
}

template <class T>
void Vector<T>::assign(std::initializer_list<T> ilist)
{
    for (auto a : ilist)
    {
        push_back(a);
    }
}

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
                nArr[i] = _arr[i];
            }
            for (int i = pos; i < _size - 1; ++i)
            {
                nArr[i] = _arr[i + 1];
            }
            delete[] _arr;
            _arr = nArr;
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
    return &_arr[0];
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::cbegin()
{
    return &_arr[0];
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
        if (_capacity > 1)
        {
            memcpy(nArr, _arr, (_capacity) * sizeof(T));
        }
        delete[] _arr;

        _arr = nArr;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
}

#endif //VECTOR_H