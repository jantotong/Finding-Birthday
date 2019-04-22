#pragma once

#include <string>
using namespace std;

template <class T>
class HashMapNode {
private:
    string key;
    T value;
    int hashId, listPos, initialId;
    bool flagCollision;
public:
    HashMapNode();
    HashMapNode(string key, T value);
    HashMapNode(string key, T value,int id);
    HashMapNode(string key, T value,int id,int pos);
    ~HashMapNode();

    //Getter
    string getKey();
    T getValue();
    
    //Setter
    void setId(int id);
    void setValue(T value);
    void setKey(string key);
};

template <class T>
HashMapNode<T>::HashMapNode() {
    key = "";
    value = nullptr;
}

template <class T>
HashMapNode<T>::HashMapNode(string key,T value) {
    this->key = key;
    this->value = value;
}

template <class T>
HashMapNode<T>::HashMapNode(string key,T value, int id) {
    this->key = key;
    this->value = value;
    hashId = id;
}

template <class T>
HashMapNode<T>::HashMapNode(string key,T value, int id, int pos) {
    this->key = key;
    this->value = value;
    hashId = id;
    flagCollision = (pos != 0);
    listPos = pos;
}

template <class T>
HashMapNode<T>::~HashMapNode() {
}

template <class T>
string HashMapNode<T>::getKey() {
	return key;
}

template <class T>
T HashMapNode<T>::getValue() {
	return value;
}

template <class T>
void HashMapNode<T>::setKey(string key) {
	this->key = key;
}

template <class T>
void HashMapNode<T>::setValue(T value) {
	this->value = value;
}

template <class T>
void HashMapNode<T>::setId(int id) {
	hashId = id;
}
