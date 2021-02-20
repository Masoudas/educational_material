/**
* Element access: operator[], at, front, back, data (see string: element access)
* Capacity: size, length, max_size, empty (see string: size versus capacity)
* Find: find, rfind, find_first_of, find_last_of, find_first_not_of, find_last_not_of (see string: search)
* Copy: copy (see string: conversion between a C++-string and a C-String). Returns the C equivalent of the 
* string.
*/

#include <string_view>

void copy_string_view() {
	std::string_view str{ "abc" };

	char* ptr = nullptr;
	str.copy(ptr, 0);
}