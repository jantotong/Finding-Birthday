#pragma once

template <typename T>
struct Node {
	T data;
	Node *next;

	Node(T _data, Node *_next = nullptr) : data(_data), next(_next) {}
};
