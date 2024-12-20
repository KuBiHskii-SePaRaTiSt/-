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
        // Проверяем на пустые значения
        if (author.empty() || title.empty()) {
            throw std::invalid_argument("Автор и название книги не могут быть пустыми.");
        }
    }
    void display() const {
        std::cout << "Автор: " << author << ", Название: " << title << ", Тип: "
            << (type == Type::Fiction ? "Художественная" : "Техническая") << std::endl;
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
    // Подсчет книги по типам
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
    // Вывод результата
    std::cout << "Количество художественной литературы: " << fictionalCount << std::endl;
    std::cout << "Количество технической литературы: " << technicalCount << std::endl;
}
int main() {
    SetConsoleOutputCP(1251);
    std::vector<Book> library;
    try {
        // Наполняем библиотеку книгами
        library.emplace_back("Лев Толстой", "Война и мир", Book::Type::Fiction);
        library.emplace_back("Антон Чехов", "Три сестры", Book::Type::Fiction);
        library.emplace_back("Галилео Галилей", "Диалог о двух системах мира", Book::Type::Technical);
        library.emplace_back("Фёдор Достоевский", "Преступление и наказание", Book::Type::Fiction);
        library.emplace_back("Чарльз Пэз", "Программирование на C++", Book::Type::Technical);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
        return 1; // Завершаем программу при ошибке
    }
    // Выводим книги из библиотеки
    std::cout << "Список книг в библиотеке:\n";
    for (const auto& book : library) {
        book.display();
    }
    // Выводим количество художественной и технической литературы
    countBooks(library);
    return 0;
}