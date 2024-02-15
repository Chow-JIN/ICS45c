#include "list.hpp"
#include <iostream>
using namespace list;

Node* from_string(const char* s){
	Node* head = nullptr;
    for (int i = strlen(s)-1; i >= 0; --i) {
        Node* new_node = new Node;
        new_node->data = s[i];
        new_node->next = head;
        head = new_node;
    }
    return head;
}


void free(Node* head){
	while(head != nullptr){
		Node* current = head;
		delete current;
		head = head->next;
	}
}



void print(std::iostream &out, Node& head){
	for (; head != nullptr; head = head->next){
        out << head->data;
	}
}



Node* copy(Node* head){
	if(head == nullptr){
		return nullptr;
	}		
	Node* p = new Node(head->data, copy(head->next))
	return p;
}



int compare(Node* lhs, Node* rhs){
	if (lhs == nullptr && rhs == nullptr){
        return 0;
    } 
	else if (lhs == nullptr){
        return -1;
    } 
	else if (rhs == nullptr){
        return 1;
    } 
	else {
        for(; lhs!=nullptr && rhs!=nullptr; lhs=lhs->next, rhs=rhs->next)
        	if(lhs->data != rhs->data)
            	return lhs->data - rhs->data;
    }
}



int compare(Node* lhs, Node* rhs, int n){
	if (lhs == nullptr && rhs == nullptr) {
        return 0;
    } 
	else if (lhs == nullptr) {
        return -1;
    } 
	else if (rhs == nullptr) {
        return 1;
	}
	else is (n == 0) {
		return 0
    } 
	else {
        for(; lhs!=nullptr && rhs!=nullptr && n>0; lhs=lhs->next, rhs=rhs->next, --n)
        	if(lhs->data != rhs->data)
            	return lhs->data - rhs->data;
    }



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
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}




Node* append(Node* lhs, Node* rhs){
	if(lhs == nullptr && rhs == nullptr){
		return nullptr;
	}
	else if(lhs == nullptr && rhs != nullptr){
		return copy(rhs);
	}
	else if(lhs != nullptr && rhs == nullptr){
		return copy(lhs);
	}
	else{
		Node* l = copy(lhs);
		Node* r = copy(rhs);
		last(l)->next = rhs;
		return l
	}
}



int index(Node* head, Node* node){
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
}


Node* find_list(Node* haystack, Node* needle){

	int len = length(needle);
	if (len == 0){
		return haystack;
	}
    if (haystack == nullptr){
		return nullptr;
	}
	for(Node* p=haystack; p!=nullptr; p=p->next)
		if(compare(p, needle, len) == 0){
			return p;
		}
	return nullptr;
}


Node* nth(Node* head, int n){
	if(n == 0){
		return head;
	}
	Node* p = head;
	int count = 1;
	while(p != nullptr){
		if(count == n){
			return p;
			break;
		}
		p = p->next;
}
	


Node* last(Node* head){

	if (head==nullptr){
		return nullptr
	}
	
	Node* p = head;
	
	while (p->next != nullptr) {
		p = p->next;
	}
	return p;

}




