#include "post.h"
Post::Post(std::string name_of_post, int salary) noexcept : _name_of_post(name_of_post), _salary(salary) {}
Post::Post(const Post& other_post) noexcept : _name_of_post(other_post._name_of_post), _salary(other_post._salary) {}
int Post::get_salary() const noexcept {
	return _salary;
}
std::string& Post::get_name_of_post() noexcept {
	return _name_of_post;
}