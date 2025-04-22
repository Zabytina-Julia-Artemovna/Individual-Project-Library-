#pragma once
enum State {
	empty, busy, deleted
};
template <class T>
class Tvector { 
	T* _data;
	size_t _capacity;
	size_t _size;
	size_t _deleted;
	State* _states;
	inline bool is_full() const noexcept {
		return _size == _capacity;
	}
	
public:
	Tvector();
	Tvector(size_t size);
	Tvector(T* data);
	Tvector(const Tvector<T>& other_vector);

	~Tvector();

	inline bool is_empty() const noexcept;
	inline T& front() noexcept;
	inline T* begin() noexcept;
	inline T* data(const T* new_data, size_t new_size) noexcept; 
	inline const T* data() const noexcept; 
};


