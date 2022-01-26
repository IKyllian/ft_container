#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft
{
	template <typename iterator>
	class vectorReverseIterator {
		public :

			typedef iterator::value_type value_type;
			typedef iterator::pointer pointer;
			typedef iterator::reference reference;
			typedef iterator::deference_type deference_type;


			vectorReverseIterator(){ };
			vectorReverseIterator(pointer ptr){ _ptr(ptr); };
			vectorReverseIterator(const vectorIterator<value_type> &it){ _ptr = it.operator->(); };
			vectorReverseIterator(const vectorReverseIterator &src){ *this = src; };
			~vectorReverseIterator();

			vectorReverseIterator &operator=(const vectorReverseIterator& src) {
				_ptr = src._ptr;
				return (*this);
			};
			
			// ---------Bool--------
			bool operator==(const vectorIterator& src) const { return (_ptr == src._ptr); };
			bool operator!=(const vectorIterator& src) const { return (_ptr != src._ptr); };
			bool operator<(const vectorIterator& src) const { return (_ptr < src._ptr); };
			bool operator<=(const vectorIterator& src) const { return (_ptr <= src._ptr); };
			bool operator>(const vectorIterator& src) const { return (_ptr > src._ptr); };
			bool operator>=(const vectorIterator& src) const { return (_ptr >= src._ptr); };


			// ---------Increment/Decrement---------
			vectorIterator &operator++(void) {
				_ptr--;
				return (*this);
			}
			vectorIterator operator++(int) {
				vectorIterator tmp = *this;
				--(*this);
				return (tmp);
			}
			vectorIterator &operator--(void) {
				_ptr++;
				return (*this);
			}
			vectorIterator operator--(int) {
				vectorIterator tmp = *this;
				++(*this);
				return (tmp);
			}
			
			// -----------Arithmetic operators---------
			vectorIterator operator+(difference_type n){ return (vectorIterator(_ptr - n)); };
			vectorIterator operator-(difference_type n){ return (vectorIterator(_ptr + n)); };
			difference_type operator+(vectorIterator b){ return (_ptr - b._ptr); };
			difference_type operator-(vectorIterator b){ return (_ptr + b._ptr); };

			vectorIterator &operator+=(difference_type n) {
				_ptr -= n;
				return (*this);
			};
			vectorIterator &operator-=(difference_type n) {
				_ptr += n;
				return (*this);
			};

			// -----------Dereferencing/Address----------
			reference operator[](difference_type n){ return (*(_ptr + n)); };
			pointer operator->(){ return (_ptr); };
			reference operator*(){ return (*(_ptr)); };

		private :
			pointer _ptr;
	};
}

#endif