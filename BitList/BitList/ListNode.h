#pragma once

//���� ������
class ListNode
{
public:
	//����������� �� ���������
	ListNode();
	
	//����������� ���������������� ���� ��������� val
	ListNode(bool val);

	//������ �������� ����
	void setVal(bool val);

	//�������� �������� ����
	bool getVal();

	//������ ��������� ����
	void setNext(ListNode* next);

	//���������� ����������� ��������� ����
	ListNode* getNext();

	//������ ��������� ����
	void setPrev(ListNode* prev);
	
	//���������� ��������� ����
	ListNode* getPrev();

private:
	//�������� ���� ������
	bool val = 0;

	//��������� ������� ������
	ListNode* next = nullptr;

	//���������� ������� ������
	ListNode* prev = nullptr;
};