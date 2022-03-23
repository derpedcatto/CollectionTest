#pragma once
#include <set>
#include "Collection.h"

template <typename T>
class Set : public Collection <T>
{
private:
	set<T> list;

public:
	void Print() const;
	void Sort() const;
	bool Search(T data) const;
	int GetCount() const;
	void Add(T data);
	void Remove(T data);	// or index
	void Replace(int index, T value);
};

template <typename T>
void Set<T>::Print() const
{
	for (auto i = list.begin(); i != list.end(); i++)
		cout << *i << " ";
}

template <typename T>
void Set<T>::Sort() const
{
	std::cout << "\nNo need to sort!\n\n";
}

template <typename T>
bool Set<T>::Search(T data) const
{
	return list.find(data) != list.end();
}

template <typename T>
int Set<T>::GetCount() const
{
	int count = 0;
	for (auto i = list.begin(); i != list.end(); i++)
		count++;

	return count;
}

template <typename T>
void Set<T>::Add(T data)
{
	list.insert(data);
}

template <typename T>
void Set<T>::Remove(T data)
{
	list.erase(data);
}

template <typename T>
void Set<T>::Replace(int index, T value)
{
	std::cout << "\nCan't replace in Set!\n\n";
}