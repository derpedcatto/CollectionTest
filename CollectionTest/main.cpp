#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Set.h"

int main()
{
	printf("SLL\n");
	SinglyLinkedList<double> a;
	a.Add(30.5);
	a.Add(20.125);
	a.Add(30);
	a.Print();

	printf("\nDLL\n");
	DoublyLinkedList<int> b;
	b.Add(10000);
	b.Add(1000);
	b.Add(100);
	b.Sort();
	b.Print();

	printf("\nSET\n");
	Set<int> c;
	c.Add(-10);
	c.Add(-2);
	c.Add(-3);
	c.Print();
}