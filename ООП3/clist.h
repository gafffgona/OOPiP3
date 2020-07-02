#pragma once

// Ячейка
struct cell
{
	char value = 0;
	cell* next = nullptr;
};

class clist // Односвязный список
{
private:
	cell* begin;
	int size;
public:
	clist() : begin(nullptr), size(0) { } 	// Конструктор
	clist(const clist&); // Копирования
	~clist(); // Деструктор
	void push(char _value); // Добавление элемента в список
	void pop(); // Удаление элемента списка
	void popAll(); // Удаление всех элементов списка
	void print();
	inline int getSize() { return size; } // Получение количества элементов, находящихся в списке
	bool equal(const clist&);

	clist& operator+=(char); // Перегрузка оператора +=
	friend clist operator+(clist&, char); // Перегрузка оператора +
	clist operator--(); // Перегрузка оператора --
	bool operator==(const clist&);
};
