#include "passport_data.h"
Passport::Passport(int number, int series) : _number(number), _series(series) {}
Passport::Passport(const Passport& other_passport) : _number(other_passport._number), _series(other_passport._series) {}
int Passport::get_number() const noexcept{
	return _number;
}
int Passport::get_series() const noexcept {
	return _series;
}