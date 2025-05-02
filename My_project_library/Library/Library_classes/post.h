#pragma once
#include <iostream>
#include <string>
class Post {
	std::string _name_of_post;
	int _salary;
public:
	Post(std::string name_of_post, int salary) noexcept;
	Post(const Post& other_post) noexcept;
	int get_salary() const noexcept;
	std::string& get_name_of_post() noexcept;
};
