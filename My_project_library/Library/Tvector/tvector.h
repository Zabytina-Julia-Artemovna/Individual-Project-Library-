#pragma once
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
	Tvector() noexcept;
	Tvector(size_t size);
	Tvector(T* data, size_t size);
	Tvector(const Tvector<T>& other_vector);
	~Tvector() noexcept;

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

	void shrink_to_fit();
	void reserve(size_t new_capacity);
	void resize(size_t new_size);
	void resize(size_t new_size, T& value);
	
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
		T* new_data = new T[vector._capacity];
		State* new_states = new State[vector._capacity];
		std::fill_n(new_states, new_capacity, empty);
		size_t new_deleted = 0;
		for (size_t i = 0; i < vector._capacity) {
			if (vector._states[i] == deleted) {
				new_deleted++;
			}
			new_data[i] = vector[i];
			new_states[i] = vector._states[i];
		}
		delete[] _data;
		delete[] _states;
		_data = new_data;
		_states = new_states;
		_capacity = vector._capacity;
		_size = vector._size;
		_deleted = new_deleted;
	}
	inline const T& operator [] (size_t index) const {
		return this._data[index];
	}
	inline T& operator [] (size_t index){
		return _data[index];
	}
};
/*
	void push_front(const T& value);
	void push_back(const T& value);
	void insert(int position, const T& value);
	*/