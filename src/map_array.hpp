#ifndef MAP_ARRAY_HPP
#define MAP_ARRAY_HPP

#include <algorithm>
#include <iterator>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>

using namespace std;

template <typename Key, typename Value>
class MapArray {
public:     


    class ArrayIterator {
    public:
        using iterator_category = random_access_iterator_tag; 
        using value_type = typename MapArray<Key, Value>::value_type;
        using difference_type = ptrdiff_t;
        using pointer = value_type*;
        using reference =value_type&;


        explicit ArrayIterator(pair<Key, Value>* ptr = nullptr):ptr(ptr){

		}


        ArrayIterator& operator++() {
			++ptr;
			return *this;

		}

        ArrayIterator& operator--() {
			--ptr;
			return *this;


		}
        ArrayIterator operator++(int) {
			ArrayIterator p = *this;
			++ptr;
			return p;
	


		}
        ArrayIterator operator--(int) { 
			ArrayIterator p = *this;
			--ptr;
			return p;


		}
        ArrayIterator& operator +=(difference_type d) { 
			ArrayIterator p = *this;
			ptr += d;
			return p;


		}
        ArrayIterator& operator -=(difference_type d) { 
			ArrayIterator p = *this;
			ptr -= d;
			return p;


		}
        friend ArrayIterator operator+(ArrayIterator it, difference_type d) { 
       		return ArrayIterator(it.ptr + d);


	    }
        friend ArrayIterator operator+(difference_type d, ArrayIterator it) { 
       		return ArrayIterator(it.ptr + d);


	    }
        friend ArrayIterator operator-(ArrayIterator it, difference_type d) { 
       		return ArrayIterator(it.ptr - d);


	    }
        friend difference_type operator-(ArrayIterator lhs, ArrayIterator rhs) { 
       		return lhs.ptr - rhs.ptr;


	    }

        auto operator<=>(const ArrayIterator& other) const = default;



        std::pair<Key, Value>& operator*() const {
			return *ptr;

		}
        std::pair<Key, Value>* operator->() const {
			return ptr;

		}


		std::pair<Key, Value>& operator[] (difference_type d) const { 
			return *(ptr + d);


		}
    private:
        std::pair<Key, Value>* ptr;
    };
   

    using value_type = pair<Key, Value>;
    using iterator = ArrayIterator;



    ArrayIterator begin() { 
		if (data.size()){
			return ArrayIterator(data.data());
		}
		else{
			return ArrayIterator();
		}

	}
    ArrayIterator end() { 
		if (data.size()){
			return ArrayIterator(&data[data.size()]);
		}
		else{
			return ArrayIterator();
		}

	}
    Value& operator[] (const Key& key) 
    {
		auto i = std::lower_bound(data.begin(), data.end(), key, [](const auto& pair, const auto& k) {
                               return pair.first < k;
                           });

		if (i != data.end() && i->first == key) {
   			 return i->second;
		} else {
   			 return data.insert(i, {key, Value()})->second;
		}


    }
private:
    std::vector<std::pair<Key, Value>> data;
	static_assert(std::random_access_iterator<iterator>);
};

#endif
