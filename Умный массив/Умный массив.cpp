#include <iostream>
#include <windows.h>
#include <stdexcept>

class smart_array {
public:
    smart_array(size_t size) : size(size), count(0) {
        data = new int[size];
    }

    void add_element(int element) {
        if (count >= size) {
            throw std::out_of_range("Массив заполнен. Невозможно добавить больше элементов.");
        }
        data[count++] = element;
    }

    int get_element(size_t index) const {
        if (index >= count) {
            throw std::out_of_range("Индекс вне диапазона.");
        }
        return data[index];
    }

    ~smart_array() {
        delete[] data;
    }

private:
    int* data;
    size_t size;
    size_t count;
};

int main() {
    SetConsoleOutputCP(65001);
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}