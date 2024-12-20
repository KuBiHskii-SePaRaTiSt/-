#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
// Базовый класс Publication
class Publication {
protected:
    string title;
    float price;
public:
    // Конструктор по умолчанию
    Publication() : title(""), price(0.0f) {}
    // Параметризованный конструктор
    Publication(string t, float p) : title(t), price(p) {}
    // Виртуальный деструктор
    virtual ~Publication() {}
};

// Производный класс Book
class Book : public Publication {
private:
    int pages;
public:
    // Конструктор по умолчанию
    Book() : Publication(), pages(0) {}
    // Метод для ввода данных
    void getdata() {
        cout << "Введите название книги: ";
        getline(cin, title);
        cout << "Введите цену книги: ";
        cin >> price;
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore(); // Игнорирование оставшегося символа новой строки
    }
    // Метод для вывода данных
    void putdata() const {
        cout << "\n--- Информация о книге ---" << endl;
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
        cout << "Количество страниц: " << pages << endl;
    }
};
// Производный класс Type (аудиокнига)
class Type : public Publication {
private:
    int minutes;
public:
    // Конструктор по умолчанию
    Type() : Publication(), minutes(0) {}
    // Метод для ввода данных
    void getdata() {
        cout << "Введите название аудиозаписи: ";
        getline(cin, title);
        cout << "Введите цену аудиозаписи: ";
        cin >> price;
        cout << "Введите длительность записи (в минутах): ";
        cin >> minutes;
        cin.ignore(); // Игнорирование оставшегося символа новой строки
    }
    // Метод для вывода данных
    void putdata() const {
        cout << "\n--- Информация об аудиозаписи ---" << endl;
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
        cout << "Длительность: " << minutes << " минут" << endl;
    }
};
int main() {
    SetConsoleOutputCP(1251);
    int choice;
    Book book;
    Type audiobook;

    while (true) {
        cout << "\nВыберите действие:" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Добавить аудиозапись" << endl;
        cout << "3. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore(); // Игнорирование оставшегося символа новой строки
        if (choice == 1) {
            book.getdata();
            book.putdata();
        }
        else if (choice == 2) {
            audiobook.getdata();
            audiobook.putdata();
        }
        else if (choice == 3) {
            cout << "Выход из программы." << endl;
            break;
        }
        else {
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    }
    return 0;
}
