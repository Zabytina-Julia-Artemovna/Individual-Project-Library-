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
	Tvector();
	Tvector(size_t size);
	Tvector(T* data, size_t size);
	Tvector(const Tvector<T>& other_vector);
	~Tvector() noexcept;

	inline bool is_empty() const noexcept;
	size_t size() const noexcept;
	size_t capacity() const noexcept;

	inline T& back() noexcept;
	inline T& front() noexcept;
	inline T* begin() noexcept;
	inline T* end() noexcept;
	inline T* data(const T* new_data, size_t new_size) noexcept;
	inline const T* data() const noexcept;
};
