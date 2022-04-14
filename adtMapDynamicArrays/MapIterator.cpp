#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d){
	//complexity theta(1)
	this->index = 0;
}


void MapIterator::first() {
	//complexity theta(1)
	this->index = 0;
}


void MapIterator::next() {
	//complexity theta(1)
	if (valid()){
		this->index++;
	}
	else {
		throw exception();
	}
}


TElem MapIterator::getCurrent(){
	if (valid())
		return map.elements[index];
	throw exception();
}


bool MapIterator::valid() const {
	if (map.nrElems != 0 && index < map.nrElems) {
		return true;
	}
	else {
		return false;
	}
}



