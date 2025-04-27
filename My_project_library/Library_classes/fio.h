#pragma once
#include <iostream>
class FIO {
	std::string _name;
	std::string _last_name;
	std::string _first_name;
public:
	FIO(std::string name, std::string last_name, std::string first_name);
	FIO(const FIO& other);
	std::string& get_name();
	std::string& get_last_name();
	std::string& get_first_name();
};