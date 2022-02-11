#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft
{
	template <typename iterator>
	class vectorReverseIterator {
		public :

			typedef typename iterator::value_type		value_type;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::difference_type	difference_type;


			vectorReverseIterator(){ };
			vectorReverseIterator(pointer ptr) { _ptr = ptr; };
			// vectorReverseIterator( vectorIterator<value_type> &src) { _ptr = src.operator->(); } ;
			vectorReverseIterator(iterator src) { _ptr = src.operator->(); } ;
			vectorReverseIterator(const vectorReverseIterator &src){ *this = src; };
			~vectorReverseIterator() {};

			vectorReverseIterator &operator=(const vectorReverseIterator& src) {
				_ptr = src._ptr;
				return (*this);
			};
			
			// ---------Bool--------
			bool operator==(const vectorReverseIterator& src) const { return (_ptr == src._ptr); };
			bool operator!=(const vectorReverseIterator& src) const { return (_ptr != src._ptr); };
			bool operator<(const vectorReverseIterator& src) const { return (_ptr < src._ptr); };
			bool operator<=(const vectorReverseIterator& src) const { return (_ptr <= src._ptr); };
			bool operator>(const vectorReverseIterator& src) const { return (_ptr > src._ptr); };
			bool operator>=(const vectorReverseIterator& src) const { return (_ptr >= src._ptr); };


			// ---------Increment/Decrement---------
			vectorReverseIterator &operator++(void) {
				_ptr--;
				return (*this);
			}
			vectorReverseIterator operator++(int) {
				vectorReverseIterator tmp = *this;
				_ptr--;
				return (tmp);
			}
			vectorReverseIterator &operator--(void) {
				_ptr++;
				return (*this);
			}
			vectorReverseIterator operator--(int) {
				vectorReverseIterator tmp = *this;
				_ptr++;
				return (tmp);
			}
			
			// -----------Arithmetic operators---------
			vectorReverseIterator operator+(difference_type n){ return (vectorReverseIterator(_ptr - n)); };
			vectorReverseIterator operator-(difference_type n){ return (vectorReverseIterator(_ptr + n)); };
			difference_type operator+(vectorReverseIterator b){ return (_ptr - b._ptr); };
			difference_type operator-(vectorReverseIterator b){ return (_ptr + b._ptr); };

			vectorReverseIterator &operator+=(difference_type n) {
				_ptr -= n;
				return (*this);
			};
			vectorReverseIterator &operator-=(difference_type n) {
				_ptr += n;
				return (*this);
			};

			// -----------Dereferencing/Address----------
			reference operator[](difference_type n){ return (*(_ptr + n)); };
			const_reference operator [](difference_type n) const { return (*(_ptr + n)); };
			pointer operator->(){ return (_ptr); };
			pointer operator ->() const { return (_ptr); };		
			reference operator*(){ return (*(_ptr)); };
			const_reference operator *() const { return (*_ptr); };

		private :
			pointer _ptr;
	};
}

#endif