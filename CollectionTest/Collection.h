#pragma once
#include "SinglyLinkedList.h"

template <typename T>
class Collection
{
public:
	virtual void Print() const = 0;
	virtual void Add(int data) = 0;
};

/*
GetCount
Add
Remove
Print
Search
Replace
Sort
*/