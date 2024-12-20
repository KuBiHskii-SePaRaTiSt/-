#include <windows.h>
#include <iostream>
#include <iomanip> // ��� ��������� �������� ������

int main() {
    SetConsoleOutputCP(1251);
    // ���������� ��������� � �������
    const int SIZE = 10;

    // ������������ ��������� ������ ��� ������� �� 10 ��������� ���� double
    double* array = new double[SIZE];

    // ���������� ������� ������� 
    for (int i = 0; i < SIZE; ++i) {
        array[i] = static_cast<double>(i + 1);
    }

    // ����� ����������� ������� �� �������
    std::cout << "���������� �������:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "array[" << i << "] = " << std::fixed << std::setprecision(2) << array[i] << "\n";
    }

    // ����� ������ ������ �������
    std::cout << "\n����� ������ �������: " << static_cast<void*>(array) << "\n";

    // ����� ������� ������� �������� � ���������� �� ������ �������
    std::cout << "\n������ ��������� ������� � ���������� �� ������:\n";
    for (int i = 0; i < SIZE; ++i) {
        void* addr = static_cast<void*>(&(array[i]));
        // ���������� � ������
        std::ptrdiff_t distance = reinterpret_cast<char*>(&(array[i])) - reinterpret_cast<char*>(array);
        std::cout << "array[" << i << "] �����: " << addr
            << ", ���������� �� ������: " << distance << " ����\n";
    }

    // ������������ ���������� ������
    delete[] array;

    return 0;
}
