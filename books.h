#pragma once
#include <iostream>
#include <vector>
#include "book.h"
class Books {
	std::vector<Books> _books;
public:
	void add(); //�������� ������ �����
	void show_all();
	void delete_book(); //� �������� �������� id �����. ����� 
	void load();
	void save_all();
};
