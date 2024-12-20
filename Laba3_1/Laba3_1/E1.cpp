#include <iostream>
#include <vector>
#include <memory>

// Базовый класс Part (Деталь)
class Part {
protected:
    Part() = default; // Конструктор защищен
public:
    virtual ~Part() = default; // Виртуальный деструктор
    virtual void display() const = 0; // Чисто виртуальная функция
};

// Производный класс Assembly (Сборка)
class Assembly : public Part {
protected:
    Assembly() = default; // Конструктор защищен

    // Делаем шаблонную функцию createInstance() другом
    template <typename T>
    friend std::shared_ptr<T> createInstance();
public:
    ~Assembly() override = default;
    void display() const override {
        std::cout << "Hello there\n"; // Реализация метода display
    }
};

// Шаблонная дружественная функция для создания экземпляров
template <typename T>
std::shared_ptr<T> createInstance() {
    // Доступ к защищённому конструктору через дружественную функцию
    return std::shared_ptr<T>(new T());
}

int main() {
    std::vector<std::shared_ptr<Part>> storage; // Хранилище объектов

    // Создаём экземпляр Assembly через createInstance
    storage.push_back(createInstance<Assembly>());

    // Отображаем содержимое хранилища
    for (const auto& item : storage) {
        item->display();
    }

    return 0; // Умные указатели автоматически освобождают память
}