#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
// ������� ����� Publication
class Publication {
protected:
    string title;
    float price;
public:
    // ����������� �� ���������
    Publication() : title(""), price(0.0f) {}
    // ����������������� �����������
    Publication(string t, float p) : title(t), price(p) {}
    // ����������� ����������
    virtual ~Publication() {}
};

// ����������� ����� Book
class Book : public Publication {
private:
    int pages;
public:
    // ����������� �� ���������
    Book() : Publication(), pages(0) {}
    // ����� ��� ����� ������
    void getdata() {
        cout << "������� �������� �����: ";
        getline(cin, title);
        cout << "������� ���� �����: ";
        cin >> price;
        cout << "������� ���������� �������: ";
        cin >> pages;
        cin.ignore(); // ������������� ����������� ������� ����� ������
    }
    // ����� ��� ������ ������
    void putdata() const {
        cout << "\n--- ���������� � ����� ---" << endl;
        cout << "��������: " << title << endl;
        cout << "����: " << price << " ���." << endl;
        cout << "���������� �������: " << pages << endl;
    }
};
// ����������� ����� Type (����������)
class Type : public Publication {
private:
    int minutes;
public:
    // ����������� �� ���������
    Type() : Publication(), minutes(0) {}
    // ����� ��� ����� ������
    void getdata() {
        cout << "������� �������� �����������: ";
        getline(cin, title);
        cout << "������� ���� �����������: ";
        cin >> price;
        cout << "������� ������������ ������ (� �������): ";
        cin >> minutes;
        cin.ignore(); // ������������� ����������� ������� ����� ������
    }
    // ����� ��� ������ ������
    void putdata() const {
        cout << "\n--- ���������� �� ����������� ---" << endl;
        cout << "��������: " << title << endl;
        cout << "����: " << price << " ���." << endl;
        cout << "������������: " << minutes << " �����" << endl;
    }
};
int main() {
    SetConsoleOutputCP(1251);
    int choice;
    Book book;
    Type audiobook;

    while (true) {
        cout << "\n�������� ��������:" << endl;
        cout << "1. �������� �����" << endl;
        cout << "2. �������� �����������" << endl;
        cout << "3. �����" << endl;
        cout << "��� �����: ";
        cin >> choice;
        cin.ignore(); // ������������� ����������� ������� ����� ������
        if (choice == 1) {
            book.getdata();
            book.putdata();
        }
        else if (choice == 2) {
            audiobook.getdata();
            audiobook.putdata();
        }
        else if (choice == 3) {
            cout << "����� �� ���������." << endl;
            break;
        }
        else {
            cout << "�������� �����. ����������, ���������� �����." << endl;
        }
    }
    return 0;
}
