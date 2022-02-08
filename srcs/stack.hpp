#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack
	{
		public : 

			typedef Container container_type;
			typedef typename Container::value_type container_type;
			typedef typename Container::size_type size_type;

			explicit stack(const Container &cont = Container());

			bool empty() const {return (_cont.size());};
			size_type size() const {return (_cont.empty());};

			value_type& top(){return(_cont.back())};
			const value_type& top(){return(_cont.back())} const;

			void push (const value_type& val) {_cont.push_back(val)};
			void pop() {c.pop_back()};

		protected :
			container_type _cont;

			
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhc.ct == rhc.ct);
	};

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhc.ct != rhc.ct);
	};

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhc.ct < rhc.ct);
	};

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhc.ct <= rhc.ct);
	};

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhc.ct > rhc.ct);
	};

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhc.ct >= rhc.ct);
	};
}


#endif