#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <windows.h>
class Book {
public:
    enum class Type { Fiction, Technical };
    Book(const std::string& author, const std::string& title, Type type)
        : author(author), title(title), type(type) {
        // ��������� �� ������ ��������
        if (author.empty() || title.empty()) {
            throw std::invalid_argument("����� � �������� ����� �� ����� ���� �������.");
        }
    }
    void display() const {
        std::cout << "�����: " << author << ", ��������: " << title << ", ���: "
            << (type == Type::Fiction ? "��������������" : "�����������") << std::endl;
    }
    Type getType() const {
        return type;
    }
private:
    std::string author;
    std::string title;
    Type type;
};
void countBooks(const std::vector<Book>& library) {
    int fictionalCount = 0;
    int technicalCount = 0;
    // ������� ����� �� �����
    for (const auto& book : library) {
        switch (book.getType()) {
        case Book::Type::Fiction:
            fictionalCount++;
            break;
        case Book::Type::Technical:
            technicalCount++;
            break;
        }
    }
    // ����� ����������
    std::cout << "���������� �������������� ����������: " << fictionalCount << std::endl;
    std::cout << "���������� ����������� ����������: " << technicalCount << std::endl;
}
int main() {
    SetConsoleOutputCP(1251);
    std::vector<Book> library;
    try {
        // ��������� ���������� �������
        library.emplace_back("��� �������", "����� � ���", Book::Type::Fiction);
        library.emplace_back("����� �����", "��� ������", Book::Type::Fiction);
        library.emplace_back("������� �������", "������ � ���� �������� ����", Book::Type::Technical);
        library.emplace_back("Ը��� �����������", "������������ � ���������", Book::Type::Fiction);
        library.emplace_back("������ ���", "���������������� �� C++", Book::Type::Technical);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "������: " << e.what() << '\n';
        return 1; // ��������� ��������� ��� ������
    }
    // ������� ����� �� ����������
    std::cout << "������ ���� � ����������:\n";
    for (const auto& book : library) {
        book.display();
    }
    // ������� ���������� �������������� � ����������� ����������
    countBooks(library);
    return 0;
}