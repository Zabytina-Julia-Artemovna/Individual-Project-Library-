#pragma once
enum State {
	emty, busy, deleted
};
template <class T>
class Tvector {
	T* _data;
	size_t _capacity;
	size_t _size;
	size_t deleted;
	State* states;
	inline bool is_full() const noexcept;
public:
	Tvector(sie_t size = 0);
	Tvector(size_t size);
	Tvector(T* data);
	Tvector(const Tvector<T>& vector);
	~Tvector();

	inline bool is_empty() const noexcept;
	inline T& front() noexcept;
	inline T* begin() noexcept;
	inline T* data() noexcept; //сеттер
	inline const T* data() const noexcept; //геттер
};