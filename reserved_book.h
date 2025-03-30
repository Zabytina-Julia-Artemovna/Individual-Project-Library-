#pragma once
#include "book.h"
#include <iostream>
class Reserved_book {
	Book _book;
	int _booking_code;
	int _readers_id;
	std::string _order_date;
	Reserved_book(const Book& book, int booking_code, int readers_id): _book(book), _booking_code(booking_code), _readers_id(readers_id){}
};
