#pragma once
#include <iostream>
class Post {
	int _salary;
	std::string _post_name;
public:
	Post(int salary, const std::string& post_name): _salary(salary), _post_name(post_name) {}
};
