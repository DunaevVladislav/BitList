#pragma once

//����������� ����� ������
template<typename T>
class ListContainer
{
public:

	//�������� ������� �� �������� val � ������
	virtual void push_front(T val) = 0;

	//�������� ������� �� ��������� val � �����
	virtual void push_end(T val) = 0;

	//�������� ������ ������
	virtual size_t size() = 0;
};