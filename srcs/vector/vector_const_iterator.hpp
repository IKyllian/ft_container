#ifndef VECTOR_CONST_ITERATOR_HPP
#define VECTOR_CONST_ITERATOR_HPP

#include <iostream>

namespace ft
{
	template <typename T>
	class vectorConstIterator {
		public :

			typedef const T		value_type;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef typename	std::ptrdiff_t difference_type;


			vectorConstIterator(){ };
			vectorConstIterator(pointer ptr){ _ptr = ptr; };
			vectorConstIterator(const vectorConstIterator &src){ *this = src; };
			~vectorConstIterator();

			vectorConstIterator &operator=(const vectorConstIterator& src) {
				_ptr = src._ptr;
				return (*this);
			};
			
			// ---------Bool--------
			bool operator==(const vectorConstIterator& src) const { return (_ptr == src._ptr); };
			bool operator!=(const vectorConstIterator& src) const { return (_ptr != src._ptr); };
			bool operator<(const vectorConstIterator& src) const { return (_ptr < src._ptr); };
			bool operator<=(const vectorConstIterator& src) const { return (_ptr <= src._ptr); };
			bool operator>(const vectorConstIterator& src) const { return (_ptr > src._ptr); };
			bool operator>=(const vectorConstIterator& src) const { return (_ptr >= src._ptr); };


			// ---------Increment/Decrement---------
			vectorConstIterator &operator++(void) {
				_ptr++;
				return (*this);
			}
			vectorConstIterator operator++(int) {
				vectorConstIterator tmp = *this;
				_ptr++;
				return (tmp);
			}
			vectorConstIterator &operator--(void) {
				_ptr--;
				return (*this);
			}
			vectorConstIterator operator--(int) {
				vectorConstIterator tmp = *this;
				_ptr--;
				return (tmp);
			}
			
			// -----------Arithmetic operators---------
			vectorConstIterator operator+(difference_type n){ return (vectorConstIterator(_ptr + n)); };
			vectorConstIterator operator-(difference_type n){ return (vectorConstIterator(_ptr - n)); };
			difference_type operator+(vectorConstIterator b){ return (_ptr + b._ptr); };
			difference_type operator-(vectorConstIterator b){ return (_ptr - b._ptr); };

			vectorConstIterator &operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			};
			vectorConstIterator &operator-=(difference_type n) {
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