
#ifndef SET_LIST_HPP
#define SET_LIST_HPP

#include <algorithm> 
#include <functional>
#include <iterator>
#include <memory>
#include <ranges>
using namespace std;

template <typename T>
class SetList {
    struct ListNode {
        T data;
        std::shared_ptr<ListNode> next;
    };

public:

  
    class ListIterator {
    public:
		
        using iterator_category = forward_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;
        
        explicit ListIterator(std::shared_ptr<ListNode> ptr = nullptr):ptr(ptr)
        {
        }

        ListIterator& operator++()
        {
			ptr = ptr->next;
       		return *this; 
        }

        ListIterator operator++(int)
        {
			ListIterator i = ptr;
			++(ptr);
       		return  i;
        }

        T& operator*() const {
			return ptr->data;

		}
        T* operator->() const {
			return ptr;

		}
        bool operator==(const ListIterator& other) const = default;


    private:
        std::shared_ptr<ListNode> ptr;
    };
    
	using value_type = T;
	using iterator = ListIterator;


    SetList() = default;

    template <std::ranges::input_range Rng>
    explicit SetList(Rng&& rng)
    {
        std::ranges::for_each(std::forward<Rng>(rng),
                                std::bind_front(&SetList::insert, this) );
    }
    ListIterator begin(){
		return ListIterator(head);


	}
    ListIterator end() {
		return ListIterator(nullptr);


	}

    bool contains(T const& value)
    {
		for(shared_ptr<ListNode> p = head; p != nullptr; p = p->next)
			if(p->data == value)
				return true;

		return false;
     
    }

    ListIterator insert(T value){


		if(!contains(value))
		{
		
			head = std::make_shared<ListNode>(move(value), head);

		}
		return ListIterator(head);        
    }
private:

    std::shared_ptr<ListNode> head = nullptr;
};

#endif
