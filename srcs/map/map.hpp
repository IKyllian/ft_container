#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "utils.hpp"
#include "node_tree.hpp"
#include "../vector/vector_reverse_iterator.hpp"

namespace ft
{
	// template <class Iter>
	// class mapIterator {
	// 	public :

	// 		typedef typename ft::iterator_traits<Iter>::value_type value_type;
	// 		typedef typename ft::iterator_traits<Iter>::pointer pointer;
	// 		typedef typename ft::iterator_traits<Iter>::reference reference;
	// 		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
	// 		typedef ft::bidirectional_iterator_tag iterator_category;
			
	// 		mapIterator() : current() { };
	// 		mapIterator(Iter iterator) : current(iterator) {};
	// 		mapIterator(const mapIterator &src) : current(src.current) {};
	// 		~mapIterator() {};

	// 		mapIterator &operator=(const mapIterator& src) {
	// 			current = src.current;
	// 			return (*this);
	// 		};

	// 		// ---------Increment/Decrement---------
	// 		mapIterator &operator++(void) {
	// 			current++;
	// 			return (*this);
	// 		}
	// 		mapIterator operator++(int) {
	// 			mapIterator tmp = *this;
	// 			current++;
	// 			return (tmp);
	// 		}
	// 		mapIterator &operator--(void) {
	// 			current--;
	// 			return (*this);
	// 		}
	// 		mapIterator operator--(int) {
	// 			mapIterator tmp = *this;
	// 			current--;
	// 			return (tmp);
	// 		}

	// 		// -----------Dereferencing/Address----------
	// 		Iter operator ->() const { return (current); };		
	// 		reference operator*() const { return (*(current)); };
	// 		Iter base() const { return (current); }
	// 	private :
	// 		Iter current;
	// };

	// template <class Iter>
	// bool operator==(const ft::mapIterator<Iter>& lhs, const ft::mapIterator<Iter>& rhs) { return (lhs.base() == rhs.base()); };
	// template <class Iter>
	// bool operator!=(const ft::mapIterator<Iter>& lhs, const ft::mapIterator<Iter>& rhs) { return (lhs.base() != rhs.base()); };


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

			typedef typename allocator_type::size_type	size_type;

			typedef typename std::ptrdiff_t difference_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;
					// value_compare(Compare c) : comp(c) {} // A verifier. Normalement le constructeur devrait etre en protected mais probleme pour passé comp à _tree
				public:
					value_compare(Compare c) : comp(c) {}
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

			typedef typename ft::tree<value_type, value_compare> tree;

			// typedef typename ft::mapIterator<typename tree::iterator> iterator;

			// typedef typename ft::mapIterator<typename tree::const_iterator> const_iterator;

			// typedef typename ft::vectorReverseIterator<iterator> reverse_iterator;

			// typedef typename ft::vectorReverseIterator<const_iterator> const_reverse_iterator;

			typedef typename tree::iterator iterator;

			typedef typename tree::const_iterator const_iterator;

			typedef typename ft::vectorReverseIterator<iterator> reverse_iterator;

			typedef typename ft::vectorReverseIterator<const_iterator> const_reverse_iterator;


			// ---------------------- Constructor / Destructor / Asigment operator ---------------------------


			// Default Constructor
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(comp, alloc) {};

			// Range Constructor
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(comp, alloc) {
				insert(first, last);
			};

			// Copy Constructor
			map(const map& x) : _alloc(x._alloc), _comp(x._comp), _tree(x._comp, x._alloc) {
				_tree = x._tree;
			};

			~map() {};

			map& operator= (const map& x) {
				this->_tree = x._tree;
				this->_comp = x._comp;
				return (*this);
			};

			tree get_tree() { return (_tree);}; // Temporaire

			// ---------------------- Iterators ---------------------------

			// iterator begin() { return (iterator(_tree.begin())); };
			// const_iterator begin() const { return (const_iterator(_tree.begin())); };

			// iterator end() { return (iterator(_tree.end())); };
			// const_iterator end() const { return (const_iterator(_tree.end())); };
			iterator begin() { return (_tree.begin()); };
			const_iterator begin() const { return (_tree.begin()); };

			iterator end() { return (_tree.end()); };
			const_iterator end() const { return (_tree.end()); };

			reverse_iterator rbegin() { return (_tree.rbegin()); };
			const_reverse_iterator rbegin() const { return (_tree.rbegin()); };

			reverse_iterator rend() { return (_tree.rend()); };
			const_reverse_iterator rend() const { return (_tree.rend()); };

			// ---------------------- Capacity ---------------------------

			bool empty() const { return (_tree.empty()); };
			size_type size() const { return (_tree.size()); };
			size_type max_size() const;

			// ---------------------- Element Access ---------------------------

			mapped_type& operator[] (const key_type& k) { return ((*((this->insert(ft::make_pair(k,mapped_type()))).first))._pair.second); };	

			// ---------------------- Modifiers ---------------------------

			pair<iterator,bool> insert (const value_type& val) { return (_tree.insert(val)); };

			iterator insert (iterator position, const value_type& val) { return (_tree.insert(position, val)); };

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) { _tree.insert(first, last); };


			void erase (iterator position) { _tree.erase(position); };
			size_type erase (const key_type& k) { return (_tree.erase(ft::make_pair(k, mapped_type()))); };
			void erase (iterator first, iterator last) { _tree.erase(first, last); };

			void swap (map& x) { return (_tree.swap(x._tree)); };

			void clear() { _tree.clear(); };

			// ---------------------- Observers ---------------------------
			
			key_compare key_comp() const { return (key_compare()); };
			value_compare value_comp() const { return (value_compare(key_comp())); };

			// ---------------------- Operations ---------------------------

			iterator find (const key_type& k) { return (_tree.find(ft::make_pair(k, mapped_type()))); };
			const_iterator find (const key_type& k) const { return (_tree.find(ft::make_pair(k, mapped_type()))); };

			size_type count(const key_type& k) const { return (_tree.count(ft::make_pair(k, mapped_type()))); };

			iterator lower_bound(const key_type& k) { return (_tree.lower_bound(ft::make_pair(k, mapped_type()))); };
			const_iterator lower_bound (const key_type& k) const { return (_tree.lower_bound(ft::make_pair(k, mapped_type()))); };

			iterator upper_bound (const key_type& k) { return (_tree.upper_bound(ft::make_pair(k, mapped_type()))); };
			const_iterator upper_bound (const key_type& k) const { return (_tree.upper_bound(ft::make_pair(k, mapped_type()))); };

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return (_tree.equal_range(ft::make_pair(k, mapped_type()))); };
			pair<iterator,iterator>	equal_range (const key_type& k) { return (_tree.equal_range(ft::make_pair(k, mapped_type()))); };

			// ---------------------- Allocator ---------------------------

			allocator_type get_allocator() const { return (_alloc); };

		private :
			Alloc		_alloc;
			Compare		_comp;
			tree		_tree;
	};
}

#endif