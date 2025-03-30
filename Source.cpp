#include "csv_reader.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
bool csv_reader::read() {
	std::ifstream file(_file_path);
	if (!file.is_open()) {
		std::cerr << "Ошибка. Не удалось открыть файл";

	}
}


