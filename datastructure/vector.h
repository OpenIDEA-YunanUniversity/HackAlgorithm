#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <iostream>
#include<stdexcept>
#include "dsexceptions.h"

template <typename Object>

class Vector{


public:
	explicit Vector(int init_size=0):_the_size(init_size),
	_the_capacity(init_size+SPARE_CAPACITY)
	{
		_objects = new Object[_the_capacity];
	}

	Vector(const Vector &rhs):_the_size(rhs._the_size),
	_the_capacity(rhs._the_capacity), _objects(nullptr)
	{
		_objects = new Object[_the_capacity];
		for(int k=0; k<_the_size; k++){
			_objects[k] = rhs._objects[k];
		}
	}

	Vector &operator=(const Vector &rhs){
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	~Vector(){delete [] _objects;}

	Vector(Vector && rhs):_the_size(rhs._the_size),
	_the_capacity(rhs._the_capacity), _objects(rhs._objects){
		rhs._objects = nullptr;
		rhs._the_size = 0;
		rhs._the_capacity = 0;
	}

	Vector &operator=(Vector && rhs){
		std::swap(_the_size, rhs._the_size);
		std::swap(_the_capacity, rhs._the_capacity);
		std::swap(_objects, rhs._objects);

		return *this;
	}

	void resize(int new_size){
		if(new_size>_the_capacity)
			reserve(new_size*2);
		_the_size = new_size;
	}

	void reserve(int new_capacity){
		if(new_capacity<_the_size)
			return;
		Object *new_array = new Object[new_capacity];
		for(int k=0;k<_the_size;k++)
			new_array[k] = std::move(_objects[k]);
		_the_capacity = new_capacity;
		std::swap(_objects, new_array);
		delete []new_array;
	}

	Object &operator[](int index){
		return _objects[index];
	}

	const Object &operator[](int index) const{
		return _objects[index];
	}

	bool empty() const {return size()==0;}
	int size() const {return _the_size;}
	int capacity()const {return _the_capacity;}

	void push_back(const Object &x){
		if(_the_size==_the_capacity)
			reserve(2*_the_capacity+1);
		_objects[_the_size++] = x;
	}

	void push_back(const Object && x){
		if(_the_size == _the_capacity)
			reserve(2*_the_capacity+1);
		_objects[_the_size++] = std::move(x);
	}

	void pop_back(){ _the_size--;}
	const Object &back()const{return _objects[_the_size-1];}


	typedef Object *iterator;
	typedef const Object *const_iterator;

	iterator begin(){return &_objects[0];}
	const_iterator begin() const{return &_objects[0];}

	iterator end(){return &_objects[size()];}
	const_iterator end() const{return &_objects[size()];}


	static const int SPARE_CAPACITY=16;
private:
	int _the_size;
	int _the_capacity;
	Object *_objects;


};


#endif
