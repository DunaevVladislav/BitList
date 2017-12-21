#pragma once
#include "ListNode.h"
#include "ListContainer.h"
#include <string>
#include <iterator>
#include <iostream>  
using namespace std;

//список, который хранит двоичное представление числа
class BitList:public ListContainer<bool>
{
public:

	//константный итератор
	class iterator :public std::iterator<std::bidirectional_iterator_tag, ListNode> { 
		friend class BitList;

	private:
		//узел списка
		ListNode* listNode;

		//конструктор для узла списка
		iterator(ListNode* listNode);

	public:
		//конструктор по умолчанию
		iterator();

		//конструктор копирования
		iterator(const iterator &it);

		//оператор неравенства
		bool operator!=(iterator const& other) const;

		//оператор равенства
		bool operator==(iterator const& other) const;

		//оператор разыменывания
		bool operator*() const;

		//оператор префиксного инкремента
		iterator& operator++();

		//перегрузка оператор постфиксного инкремента
		iterator operator++(int);

		//оператор префиксного декремента
		iterator& operator--();

		//оператор постфиксного декремента
		iterator operator--(int);

		//оператор обращения члену структуры
		pointer operator->() const {};
	};

	//конструктор по умолчанию
	BitList();

	//конструктор, инициализирует список num
	BitList(unsigned long long num);

	//конструтор копирования
	BitList(BitList& bitList);

	//двоичное представление числа
	string binVal();

	//десятичное представление числа
	unsigned long long decVal();

	//итератор на первый элемент списка
	iterator begin();

	//добавить элемент в конец
	void push_end(bool val);

	//добавить элемент в начало
	void push_front(bool val);

	//инициализирует список новым числом
	void reset(unsigned long long num);

	//итератор на последний элемент списка
	iterator end();

	//увеличить значение списка на 1
	void inc();

	//уменьшить значение списка на 1
	void dec();

	//возвращает размер списка
	size_t size();

	//оператор присвоения
	const BitList& operator=(BitList& right);

	//оператор префиксного инкремента
	BitList& operator++();

	//оператор постфиксного инкремента
	BitList operator++(int);

	//оператор префиксного декремента
	BitList& operator--();

	//оператор постфиксного декремента
	BitList operator--(int);

	//оператор сложения
	friend BitList operator+(BitList& left, BitList& right);

	//оператор вычитания
	friend BitList operator-(BitList& left, BitList& right);

	//оператор вывода
	friend ostream& operator<<(ostream& out, BitList& bitList);

	//оператор ввода
	friend istream& operator>>(istream& in, BitList& bitList);

	//деструктор
	~BitList();

private:
	//итератор на первый элемент списка
	iterator firstIter;

	//итератор на последний элемент списка
	iterator lastIter;

	//первый элемент списка
	ListNode* first;

	//последний элемент списка
	ListNode* last;

	//размер
	size_t sz = 0;

	//инициализация списка
	void initialize();
};