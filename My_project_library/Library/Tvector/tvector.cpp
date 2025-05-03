#include "tvector.h"
#include <stdexcept>
#include <exception>
#include <random>
#include <iostream>
#define RESERVE 15
#define PERSENT_OF_DELETED_ELEMENTS

template <class T>
Tvector<T>::Tvector() noexcept {
	_size = 0;
	_capacity = 0;
	_data = nullptr;
	_states = nullptr;
	_deleted = 0;
}
template <class T>
Tvector<T>::Tvector(size_t size) {
	_size = size;
	_capacity = size + RESERVE;
	try {
		_data = new T[_capacity];
	}
	catch (const std::bad_alloc&) {
		throw;
	}
	try {
		_states = new State[_capacity];
	}
	catch (const std::bad_alloc&) {
		delete[] _data;
		throw;
	}
	_deleted = 0;

	for (size_t i = 0; i < _capacity; ++i) {
		_states[i] = i < _size ? State::busy : State::empty;
	}
}
template <class T>
Tvector<T>::Tvector(T* data, size_t size)
{
	if (size > 0 && data == nullptr) {
		throw std::invalid_argument("Null data pointer with non-zero size");
	}
	_size = size;
	_capacity = _size + RESERVE;
	try {
		_data = new T[_capacity];
	}
	catch (const std::bad_alloc&) {
		throw;
	}
	try {
		_states = new State[_capacity];
	}
	catch (const std::bad_alloc&) {
		delete[] _data;
		throw;
	}
	for (size_t i = 0; i < _capacity; ++i) {
		if (i < _size) {
			_data[i] = data[i];
			_states[i] = State::busy;
		}
		else {
			_states[i] = State::empty;
		}
	}
	_deleted = 0;
}
template <class T>
Tvector<T>::Tvector(const Tvector<T>& other_vector) {
	if (this == &other_vector) {
		throw std::logic_error("Self-copy prohibited");
	}
	_size = other_vector._size;
	_capacity = other_vector._capacity;
	try {
		_data = new T[_capacity];
	}
	catch (const std::bad_alloc&) {
		throw;
	}
	try {
		_states = new State[_capacity];
	}
	catch (const std::bad_alloc&) {
		delete[] _data;
		throw;
	}
	_deleted = other_vector._deleted;

	for (size_t i = 0; i < other_vector._size; ++i) {
		_data[i] = other_vector._data[i];
		_states[i] = other_vector._states[i];
	}
	for (size_t i = other_vector._size; i < other_vector._capacity; ++i) {
		_states[i] = State::empty;
	}
}
template <class T>
Tvector<T>::~Tvector() noexcept {
	delete[] _data;
	delete[] _states;
};

template <class T>
void Tvector<T>::shrink_to_fit() {
	if (_size >= _capacity) {
		return;
	}
	T* new_data = new T[_size];
	State* new_states = new State[_size];
	for (size_t i = 0; i < _size; ++i) {
		new_data[i] = std::move(_data[i]);
		new_states[i] = _states[i];
	}
	delete[] _data;
	delete[] _states;
	_data = new_data;
	_states = new_states;
	_capacity = _size;

}
template <class T>
void Tvector<T>::reserve_memory(size_t new_capacity) {
	if (new_capacity <= _capacity) {
		return;
	}
	T* new_data = new T[new_capacity];
	State* new_states = new State[new_capacity];
	std::fill_n(new_states, new_capacity, empty);
	for (size_t i = 0; i < _size; ++i) {
		new_data[i] = std::move(_data[i]);
		new_states[i] = _states[i];
	}
	delete[] _data;
	delete[] _states;
	_data = new_data;
	_states = new_states;
	_capacity = new_capacity;
}
template <class T>
void Tvector<T>::resize(size_t new_size) {
	if (new_size == _size) {
		return;
	}
	else if (new_size > _size) {
		T* new_data = new T[new_size];
		State* new_states = new State[new_size];
		std::fill_n(new_states, new_size, empty);
		for (size_t i = 0; i < _size; ++i) {
			_new_data[i] = std::move(_data[i]);
			new_states = _states[i];
		}
		delete[] _data;
		delete[] _states;
	}
}
/*
void push_front_elem(int* mass, int size, int value) {
	for (int i = size - 1; i > 0; i--) {
		mass[i] = mass[i - 1];
	}
	mass[0] = value;
}

void push_back_elem(int* mass, int size, int value) {
	mass[size - 1] = value;
}

void insert_elem(int* mass, int size, int pos, int value) {
	for (int i = size - 1; i > pos; i--) {
		mass[i] = mass[i - 1];
	}
	mass[pos] = value;
}

*/

/*
Для вектора:
template <class T>
void Tvector<T>::push_front(const T& value) {
	if (_size >= _capacity) {
		// Реаллокация (например, увеличиваем _capacity в 2 раза)

	}
	for (size_t i = _size; i > 0; --i) {
		_data[i] = std::move(_data[i - 1]);
	}
	_data[0] = value;
	_size++;
}
template <class T>
void Tvector<T>::push_back(const T& value) {
	if (_size >= _capacity) {
		// Реаллокация (например, увеличиваем _capacity в 2 раза)

	}

}
template <class T>
void Tvector<T>::insert(int position, const T& value) {
	if (_size >= _capacity) {
		// Реаллокация (например, увеличиваем _capacity в 2 раза)

	}

}
*/