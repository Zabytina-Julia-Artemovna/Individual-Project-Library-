#pragma once
#include <vector>
#include <string>
class csv_reader {
	std::string _file_path;
	char _separator;
	std::vector<std::vector<std::string>> _data;
public:
	explicit csv_reader(const std::string& file_path, char separator = ';')//explicit запрещает неявное преобр. типов
		: _file_path(file_path), _separator(separator) {}
	bool read();
};
