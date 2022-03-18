#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iostream>
#include "../iterators.hpp"

namespace ft
{
	template <class T>
	class vectorIterator {
		public :
			typedef T iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference reference;
			typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
			
			vectorIterator(){ };
			vectorIterator(pointer ptr) : current(ptr) {};
			template <class U>
			vectorIterator(const vectorIterator<U> &src) : current(src.base()) {};
			~vectorIterator() {};

			vectorIterator &operator=(const vectorIterator& src) {
				current = src.base();
				return (*this);
			};
			
			// ---------Increment/Decrement---------
			vectorIterator &operator++(void) {
				current++;
				return (*this);
			}
			vectorIterator operator++(int) {
				vectorIterator tmp = *this;
				current++;
				return (tmp);
			}
			vectorIterator &operator--(void) {
				current--;
				return (*this);
			}
			vectorIterator operator--(int) {
				vectorIterator tmp = *this;
				current--;
				return (tmp);
			}
			
			// -----------Arithmetic operators---------
			vectorIterator operator+(difference_type n){ return (vectorIterator(current + n)); };
			vectorIterator operator-(difference_type n){ return (vectorIterator(current - n)); };
			difference_type operator+(vectorIterator b){ return (current + b.current); };
			difference_type operator-(vectorIterator b){ return (current - b.current); };

			vectorIterator &operator+=(difference_type n) {
				current += n;
				return (*this);
			};
			vectorIterator &operator-=(difference_type n) {
				current -= n;
				return (*this);
			};

			// -----------Dereferencing/Address----------
			reference operator [](difference_type n) const { return (*(current + n)); };
			pointer operator ->() { return (current); };
			// const pointer operator ->() const { return (current); };
			reference operator*() { return *current; };
			const reference operator*() const { return *current; };
			iterator_type base() const { return (current); };
			// const iterator_type base() const { return (current); }
		private :
			iterator_type current;
	};

	template <class T>
    bool operator== (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return (lhs.base() == rhs.base()); }
    template <class T>
    bool operator!= (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return (lhs.base() != rhs.base()); }
    template <class T>
    bool operator<  (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return (lhs.base() < rhs.base()); }
    template <class T>
    bool operator<= (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return (lhs.base() <= rhs.base()); }
    template <class T>
    bool operator>  (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return (lhs.base() > rhs.base()); }
    template <class T>
    bool operator>= (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return (lhs.base() >= rhs.base()); }


	
}

#endif