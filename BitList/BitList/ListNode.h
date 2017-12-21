#pragma once

//узел списка
class ListNode
{
public:
	//конструктор по умолчанию
	ListNode();
	
	//конструктор инициализирующий узел знчаением val
	ListNode(bool val);

	//задает значение узла
	void setVal(bool val);

	//получает значение узла
	bool getVal();

	//задает следующий узел
	void setNext(ListNode* next);

	//возвращает указательна следующий узел
	ListNode* getNext();

	//задает предыдщий узел
	void setPrev(ListNode* prev);
	
	//возвращает предыдщий узел
	ListNode* getPrev();

private:
	//значение узла списка
	bool val = 0;

	//следующий элемент списка
	ListNode* next = nullptr;

	//предыдущий элемент списка
	ListNode* prev = nullptr;
};