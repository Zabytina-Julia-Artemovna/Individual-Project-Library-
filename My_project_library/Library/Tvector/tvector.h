#pragma once
#define RESERVE 15
#include <stdexcept>
#include <exception>
#include <random>
#include <iostream>
enum State {
	empty, busy, deleted
};
template <class T>
class Tvector {
	size_t _size;
	size_t _capacity;
	T* _data;
	State* _states;
	size_t _deleted;

	inline bool is_full() const noexcept {
		return _size == _capacity;
	}
public:
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

	inline bool is_empty() const noexcept {
		return _size == 0;
	}

	inline const T* data() const noexcept {
		return _data;
	}
	inline T* data() noexcept {
		return _data;
	}

	inline T& front() noexcept {
		if (_size == 0) {
			throw std::out_of_range("Vector is empty");
		}
		return _data[0];
	}
	inline T& back() noexcept {
		if (_size == 0) {
			throw std::out_of_range("Vector is empty");
		}
		return _data[_size - 1];
	}
	inline const T& front() noexcept {
		if (_size == 0) {
			throw std::out_of_range("Vector is empty");
		}
		return _data[0];
	}
	inline const T& back() noexcept {
		if (_size == 0) {
			throw std::out_of_range("Vector is empty");
		}
		return _data[_size - 1];
	}

	size_t size() const noexcept {
		return _size;
	}
	size_t capacity() const noexcept {
		return _capacity;
	}

	inline T* begin() const noexcept {
		return _data;
	}
	inline T* end() const noexcept {
		return _data + _size;
	}

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
	void Tvector<T>::reserve(size_t new_capacity) {
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
	void resize(size_t new_size);
	void resize(size_t new_size, T& value);
	/*

template <class T>
void Tvector<T>::resize(size_t new_size) {
	if (new_size == _size) {
		return;
	}
	else if (new_size < _size){
		size_t new_capacity = new_size + RESERVE;
		T* new_data = new T[new_capacity];
		State* new_states = new State[new_capacity];
		std::fill_n(new_states, new_capacity, empty);
		size_t count_of_deleted = 0;
		for (size_t i = 0; i < new_size; ++i) {
			if (_states[i] == deleted) {
				count_of_deleted++;
			}
			new_data[i] = std::move(_data[i]);
			new_states[i] = _states[i];
		}
		delete[] _data;
		delete[] _states;
		_size = new_size;
		_capacity = new_capacity;
		_deleted = count_of_deleted;
	}
	else if (new_size > _size) {
		size_t new_capacity = new_size + RESERVE;
		T* new_data = new T[new_capacity];
		State* new_states = new State[new_capacity];
		std::fill_n(new_states, new_capacity, empty);
		for (size_t i = 0; i < new_size; ++i) {
			new_data[i] = std::move(_data[i]);
			new_states[i] = _states[i];
		}
		delete[] _data;
		delete[] _states;
		_size = new_size;
		_capacity = new_capacity;
	}
}
template <class T>
void Tvector<T>::resize(size_t new_size, T& value) {

}
*/
	
	friend bool operator == (const Tvector<T>& vector1, const Tvector<T>& vector2) {
		if (vector1._size == vector2._size) {
			for (size_t i = 0; i < vector1._size; ++i) {
				if (vector1[i] != vector2[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
	bool operator != (const Tvector<T>& vector1, const Tvector<T>& vector2) {
		return !(vector1 == vector2);
	}
	Tvector<T>& operator = (const Tvector<T>& vector) {
		if (this == &vector) {
			return *this;
		}
		T* new_data = new T[vector._capacity];
		State* new_states = new State[vector._capacity];
		for (size_t i = 0; i < vector._size; ++i) {
			new_data[i] = vector[i];
			new_states[i] = vector._states[i];
		}
		delete[] _data;
		delete[] _states;
		_data = new_data;
		_states = new_states;
		_capacity = vector._capacity;
		_size = vector._size;
		_deleted = vector._deleted;
		return *this;
	}
	inline const T& operator[](size_t index) const {
		return _data[index]; 
	}
	inline T& operator[](size_t index) {
		return _data[index];
	}
};
/*
	void push_front(const T& value);
	void push_back(const T& value);
	void insert(int position, const T& value);
	*/