#pragma once
#include <iostream>

class FIO {
private:
    std::string _last_name;
    std::string _name;
    std::string _first_name;

public:
    FIO() : _last_name("Ivanov"), _name("Ivan"), _first_name("Ivanovich") {}
    FIO(std::string name, std::string last_name, std::string first_name) :
        _last_name(last_name), _name(name), _first_name(first_name) {}
    FIO(const FIO& other) :
        _last_name(other._last_name),
        _name(other._name),
        _first_name(other._first_name) {}
    std::string get_name() const {
        return _name;
    }
    std::string get_last_name() const {
        return _last_name;
    }
    std::string get_first_name() const {
        return _first_name;
    }
    void set_name(std::string name) {
        _name = name;
    }
    void set_last_name(std::string last_name) {
        _last_name = last_name;
    }
    void set_first_name(std::string first_name) {
        _first_name = first_name;
    }
};
