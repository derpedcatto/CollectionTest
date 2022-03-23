#pragma once
#include <iostream>
#include "Collection.h"
#include "Node.h"
using namespace std;

template <typename T>
class SinglyLinkedList : public Collection <T>
{
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	/*CONSTRUCTOR*/
	SinglyLinkedList();

	/*COLLECTION*/
	void Print() const;
	void Add(T data);
	void Remove(T data);
	void Replace(int index, T value);
	void Sort() const;
	bool Search(T data) const;
	int GetCount() const;

	/*DEST*/
	~SinglyLinkedList();
};


/*METHODS*/
template <typename T>
void SinglyLinkedList<T>::Add(T data)
{
	Node<T>* newElem = new Node<T>();
	newElem->data = data;
	if (tail == nullptr)
	{
		head = newElem;
	}
	else
	{
		tail->next = newElem;
	}
	tail = newElem;
	count++;
}

template <typename T>
void SinglyLinkedList<T>::Remove(T data)
{
	/*DeleteFromHead()*/
	if (data <= 0)
	{
		if (count == 0)
		{
			cout << "Empty list!\n";
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		count--;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		return;
	}

	if (data >= count)
	{
		data = count - 1;
	}

	int i = 1;
	Node<T>* beforeDel = head;
	while (i++ != data)
	{
		beforeDel = beforeDel->next;
	}
	Node<T>* sacrifice = beforeDel->next;
	beforeDel->next = sacrifice->next;
	delete sacrifice;
	count--;
	if (beforeDel->next == nullptr)
	{
		tail = beforeDel;
	}
}

template <typename T>
void SinglyLinkedList<T>::Print() const
{
	if (count == 0)
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
void SinglyLinkedList<T>::Replace(int index, T value)
{
	if (index > count - 1)
		return;

	Node<T>* current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	current->data = value;
}

template <typename T>
void SinglyLinkedList<T>::Sort() const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node<T>* index = head;
	Node<T>* current;

	while (index != tail)
	{
		current = index;
		while (current != nullptr)
		{
			if (index->data > current->data)
				swap(index->data, current->data);

			current = current->next;
		}

		index = index->next;
	}
}

template <typename T>
bool SinglyLinkedList<T>::Search(T data) const
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
int SinglyLinkedList<T>::GetCount() const
{
	return count;
}


/*CONST-DEST*/
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	Node<T>* current = head;
	Node<T>* next;
	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
}