#include "tvector.h"
#include <stdexcept>
#include <exception>
#include <random>
#define RESERVE 15

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

/*
template <class T>
void Tvector<T>::sort_array(Tvector<T>& vector) {
	int h = 1;
	while (h < _size / 3) {
		h = 3 * h + 1;
	}
	while (h >= 1) {
		for (size_t i = h; i < _size; i++) {
			for (size_t j = i; j >= h && _data[j] < _data[j - h]; j -= h) {
				std::swap(_data[j], _data[j - h]);
				std::swap(_states[j], _states[j - h]);
			}
		}
		h /= 3;
	}
}
template <class T>
void Tvector<T>::shuffle_array(Tvector<T>& vector) {
	size_t j = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	for(size_t i = _size; i-- > 0; ) {

		std::uniform_int_distribution<size_t> dist(0, i);
		j = dist(gen);
		std::swap(vector._data[i], vector._data[j]);
		std::swap(vector._states[i], vector._states[j]);
	}
}

*/