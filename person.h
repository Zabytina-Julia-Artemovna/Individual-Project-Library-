#pragma once
#include <iostream>
#include "passport_data.h"
#include "fio.h"
class Person {
	std::string _number_of_phone;
	std::string _date_of_birth;
	Passport _passport;
	FIO _person_name;
};
