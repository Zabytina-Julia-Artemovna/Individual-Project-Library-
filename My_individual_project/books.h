#pragma once
#include <iostream>
#include <vector>
#include "book.h"
class Books {
	std::vector<Books> _books;
public:
	void add(); //добавить объект  нига
	void show_all();
	void delete_book(); //в аргумент передать id соотв. книги 
	void load();
	void save_all();
};
