// address_book.cpp
// Implementation of the AddressBookEntry class
#include "address-book.h"
#include <memory>
using std::make_shared;
using std::make_unique;
using std::unique_ptr;

// AddressBookEntry Constructor
AddressBookEntry::AddressBookEntry(	const Person& person,
								   const string& image_filename)
								   :_person(person)
{
	// dynamically allocate memory for the image
	if (image_filename != "") {
		// ignore (for now) what will happen if there is a memory allocation failure
        _image_ptr = make_shared<Image>(image_filename);
	}
}

string AddressBookEntry::getImageName() const
{
	if (_image_ptr != nullptr)
		return _image_ptr->name();
	else return "No image!";
}

void AddressBookEntry::setImageName(string newname)
{
	if (_image_ptr != nullptr) _image_ptr->name(newname);
}


//Exercise 4.3
AddressBookEntry::AddressBookEntry(const AddressBookEntry& rhs) : _person(rhs._person)
{
	if (rhs.getImageName() != "") 
	{
		_image_ptr = make_unique<Image>(rhs.getImageName());
	}

	//if (image_filename != "") 
	//{
	//	_image_ptr = make_shared<Image>(image_filename);
	//	_image_ptr = make_unique<Image>(image_filename);
	//}

	unique_ptr<Image> _image_ptr;
}
