#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public : 

			template <class _T, class _Container>
			friend bool operator== (const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template <class _T, class _Container>
			friend bool operator!= (const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template <class _T, class _Container>
			friend bool operator< (const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template <class _T, class _Container>
			friend bool operator<= (const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template <class _T, class _Container>
			friend bool operator> (const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			template <class _T, class _Container>
			friend bool operator>= (const ft::stack<_T, _Container>& lhs, const ft::stack<_T, _Container>& rhs);

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit stack(const container_type &cont = container_type()) : _cont(cont) {};

			bool empty() const { return (_cont.empty()); };
			size_type size() const { return (_cont.size()); };

			value_type& top(){ return (_cont.back()); };
			const value_type& top() const { return (_cont.back()); };

			void push (const value_type& val) { _cont.push_back(val); };
			void pop() { _cont.pop_back(); };

		protected :
		
			Container _cont;
	};

	template <class _T, class _Container>
	bool operator==(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs) {
		return (lhs._cont == rhs._cont);
	};

	template <class _T, class _Container>
	bool operator!=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs) {
		return (lhs._cont != rhs._cont);
	};

	template <class _T, class _Container>
	bool operator<(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs) {
		return (lhs._cont < rhs._cont);
	};

	template <class _T, class _Container>
	bool operator<=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs) {
		return (lhs._cont <= rhs._cont);
	};

	template <class _T, class _Container>
	bool operator>(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs) {
		return (lhs._cont > rhs._cont);
	};

	template <class _T, class _Container>
	bool operator>=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs) {
		return (lhs._cont >= rhs._cont);
	};
}

#endif