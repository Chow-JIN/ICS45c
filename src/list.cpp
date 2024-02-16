#include "list.hpp"
#include <iostream>




namespace list{


Node* from_string(const char* s){
	if (!s || s[0] == '\0') {
		return nullptr;
	}
	Node* head = new Node{.data=*s, .next=nullptr};	
	Node* p = head;
	++s;
	while (*s != '\0') {
		p->next = new Node{.data=*s, .next=nullptr};
		p = p->next;
		++s;
	}
			
	return head;
}


void free(Node* head){
    if (!head)
        return;
    free(head->next); 
    delete head; 
    return;
}



void print(std::ostream &out, Node* head){
	for (; head != nullptr; head = head->next){
        out << head->data;
	}
}



Node* copy(Node* head){
	if(head == nullptr){
		return nullptr;
	}		
	Node* p = new Node(head->data, list::copy(head->next));
	return p;
}



int compare(Node* lhs, Node* rhs){
	for(; lhs!=nullptr && rhs!=nullptr; lhs=lhs->next, rhs=rhs->next)
        if(lhs->data != rhs->data)
            return lhs->data - rhs->data;
    if(!lhs && !rhs)
        return 0;
    else if(!rhs)
        return 1;
    else
        return -1;
}



int compare(Node* lhs, Node* rhs, int n){
	for(; lhs!=nullptr && rhs!=nullptr && n>0; lhs=lhs->next, rhs=rhs->next, --n)
        if(lhs->data != rhs->data)
            return lhs->data - rhs->data;
    if(n == 0)
        return 0;
    else if(!lhs && !rhs)
        return 0;
    else if(!rhs)
        return 1;
    else
        return -1;
}


int length(Node* head){
	if(head == nullptr){
		return 0;
	}
	int count = 0;
	Node*p = head;
	for( ; p != nullptr; p = p->next)
		++count;
	return count;
}




Node* reverse(Node* head){
	if(head == nullptr){
		return nullptr;
	}
	Node* current = head;
	Node* next = nullptr;
	Node* last = nullptr;
	while(current != nullptr){
		next = current->next;
        current->next = last;
        last = current;
        current = next;
    }
    return last;
}




Node* append(Node* lhs, Node* rhs){
	if(lhs == nullptr && rhs == nullptr){
		return nullptr;
	}
	else if(lhs == nullptr && rhs != nullptr){
		return list::copy(rhs);
	}
	else if(lhs != nullptr && rhs == nullptr){
		return list::copy(lhs);
	}
	else{
		Node* l = list::copy(lhs);
		Node* r = list::copy(rhs);
		last(l)->next = rhs;
		return l;
	}
}



int index(Node* head, Node* node){
	if(head == nullptr)
		return -1;
	int i = 0;
    for(Node* p=head; p!=nullptr; p=p->next, ++i)
        if(p == node)
            return i;
    return -1;
}





Node* find_char(Node* head, char c){

    for(Node* p=head; p!=nullptr; p=p->next)
        if(p->data == c)
            return p;
	return nullptr;
}


Node* find_list(Node* haystack, Node* needle){

	int len = list::length(needle);
	if (len == 0){
		return haystack;
	}
    if (haystack == nullptr){
		return nullptr;
	}
	for(Node* p=haystack; p!=nullptr; p=p->next)
		if(list::compare(p, needle, len) == 0){
			return p;
		}
	return nullptr;
}


Node* nth(Node* head, int n){
	if (n == 0)
		return head;
	return nth(head->next, n-1);
}
	


Node* last(Node* head){

	if (head==nullptr){
		return nullptr;
	}
	
	Node* p = head;
	
	while (p->next != nullptr) {
		p = p->next;
	}
	return p;

}


}

