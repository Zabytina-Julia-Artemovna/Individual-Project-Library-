#pragma once
#include "person.h"
#include "readers_ticket.h"
class Reader : public Person {
	Ticket _readers_ticket;
public:
	int get_id(); //получить id билета
};