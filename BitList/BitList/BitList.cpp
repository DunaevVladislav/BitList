#include "BitList.h"
#include "ListNode.h"
#include <string>
#include <iterator>
#include <iostream>
using namespace std;


/** ------------------------------���������� BitList------------------------------ */
//������������� ������
void BitList::initialize()
{
	last = new ListNode(true);
	first = new ListNode(true);
	first->setNext(last);
	last->setPrev(first);
	this->firstIter = BitList::iterator(first);
	this->lastIter = BitList::iterator(last);
}

//����������� �� ���������
BitList::BitList()
{
	initialize();
}

//�����������, �������������� ������ num
BitList::BitList(unsigned long long num)
{
	initialize();
	reset(num);
}

//���������� �����������
BitList::BitList(BitList &bitList)
{
	initialize();
	reset(bitList.decVal());
}

//�������� ������������� �����
std::string BitList::binVal()
{
	std::string bitS = "";
	for(auto it = this->begin(); it != this->end(); it++){
		bitS += '0' + *it;
	}
	return bitS;
}

//���������� ������������� �����
unsigned long long BitList::decVal()
{
	long long dec = 0;
	for (auto it = this->begin(); it != this->end(); it++) {
		dec <<= 1;
		dec += *it;
	}
	return dec;
}

//�������� �� ������ ������� ������
BitList::iterator BitList::begin()
{
	BitList::iterator temp = firstIter;
	return ++temp;
}

//�������� ������� � �����
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

//�������� ������� � ������
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

//�������������� ������ ����� ������
void BitList::reset(unsigned long long num)
{
	while (num) {
		push_front(num & 1);
		num >>= 1;
	}
}

//�������� �� ��������� ������� ������
BitList::iterator BitList::end()
{
	return lastIter;
}

//��������� �������� ������ �� 1
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

//��������� �������� ������ �� 1
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

//���������� ������ ������
size_t BitList::size()
{
	return this->sz;
}

//�������� ����������
const BitList& BitList::operator=(BitList& right)
{
	this->reset(right.decVal());
	return *this;
}

//�������� ����������� ����������
BitList& BitList::operator++()
{
	this->inc();
	return *this;
}

//�������� ������������ ����������
BitList BitList::operator++(int)
{
	BitList temp = *this;
	++*this;
	return temp;
}

//�������� ����������� ����������
BitList& BitList::operator--()
{
	this->dec();
	return *this;
}

//�������� ������������ ����������
BitList BitList::operator--(int)
{
	BitList temp = *this;
	--*this;
	return temp;
}

//�������� ��������
BitList operator+(BitList& left, BitList& right)
{
	return BitList(left.decVal() + right.decVal());
}

//�������� ���������
BitList operator-(BitList& left, BitList& right)
{
	int leftDec = left.decVal();
	int rightDec = right.decVal();
	if (rightDec>leftDec) throw new exception("value less 0");
	return BitList(left.decVal() - right.decVal());
}

//�������� ������
ostream& operator<<(ostream& out, BitList& bitList)
{
	return out << bitList.binVal();
}

//�������� �����
istream& operator>>(istream& in, BitList& bitList)
{
	long long val;
	in >> val;
	bitList.reset(val);
	return in;
}

//����������
BitList::~BitList()
{
	while (first != nullptr) {
		ListNode* temp = first->getNext();
		first->~ListNode();
		first = temp;
	}
}
/** ------------------------------------------------------------------------------ */
/** -------------------------���������� BitList::iterator------------------------- */

//����������� �� ���������
BitList::iterator::iterator()
{
}

//����������� ��� ���� ������
BitList::iterator::iterator(ListNode * listNode) :listNode(listNode)
{
}

//����������� �����������
BitList::iterator::iterator(const iterator &it) : listNode(it.listNode)
{
}

//�������� �����������
bool BitList::iterator::operator!=(iterator const & other) const
{
	return listNode != other.listNode;
}

//�������� ���������
bool BitList::iterator::operator==(iterator const & other) const
{
	return listNode == other.listNode;
}

//�������� �������������
bool BitList::iterator::operator*() const
{
	return listNode->getVal();
}

//�������� ����������� ����������
BitList::iterator& BitList::iterator::operator++()
{
	listNode = listNode->getNext();
	return *this;
}

//�������� ������������ ����������
BitList::iterator BitList::iterator::operator++(int)
{
	BitList::iterator temp = *this;
	++*this;
	return temp;
}

//�������� ����������� ����������
BitList::iterator& BitList::iterator::operator--()
{
	listNode = listNode->getPrev();
	return *this;
}

//�������� ������������ ����������
BitList::iterator BitList::iterator::operator--(int)
{
	auto temp = *this;
	--*this;
	return temp;
}
/** ------------------------------------------------------------------------------ */