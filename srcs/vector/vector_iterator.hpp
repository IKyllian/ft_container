#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iostream>

namespace ft
{
	template <typename T>
	class vectorIterator {
		public :

			typedef T			value_type;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef typename	std::ptrdiff_t difference_type;


			vectorIterator(){ };
			vectorIterator(pointer ptr){ _ptr = ptr; };
			vectorIterator(const vectorIterator &src){ *this = src; };
			~vectorIterator() {};

			vectorIterator &operator=(const vectorIterator& src) {
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
				_ptr++;
				return (*this);
			}
			vectorIterator operator++(int) {
				vectorIterator tmp = *this;
				_ptr++;
				return (tmp);
			}
			vectorIterator &operator--(void) {
				_ptr--;
				return (*this);
			}
			vectorIterator operator--(int) {
				vectorIterator tmp = *this;
				_ptr--;
				return (tmp);
			}
			
			// -----------Arithmetic operators---------
			vectorIterator operator+(difference_type n){ return (vectorIterator(_ptr + n)); };
			vectorIterator operator-(difference_type n){ return (vectorIterator(_ptr - n)); };
			difference_type operator+(vectorIterator b){ return (_ptr + b._ptr); };
			difference_type operator-(vectorIterator b){ return (_ptr - b._ptr); };

			vectorIterator &operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			};
			vectorIterator &operator-=(difference_type n) {
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