#include <iostream>
#include <vector>
#include <memory>

// ������� ����� Part (������)
class Part {
protected:
    Part() = default; // ����������� �������
public:
    virtual ~Part() = default; // ����������� ����������
    virtual void display() const = 0; // ����� ����������� �������
};

// ����������� ����� Assembly (������)
class Assembly : public Part {
protected:
    Assembly() = default; // ����������� �������

    // ������ ��������� ������� createInstance() ������
    template <typename T>
    friend std::shared_ptr<T> createInstance();
public:
    ~Assembly() override = default;
    void display() const override {
        std::cout << "Hello there\n"; // ���������� ������ display
    }
};

// ��������� ������������� ������� ��� �������� �����������
template <typename T>
std::shared_ptr<T> createInstance() {
    // ������ � ����������� ������������ ����� ������������� �������
    return std::shared_ptr<T>(new T());
}

int main() {
    std::vector<std::shared_ptr<Part>> storage; // ��������� ��������

    // ������ ��������� Assembly ����� createInstance
    storage.push_back(createInstance<Assembly>());

    // ���������� ���������� ���������
    for (const auto& item : storage) {
        item->display();
    }

    return 0; // ����� ��������� ������������� ����������� ������
}