#include <iostream>
#include <string>
#include <windows.h>
#include <stdexcept> 
using namespace std;

// ��������� ����� PointerArray
template <typename T>
class PointerArray {
private:
	T** array;   // ������ ���������� �� ��� T
	size_t size; // ������ �������

public:
	// �����������
	PointerArray(size_t arraySize) : size(arraySize) {
		array = new T * [size]; // �������� ������ ��� ������� ����������
		for (size_t i = 0; i < size; ++i) {
			array[i] = nullptr; // ���������� ��� ��������� �����
		}
	}

	// ����������
	~PointerArray() {
		for (size_t i = 0; i < size; ++i) {
			delete array[i]; // ������� �������, �� ������� ��������� ���������
		}
		delete[] array; // ������� ��� ������ ����������
	}

	// ���������� ��������� [] ��� ������� � ��������� �������
	T*& operator[](size_t index) {
		if (index >= size) {
			throw std::out_of_range("������ ������� �� ������� �������!");
		}
		return array[index];
	}

	// ���������� �������� � ������
	void Set(size_t index, T* element) {
		if (index >= size) {
			throw std::out_of_range("������ ������� �� ������� �������!");
		}
		array[index] = element;
	}

	// ��������� ���������� ���������
	size_t GetSize() const {
		return size;
	}
};

// ������� ����� �������� ������������
class Transport {
public:
	virtual void Move() = 0; // ����������� �����
	virtual void DisplayInfo() = 0; // ����� ��� ����������� ����������

	//����������� ���������� ��� ����������� �������� ��������-�����������
	virtual ~Transport() {}
};

class Bicycle : public Transport {
private:
	int gearCount; // ���������� �������
public:
	// �����������
	Bicycle(int gears) : gearCount(gears) {}
	// ����� Move()
	void Move() override {
		cout << "��������� ���� ��������� ���� ��������" << endl;
	}
	//���������� ������ DisplayInfo()
	void DisplayInfo() override {
		cout << "���������: ���������. ���������� �������: " << gearCount << endl;
	}
};

class Car : public Transport {
private:
	int horsepower; // ��������� ���� ���������

public:
	// �����������
	Car(int hp) : horsepower(hp) {}

	//���������� ������ Move()
	void Move() override {
		cout << "���������� ��������� ��� ����������� � �������� ����������� ��������" << endl;
	}
	// ���������� ������ DisplayInfo()
	void DisplayInfo() override {
		cout << "���������: ����������. ��������: " << horsepower << " �.�. " << endl;
	}
};

class Truck : public Transport {
private:
	int capacity; //���������������� � ������

public:
	// �����������
	Truck(int cap) : capacity(cap) {}

	// ���������� ������ Move()
	void Move() override {
		cout << "�������� ��������� ��� ��������� ������� ������" << endl;
	}
	// ���������� ������ DisplayInfo()
	void DisplayInfo() override {
		cout << "���������: ��������.����������������:" << capacity << "����." << endl;
	}
};

int main() {
	SetConsoleOutputCP(1251);
	// ������� ��������� ������ ���������� �� ������� ������ Transport
	PointerArray<Transport> transports(3);

	// ������� �������-���������� � ��������� �� � ������
	transports.Set(0, new Bicycle(21));  // ��������� � 21 ���������
	transports.Set(1, new Car(120));     // ���������� � ��������� 120 �.�.
	transports.Set(2, new Truck(15));    // �������� � ����������������� 15 ����

	// ���������� � �������� ������ ������� �������
	for (size_t i = 0; i < transports.GetSize(); ++i) {
		transports[i]->Move();         // ����� ������ Move
		transports[i]->DisplayInfo(); // ����� ������ DisplayInfo
	}

	// ���������� PointerArray ������������� ������ ��� �������
	return 0;
}