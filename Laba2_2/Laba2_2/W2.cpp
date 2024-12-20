#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <windows.h>

using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0f) {}
    virtual ~Publication() {}
    virtual void getdata() {
        cout << "Введите название: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore();
    }
    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << fixed << setprecision(2) << "Цена: " << price << " руб." << endl;
    }
};

// Класс Sales для хранения данных о продажах
class Sales {
private:
    float sales[3];
public:
    Sales() {
        for (float& sale : sales)
            sale = 0.0f;
    }
    void getdata() {
        cout << "Введите продажи за последние три месяца (руб.):" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();
    }
    void putdata() const {
        cout << "Продажи за последние три месяца (руб.): ";
        for (int i = 0; i < 3; ++i) {
            cout << fixed << setprecision(2) << sales[i];
            if (i < 2) cout << ", ";
        }
        cout << endl;
    }
};

// Класс Book, производный от Publication
class Book : public Publication {
private:
    int pages;
    Sales salesData;
public:
    Book() : Publication(), pages(0) {}
    void getdata() override {
        cout << "\n--- Ввод данных о книге ---" << endl;
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore();
        salesData.getdata();
    }
    void putdata() const override {
        cout << "\n--- Информация о книге ---" << endl;
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
        salesData.putdata();
    }
};

// Класс Tape (аудиозапись), производный от Publication
class Tape : public Publication {
private:
    float playTime;
    Sales salesData;
public:
    Tape() : Publication(), playTime(0.0f) {}
    void getdata() override {
        cout << "\n--- Ввод данных об аудиозаписи ---" << endl;
        Publication::getdata();
        cout << "Введите длительность записи (в минутах): ";
        cin >> playTime;
        cin.ignore();
        salesData.getdata();
    }
    void putdata() const override {
        cout << "\n--- Информация об аудиозаписи ---" << endl;
        Publication::putdata();
        cout << "Длительность записи: " << playTime << " минут" << endl;
        salesData.putdata();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    vector<Publication*> publications;
    char choice;
    do {
        cout << "Добавить книгу - 0 или аудиозапись - 1 ? ";
        cin >> choice;
        cin.ignore();
        if (choice == '0') {
            Publication* pub = new Book();
            pub->getdata();

            publications.push_back(pub);
        }
        else if (choice == '1') {
            Publication* pub = new Tape();
            pub->getdata();
            publications.push_back(pub);
        }
        else {
            cout << "Неверный выбор!" << endl;
        }
        cout << "Добавить еще? Да - 0 , Нет - 1 ";
        cin >> choice;
        cin.ignore();
    } while (choice == '0');

    cout << "\n--- Вывод информации о публикациях ---" << endl;
    for (const Publication* pub : publications) {
        pub->putdata();
    }

    // Освобождение памяти
    for (Publication* pub : publications) {
        delete pub;
    }

    return 0;
}