#include <iostream>
#include <string>
#include <windows.h>
#include <stdexcept> 
using namespace std;

// Шаблонный класс PointerArray
template <typename T>
class PointerArray {
private:
	T** array;   // Массив указателей на тип T
	size_t size; // Размер массива

public:
	// Конструктор
	PointerArray(size_t arraySize) : size(arraySize) {
		array = new T * [size]; // Выделяем память для массива указателей
		for (size_t i = 0; i < size; ++i) {
			array[i] = nullptr; // Изначально все указатели пусты
		}
	}

	// Деструктор
	~PointerArray() {
		for (size_t i = 0; i < size; ++i) {
			delete array[i]; // Удаляем объекты, на которые указывают указатели
		}
		delete[] array; // Удаляем сам массив указателей
	}

	// Перегрузка оператора [] для доступа к элементам массива
	T*& operator[](size_t index) {
		if (index >= size) {
			throw std::out_of_range("Индекс выходит за пределы массива!");
		}
		return array[index];
	}

	// Добавление элемента в массив
	void Set(size_t index, T* element) {
		if (index >= size) {
			throw std::out_of_range("Индекс выходит за пределы массива!");
		}
		array[index] = element;
	}

	// Получение количества элементов
	size_t GetSize() const {
		return size;
	}
};

// Базовый класс средства передвижения
class Transport {
public:
	virtual void Move() = 0; // Виртуальный метод
	virtual void DisplayInfo() = 0; // Метод для отображения информации

	//Виртуальный деструктор для корректного удаления объектов-наследников
	virtual ~Transport() {}
};

class Bicycle : public Transport {
private:
	int gearCount; // Количество передач
public:
	// Конструктор
	Bicycle(int gears) : gearCount(gears) {}
	// Метод Move()
	void Move() override {
		cout << "Велосипед едет используя мощь человека" << endl;
	}
	//Реализация метода DisplayInfo()
	void DisplayInfo() override {
		cout << "Транспорт: Велосипед. Количество передач: " << gearCount << endl;
	}
};

class Car : public Transport {
private:
	int horsepower; // Лошадиные силы двигателя

public:
	// Конструктор
	Car(int hp) : horsepower(hp) {}

	//Реализация метода Move()
	void Move() override {
		cout << "Автомобиль необходим для комфортного и быстрого перемещения человека" << endl;
	}
	// Реализация метода DisplayInfo()
	void DisplayInfo() override {
		cout << "Транспорт: Автомобиль. Мощность: " << horsepower << " л.с. " << endl;
	}
};

class Truck : public Transport {
private:
	int capacity; //Грузоподъемность в тоннах

public:
	// Конструктор
	Truck(int cap) : capacity(cap) {}

	// Реализация метода Move()
	void Move() override {
		cout << "Грузовик необходим для перевозки тяжелых грузов" << endl;
	}
	// Реализация метода DisplayInfo()
	void DisplayInfo() override {
		cout << "Транспорт: Грузовик.Грузоподъемность:" << capacity << "тонн." << endl;
	}
};

int main() {
	SetConsoleOutputCP(1251);
	// Создаем шаблонный массив указателей на объекты класса Transport
	PointerArray<Transport> transports(3);

	// Создаем объекты-наследники и добавляем их в массив
	transports.Set(0, new Bicycle(21));  // Велосипед с 21 передачей
	transports.Set(1, new Car(120));     // Автомобиль с мощностью 120 л.с.
	transports.Set(2, new Truck(15));    // Грузовик с грузоподъемностью 15 тонн

	// Перебираем и вызываем методы каждого объекта
	for (size_t i = 0; i < transports.GetSize(); ++i) {
		transports[i]->Move();         // Вызов метода Move
		transports[i]->DisplayInfo(); // Вызов метода DisplayInfo
	}

	// Деструктор PointerArray автоматически удалит все объекты
	return 0;
}