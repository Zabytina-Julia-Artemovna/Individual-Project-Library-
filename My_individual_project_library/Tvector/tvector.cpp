#include "tvector.h"
#include <exception>
#define RESERVE 15

template <class T>
Tvector<T>::Tvector(): _size(0), _capacity(0), _data(nullptr), _states(nullptr), _deleted(0){}
template <class T>
Tvector<T>::Tvector(size_t size) : _size(size), _capacity(size + RESERVE),
_data(new T[_capacity]()), _states(new State[_capacity]), _deleted(0) {
	for (size_t i = 0; i < _capacity; ++i) {
		_states[i] = i < _size ? State::busy : State::empty;
	}
}
template <class T>
Tvector<T>::Tvector(T* data, size_t size) 
{
	_size = size;
	_capacity = _size + RESERVE;
	_data = new T[_capacity];
	_states = new State[_capacity];
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
Tvector<T>::Tvector(const Tvector<T>& other_vector): _size(other_vector._size),
_capacity(other_vector._capacity), _data(new T[other_vector._capacity]), 
_states(new State[other_vector._capacity]), _deleted(other_vector._deleted) {
	if (this == &other_vector) {
		throw std::logic_error("Self-copy prohibited");
	}
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
	_data = nullptr;
	_states = nullptr;
};