#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
#define VECTOR_CONST_REVERSE_ITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft
{
	template <typename iterator>
	class vectorConstReverseIterator {
		public :

			typedef typename iterator::value_type		value_type;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::difference_type	difference_type;


			vectorConstReverseIterator(){ };
			vectorConstReverseIterator(pointer ptr) { _ptr = ptr; };
			vectorConstReverseIterator(iterator src) { _ptr = src.operator->(); } ;
			vectorConstReverseIterator(const vectorConstReverseIterator &src){ *this = src; };
			~vectorConstReverseIterator();

			vectorConstReverseIterator &operator=(const vectorConstReverseIterator& src) {
				_ptr = src._ptr;
				return (*this);
			};
			
			// ---------Bool--------
			bool operator==(const vectorConstReverseIterator& src) const { return (_ptr == src._ptr); };
			bool operator!=(const vectorConstReverseIterator& src) const { return (_ptr != src._ptr); };
			bool operator<(const vectorConstReverseIterator& src) const { return (_ptr < src._ptr); };
			bool operator<=(const vectorConstReverseIterator& src) const { return (_ptr <= src._ptr); };
			bool operator>(const vectorConstReverseIterator& src) const { return (_ptr > src._ptr); };
			bool operator>=(const vectorConstReverseIterator& src) const { return (_ptr >= src._ptr); };


			// ---------Increment/Decrement---------
			vectorConstReverseIterator &operator++(void) {
				_ptr--;
				return (*this);
			}
			vectorConstReverseIterator operator++(int) {
				vectorConstReverseIterator tmp = *this;
				_ptr--;
				return (tmp);
			}
			vectorConstReverseIterator &operator--(void) {
				_ptr++;
				return (*this);
			}
			vectorConstReverseIterator operator--(int) {
				vectorConstReverseIterator tmp = *this;
				_ptr++;
				return (tmp);
			}
			
			// -----------Arithmetic operators---------
			vectorConstReverseIterator operator+(difference_type n){ return (vectorConstReverseIterator(_ptr - n)); };
			vectorConstReverseIterator operator-(difference_type n){ return (vectorConstReverseIterator(_ptr + n)); };
			difference_type operator+(vectorConstReverseIterator b){ return (_ptr - b._ptr); };
			difference_type operator-(vectorConstReverseIterator b){ return (_ptr + b._ptr); };

			vectorConstReverseIterator &operator+=(difference_type n) {
				_ptr -= n;
				return (*this);
			};
			vectorConstReverseIterator &operator-=(difference_type n) {
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