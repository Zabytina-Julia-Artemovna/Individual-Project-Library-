#include "book.h"
Book::Book(int count, int year_of_publication, int id, std::string title, std::string author, std::string publishing_house,
	std::string language, State state) noexcept : _count(count), _year_of_publication(year_of_publication), _id(id),
	_title(title), _author(author), _publishing_house(publishing_house), _language(language), _state(state) {}
Book::Book(const Book& other_book) noexcept : _count(other_book._count), _year_of_publication(other_book._year_of_publication), _id(other_book._id),
_title(other_book._title), _author(other_book._author), _publishing_house(other_book._publishing_house),
_language(other_book._language), _state(other_book._state) {}
int Book::get_count() const noexcept {
	return _count;
}
int Book::get_year_of_publication() const noexcept {
	return _year_of_publication;
}
std::string& Book::get_title() noexcept {
	return _title;
}
std::string& Book::get_author() noexcept {
	return _author;
}
std::string& Book::get_publishing_house() noexcept {
	return _publishing_house;
}
std::string& Book::get_language() noexcept {
	return _language;
}
State& Book::get_state() noexcept {
	return _state;
}