#include <windows.h>
#include <iostream>
#include <iomanip> // Для установки точности вывода

int main() {
    SetConsoleOutputCP(1251);
    // Количество элементов в массиве
    const int SIZE = 10;

    // Динамическое выделение памяти для массива из 10 элементов типа double
    double* array = new double[SIZE];

    // Заполнение массива данными 
    for (int i = 0; i < SIZE; ++i) {
        array[i] = static_cast<double>(i + 1);
    }

    // Вывод содержимого массива на консоль
    std::cout << "Содержимое массива:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "array[" << i << "] = " << std::fixed << std::setprecision(2) << array[i] << "\n";
    }

    // Вывод адреса начала массива
    std::cout << "\nАдрес начала массива: " << static_cast<void*>(array) << "\n";

    // Вывод адресов каждого элемента и расстояния от начала массива
    std::cout << "\nАдреса элементов массива и расстояние от начала:\n";
    for (int i = 0; i < SIZE; ++i) {
        void* addr = static_cast<void*>(&(array[i]));
        // Расстояние в байтах
        std::ptrdiff_t distance = reinterpret_cast<char*>(&(array[i])) - reinterpret_cast<char*>(array);
        std::cout << "array[" << i << "] адрес: " << addr
            << ", расстояние от начала: " << distance << " байт\n";
    }

    // Освобождение выделенной памяти
    delete[] array;

    return 0;
}
