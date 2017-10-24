#include "date.h"
#include "address-book.h"
#include "person.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


//Exercise 3.1
//there are no pointer data members, hence no states are shared
TEST_CASE("No state shared between a Date and its copy") {
	// calls constructor
	Date current_day{1, Month::January, 2003}; 
	// calls default constructor
	Date next_day; 
	// calls assignment operator
	next_day = current_day; 
	next_day.addDay();

	CHECK_FALSE(current_day == next_day);
}
