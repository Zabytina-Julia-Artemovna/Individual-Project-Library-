#pragma once
#include <vector>
#include <iostream>
#include "reserved_book.h"
class Ticket {
	int _ticket_id;
	std::vector <Reserved_book> _reserved_books;
	//����� �� ����� - ?

	int get_ticket_id();
};
