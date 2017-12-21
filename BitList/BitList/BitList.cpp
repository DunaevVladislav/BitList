#include "BitList.h"
#include "ListNode.h"
#include <string>
#include <iterator>
#include <iostream>
using namespace std;


/** ------------------------------–≈јЋ»«ј÷»я BitList------------------------------ */
//инициализаци€ списка
void BitList::initialize()
{
	last = new ListNode(true);
	first = new ListNode(true);
	first->setNext(last);
	last->setPrev(first);
	this->firstIter = BitList::iterator(first);
	this->lastIter = BitList::iterator(last);
}

//конструктор по умолчанию
BitList::BitList()
{
	initialize();
}

//конструктор, инициализирует список num
BitList::BitList(unsigned long long num)
{
	initialize();
	reset(num);
}

//конструтор копировани€
BitList::BitList(BitList &bitList)
{
	initialize();
	reset(bitList.decVal());
}

//двоичное представление числа
std::string BitList::binVal()
{
	std::string bitS = "";
	for(auto it = this->begin(); it != this->end(); it++){
		bitS += '0' + *it;
	}
	return bitS;
}

//дес€тичное представление числа
unsigned long long BitList::decVal()
{
	long long dec = 0;
	for (auto it = this->begin(); it != this->end(); it++) {
		dec <<= 1;
		dec += *it;
	}
	return dec;
}

//итератор на первый элемент списка
BitList::iterator BitList::begin()
{
	BitList::iterator temp = firstIter;
	return ++temp;
}

//добавить элемент в конец
void BitList::push_end(bool val)
{
	if (this->sz == 64) throw new exception("list overflow");
	ListNode* temp = last->getPrev();
	temp->setNext(new ListNode(val));
	ListNode* newNode = temp->getNext();
	newNode->setNext(last);
	newNode->setPrev(temp);
	last->setPrev(newNode);
	this->sz++;
}

//добавить элемент в начало
void BitList::push_front(bool val)
{
	if (this->sz == 64) throw new exception("list overflow");
	ListNode* temp = first->getNext();
	temp->setPrev(new ListNode(val));
	ListNode* newNode = temp->getPrev();
	newNode->setPrev(first);
	newNode->setNext(temp);
	first->setNext(newNode); 
	this->sz++;
}

//инициализирует список новым числом
void BitList::reset(unsigned long long num)
{
	while (num) {
		push_front(num & 1);
		num >>= 1;
	}
}

//итератор на последний элемент списка
BitList::iterator BitList::end()
{
	return lastIter;
}

//увеличить значение списка на 1
void BitList::inc()
{
	ListNode* it = last->getPrev();
	while (it != nullptr && it->getVal()) {
		it->setVal(false);
		it = it->getPrev();
	}
	if (it != nullptr) it->setVal(true);
	else push_front(true);
}

//уменьшить значение списка на 1
void BitList::dec()
{
	ListNode* it = last->getPrev();
	while (it != nullptr && !it->getVal()) {
		it->setVal(true);
		it = it->getPrev();
	}
	if (it != nullptr) it->setVal(false);
	else throw new exception("value less 0");
	while (!first->getNext()->getVal()) {
		ListNode* temp = first->getNext()->getNext();
		temp->setPrev(first);
		first->getNext()->~ListNode();
		first->setNext(temp);
	}
}

//возвращает размер списка
size_t BitList::size()
{
	return this->sz;
}

//оператор присвоени€
const BitList& BitList::operator=(BitList& right)
{
	this->reset(right.decVal());
	return *this;
}

//оператор префиксного инкремента
BitList& BitList::operator++()
{
	this->inc();
	return *this;
}

//оператор постфиксного инкремента
BitList BitList::operator++(int)
{
	BitList temp = *this;
	++*this;
	return temp;
}

//оператор префиксного декремента
BitList& BitList::operator--()
{
	this->dec();
	return *this;
}

//оператор постфиксного декремента
BitList BitList::operator--(int)
{
	BitList temp = *this;
	--*this;
	return temp;
}

//оператор сложени€
BitList operator+(BitList& left, BitList& right)
{
	return BitList(left.decVal() + right.decVal());
}

//оператор вычитани€
BitList operator-(BitList& left, BitList& right)
{
	int leftDec = left.decVal();
	int rightDec = right.decVal();
	if (rightDec>leftDec) throw new exception("value less 0");
	return BitList(left.decVal() - right.decVal());
}

//оператор вывода
ostream& operator<<(ostream& out, BitList& bitList)
{
	return out << bitList.binVal();
}

//оператор ввода
istream& operator>>(istream& in, BitList& bitList)
{
	long long val;
	in >> val;
	bitList.reset(val);
	return in;
}

//деструктор
BitList::~BitList()
{
	while (first != nullptr) {
		ListNode* temp = first->getNext();
		first->~ListNode();
		first = temp;
	}
}
/** ------------------------------------------------------------------------------ */
/** -------------------------–≈јЋ»«ј÷»я BitList::iterator------------------------- */

//конструктор по умолчанию
BitList::iterator::iterator()
{
}

//конструктор дл€ узла списка
BitList::iterator::iterator(ListNode * listNode) :listNode(listNode)
{
}

//конструктор копировани€
BitList::iterator::iterator(const iterator &it) : listNode(it.listNode)
{
}

//оператор неравенства
bool BitList::iterator::operator!=(iterator const & other) const
{
	return listNode != other.listNode;
}

//оператор равенства
bool BitList::iterator::operator==(iterator const & other) const
{
	return listNode == other.listNode;
}

//оператор разыменывани€
bool BitList::iterator::operator*() const
{
	return listNode->getVal();
}

//оператор префиксного инкремента
BitList::iterator& BitList::iterator::operator++()
{
	listNode = listNode->getNext();
	return *this;
}

//оператор постфиксного инкремента
BitList::iterator BitList::iterator::operator++(int)
{
	BitList::iterator temp = *this;
	++*this;
	return temp;
}

//оператор префиксного декремента
BitList::iterator& BitList::iterator::operator--()
{
	listNode = listNode->getPrev();
	return *this;
}

//оператор постфиксного декремента
BitList::iterator BitList::iterator::operator--(int)
{
	auto temp = *this;
	--*this;
	return temp;
}
/** ------------------------------------------------------------------------------ */