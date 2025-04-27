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
		return _data[0];
	}
	inline T& back() noexcept { 
		return _data[_size - 1];
	}
	inline const T& front() noexcept {
		return _data[0];
	}
	inline const T& back() noexcept {
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
};
/*
	friend void sort_array(Tvector<T>& vector);
	friend void shuffle_array(Tvector<T>& vector);
*/

