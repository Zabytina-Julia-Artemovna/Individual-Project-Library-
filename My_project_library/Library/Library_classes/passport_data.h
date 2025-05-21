#pragma once
#include <cstddef> 
class Passport {
private:
    size_t _passport_number;
    size_t _passport_series;
public:
    Passport() : _passport_number(0), _passport_series(0) {}
    Passport(size_t number, size_t series) : _passport_number(number),
        _passport_series(series) {}
    Passport(const Passport& other) = default;
    size_t get_number() const {
        return _passport_number;
    }
    size_t get_series() const {
        return _passport_series;
    }
    void set_number(size_t number) {
        _passport_number = number;
    }
    void set_series(size_t series) {
        _passport_series = series;
    }
};
