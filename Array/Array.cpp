#include "Array.h"

Array::Array(int sz): size (sz)
{
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

void Array::copyFrom(const Array& other)
{
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }  
}

bool Array::operator==(const Array& other)
{
    if (size != other.size)
        return false;

    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i])
            return false;
    }

    return true;
}

std::ostream& operator<<(std::ostream& out, const Array& arr)
{
    bool first = true;

    out << "{";
    for (int i = 0; i < arr.getSize(); i++) {
        if (first)
            first = false;
        else {
            out << ", ";
        }
        out << arr[i];
    }
    out << "}";

    return out;
}