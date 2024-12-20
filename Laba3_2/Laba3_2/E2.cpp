#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
// Базовый класс
class Base {
public:
    virtual void show() const {
        std::cout << "This is Base class." << std::endl;
    }
    virtual ~Base() = default; // Виртуальный деструктор
};
// Производный класс
class Derived : public Base {
public:
    void show() const override {
        std::cout << "This is Derived class." << std::endl;
    }
};
// Функция добавления объекта в хранилище
void add(std::vector<std::unique_ptr<Base>>& storage, std::unique_ptr<Base> obj) {
    storage.push_back(std::move(obj));
}
int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Инициализация генератора случайных чисел
    // Создание хранилища
    std::vector<std::unique_ptr<Base>> storage;
    // Цикл создания и добавления объектов в хранилище
    for (int i = 0; i < 10; ++i) {
        int randNumber = std::rand(); // Генерация случайного числа
        if (randNumber % 2 == 0) {
            add(storage, std::make_unique<Base>()); // Четное число — создаём Base
        }
        else {
            add(storage, std::make_unique<Derived>()); // Нечетное число — создаём Derived
        }
    }
    // Отображение поведения объектов из хранилища
    for (const auto& obj : storage) {
        obj->show(); // Полиморфный вызов метода
    }
    // Ресурсы освобождаются автоматически благодаря std::unique_ptr
    return 0;
}