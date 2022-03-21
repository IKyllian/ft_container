#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iostream>
#include "../iterators.hpp"

namespace ft
{
	template <class T>
	class vectorIterator {
		public :
			typedef typename ft::iterator_traits<T>::pointer pointer;
			typedef typename ft::iterator_traits<T>::reference reference;
			typedef typename ft::iterator_traits<T>::difference_type difference_type;
			typedef typename ft::iterator_traits<T>::value_type value_type;
			typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
			
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
			reference operator*() const { return *current; };
			pointer base() const { return (current); };
		private :
			pointer current;
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

	template<class Iter>
	typename vectorIterator<Iter>::difference_type operator-( const vectorIterator<Iter>& lhs, const vectorIterator<Iter>& rhs ) {
		return (lhs.base() - rhs.base());
	}

	template< class Iter >
	vectorIterator<Iter> operator+( typename vectorIterator<Iter>::difference_type n, const vectorIterator<Iter>& it ) {
		return (vectorIterator<Iter>(it.base() + n));
	}
}

#endif