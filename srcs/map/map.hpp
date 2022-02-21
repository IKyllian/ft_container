#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "utils.hpp"
#include "node_tree.hpp"

namespace ft
{
	template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type;
    >
	class map 
	{
		public :
		
			typedef Key key_type;

			typedef T mapped_type;

			typedef ft::pair<const key_type, mapped_type> value_type; 

			typedef Compare key_compare;

			typedef Alloc allocator_type;

			typedef typename allocator_type::reference reference;
			
			typedef typename allocator_type::const_reference const_reference;
			
			typedef typename allocator_type::pointer pointer;
			
			typedef typename allocator_type::const_pointer const_pointer;

			// typedef typename ft::mapIterator<key_type, Compare> iterator;

			// typedef type name ft::mapIterator<value_type> const_iterator;

			// typedef typename ft::mapIterator<iterator> reverse_iterator;

			// typedef typename ft::mapIterator<const_iterator> const_reverse_iterator;

			typedef typename allocator_type::size_type	size_type;

			typedef typename std::ptrdiff_t difference_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;
					// value_compare(Compare c) : comp(c) {} // A verifier. Normalement le constructeur devrait respecté en protected mais probleme pour passé comp à _tree
				public:
					value_compare(Compare c) : comp(c) {}
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

			typedef typename ft::tree<value_type, value_compare> tree;


			// ---------------------- Constructor / Destructor / Asigment operator ---------------------------


			// Default Constructor
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(comp, alloc) {};

			// Range Constructor
			// template <class InputIterator>
			// map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp) {
				// difference_type size = last - first;
				// _alloc_size = size;
				// _pair = _alloc.allocate(size);
				// for (ft::map<Key, T>::iterator it(first); it != end; it++) {
				// 	_alloc.construct(_pair + _fill_size, ft::pair<(*it).first, (*it).second>);
				// 	_fill_size++;
				// }
			// };

			// Copy Constructor
			map(const map& x) : _alloc(x._alloc), _comp(x._comp) {
				*this = x;
			};

			~map() {};

			map& operator= (const map& x) {
				this->_tree = x._tree;
				std::cout << "TEST" << std::endl;
				this->_comp = x._comp;
				return (*this);
			};

			// ---------------------- Iterators ---------------------------

			// iterator begin();
			// const_iterator begin() const;

			// iterator end();
			// const_iterator end() const;

			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;

			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			// ---------------------- Capacity ---------------------------

			bool empty() const { _tree.empty(); };
			size_type size() const { _tree.size(); };
			size_type max_size() const;

			// ---------------------- Element Access ---------------------------

			mapped_type& operator[] (const key_type& k);	

			// ---------------------- Modifiers ---------------------------

			// pair<iterator,bool> insert (const value_type& val);
			void insert (const value_type& val) {
				_tree.insert(val);
			};

			// iterator insert (iterator position, const value_type& val);

			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);


			// void erase (iterator position);
			// size_type erase (const key_type& k);
			// void erase (iterator first, iterator last);

			void swap (map& x);

			void clear() { _tree.clear(); };

			// ---------------------- Observers ---------------------------
			
			key_compare key_comp() const { return (key_compare()); };
			value_compare value_comp() const { return (value_compare(key_comp())); };

			// ---------------------- Operations ---------------------------

			// iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;

			size_type count (const key_type& k) const;

			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;

			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;

			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator>             equal_range (const key_type& k);

			// ---------------------- Allocator ---------------------------

			allocator_type get_allocator() const { return (_alloc); };

		private :
			Alloc		_alloc;
			Compare		_comp;
			tree		_tree;
	};
}


#endif