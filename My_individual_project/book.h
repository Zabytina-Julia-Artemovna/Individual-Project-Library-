#pragma once
#include <iostream>
class Book {
	std::string _author;
	std::string _publishing_house;
	std::string _book_title;
	std::string _language;
	std::string _book_status;
	int _year_of_publication;
	int _number_of_books;
	int _book_id;
public:
	Book(std::string author, std::string publishing_house,
		std::string book_title, std::string language,
		std::string book_status, int year_of_publication,
		int number_of_books, int book_id) : _author(author), _publishing_house(publishing_house),
			_book_title(book_title), _language(language), _book_status(book_status),
			_year_of_publication(year_of_publication), _number_of_books(number_of_books), _book_id(book_id) {}
	int get_book_id();
};