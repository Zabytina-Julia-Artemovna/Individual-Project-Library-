#pragma once
#define RESERVE 256
#include <stdexcept>
#include <exception>
#include <random>
#include <iostream>
#include <utility>
#include <memory>
#include <algorithm>
enum State {
    empty, busy, deleted
};
template <class T>
class Tvector {
    static_assert(std::is_nothrow_move_constructible_v<T>,
        "T must have noexcept move constructor");
    static_assert(std::is_default_constructible_v<T>,
        "T must be default-constructible");

 private:
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
            size_t new_capacity = new_size + RESERVE;
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
        }
        else if (new_size < _size) {
            for (size_t i = new_size; i < _size; ++i) {
                if (_states[i] == State::deleted) {
                    _deleted--;
                }
                _data[i].~T();
                _states[i] = State::empty;
            }
            _size = new_size;
        }
        else {
            size_t new_capacity = new_size + RESERVE;
            T* new_data = static_cast<T*>(::operator new(new_capacity * sizeof(T)));
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
        }
        else if (_size == 0) {
            delete[] _data;
            delete[] _states;
            _data = nullptr;
            _states = nullptr;
            _capacity = 0;
            _deleted = 0;
        }
        else {
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
    inline bool is_full() const noexcept {
        return _size == _capacity;
    }

 public:
    Tvector() noexcept {
        _size = 0;
        _capacity = 0;
        _data = nullptr;
        _states = nullptr;
        _deleted = 0;
    }
    Tvector(size_t size) {
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
    Tvector(T* data, size_t size)
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
            throw std::logic_error("Element at this index is not available (deleted or empty)");
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
};