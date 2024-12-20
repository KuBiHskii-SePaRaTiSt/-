#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <windows.h>

using namespace std;

// ������� ����� Publication
class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0f) {}
    virtual ~Publication() {}
    virtual void getdata() {
        cout << "������� ��������: ";
        getline(cin, title);
        cout << "������� ����: ";
        cin >> price;
        cin.ignore();
    }
    virtual void putdata() const {
        cout << "��������: " << title << endl;
        cout << fixed << setprecision(2) << "����: " << price << " ���." << endl;
    }
};

// ����� Sales ��� �������� ������ � ��������
class Sales {
private:
    float sales[3];
public:
    Sales() {
        for (float& sale : sales)
            sale = 0.0f;
    }
    void getdata() {
        cout << "������� ������� �� ��������� ��� ������ (���.):" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "����� " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();
    }
    void putdata() const {
        cout << "������� �� ��������� ��� ������ (���.): ";
        for (int i = 0; i < 3; ++i) {
            cout << fixed << setprecision(2) << sales[i];
            if (i < 2) cout << ", ";
        }
        cout << endl;
    }
};

// ����� Book, ����������� �� Publication
class Book : public Publication {
private:
    int pages;
    Sales salesData;
public:
    Book() : Publication(), pages(0) {}
    void getdata() override {
        cout << "\n--- ���� ������ � ����� ---" << endl;
        Publication::getdata();
        cout << "������� ���������� �������: ";
        cin >> pages;
        cin.ignore();
        salesData.getdata();
    }
    void putdata() const override {
        cout << "\n--- ���������� � ����� ---" << endl;
        Publication::putdata();
        cout << "���������� �������: " << pages << endl;
        salesData.putdata();
    }
};

// ����� Tape (�����������), ����������� �� Publication
class Tape : public Publication {
private:
    float playTime;
    Sales salesData;
public:
    Tape() : Publication(), playTime(0.0f) {}
    void getdata() override {
        cout << "\n--- ���� ������ �� ����������� ---" << endl;
        Publication::getdata();
        cout << "������� ������������ ������ (� �������): ";
        cin >> playTime;
        cin.ignore();
        salesData.getdata();
    }
    void putdata() const override {
        cout << "\n--- ���������� �� ����������� ---" << endl;
        Publication::putdata();
        cout << "������������ ������: " << playTime << " �����" << endl;
        salesData.putdata();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    vector<Publication*> publications;
    char choice;
    do {
        cout << "�������� ����� - 0 ��� ����������� - 1 ? ";
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
            cout << "�������� �����!" << endl;
        }
        cout << "�������� ���? �� - 0 , ��� - 1 ";
        cin >> choice;
        cin.ignore();
    } while (choice == '0');

    cout << "\n--- ����� ���������� � ����������� ---" << endl;
    for (const Publication* pub : publications) {
        pub->putdata();
    }

    // ������������ ������
    for (Publication* pub : publications) {
        delete pub;
    }

    return 0;
}