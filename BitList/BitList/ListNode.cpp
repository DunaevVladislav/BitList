#include "ListNode.h"

/** ------------------------------–≈јЋ»«ј÷»я ListNode----------------------------- */

//конструктор по умолчанию
ListNode::ListNode()
{
}

//конструктор инициализирующий узел знчаением val
ListNode::ListNode(bool val)
{
	setVal(val);
}

//задает значение узла
void ListNode::setVal(bool val)
{
	this->val = val;
}

//получает значение узла
bool ListNode::getVal()
{
	return this->val;
}

//задает следующий узел
void ListNode::setNext(ListNode *next)
{
	this->next = next;
}

//возвращает указательна следующий узел
ListNode *ListNode::getNext()
{
	return (this->next);
}

//задает предыдщий узел
void ListNode::setPrev(ListNode *prev)
{
	this->prev = prev;
}

//возвращает предыдщий узел
ListNode *ListNode::getPrev()
{
	return (this->prev);
}

/** ------------------------------------------------------------------------------ */