#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdint>
#include "LinkedList.h"
#include "HashMapNode.h"
using namespace std;
template <class T>

class HashMap {
private:
	int map_size;
	int insertAttempt;

public:
	HashMap(int size);
	~HashMap();

	List<HashMapNode<T>> *map;
	int size() ;
	int bucketsUsed() ;
	int indexer(string key);
    int collisions() ;
	int insertAttempts();
    void clear();
    void insert(string key, T value);
	T find(string key);
};

template <class T>
HashMap<T>::HashMap(int size): map_size(size), insertAttempt(0) {
    map = new List<HashMapNode<T>>[size];
}

template <class T>
HashMap<T>::~HashMap() {
    clear();
}

template <class T>
void HashMap<T>::clear() {
	delete[] map;
	map = nullptr;
	map_size = 0;
	insertAttempt = 0;
}

template <class T>
int HashMap<T>::indexer(string key) { //for turning key into an int for index
	key.erase(remove(key.begin(), key.end(), '-'), key.end());
	int index = 0;
	int sum = 0;
	int fSum = 0;
	int strLen = (int)key.length();

	while (index < strLen) {
		sum = (key[index] - '0') + sum;
		index++;
	}
	//second time
	string temp = to_string(sum);
	index = 0;
	strLen = (int)temp.length();
	sum = 0;
	while (index < strLen) {
		sum = (temp[index] - '0') + sum;
		index++;
	}
	return sum;
}

template <class T>
 int HashMap<T>::size()  {
    return map_size;
}

template <class T>
 int HashMap<T>::bucketsUsed()  {
	 int bucketCount = 0;
    for (int i = 0; i < map_size; ++i) {
        auto &bucket = map[i];
        if (bucket.size() > 0)
            ++bucketCount;
    }
    return bucketCount;
}

template <class T>
 int HashMap<T>::collisions()  {
	 int collisionCount = 0;
    for (int i = 0; i < map_size; ++i) {
		auto &bucket = map[i];
        if (bucket.size() > 1)
            collisionCount += (bucket.size() - 1);
    }
    return collisionCount;
}

template <class T>
int HashMap<T>::insertAttempts()  {
    return insertAttempt;
}

template <class T>
void HashMap<T>::insert(string key, T value) { 
	int index = indexer(key);  //for turning bday into an int for index
	List<HashMapNode<T> > &bucket = map[index];
	if (bucket.size() > 1) { 
		index = (index*index) % map_size; //quadratic probing for collision resolution
	}
	bucket = map[index];
    for (int i = 0; i < bucket.size(); ++i) {
        HashMapNode<T> &node = bucket[i];
        if (node.getKey() == key) {
            node.setValue(value);
            return;
        }
        insertAttempt++;
    }
    bucket.push_back(HashMapNode<T>(key, value)); 
}

template <class T>
T HashMap<T>::find(string key) {
	int index = indexer(key); //for turning bday into an int for index
	List<HashMapNode<T> > &bucket = map[index];
	if (bucket.size() > 1) { 
		index = (index*index) % map_size; //quadratic probing for collision resolution
	}
	bucket = map[index];
	for (int i = 0; i < bucket.size(); ++i) {
		if (bucket[i].getKey() == key) {
			HashMapNode<T> tmp = bucket.remove(i);
			bucket.push_front(tmp);
			return tmp.getValue();
		}
		else {
		}
	}
}
