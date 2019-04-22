#pragma once

#include "Node.h"
#include <stdexcept>

template <typename T>
class List {
private:
	unsigned node_count;
	Node<T> *head;
	Node<T> *tail;

	// returns nullptr on failure
	Node<T> *iterate_to_index(unsigned index) const;

public:
	List() : node_count(0), head(nullptr), tail(nullptr) {
	}

	List(const List &old) : node_count(0), head(nullptr), tail(nullptr) {
		this->operator=(old);
	}
	// and proper copy assignment operator.
	List &operator=(const List &old);

	void clear();
	~List() {
		clear();
	}

	void push_front(T data);
	void push_back(T data);
	void insert(T data, unsigned index);
	T pop_front();
	T pop_back();
	T remove(unsigned index);
	T &operator[](unsigned index) const;

	int find(T item);

	unsigned size() const { return node_count; }
	bool isempty() const { return node_count == 0; }
};

template <typename T>
Node<T> *List<T>::iterate_to_index(unsigned index) const {
	// we can skip iterating in this easy case.
	if (index == node_count - 1) return tail;

	Node<T> *node = head;
	for (unsigned iii = 0; node && iii < index; ++iii) {
		node = node->next;
	}
	return node;
}

template <typename T>
void List<T>::clear() {
	auto node = head;
	while (node) {
		auto old = node;
		node = old->next;
		delete old;
	}
	head = nullptr;
	tail = nullptr;
	node_count = 0;
}

template <typename T>
List<T> &List<T>::operator=(const List &old) {
	if (this == &old)
		return *this;

	clear();
	if (!old.head)
		return *this;

	head = new Node<T>(old.head->data);
	Node<T> *old_node = old.head;
	Node<T> *new_node = head;

	while (old_node->next) {
		old_node = old_node->next;
		new_node->next = new Node<T>(old_node->data);
		new_node = new_node->next;
	}

	tail = new_node;
	node_count = old.node_count;

	return *this;
}

template <typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	if (!tail) tail = head;
	++node_count;
}

template <typename T>
void List<T>::push_back(T data) {
	if (!tail) return push_front(data);
	tail->next = new Node<T>(data, nullptr);
	tail = tail->next;

	++node_count;
}

template <typename T>
void List<T>::insert(T data, unsigned index) {
	if (index == 0)
		return push_front(data);
	else if (index == node_count)
		return push_back(data);
	else if (index > node_count)
		throw std::out_of_range("Tried to insert to an out of range index!");

	// We need to modify the node before the removed one.
	Node<T> *node = iterate_to_index(index - 1);
	if (!node) throw std::logic_error("Ran into end of list while remaining within node_count!");

	// inserts between node and the current node->next
	node->next = new Node<T>(data, node->next);
	++node_count;
}

template <typename T>
T List<T>::pop_front() {
	if (node_count == 0)
		throw std::out_of_range("No items in the list to pop!");

	auto data = head->data;
	auto old = head;
	head = head->next;
	delete old;

	if (!head) tail = nullptr;

	--node_count;

	return data;
}

template <typename T>
T List<T>::pop_back() {
	if (node_count <= 1)
		return pop_front();

	// off by one for zero indexing, and then subtract one to get the node before the tail.
	auto node = iterate_to_index(node_count - 2);

	auto data = node->next->data;
	delete node->next;
	node->next = nullptr;
	tail = node;
	--node_count;

	return data;
}

template <typename T>
T List<T>::remove(unsigned index) {
	if (index == 0)
		return pop_front();
	else if (index == node_count - 1)
		return pop_back();
	else if (index >= node_count)
		throw std::out_of_range("Tried to remove an out of range index!");

	// We need to modify the node before the removed one.
	auto node = iterate_to_index(index - 1);
	if (!node) throw std::logic_error("Ran into end of list while remaining within node_count!");

	auto removed = node->next;
	node->next = removed->next;

	auto data = removed->data;
	delete removed;
	--node_count;

	return data;
}

template <typename T>
T &List<T>::operator[](unsigned index) const {
	if (index >= node_count) throw std::out_of_range("out of range index in operator[]");

	auto node = iterate_to_index(index);
	if (!node) throw std::logic_error("Ran into end of list while remaining within node_count!");

	return node->data;
}

template <typename T>
int List<T>::find(T item) {
	auto node = head;
	unsigned index = 0;
	// manual iteration makes more sense here.
	while (node) {
		if (node->data == item)
			return index;
		node = node->next;
		++index;
	}
	return -1;
}
