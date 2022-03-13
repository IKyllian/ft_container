#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public : 

			friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs); 
			friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit stack(const Container &cont = Container()) : _cont(cont) {};

			bool empty() const { return (_cont.empty()); };
			size_type size() const { return (_cont.size()); };

			value_type& top(){ return (_cont.back()); };
			const value_type& top() const { return (_cont.back()); };

			void push (const value_type& val) { _cont.push_back(val); };
			void pop() { _cont.pop_back(); };

		protected :
		
			Container _cont;
	};

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont == rhs._cont);
	};

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont != rhs._cont);
	};

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont < rhs._cont);
	};

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont <= rhs._cont);
	};

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont > rhs._cont);
	};

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont >= rhs._cont);
	};
}


#endif