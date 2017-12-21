#pragma once

//абстрактный класс список
template<typename T>
class ListContainer
{
public:

	//добавить элемент со знчаеним val в начало
	virtual void push_front(T val) = 0;

	//добавить элемент со значением val в конец
	virtual void push_end(T val) = 0;

	//получить размер списка
	virtual size_t size() = 0;
};