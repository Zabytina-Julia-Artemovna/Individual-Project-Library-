#pragma once
#include <string>
struct FIO {
    std::string _last_name;
    std::string _name;
    std::string _first_name;
    FIO(const std::string& name, const std::string& last_name, const std::string& first_name) :
        _last_name(last_name),
        _name(name),
        _first_name(first_name) {}
    FIO(const FIO& other) = default;
    const std::string& get_name() const {
        return _name;
    }
    const std::string& get_last_name() const {
        return _last_name;
    }
    const std::string& get_first_name() const {
        return _first_name;
    }
    void set_name(const std::string& name) {
        _name = name;
    }
    void set_last_name(const std::string& last_name) {
        _last_name = last_name;
    }
    void set_first_name(const std::string& first_name) {
        _first_name = first_name;
    }
};
