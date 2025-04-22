#include "tvector.h"
#define RESERVE 15

template <class T>
Tvector<T>::Tvector() : _data(nullptr), _capacity(0), _size(0), _deleted(0), _states(nullptr) {}
template <class T>
Tvector<T>::Tvector(size_t size) {
	_size = size;
	_capacity = size + RESERVE;
	_data = new T[_capacity];
	_states = new State[_capacity];
	for (int i = 0; i < _size; ++i) {
		_states[i] = busy;
	}
	for (int i = _size; i < _capacity; ++i) {
		_states[i] = empty;
	}
	deleted = 0;
}
template <class T>
Tvector<T>::Tvector(T* data) {
	//???
}
template <class T>
Tvector<T>::Tvector(const Tvector<T>& other_vector) {
	_size = other_vector._size;
	_capacity = other_vector._capacity;
	_data = other_vector._data;
	_deleted = other_vector._deleted;
	_states = other_vector._states;
}
template <class T>
Tvector<T>::~Tvector() {
	delete[] _data;
	delete[] _states;
	_data = nullptr;
	_states = nullptr;
}
template <class T>
inline bool Tvector<T>::is_empty() const noexcept {
	return _size == 0;
}
template <class T>
inline const T* Tvector<T>::data() const noexcept {
	return _data;
}
template <class T>
inline T* Tvector<T>::data(const T* new_data, size_t new_size) noexcept { // нужно изменить массив состояний!
	if (new_size > _capacity) {
		delete[] _data;
		_capacity = new_size + RESERVE;
		new_data = new T[_capacity];
		//?
		
	}
}
//inline const T* Tvector<T>::data() const noexcept{
// 
// 
// } //геттер