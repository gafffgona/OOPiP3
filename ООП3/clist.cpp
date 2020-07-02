#include "clist.h"
#include <iostream>


clist::clist(const clist& _list)
{
	cell* temp = _list.begin;
	for (int i = 0; i < _list.size; i++) {
		push(temp->value);
		temp = temp->next;
	}
	size = _list.size;
	begin = _list.begin;
	delete(temp);
}

clist::~clist() {

}

void clist::push(char _value) {
	cell* newCell = new cell;
	newCell->value = _value;
	newCell->next = NULL;

	if (begin == nullptr) {
		begin = newCell;
		size++;
		return;
	}
	newCell->next = begin;
	begin = newCell;
	size++;
}


void clist::pop() {
	cell* cur = begin;
	begin = begin->next;
	size--;
	delete cur;
	cur = nullptr;
}

void clist::popAll()
{
	while (size != 0) // Пока еще есть элементы
		pop(); // Удаляем элементы по одному
}

void clist::print() {
	cell* temp = begin;
	while (temp != nullptr) {
		std::cout << temp->value << "   ";
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	std::cout << std::endl;
}

bool clist::equal(const clist& _clist) {
	if (size != _clist.size)
		return 0;
	cell* tf = this->begin;
	cell* tf2 = _clist.begin;
	for (int i = 0; i < size; i++) {
		if (tf->value != tf2->value)
			return 0;
		tf = tf->next;
		tf2 = tf2->next;
	}
	return 1;
}

clist& clist::operator+=(char _value) {
	push(_value);
	return *this;
}

clist clist::operator--() {
	pop();
	return *this;
}

clist operator+(clist& _list, char _value)
{
	clist _bufferlist = _list;
	_bufferlist += _value;
	return _bufferlist;
}

bool clist::operator==(const clist& _clist) {
	return equal(_clist);
}
