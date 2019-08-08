#include <iostream>

class Array {
public:
    Array(): size(0), data(nullptr) {}

    Array(int size);

    Array(const Array& other)
    { 
        copyFrom(other); 
    }

    ~Array() { 
        std::cout << "Array destructor size is " << size << '\n';
        delete [] data; 
    }

    int& operator[] (int index) const
    {
        return data[index];
    }

    Array& operator= (const Array& other)
    {
        if (&other != this) {
            delete [] data;
            copyFrom(other);
        }

        return *this;
    }

    bool operator==(const Array& other);

    bool operator!=(const Array& other) {
        return !operator==(other);
    }

    int getSize() const {
        return size;
    }

private:
    void copyFrom(const Array& other);

private:
    int size;
    int *data;
};

std::ostream& operator<<(std::ostream& out, const Array& arr);