#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>

#define NOIR 0
#define ROUGE 1

namespace ft
{

	template <typename T>
	class mapIterator {
		public :

			typedef T			value_type;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef typename	std::ptrdiff_t difference_type;

			mapIterator(){ };
			mapIterator(pointer ptr){ _ptr = ptr; };
			mapIterator(const mapIterator &src){ *this = src; };
			~mapIterator() {};

			mapIterator &operator=(const mapIterator& src) {
				_ptr = src._ptr;
				return (*this);
			};

			// ---------Increment/Decrement---------
			mapIterator &operator++(void) {
				_ptr++;
				return (*this);
			}
			mapIterator operator++(int) {
				mapIterator tmp = *this;
				_ptr++;
				return (tmp);
			}
			mapIterator &operator--(void) {
				_ptr--;
				return (*this);
			}
			mapIterator operator--(int) {
				mapIterator tmp = *this;
				_ptr--;
				return (tmp);
			}
			
			// -----------Dereferencing/Address----------
			pointer operator->(){ return (_ptr); };
			pointer operator ->() const { return (_ptr); };		
			reference operator*(){ return (*(_ptr)); };
			const_reference operator *() const { return (*_ptr); };

		private :
			pointer _ptr;
	};

	template <typename T>
	class mapConstIterator {
		public :

			typedef T			value_type;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef typename	std::ptrdiff_t difference_type;

			mapConstIterator(){ };
			mapConstIterator(pointer ptr){ _ptr = ptr; };
			mapConstIterator(const mapConstIterator &src){ *this = src; };
			~mapConstIterator() {};

			mapConstIterator &operator=(const mapConstIterator& src) {
				_ptr = src._ptr;
				return (*this);
			};

			// ---------Increment/Decrement---------
			mapConstIterator &operator++(void) {
				_ptr++;
				return (*this);
			}
			mapConstIterator operator++(int) {
				mapConstIterator tmp = *this;
				_ptr++;
				return (tmp);
			}
			mapConstIterator &operator--(void) {
				_ptr--;
				return (*this);
			}
			mapConstIterator operator--(int) {
				mapConstIterator tmp = *this;
				_ptr--;
				return (tmp);
			}
			
			// -----------Dereferencing/Address----------
			pointer operator->(){ return (_ptr); };
			pointer operator ->() const { return (_ptr); };		
			reference operator*(){ return (*(_ptr)); };
			const_reference operator *() const { return (*_ptr); };

		private :
			pointer _ptr;
	};

	template <typename iterator>
	class mapConstReverseIterator {
		public :

			typedef typename iterator::value_type		value_type;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::difference_type	difference_type;


			mapConstReverseIterator(){ };
			mapConstReverseIterator(pointer ptr) { _ptr = ptr; };
			mapConstReverseIterator(iterator src) { _ptr = src.operator->(); } ;
			mapConstReverseIterator(const mapConstReverseIterator &src){ *this = src; };
			~mapConstReverseIterator() {};

			mapConstReverseIterator &operator=(const mapConstReverseIterator& src) {
				_ptr = src._ptr;
				return (*this);
			};
			

			// ---------Increment/Decrement---------
			mapConstReverseIterator &operator++(void) {
				_ptr--;
				return (*this);
			}
			mapConstReverseIterator operator++(int) {
				mapConstReverseIterator tmp = *this;
				_ptr--;
				return (tmp);
			}
			mapConstReverseIterator &operator--(void) {
				_ptr++;
				return (*this);
			}
			mapConstReverseIterator operator--(int) {
				mapConstReverseIterator tmp = *this;
				_ptr++;
				return (tmp);
			}

			// -----------Dereferencing/Address----------
			pointer operator->(){ return (_ptr); };
			pointer operator ->() const { return (_ptr); };		
			reference operator*(){ return (*(_ptr)); };
			const_reference operator *() const { return (*_ptr); };

		private :
			pointer _ptr;
	};

	template <typename iterator>
	class mapReverseIterator {
		public :

			typedef typename iterator::value_type		value_type;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::difference_type	difference_type;


			mapReverseIterator(){ };
			mapReverseIterator(pointer ptr) { _ptr = ptr; };
			mapReverseIterator(iterator src) { _ptr = src.operator->(); } ;
			mapReverseIterator(const mapReverseIterator &src){ *this = src; };
			~mapReverseIterator() {};

			mapReverseIterator &operator=(const mapReverseIterator& src) {
				_ptr = src._ptr;
				return (*this);
			};
			

			// ---------Increment/Decrement---------
			mapReverseIterator &operator++(void) {
				_ptr--;
				return (*this);
			}
			mapReverseIterator operator++(int) {
				mapReverseIterator tmp = *this;
				_ptr--;
				return (tmp);
			}
			mapReverseIterator &operator--(void) {
				_ptr++;
				return (*this);
			}
			mapReverseIterator operator--(int) {
				mapReverseIterator tmp = *this;
				_ptr++;
				return (tmp);
			}

			// -----------Dereferencing/Address----------
			pointer operator->(){ return (_ptr); };
			pointer operator ->() const { return (_ptr); };		
			reference operator*(){ return (*(_ptr)); };
			const_reference operator *() const { return (*_ptr); };

		private :
			pointer _ptr;
	};


	template <class T1, class T2>
	class pair
	{
		public :

			typedef T1 first_type;
			typedef T2 second_type;

			// Default constructor
			pair() {};

			/* 
				Copy / Move constructor
				The object is initialized with the contents of the pr pair object.
				The corresponding member of pr is passed to the constructor of each of its members.
			*/
			template<class U, class V>
			pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
			
			/*
				initialization constructor
				Member first is constructed with a and member second with b.
			*/
			pair(const first_type& a, const second_type& b) : first(a), second(b) {};
			
			pair& operator=(const pair &pr) {
				this->first = pr.first;
				this->second = pr.second;
			};

			template <class T1, class T2>
			bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
				return lhs.first==rhs.first && lhs.second==rhs.second;
			}

			template <class T1, class T2>
			bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
				return !(lhs==rhs);
			}

			template <class T1, class T2>
			bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
				return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
			}

			template <class T1, class T2>
			bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
				return !(rhs<lhs);
			}

			template <class T1, class T2>
			bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
				return rhs<lhs;
			}

			template <class T1, class T2>
			bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
				return !(lhs<rhs);
			}
			
			// Member Type
			first_type	first;
			second_type	second;
	};	

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y) {
		return (ft::pair<T1,T2>(x,y));
	};

	template <class Key, class Comapare>
	class node
	{
		public :

		node();
		node& operator=(const node& src);
		~node();

		node* get_parent() { return (this->_parent) };
		node* get_grandparent() { 
			node *p = get_parent();
			if (p == NULL) // Noeud sans parent n'a pas de grand parent
				return (NULL);
			return (p->get_parent());
		};
		node* get_brother() {
			node *p = get_parent();
			if (p == NULL) // Noeud sans parent n'a pas de frere
				return (NULL);
			if (this == p->_left)
				return (p->_right);
			return (p->left);
		};
		node* get_oncle() {
			node *p = get_parent();
			node *g = get_grandparent();
			if (g == NULL) // Noeud sans grand parent n'a pas d'oncle
				return (NULL);
			return (p->get_brother());
		};

		void left_rotation() {
			node *y = this->_right;

			// -------- 1 --------
			this->_right = y->_left;
			if (y->_left != NULL)
				y->_left->_parent = this;
			// -------------------

			// -------- 2 --------
			y->_parent = this->_parent;
			if (this->_parent == NULL)
				this = y;
			else if (this == this->_parent->_left)
				this->_parent->_left = y;
			else
				this->_parent->_right = y;
			// -------------------

			// -------- 3 --------
			y->_left = this;
			this->parent = y;
			// -------------------
		}

		void right_rotation() {
			node *y = this->_left;

			// -------- 1 --------
			this->_left = y->_right;
			if (y->_right != NULL)
				y->_right->_parent = this;
			// -------------------

			// -------- 2 --------
			y->_parent = this->_parent;
			if (this->_parent == NULL)
				this = y;
			else if (this == this->_parent->_right)
				this->_parent->_right = y;
			else
				this->_parent->_left = y;
			// -------------------

			// -------- 3 --------
			y->_right = this;
			this->parent = y;
			// -------------------
		}

		node *search_node(Key key) {
			node *tmp = this;

			while (tmp != NULL)
			{
				if (tmp->_key == key)
					return (tmp);
				if (key > tmp->_key)
					tmp = tmp->_right;
				else
					tmp = tmp->_left;
			}
			return (NULL);
		};

		void insert_repare()
		{
			if (this->parent() == NULL)
				this->>_color = NOIR;
			else if (parent(n)->couleur == NOIR)
				return ;
			else if (this->>get_oncle()->_color == ROUGE) {
				this->get_parent()->_color = NOIR;
				this->get_oncle()->_color = NOIR;

				node *g = this->get_grandparent();
				g->_color = ROUGE;
				g.insert_repare();
			}
			else {
				node *p = this->get_parent();
				node *g = this->get_grandparent();
			}
		}

		node *insert_node(node *new_node) {
			while (this != NULL)
			{
				if (new_node->_key > this->_key) {
					if (this->_right != NULL)
						this = this->_right;
					else {
						this->_right = new_node;
						break ;
					}
				}
				else {
					if (this->_left != NULL)
						this = this->_left;
					else {
						this->_left = new_node;
						break ;
					}
				}
			}
			new_node->parent = this;
			new_node->_right = NULL;
			new_node->_left = NULL;
			new_node = ROUGE;

			// Equilibrer arbre si il le faut
			new_node->insert_repare();
			
			while (this->parent() != NULL)
				this = this->parent();
			return (this);
		};


		private :

			node(const node& src);

			node	*_left;
			node	*_right;
			node	*_parent;
			int		_color;
			Key		_key;
	};

	template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = allocator<ft::pair<const Key,T> >    // map::allocator_type;
    >
	class map 
	{
		public :
		
			typedef Key key_type;

			typedef T mapped_type

			typedef ft::pair<const key_type, mapped_type> value_type; 

			typedef Compare key_compare;

			typedef Compare value_compare;

			typedef Alloc allocator_type;

			typedef typename allocator_type::reference reference;
			
			typedef typename allocator_type::const_reference const_reference;
			
			typedef typename allocator_type::pointer pointer;
			
			typedef typename allocator_type::const_pointer const_pointer;

			typedef typename ft::mapIterator<value_type> iterator;

			typedef typename ft::mapIterator<value_type> const_iterator;

			typedef typename ft::mapIterator<iterator> reverse_iterator;

			typedef typename ft::mapIterator<const_iterator> const_reverse_iterator;

			typedef typename allocator_type::size_type	size_type;

			typedef typename std::ptrdiff_t difference_type;


			// ---------------------- Constructor / Destructor / Asigment operator ---------------------------


			// Default Constructor
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _alloc_size(0), _fill_size(0) {};

			// Range Constructor
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp) {
				difference_type size = last - first;
				_alloc_size = size;
				_pair = _alloc.allocate(size);
				for (ft::map<Key, T>::iterator it(first); it != end; it++) {
					_alloc.construct(_pair + _fill_size, ft::pair<(*it).first, (*it).second>);
					_fill_size++;
				}
			};

			// Copy Constructor
			map(const map& x) : _alloc(x._alloc), _comp(c._comp) {};

			~map() {};

			map& operator= (const map& x) {};

			// ---------------------- Iterators ---------------------------

			iterator begin();
			const_iterator begin() const;

			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;

			reverse_iterator rend();
			const_reverse_iterator rend() const;

			// ---------------------- Capacity ---------------------------

			bool empty() const { return (!this->_fill_size ? true : false); };
			size_type size() const { return (this->_fill_size); };
			size_type max_size() const;

			// ---------------------- Element Access ---------------------------

			mapped_type& operator[] (const key_type& k);	

			// ---------------------- Modifiers ---------------------------

			pair<iterator,bool> insert (const value_type& val);

			iterator insert (iterator position, const value_type& val);

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);


			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);

			void swap (map& x);

			void clear();

			// ---------------------- Observers ---------------------------
			
			key_compare key_comp() const;
			value_compare value_comp() const;

			// ---------------------- Operations ---------------------------

			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;

			size_type count (const key_type& k) const;

			iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;

			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>             equal_range (const key_type& k);

			// ---------------------- Allocator ---------------------------

			allocator_type get_allocator() { return (_alloc); } const;


		private :
			Alloc		_alloc;
			Compare		_comp;
			node		*_node;
			size_type	_fill_size;
			size_type	_alloc_size;
	};
}
