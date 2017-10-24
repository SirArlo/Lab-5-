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

//Exercise 4.1
//there are pointer data members, through this copy method no states are shared
TEST_CASE("No state shared between an AddressBookEntry and its copy") {
	Person Gatsby{"JayGatz", 12};
	Person Daisy{"Daisy", 10};

	// calls constructor
	AddressBookEntry AddressGatsby{Gatsby, "West Egg"}; 
	// copies object
	AddressBookEntry AddressDaisy{AddressGatsby};

	AddressGatsby.setPerson(Daisy);
	AddressGatsby.setImageName("East Egg");

	CHECK_FALSE(AddressGatsby.getImageName() == AddressDaisy.getImageName());
}

//Exercise 4.2
//there are pointer data members, through this copy method no states are shared and if a value is changed in the one then it will change in the other
//this is due to the pointer accessing the same data and as a result the image names are constant
TEST_CASE("No state shared between an AddressBookEntry and its copy through assignment operation") {
	Person Gatsby{"JayGatz", 12};
	Person Daisy{"Daisy", 10};

	// calls constructor
	AddressBookEntry AddressGatsby{Gatsby, "West Egg"}; 
	// copies object
	AddressBookEntry AddressDaisy = AddressGatsby;

	AddressGatsby.setPerson(Daisy);
	AddressGatsby.setImageName("East Egg");

	CHECK_FALSE(AddressGatsby.getImageName() == AddressDaisy.getImageName());
}