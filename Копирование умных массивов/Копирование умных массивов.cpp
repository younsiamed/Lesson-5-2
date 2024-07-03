#include <iostream>
#include <algorithm>

class smart_array {
private:
    int size;
    int* data;

public:
    smart_array(int sz = 0) : size(sz), data(new int[size]) {}

    smart_array(const smart_array& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
    }

    smart_array& operator=(const smart_array& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + other.size, data);
        }
        return *this;
    }

    ~smart_array() {
        delete[] data;
    }

    void add_element(int element) {
        int* new_data = new int[size + 1];
        std::copy(data, data + size, new_data);
        new_data[size] = element;
        delete[] data;
        data = new_data;
        size++;
    }

};

int main() {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

    return 0;
}
