//
//  List.h
//  max_min_tournament_method
//
//  Created by Reza Roofegari nejad
//

/* *************************************************
Linked List class declaration
*****************************************************/
#pragma once
#include <iostream>
using namespace std;

class List {
public:
	// class constructor
	List() : head_(nullptr) {}

	// Insert method
	void insert(const int &data);

	// operator to access specific index in the list
	const int & operator[](unsigned int index);

	// find minimum element in the list
	const int & find_min();

	// find maximum element in the list
	const int & find_max();

	// class destructor
	~List()
	{
		ListNode *node = head_;
		while (node != nullptr)
		{
			ListNode *to_delete = node;
			node = node->next;
			delete to_delete;
			to_delete = nullptr;
		}
	}


private:
	class ListNode {
	public:
		const int &data;
		ListNode *next;
		ListNode(const int &data) : data(data), next(nullptr) {}
	};

	ListNode *head_;
};

/* *************************************************
Define class methods
*****************************************************/

/* *************************************************
Insert function for Linked List class
*****************************************************/
void List::insert(const int &data)
{
	ListNode *node = new ListNode(data);
	node->next = head_;
	head_ = node;
}


/* *************************************************
Operator[] for Linked List class
*****************************************************/
const int & List::operator[](unsigned int index)
{
	ListNode *node = head_;

	// loop through the list to find the index
	while (index > 0 && node->next != nullptr)
	{
		node = node->next;
		index--;
	}

	if (nullptr == node)
	{
		cout << "Error: index is out of the List capacity" << endl;
	}

	return node->data;
}

/* *************************************************
Find minimum element in the list
*****************************************************/
const int & List::find_min()
{
	ListNode *node = head_;
	int min = node->data;

	while (node->next != nullptr)
	{
		node = node->next;
		if (node->data < min)
		{
			min = node->data;
		}
	}

	return min;
}

/* *************************************************
Find maximum element in the list
*****************************************************/
const int & List::find_max()
{
	ListNode *node = head_;
	int max = node->data;

	while (node->next != nullptr)
	{
		node = node->next;
		if (node->data > max)
		{
			max = node->data;
		}
	}

	return max;
}
