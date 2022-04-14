#include "Map.h"
#include "MapIterator.h"
#include <exception>

Map::Map() {
	//complexity theta(1)
	this->nrElems = 0;
	this->capacity = 8;
	this->elements = new std::pair<TKey, TValue>[this->capacity];
}

Map::~Map() {
	delete[] this->elements;
}

TValue Map::add(TKey c, TValue v){
	//complexity O(n)
	int count = 0;
	int position = 0;
	int index = 0;
	TValue x = 0;

	if (this->nrElems == this->capacity)
		this->capacity *= 2;

	while (index < this->nrElems && count < 1) {
		if (this->elements[index].first == c) {
			count++;
			position = index;
		}
		index++;
	}
	if (count == 1) {
		x = this->elements[position].second;
		this->elements[position].second = v;
		return x;
	}
	else {
		TElem newpair(c, v);
		this->elements[this->nrElems] = newpair;
		this->nrElems++;
		return NULL_TVALUE;
	}
}

TValue Map::search(TKey c) const{
	//complexity theta(n)
	for (int i = 0; i < this->nrElems; i++) {
		if (this->elements[i].first == c) 
			return this->elements[i].second;
	}
	return NULL_TVALUE;
}

TValue Map::remove(TKey c){
	//complexity theta(n)
	TValue x = 0;
	if (this->nrElems == 0 || search(c) == NULL_TVALUE) {
		return NULL_TVALUE;
	}
	else
		for (int i = 0; i <= this->nrElems; i++)
			if (this->elements[i].first == c) {
				x = this->elements[i].second;
				for (int j = i; j < this->nrElems - 1; j++)
					this->elements[j] = this->elements[j + 1];
				this->nrElems--;
				return x;
			}
	return NULL_TVALUE;
}


int Map::size() const {
	//complexity theta(1)
	return this->nrElems;
}

bool Map::isEmpty() const{
	//complexity theta(1)
	if (this->nrElems == 0) {
		return true;
	}
	return false;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}



