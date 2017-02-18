
#include <iostream>
using namespace std;

template <class T>
class  Vector {
public:

    typedef T * iterator;

    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);
    ~Vector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T & front();
    T & back();
    void push_back(const T & value);
    void pop_back();

    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    T & operator[](unsigned int index);
    Vector<T> & operator=(const Vector<T> &);
    void clear();
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};

// Your code goes here ...
template<class T>
Vector<T>::Vector() {
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
}

template<class T>
Vector<T>::Vector(unsigned int size) {
    if(size < 0) { throw -2; }
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T [size];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
    //T();
}

template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> & v)
{
    delete[ ] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T [my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return buffer + size();
}

template<class T>
T& Vector<T>::front()
{
    return buffer[0];
}

template<class T>
T& Vector<T>::back()
{
    return buffer[my_size - 1];
}

template<class T>
void Vector<T>::push_back(const T & v)
{
    if (my_size >= my_capacity)
        reserve(my_capacity +5);
    buffer [my_size++] = v;
}

template<class T>
void Vector<T>::pop_back() {
    if(my_size-1< 0) { throw -2; }
    my_size--;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity) {
    if(capacity < 0) { throw -2; }
    if(buffer == 0)
    {
        my_size = 0;
        my_capacity = 0;
    }
    T * Newbuffer = new T [capacity];
    //assert(Newbuffer);
    unsigned int l_Size = capacity < my_size ? capacity : my_size;
    //copy (buffer, buffer + l_Size, Newbuffer);

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = buffer[i];

    my_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}

template<class T>
unsigned int Vector<T>::size()const{
    return my_size;
}

template<class T>
void Vector<T>::resize(unsigned int size)
{
    if(size < 0) { throw -2; }
    reserve(size);
    my_size = size;
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    if(index>=size() || index < 0) { throw -2; }
    return buffer[index];
}

template<class T>
unsigned int Vector<T>::capacity()const
{
    return my_capacity;
}

template<class T>
Vector<T>::~Vector() {
    delete[ ] buffer;
}
template <class T>
void Vector<T>::clear() {
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

int main()
{
    Vector<int> vv;

    vv.push_back(3);
    vv.push_back(2*4);
    vv.push_back(1);

    vv.push_back(11);
    vv.push_back(2*4+11);
    vv.push_back(1223);

    std::cout << vv.back() << "\n";
    std::cout << vv.front() << "\n";

    vv[2] = -23;
    for (int i = 0; i < vv.size() ; ++i) {
        std::cout <<"v["<<i<<"] = " << vv[i] << "\t";
    }//*/
    std::cout <<"ssss = " << vv[-1] << "\n";
    return 0;
}