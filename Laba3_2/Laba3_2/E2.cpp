#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
// ������� �����
class Base {
public:
    virtual void show() const {
        std::cout << "This is Base class." << std::endl;
    }
    virtual ~Base() = default; // ����������� ����������
};
// ����������� �����
class Derived : public Base {
public:
    void show() const override {
        std::cout << "This is Derived class." << std::endl;
    }
};
// ������� ���������� ������� � ���������
void add(std::vector<std::unique_ptr<Base>>& storage, std::unique_ptr<Base> obj) {
    storage.push_back(std::move(obj));
}
int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // ������������� ���������� ��������� �����
    // �������� ���������
    std::vector<std::unique_ptr<Base>> storage;
    // ���� �������� � ���������� �������� � ���������
    for (int i = 0; i < 10; ++i) {
        int randNumber = std::rand(); // ��������� ���������� �����
        if (randNumber % 2 == 0) {
            add(storage, std::make_unique<Base>()); // ������ ����� � ������ Base
        }
        else {
            add(storage, std::make_unique<Derived>()); // �������� ����� � ������ Derived
        }
    }
    // ����������� ��������� �������� �� ���������
    for (const auto& obj : storage) {
        obj->show(); // ����������� ����� ������
    }
    // ������� ������������� ������������� ��������� std::unique_ptr
    return 0;
}