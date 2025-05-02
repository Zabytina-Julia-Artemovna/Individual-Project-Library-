#include "fio.h"
FIO::FIO(std::string name, std::string last_name, std::string first_name) : _name(name), _last_name(last_name), _first_name(first_name) {}
FIO::FIO(const FIO& other) : _name(other._name), _last_name(other._last_name), _first_name(other._first_name) {}
std::string& FIO::get_name() {
	return _name;
}
std::string& FIO::get_last_name() {
	return _last_name;

}
std::string& FIO::get_first_name() {
	return _first_name;

}