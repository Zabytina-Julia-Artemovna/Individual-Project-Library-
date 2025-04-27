#pragma once
#include <iostream>
enum State { reserved, on_hand, free };
class Book {
	int _count;
	int _year_of_publication;
	int _id;
	std::string _title;
	std::string _author;
	std::string _publishing_house;
	std::string _language;
	State _state;
public:
	Book(int count, int year_of_publication, int id, std::string title, std::string author, std::string publishing_house, 
		 std::string language, State state) noexcept;
	Book(const Book& other_book) noexcept;
	int get_count() const noexcept;
	int get_year_of_publication() const noexcept;
	std::string& get_title() noexcept;
	std::string& get_author() noexcept;
	std::string& get_publishing_house() noexcept;
	std::string& get_language() noexcept;
	State& get_state() noexcept;
};