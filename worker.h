#pragma once
#include <iostream>
#include "person.h"
#include "post.h"
class Worker : public Person {
	std::string _date_of_start_working;
	Post _post_of_worker;
	int _personal_boost_factor;
	int _worker_id;
	Worker(std::string date_of_start_working, const Post& post_of_worker, int personal_boost_factor);
};
