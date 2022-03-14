#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iostream>
#include "../iterators.hpp"

namespace ft
{
	template <class T>
	class vectorIterator {
		public :
			typedef T* pointer;
			typedef T& reference;
			// typedef typename iterator_traits<T>::pointer pointer;
			// typedef typename iterator_traits<T>::reference reference;
			typedef typename iterator_traits<pointer>::difference_type difference_type;
			typedef typename iterator_traits<pointer>::value_type value_type;
			typedef typename iterator_traits<pointer>::iterator_category iterator_category;
			
			vectorIterator(){ };
			vectorIterator(pointer ptr) : current(ptr) {};
			vectorIterator(const vectorIterator &src) : current(src.base()) {};
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
			pointer operator ->() const { return (current); };		
			reference operator*() const { return (*(current)); };
			pointer base() const { return (current); }
		private :
			pointer current;
	};

	template <class T>
    bool operator== (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return lhs.base() == rhs.base(); }
    template <class T>
    bool operator!= (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return lhs.base() != rhs.base(); }
    template <class T>
    bool operator<  (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return lhs.base() < rhs.base(); }
    template <class T>
    bool operator<= (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return lhs.base() <= rhs.base(); }
    template <class T>
    bool operator>  (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return lhs.base() > rhs.base(); }
    template <class T>
    bool operator>= (const vectorIterator<T>& lhs, const vectorIterator<T>& rhs) { return lhs.base() >= rhs.base(); }
}

#endif