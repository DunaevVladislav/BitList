#include "ListNode.h"

/** ------------------------------���������� ListNode----------------------------- */

//����������� �� ���������
ListNode::ListNode()
{
}

//����������� ���������������� ���� ��������� val
ListNode::ListNode(bool val)
{
	setVal(val);
}

//������ �������� ����
void ListNode::setVal(bool val)
{
	this->val = val;
}

//�������� �������� ����
bool ListNode::getVal()
{
	return this->val;
}

//������ ��������� ����
void ListNode::setNext(ListNode *next)
{
	this->next = next;
}

//���������� ����������� ��������� ����
ListNode *ListNode::getNext()
{
	return (this->next);
}

//������ ��������� ����
void ListNode::setPrev(ListNode *prev)
{
	this->prev = prev;
}

//���������� ��������� ����
ListNode *ListNode::getPrev()
{
	return (this->prev);
}

/** ------------------------------------------------------------------------------ */