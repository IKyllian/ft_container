#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <deque>
#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public : 

			typedef T value_type;
			typedef typename Container::value_type container_type;
			typedef typename Container::size_type size_type;

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
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ct == rhs.ct);
	};

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ct != rhs.ct);
	};

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ct < rhs.ct);
	};

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ct <= rhs.ct);
	};

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ct > rhs.ct);
	};

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ct >= rhs.ct);
	};
}


#endif