#pragma once
#include "worker.h"
#include <iostream>
#include <vector>
class Workers {
	std::vector <Worker> _workers;
public:
	void add(); //добавить объект Сотрудник
	void show_all();
	void delete_reader(); //в аргумент передать id соотв. сотрудника
	void load();
	void save_all();
};
