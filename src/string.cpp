#include <iostream>
#include "string.hpp"
using namespace list:

String::String(const String &s){
	head = from_string(s);
}


String::String(String &&s){
	head = s.head;
	s.head = nullptr
