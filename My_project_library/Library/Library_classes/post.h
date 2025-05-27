#pragma once
#include <string>
#include <cstddef> 
class Post {
private:
    std::string _post_name;
    size_t _salary;

public:
    Post(const std::string& post_name, size_t salary) :
        _post_name(post_name),
        _salary(salary) {}
    Post(const Post& other) = default;
    const std::string& get_post_name() const {
        return _post_name;
    }
    size_t get_salary() const {
        return _salary;
    }
    void set_post_name(const std::string& post_name) {
        _post_name = post_name;
    }
    void set_salary(size_t salary) {
        _salary = salary;
    }
};