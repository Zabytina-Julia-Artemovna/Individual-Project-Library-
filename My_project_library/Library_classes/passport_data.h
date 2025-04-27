#pragma once
class Passport {
	int _number;
	int _series;
public:
	Passport(int number, int series) noexcept;
	Passport(const Passport& other_passport) noexcept;
	int get_number() const noexcept;
	int get_series() const noexcept;
};