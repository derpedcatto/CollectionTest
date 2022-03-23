#pragma once

template <typename T>
class Collection
{
public:
	virtual void Print() const = 0;
	virtual void Sort() const = 0;
	virtual bool Search(T data) const = 0;
	virtual int GetCount() const = 0;
	virtual void Add(T data) = 0;
	virtual void Remove(T data) = 0;	// or index
	virtual void Replace(int index, T value) = 0;
};