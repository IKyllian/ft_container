#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include "vector_iterator.hpp"
#include "../iterators.hpp"

namespace ft
{
	template <typename Iter>
	class vectorReverseIterator : ft::iterator <
		typename ft::iterator_traits<Iter>::iterator_category, 
		typename ft::iterator_traits<Iter>::value_type,
		typename ft::iterator_traits<Iter>::difference_type,
		typename ft::iterator_traits<Iter>::pointer,
		typename ft::iterator_traits<Iter>::reference > {
		public :

			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category 	iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type      	value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer     		pointer;
            typedef typename ft::iterator_traits<Iter>::reference   		reference;

			vectorReverseIterator(){ };
			vectorReverseIterator(iterator_type ptr) : current(ptr) {};
			vectorReverseIterator(const vectorReverseIterator &src) : current(src.base()) {};
			~vectorReverseIterator() {};

			vectorReverseIterator &operator=(const vectorReverseIterator& src) {
				current = src.current;
				return (*this);
			};
			
			// ---------Bool--------
			bool operator==(const vectorReverseIterator& src) const { return (current == src.current); };
			bool operator!=(const vectorReverseIterator& src) const { return (current != src.current); };
			bool operator<(const vectorReverseIterator& src) const { return (current < src.current); };
			bool operator<=(const vectorReverseIterator& src) const { return (current <= src.current); };
			bool operator>(const vectorReverseIterator& src) const { return (current > src.current); };
			bool operator>=(const vectorReverseIterator& src) const { return (current >= src.current); };


			// ---------Increment/Decrement---------
			vectorReverseIterator &operator++(void) {
				current--;
				return (*this);
			}
			vectorReverseIterator operator++(int) {
				vectorReverseIterator tmp = *this;
				current--;
				return (tmp);
			}
			vectorReverseIterator &operator--(void) {
				current++;
				return (*this);
			}
			vectorReverseIterator operator--(int) {
				vectorReverseIterator tmp = *this;
				current++;
				return (tmp);
			}
			
			// -----------Arithmetic operators---------
			vectorReverseIterator operator+(difference_type n){ return (vectorReverseIterator(current - n)); };
			vectorReverseIterator operator-(difference_type n){ return (vectorReverseIterator(current + n)); };
			difference_type operator+(vectorReverseIterator b){ return (current - b.current); };
			difference_type operator-(vectorReverseIterator b){ return (current + b.current); };

			vectorReverseIterator &operator+=(difference_type n) {
				current -= n;
				return (*this);
			};
			vectorReverseIterator &operator-=(difference_type n) {
				current += n;
				return (*this);
			};

			// -----------Dereferencing/Address----------
			reference operator [](difference_type n) const { return (current[-n - 1]); };
			reference operator *() const {
				iterator_type tmp = current;
				return (*(--tmp));
			}	
			pointer operator->() const { return (&operator*()); };
			iterator_type base() const { return (current); }
		protected :
			iterator_type current;
	};

	// template <class Iterator>
    // bool operator== (const vectorReverseIterator<Iterator>& lhs, const vectorReverseIterator<Iterator>& rhs) { return lhs.base() == rhs.base(); }
    // template <class Iterator>
    // bool operator!= (const vectorReverseIterator<Iterator>& lhs, const vectorReverseIterator<Iterator>& rhs) { return lhs.base() != rhs.base(); }
    // template <class Iterator>
    // bool operator<  (const vectorReverseIterator<Iterator>& lhs, const vectorReverseIterator<Iterator>& rhs) { return lhs.base() > rhs.base(); }
    // template <class Iterator>
    // bool operator<= (const vectorReverseIterator<Iterator>& lhs, const vectorReverseIterator<Iterator>& rhs) { return lhs.base() >= rhs.base(); }
    // template <class Iterator>
    // bool operator>  (const vectorReverseIterator<Iterator>& lhs, const vectorReverseIterator<Iterator>& rhs) { return lhs.base() < rhs.base(); }
    // template <class Iterator>
    // bool operator>= (const vectorReverseIterator<Iterator>& lhs, const vectorReverseIterator<Iterator>& rhs) { return lhs.base() <= rhs.base(); }
}

#endif