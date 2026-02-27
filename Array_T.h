//bsef24m050
#ifndef ARRAY_T_H
#define ARRAY_T_H

#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class Array {
    T* data;
    int size;

    bool isValidIndex(int ind) const
    {
        if (ind >= 0 && ind < size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    Array():data(nullptr),size(0)
    {
    }
    Array(int x):Array()
    {
        if (x>0)
        {
            data = new T [x];
            size = x;
        }
    }
    Array(initializer_list<T> list):Array()
    {

        data = new T[list.size()];
        size = list.size();
        int i = 0;
        for (auto x : list)
        {
            data[i] = x;
            i++;
        }
    }
    Array(const Array<T>& a)
    {

        if (a.data == nullptr)
        {
            return;
        }
        data = new T[a.size];
        for (int i = 0;i < a.size;i++)
        {
            data[i] = a.data[i];
        }
        size = a.size;
    }
    Array<T>& operator=(const Array<T>& arr)
    {
        //cout << arr.size<<"ele"<<arr<<"\n";
        if (size < arr.size)
        {
            reSize(arr.size);
        }
        for (int i = 0;i < arr.size;i++)
        {
            data[i] = arr.data[i];
        }
        size = arr.size;
        return *this;
    }
    Array(Array<T>&& a)
    {
        data = new Array<T>[a.size];
        for (int i = 0;i < a.size;i++)
        {
            data[i] = a.data[i];
        }
        size = a.size;
        a.data = nullptr;
    }
    Array<T>& operator=(Array<T>&& arr)
    {

        if (arr == *this)
        {
            return;
        }
        delete[]data;
        data = arr.data;
        size = arr.size;
        arr.data = nullptr;
        return *this;
    }
    T& operator[](int n)
    {
        //cout << "ags";
        if (isValidIndex(n))
        {
            return data[n];

        }
        else
        {
            exit(0);
        }
    }
    const T& operator[](int n) const
    {
        if (isValidIndex(n))
        {
            return data[n];

        }
        else
        {
            exit(0);
        }
    }
    int getSize() const
    {
        return size;
    }
    ~Array()
    {
        if (size == 0)
        {
            return;
        }
        delete[] data;
        data = nullptr;
        size = 0;
    }

    void reSize(int n)
    {
        if (n == 0 && size == 0)
        {
            return;
        }
        if (n == 0&& size>0)
        {
            delete[] data;
            data = nullptr;
            size = 0;
            return;
        }
        T* temp = new T[n];
        for (int i = 0;i < size && i < n;i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        temp = nullptr;
        size = n;
    }
    const T* begin() const
    {
        return data;
    }
    const T* end() const
    {
        return data + size;
    }
};

template <typename T>
ostream& operator<<(ostream& c, const Array<T>& arr )
{
    const T* data = arr.begin();
    for (int i = 0;i < arr.getSize();i++)
    {
        c << data[i];
    }
    return c;
}

template <typename R>
istream& operator>>(istream& c, Array<R>& arr)
{
    //const R *  temp = arr.begin();
    for (int i = 0;i < arr.getSize();i++)
    {
        c >> arr[i];
    }
    return c;
}
#endif 
