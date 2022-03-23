#pragma once

template <typename T>
class Node
{
public:
	T data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};