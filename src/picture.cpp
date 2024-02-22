#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture():head(nullptr), tail(nullptr){}



Picture::Picture(const Picture& other):head(nullptr), tail(nullptr){
	if(other.head != nullptr)
		head = copy(other.head);
}



Picture::Picture(Picture&& other){
	swap(other);
	other.head = nullptr;
	other.tail = nullptr;


}



void Picture::swap(Picture& other){
	std::swap(head, other.head);
    std::swap(tail, other.tail);
}



Picture& Picture::operator=(const Picture& other){
	if(this == &other){
		return *this;
	}

	tail = nullptr;
	free(head);
	head = copy(other.head);
    	return *this;



}


Picture& Picture::operator=(Picture&& other){
	if (this == &other)
        return *this;
    free(head);
    head = other.head;
	tail = other.tail;
    other.head = nullptr;
	other.tail = nullptr;
    return *this;


}



void Picture::add(const Shape& shape){
	if (head == nullptr)
    {
        head = new ListNode{shape.clone(), nullptr};
        tail = head;
    }
    else
    {
        ListNode* p = new ListNode{shape.clone(), nullptr};
        tail->next = p;
        tail = p;
    }


}



void Picture::print_all(std::ostream& out) const{
for (ListNode* p = head; p!=nullptr; p = p->next){
        p->shape->print(out);
	p->shape->draw(out);
	}


}



void Picture::draw_all(std::ostream& out) const{
	for (ListNode* p = head; p!=nullptr; p = p->next){
        p->shape->draw(out);
	}

}



double Picture::total_area() const{
	double total = 0.00;
    for (ListNode* p=head; p!=nullptr; p=p->next)
        total += p->shape->area();
    return total;

}


Picture::ListNode* Picture::copy(ListNode* head)
{
    if(!head)
        return nullptr;
    return new ListNode{head->shape->clone(), copy(head->next)};
}




Picture::~Picture(){

	free(head);

}
