#pragma once
#include <iostream>
#include <vector>
#include "reader.h"
class Readers {
	std::vector<Reader> _readers;
public:
	void add(); //�������� ������ ��������
	void show_all();
	void delete_reader(); //� �������� �������� id ������ �����. ��������
	void load();
	void save_all();
};
