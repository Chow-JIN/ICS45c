#include <iostream>
#include "string.hpp"
#include "list.hpp"
using namespace list;


String::String(const char* s){
	head = from_string(s);
}





String::String(const String &s){
	head = copy(s.head);
}



String::String(String &&s){
	head = nullptr;
	swap(s);
	s.head = nullptr;
}



void String::swap(String &s)
{
	std::swap(head, s.head);
}




String &String::operator=(const String &s)
{
	if(this == &s){
		return *this;
	}
	if(head){
		free(head);
	}
	head = copy(s.head);
	return *this;
}

String &String::operator=(String &&s)
{
    if (this == &s){
        return *this;
	}
    free(head);
    head = s.head;
    s.head = nullptr;

    return *this;
}

 bool String::in_bounds(int index) const
{
    return index >= 0 && index < size();
}

char String::operator[] (int index) const
{
	if (!in_bounds(index))
	{
		std::cout << "ERROR: Index Not In Bounds" << std::endl;
		return '\0';
	}
	return nth(head, index)->data;
}

int String::size() const
{
	return length(head);
}

String String::reverse() const
{
	Node* p = list::reverse(head);
	return String(p);
}

int String::indexOf(char c) const
{
	return index(head, find_char(head, c));
}

int String::indexOf(const String &s) const
{
	return index(head, find_list(head, s.head));
}

bool String::operator==(const String &s) const
{
	return compare(head, s.head) == 0;
}


std::strong_ordering String::operator<=>(const String &s) const
{
    return compare(head, s.head) <=> 0;
}

String String::operator+(const String &s) const
{
    return String(append(head, s.head));
}

String &String::operator+=(const String &s)
{
	Node* p = copy(s.head);
    last(head)->next = p;
    return *this;
}

void String::print(std::ostream &out) const
{
    list::print(out, head);
}

void String::read(std::istream &in)
{
    char c[6666];
    in >> c;
    String s(c);
    swap(s);
}

String::~String()
{
    free(head);
}

String::String(Node* head): head(head){
}


std::ostream &operator<<(std::ostream &out, const String &s)
{
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s)
{
    s.read(in);
    return in;
}



