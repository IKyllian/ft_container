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

			bool empty() const {return (c.size());};
			size_type size() const {return (c.empty());};

			value_type& top(){return(c.back())};
			const value_type& top(){return(c.back())} const;

			void push (const value_type& val) {c.push_back(val)};
			void pop() {c.pop_back()};

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
	};
}


#endif