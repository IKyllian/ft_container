#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <functional>
#include "../utils.hpp"
#include "node_tree.hpp"
#include "../vector/vector_reverse_iterator.hpp"

namespace ft
{
	template <class Iter, class Pair>
	class setIterator {
		public :
			typedef typename ft::iterator_traits<Pair>::value_type value_type;
			typedef typename ft::iterator_traits<Pair>::pointer pointer;
			typedef typename ft::iterator_traits<Pair>::reference reference;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef ft::bidirectional_iterator_tag iterator_category;
			
			setIterator() : current() { };
			setIterator(Iter iterator) : current(iterator) {};
			template <class I, class P>
			setIterator(const setIterator<I, P> &src) : current(src.base()) {};
			~setIterator() {};

			setIterator &operator=(const setIterator& src) {
				current = src.base();
				return (*this);
			};

			// ---------Increment/Decrement---------
			setIterator &operator++(void) {
				current++;
				return (*this);
			}
			setIterator operator++(int) {
				setIterator tmp = *this;
				current++;
				return (tmp);
			}
			setIterator &operator--(void) {
				current--;
				return (*this);
			}
			setIterator operator--(int) {
				setIterator tmp = *this;
				current--;
				return (tmp);
			}

			// -----------Dereferencing/Address----------
			pointer operator->() const { return (&current->_value); };		
			reference operator*() const { return (current->_value); };
			Iter base() const { return (current); }
		private :
			Iter current;
	};

	template <class Iter, class Pair>
	bool operator==(const ft::setIterator<Iter, Pair>& lhs, const ft::setIterator<Iter, Pair>& rhs) { return (lhs.base() == rhs.base()); };
	template <class Iter, class Pair>
	bool operator!=(const ft::setIterator<Iter, Pair>& lhs, const ft::setIterator<Iter, Pair>& rhs) { return (lhs.base() != rhs.base()); };


	template < class T,                                      
           class Compare = std::less<T>,
           class Alloc = std::allocator<T> >
	class set 
	{
		public :
		
			typedef T key_type;

			typedef T value_type; 

			typedef Compare key_compare;

			typedef Alloc allocator_type;

			typedef typename allocator_type::reference reference;
			
			typedef typename allocator_type::const_reference const_reference;
			
			typedef typename allocator_type::pointer pointer;
			
			typedef typename allocator_type::const_pointer const_pointer;

			typedef typename allocator_type::size_type	size_type;

			typedef typename std::ptrdiff_t difference_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;
				public:
					value_compare(Compare c) : comp(c) {}
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x, y);
					}
			};

			typedef typename ft::tree<value_type, value_compare> tree;

			typedef typename ft::setIterator<typename tree::iterator, pointer> iterator;

			typedef typename ft::setIterator<typename tree::const_iterator, const_pointer> const_iterator;

			typedef typename ft::vectorReverseIterator<iterator> reverse_iterator;

			typedef typename ft::vectorReverseIterator<const_iterator> const_reverse_iterator;


			// ---------------------- Constructor / Destructor / Asigment operator ---------------------------


			// Default Constructor
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(comp, alloc) {};

			// Range Constructor
			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(comp, alloc) {
				insert(first, last);
			};

			// Copy Constructor
			set(const set& x) : _alloc(x._alloc), _comp(x._comp), _tree(x._comp, x._alloc) {
				_tree = x._tree;
			};

			~set() {};

			set& operator= (const set& x) {
				this->_tree = x._tree;
				this->_comp = x._comp;
				return (*this);
			};

			// ---------------------- Iterators ---------------------------

			iterator begin() { return (iterator(_tree.begin())); };
			const_iterator begin() const { return (const_iterator(_tree.begin())); };

			iterator end() { return (iterator(_tree.end())); };
			const_iterator end() const { return (const_iterator(_tree.end())); };

			reverse_iterator rbegin() { return (reverse_iterator(end())); };
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); };

			reverse_iterator rend() { return (reverse_iterator(begin())); };
			const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); };


			// ---------------------- Capacity ---------------------------

			bool empty() const { return (_tree.empty()); };
			size_type size() const { return (_tree.size()); };
			size_type max_size() const { return (_tree.max_size()); };

			// ---------------------- Modifiers ---------------------------

			pair<iterator,bool> insert (const value_type& val) { return (_tree.insert(val)); };

			iterator insert (iterator position, const value_type& val) { return (iterator(_tree.insert(position.base(), val))); };

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) { 
				while (first != last)
					_tree.insert(*first++);
			};

			void erase (iterator position) { _tree.erase(position.base()); };
			size_type erase (const value_type& val) { return (_tree.erase(val)); };
			void erase (iterator first, iterator last) { 
				while (first != last)
					_tree.erase(*first++);
			};

			void swap (set& x) { return (_tree.swap(x._tree)); };

			void clear() { _tree.clear(); };

			// ---------------------- Observers ---------------------------
			
			key_compare key_comp() const { return (key_compare()); };
			value_compare value_comp() const { return (value_compare(key_comp())); };

			// ---------------------- Operations ---------------------------

			iterator find (const value_type& val) { return (iterator(_tree.find(val))); };
			const_iterator find (const value_type& val) const { return (const_iterator(_tree.find(val))); };

			size_type count(const value_type& val) const { return (_tree.count(val)); };

			iterator lower_bound(const value_type& val) { return (iterator(_tree.lower_bound(val))); };
			const_iterator lower_bound (const value_type& val) const { return (const_iterator(_tree.lower_bound(val))); };

			iterator upper_bound (const value_type& val) { return (iterator(_tree.upper_bound(val))); };
			const_iterator upper_bound (const value_type& val) const { return (const_iterator(_tree.upper_bound(val))); };

			pair<const_iterator,const_iterator> equal_range (const value_type& val) const { return (_tree.equal_range(val)); };
			pair<iterator,iterator>	equal_range (const value_type& val) { return (_tree.equal_range(val)); };

			// ---------------------- Allocator ---------------------------

			allocator_type get_allocator() const { return (_alloc); };

		private :
			Alloc		_alloc;
			Compare		_comp;
			tree		_tree;
	};
}

#endif