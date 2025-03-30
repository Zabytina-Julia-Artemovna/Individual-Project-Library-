#pragma once
#include <iostream>
class FIO {
	std::string _last_name;
	std::string _first_name;
	std::string _second_name;
public:
	FIO(const std::string& last_name, const std::string& first_name, 
		const std::string& second_name): _last_name(last_name), _first_name(first_name), _second_name(second_name){}
};
