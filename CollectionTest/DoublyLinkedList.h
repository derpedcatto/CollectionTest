#pragma once
#include <iostream>
#include "Collection.h"
#include "Node.h"
using namespace std;

template <typename T>
class DoublyLinkedList : public Collection <T>
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size = 0;

	Node<T>* GetNode(int index)
	{
		if (index < 0 || index > size - 1)
			throw "ERROR";

		Node<T>* tmp;
		if (index <= size / 2)
		{
			tmp = head;
			while (index > 0)
			{
				tmp = tmp->next;
				index--;
			}
		}
		else
		{
			tmp = tail;
			while (index < size - 1)
			{
				tmp = tmp->prev;
				index++;
			}
		}
		return tmp;
	}

public:
	/*CONST-DEST*/
	DoublyLinkedList();
	~DoublyLinkedList();

	/*COLLECTION*/
	void Print() const;
	void Add(T data);
	void Remove(T data);
	void Replace(int index, T value);
	void Sort() const;
	bool Search(T data) const;
	int GetCount() const;
};

/*CONST-DEST*/
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	while (size != 0)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;

		if (head == nullptr)
		{
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		size--;
	}
}

/*PRIVATE*/

/*COLLECTION*/

template <typename T>
void DoublyLinkedList<T>::Print() const
{
	if (size == 0)
	{
		cout << "Empty list!\n";
		return;
	}

	Node<T>* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

template <typename T>
void DoublyLinkedList<T>::Add(T data)
{
	Node<T>* newnode = new Node<T>();
	newnode->data = data;
	newnode->prev = tail;
	if (size == 0)
	{
		head = newnode;
	}
	else
	{
		tail->next = newnode;
	}
	tail = newnode;
	size++;
}

template <typename T>
void DoublyLinkedList<T>::Remove(T data)
{
	if (data < 0 || data > size - 1)
		throw "ERROR";

	if (data == 0)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;

		if (head == nullptr)
		{
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		size--;
		return;
	}
	if (data == size - 1)
	{
		Node<T>* temp = tail;
		tail = tail->prev;
		delete temp;

		if (tail == nullptr)
		{
			head = nullptr;
		}
		else
		{
			tail->next = nullptr;
		}
		size--;
		return;
	}

	Node<T>* del = GetNode(data);
	del->prev->next = del->next;
	del->next->prev = del->prev;
	delete del;
	size--;
}

template <typename T>
void DoublyLinkedList<T>::Replace(int index, T value)
{
	Node<T>* tmp = GetNode(index);
	tmp->data = value;
}

template <typename T>
void DoublyLinkedList<T>::Sort() const
{
	if (size == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node<T>* index = head;
	Node<T>* current;

	while (index != tail)
	{
		current = tail;
		while (current != index)
		{
			if (index->data > current->data)
				swap(index->data, current->data);

			current = current->prev;
		}

		index = index->next;
	}
}

template <typename T>
bool DoublyLinkedList<T>::Search(T data) const
{
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (current->data == data)
			return true;
		current = current->next;
	}
	return false;
}

template <typename T>
int DoublyLinkedList<T>::GetCount() const
{
	return size;
}