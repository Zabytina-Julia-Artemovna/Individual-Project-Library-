#pragma once
#include "worker.h"
#include <iostream>
#include <vector>
class Workers {
	std::vector <Worker> _workers;
public:
	void add(); //�������� ������ ���������
	void show_all();
	void delete_reader(); //� �������� �������� id �����. ����������
	void load();
	void save_all();
};
