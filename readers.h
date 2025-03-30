#pragma once
#include <iostream>
#include <vector>
#include "reader.h"
class Readers {
	std::vector<Reader> _readers;
public:
	void add(); //добавить объект Читатель
	void show_all();
	void delete_reader(); //в аргумент передать id билета соотв. читателя
	void load();
	void save_all();
};
