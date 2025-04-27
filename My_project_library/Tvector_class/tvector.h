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

	void pop_front_elem() {
		int first_not_null = 0;
		while (mass[first_not_null] == NULL) {
			first_not_null++;
		}
		mass[first_not_null] = NULL;
	}
	void pop_front_elems(int* mass, int size, int count) {
		int first_not_null = 0;
		for (int i = 0; i < count; i++) {
			while (mass[first_not_null] == NULL) {
				first_not_null++;
			}
			mass[first_not_null] = NULL;
		}
	}
	void pop_back_elem(int* mass, int size) {
		int last_not_null = size - 1;
		while (mass[last_not_null] == NULL) {
			last_not_null--;
		}
		mass[last_not_null] = NULL;
	}
	void pop_back_elems(int* mass, int size, int count) {
		int last_not_null = size - 1;
		for (int i = 0; i < count; i++) {
			while (mass[last_not_null] == NULL) {
				last_not_null--;
			}
			mass[last_not_null] = NULL;
		}
	}
	void erase_elem(int* mass, int size, int pos) {
		int step = 0;
		for (int i = 0; i < size; i++) {
			if (mass[i] != NULL) {
				step++;

			}
			if (step == pos) {
				mass[i] = NULL;
				break;
			}
		}
	}
	void erase_elems(int* mass, int size, int pos, int count) {
		int step = 0;
		for (int i = 0; i < size; i++) {
			if (mass[i] != NULL) {
				step++;
			}
			if (step == pos) {
				mass[i] = NULL;
				if (pos != count) {
					pos++;
				}
			}

		}
	}
	/*
	
	 Стандартные функции вставки: push_front(), push_back(), insert().

  
  Функция замены значения emplace().
	
	*/
};
/*
	friend void sort_array(Tvector<T>& vector);
	friend void shuffle_array(Tvector<T>& vector);
*/
