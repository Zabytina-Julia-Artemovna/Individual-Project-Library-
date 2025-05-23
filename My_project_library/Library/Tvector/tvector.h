// Copyright 2025 Zabytina Julia. All rights reserved.
#pragma once
#include <cstddef> 
#include <stdexcept>
#include <vector>
#include <exception>
#include <random>
#include <iostream>
#include <utility>
#include <memory>
#include <algorithm>
template <class T>
class Tvector {
 private:
     static constexpr size_t RESERVE_MEMORY = 15;
     static constexpr size_t MAX_PERCENT_DELETED = 15;
     enum State {
         empty, busy, deleted
     };
    size_t _size;
    size_t _capacity;
    T* _data;
    State* _states;
    size_t _deleted;
    void resize(size_t new_size) {
        if (new_size == _size) {
            return;
        } else if (new_size < _size) {
            for (size_t i = new_size; i < _size; ++i) {
                if (_states[i] == State::deleted) {
                    _deleted--;
                }
                _data[i].~T();
                _states[i] = State::empty;
            }
            _size = new_size;
        } else {
            size_t new_capacity = new_size + RESERVE_MEMORY;
            T* new_data = static_cast<T*>
              (::operator new(new_capacity * sizeof(T)));
            State* new_states = new State[new_capacity];
            for (size_t i = new_size; i < new_capacity; ++i) {
                new_states[i] = State::empty;
            }
            try {
                for (size_t i = 0; i < _size; ++i) {
                    new (new_data + i) T(std::move(_data[i]));
                    new_states[i] = _states[i];
                }
                for (size_t i = _size; i < new_size; ++i) {
                    new (new_data + i) T();
                    new_states[i] = State::busy;
                }
                for (size_t i = 0; i < _size; ++i) {
                    _data[i].~T();
                }
                ::operator delete(_data);
                delete[] _states;

                _data = new_data;
                _states = new_states;
                _capacity = new_capacity;
                _size = new_size;
            }
            catch (...) {
                for (size_t i = 0; i < new_size; ++i) {
                    new_data[i].~T();
                }
                ::operator delete(new_data);
                delete[] new_states;
                throw;
            }
        }
    }
    void resize(size_t new_size, const T& value) {
        if (new_size == _size) {
            return;
        } else if (new_size < _size) {
            for (size_t i = new_size; i < _size; ++i) {
                if (_states[i] == State::deleted) {
                    _deleted--;
                }
                _data[i].~T();
                _states[i] = State::empty;
            }
            _size = new_size;
        } else {
            size_t new_capacity = new_size + RESERVE_MEMORY;
            T* new_data = static_cast<T*>
                (::operator new(new_capacity * sizeof(T)));
            State* new_states = new State[new_capacity];
            for (size_t i = new_size; i < new_capacity; ++i) {
                new_states[i] = State::empty;
            }
            try {
                for (size_t i = 0; i < _size; ++i) {
                    new (new_data + i) T(std::move(_data[i]));
                    new_states[i] = _states[i];
                }
                for (size_t i = _size; i < new_size; ++i) {
                    new (new_data + i) T(value);
                    new_states[i] = State::busy;
                }
                for (size_t i = 0; i < _size; ++i) {
                    _data[i].~T();
                }
                ::operator delete(_data);
                delete[] _states;

                _data = new_data;
                _states = new_states;
                _capacity = new_capacity;
                _size = new_size;
            }
            catch (...) {
                for (size_t i = 0; i < new_size; ++i) {
                    new_data[i].~T();
                }
                ::operator delete(new_data);
                delete[] new_states;
                throw;
            }
        }
    }
    void shrink_to_fit() {
        if (_size >= _capacity) {
        } else if (_size == 0) {
            delete[] _data;
            delete[] _states;
            _data = nullptr;
            _states = nullptr;
            _capacity = 0;
            _deleted = 0;
        } else {
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
    }
    void reserve(size_t new_capacity) {
        if (new_capacity <= _capacity) {
            return;
        }
        T* new_data = new T[new_capacity];
        State* new_states = new State[new_capacity];
        std::fill_n(new_states, new_capacity, State::empty);
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
    void compact_storage() {
        size_t busy_count = 0;
        for (size_t i = 0; i < _size; ++i) {
            if (_states[i] == State::busy) {
                busy_count++;
            }
        }
        size_t new_capacity = busy_count + RESERVE_MEMORY;
        T* new_data = new T[new_capacity];
        State* new_states = new State[new_capacity];
        size_t new_index = 0;
        for (size_t i = 0; i < _size; ++i) {
            if (_states[i] == State::busy) {
                new_data[new_index] = std::move(_data[i]);
                new_states[new_index] = State::busy;
                new_index++;
            }
        }
        for (size_t i = 0; i < _size; ++i) {
            if (_states[i] != State::empty) {
                _data[i].~T();
            }
        }
        delete[] _data;
        delete[] _states;
        _data = new_data;
        _states = new_states;
        _capacity = new_capacity;
        _size = busy_count;
        _deleted = 0;
    }
    inline bool is_full() const noexcept {
        return _size == _capacity;
    }
 public:
    Tvector()  noexcept {
        _size = 0;
        _capacity = 0;
        _data = nullptr;
        _states = nullptr;
        _deleted = 0;
    }
    Tvector(size_t size) {
        _size = size;
        _capacity = size + RESERVE_MEMORY;
        _data = new T[_capacity];
        
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
    Tvector(T* data, size_t size) {
        if (size > 0 && data == nullptr) {
            throw std::invalid_argument("Null data pointer with non-zero size");
        }
        _size = size;
        _capacity = _size + RESERVE_MEMORY;
        _data = new T[_capacity];
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
            } else {
                _states[i] = State::empty;
            }
        }
        _deleted = 0;
    }
    Tvector(const Tvector<T>& other_vector) {
        _size = other_vector._size;
        _capacity = other_vector._capacity;
        _data = nullptr;
        _states = nullptr;
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
    ~Tvector() noexcept {
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

    inline const T* states() const noexcept {
        return _states;
    }
    inline T* states() noexcept {
        return _states;
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
    inline const T& front() const {
        if (_size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return _data[0];
    }
    inline const T& back() const {
        if (_size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return _data[_size - 1];
    }

    size_t size() const noexcept {
        return _size;
    }
    size_t deleted() const noexcept {
        return _deleted;
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

    bool operator==(const Tvector<T>& vector) const {
        if (this->_size != vector._size)
            return false;

        for (size_t i = 0; i < _size; ++i) {
            if ((*this)[i] != vector[i])
                return false;
        }
        return true;
    }
    bool operator!=(const Tvector<T>& vector) const {
        return !(*this == vector);
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

    T& at(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        if (_states[index] != busy) {
            throw std::logic_error
              ("Element at this index is not available (deleted or empty)");
        }
        return _data[index];
    }
    const T& at(size_t index) const {
        return const_cast<Tvector*>(this)->at(index);
    }
    void assign(size_t count, const T& value) {
        for (size_t i = 0; i < _size; ++i) {
            if (_states[i] == State::busy) {
                std::destroy_at(&_data[i]);
            }
            _states[i] = State::empty;
        }
        if (count > _capacity) {
            reserve(count);
        }
        for (size_t i = 0; i < count; ++i) {
            new (&_data[i]) T(value);
            _states[i] = State::busy;
        }
        _size = count;
        _deleted = 0;
    }
    void clear() {
        for (size_t i = 0; i < _size; ++i) {
            if (_states[i] == State::busy) {
                std::destroy_at(&_data[i]);
            }
            _states[i] = State::empty;
        }
        _size = 0;
        _deleted = 0;
    }
    void emplace(size_t index, const T& value) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        if (_states[index] == State::deleted) {
            --_deleted;
        }
        _data[index] = value;
        _states[index] = State::busy;
    }
    std::ostream& operator<<(std::ostream& out) {
        out << "[";
        size_t busy_count = 0;
        for (size_t i = 0; i < _size; ++i) {
            if (_states[i] == State::busy) {
                if (busy_count > 0) {
                    out << ", ";
                    busy_count++;
                }
                out << _data[i];
            }
        }
        out << "]";
        return out;
    }

    void push_front(const T& value) {
        if (_size >= _capacity) {
            reserve(_capacity + RESERVE_MEMORY);
        }
        for (size_t i = _size; i > 0; --i) {
            _data[i] = std::move(_data[i - 1]);
            _states[i] = _states[i - 1];
        }

        _data[0] = value;
        _states[0] = State::busy;
        _size++;
    }
    void insert(const T& value, size_t position) {
        if (position > _size) {
            throw std::out_of_range("Insert position out of range");
        }
        if (_size >= _capacity) {
            reserve(_capacity + RESERVE_MEMORY);
        }
        for (size_t i = _size; i > position; --i) {
            _data[i] = std::move(_data[i - 1]);
            _states[i] = _states[i - 1];
        }
        _data[position] = value;
        _states[position] = State::busy;
        _size++;
    }
    void push_back(const T& value) {
        if (_size >= _capacity) {
            reserve(_capacity + RESERVE_MEMORY);
        }
        _data[_size] = value;
        _states[_size] = State::busy;
        _size++;
    }

    void pop_back() {
        if (_size == 0) {
            return;
        }
            _data[_size - 1].~T();
            _states[_size - 1] = State::empty;
            _size--;
    }
    void erase(size_t position) {
        if (position >= _size) {
            throw std::out_of_range("Invalid position");
        }
        if (_size != 0) {
            if (_states[position] == State::busy) {
                _states[position] = State::deleted;
                _deleted++;
            }
            if (static_cast<float>(_deleted) / _size > MAX_PERCENT_DELETED / 100.0f) {
                compact_storage();
            }
        }
    }
    void pop_front() {
        if (_size == 0) {
            return;
        }
        for (size_t i = 0; i < _size; ++i) {
            if (_states[i] == State::busy) {
                _data[i].~T();
                _states[i] = State::deleted;
                _deleted++;
                if (static_cast<float>(_deleted) / _size > MAX_PERCENT_DELETED / 100.0f) {
                    compact_storage();
                }
                return;
            }
        }
    }
    friend void shell_sort(Tvector<T>& object) noexcept;
    friend void shuffle(Tvector<T>& object) noexcept;
    friend size_t find_first_element(const Tvector<T>& object, const T& value);
    friend size_t find_last_element(const Tvector<T>& object, const T& value);
    friend size_t find_count_of_all_suitable_elements(const Tvector<T>& object, const T& value);
};
template <class T>
void shell_sort(Tvector<T>& object) noexcept {
    if (object._size < 2 || object._data == nullptr 
       || object._states == nullptr) {
        return;
    }
    size_t h = 1;
    while (h < object._size / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (size_t i = h; i < object._size; ++i) {
            if (object._states[i] == object.State::deleted) {
                continue;
            }
            for (size_t j = i; j >= h; j -= h) {
                size_t previous = j - h;
                if (object._states[previous] == object.State::deleted) {
                    continue;
                }

                if (object._data[j] < object._data[previous]) {
                    std::swap(object._data[j], object._data[previous]);
                } else {
                    break;
                }
            }
        }
        h /= 3;
    }
}
template <class T>
void shuffle(Tvector<T>& object) noexcept {
    if (object._size < 2 || object._data == nullptr || object._states == nullptr) {
        return;
    }
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<size_t> valid_indices;
    for (size_t i = 0; i < object._size; ++i) {
        if (object._states[i] != object.State::deleted) {
            valid_indices.push_back(i);
        }
    }
    if (valid_indices.size() < 2) {
        return;
    }
    for (size_t i = valid_indices.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<size_t> dist(0, i);
        size_t j = dist(gen);
        std::swap(object._data[valid_indices[i]], object._data[valid_indices[j]]);
        std::swap(object._states[valid_indices[i]], object._states[valid_indices[j]]);
    }
}
template <class T>
size_t find_first_element(const Tvector<T>& object, const T& value) {
    size_t result = 0;
    for (size_t i = 0; i < object._size; i++) {
        if (object._states[i] == object.State::deleted) {
            continue;
        } else if (object._data[i] == value && object._states[i] == object.State::busy) {
            return result+1;
        }
        result++;
    }
    return 0; 
}
template <class T>
size_t find_last_element(const Tvector<T>& object, const T& value) {
    size_t last_pos = 0;
    size_t current_pos = 0;
    for (size_t i = 0; i < object._size; i++) {
        if (object._states[i] == object.State::deleted) {
            continue;
        }
        current_pos++;
        if (object._data[i] == value && object._states[i] == object.State::busy) {
            last_pos = current_pos;
        }
    }
    return last_pos;
}
template <class T> 
size_t find_count_of_all_suitable_elements(const Tvector<T>& object, const T& value) {
    size_t count = 0;
    for (size_t i = 0; i < object._size; ++i) {
        if (object._data[i] == value && object._states[i] == object.State::busy) {
            count++;
        }
    }
    return count;
}
