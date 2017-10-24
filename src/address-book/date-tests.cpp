#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// Comment out this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
TEST_CASE("Date has uninitialised state") {	 
    // make some prior memory allocations - which will be the case in a typical program
    auto i = {1.0,1.3,1.4,1.5,1.6,1.7,1.8,1.9,10.2,11.0,1.2,1.3,1.23};
    auto i2 = 1.0;
    
    Date today;	
    std::cout << "Today is: " << endl;
    printDate(today);
}

//Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	Date heritage_day{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.
TEST_CASE("Invalid Date Tests") {
	try 
	{
		Date date_1(-1, Month::January, -1);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error" << endl;
			break;
		}
	}
}

TEST_CASE("Identical Dates are Equal") {
	try 
	{
		Date date_2(31, Month::February, 2000);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error" << endl;
			break;
		}
	}
}
TEST_CASE("Identical Dates are Equal") {
	try 
	{
		Date date_3(32, Month::January, 2000);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error" << endl;
			break;
		}
	}
}
TEST_CASE("Identical Dates are Equal") {
	try 
	{
		Date date_4(31, Month::June, 2000);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error" << endl;
			break;
		}
	}
}
TEST_CASE("Identical Dates are Equal") {
	try 
	{
		Date date_5(1, Month::January, 2000);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error" << endl;
			break;
		}
	}
}


// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2000);

    CHECK(date_1 == date_2);
}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(2, Month::January, 2000);

    CHECK( !(date_1 == date_2) );
}
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::February, 2000);

    CHECK( !(date_1 == date_2) );
}
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2002);

    CHECK( !(date_1 == date_2) );
}


// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.
TEST_CASE("Add day") {
    Date date_1(1, Month::January, 2000);
	try 
	{
		date_1.addDay();
		printDate(date_1);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error day add: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error day add: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error day add" << endl;
			break;
		}
	}
}

TEST_CASE("Add day when new month") {
    Date date_1(31, Month::December, 2000);
	try 
	{
		date_1.addDay();
		printDate(date_1);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error day add: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error day add: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error day add" << endl;
			break;
		}
	}
}

TEST_CASE("Add day when new year") {
    Date date_1(29, Month::February, 2000);
	try 
	{
		date_1.addDay();
		printDate(date_1);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error day add: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error day add: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error day add" << endl;
			break;
		}
	}
}

// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
TEST_CASE("Default constructor works") {
	try 
	{
		Date date_1;
		printDate(date_1);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error day add: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error day add: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error day add" << endl;
			break;
		}
	}
}

TEST_CASE("Default constructor works with changing default date") {
	try 
	{
		Date date_1;
		date_1.setDefaultDate(1, Month::January, 2000);
		Date date_2;
		printDate(date_1);
		printDate(date_2);
	}
	catch(InvalidDate e)//error to catch
	{
		switch (e)
		{
			case InvalidDate::NegativeDate:
			//stuff
				cout << "Error day add: The day and/ or year is negative" << endl;
			break;
			case InvalidDate::ExcessiveDays:
			//stuff
				cout << "Error day add: The day entered exceed the amount for the specified month" << endl;
			break;
			default:
			//stuff
				cout << "Unknown Error day add" << endl;
			break;
		}
	}
}