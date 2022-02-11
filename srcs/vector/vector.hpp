#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include <type_traits> // A supprimer plus tard
#include "vector_iterator.hpp"
#include "vector_const_iterator.hpp"
#include "vector_reverse_iterator.hpp"
#include "vector_const_reverse_iterator.hpp"
#include "../utils.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
		public :

		// --------- Typedef ----------

		/*
			The first template parameter
		*/
		typedef T	value_type;

		/*
			The second template parameter
			defaults to: allocator<value_type>
		*/
		typedef Alloc allocator_type;

		/*
			Type qui fournit une référence à un élément stocké dans un vecteur.
			for the default allocator: value_type&
		*/
		typedef typename allocator_type::reference	reference;

		/*
			Type qui fournit une référence à un const élément stocké dans un vecteur.
			Elle est utilisée pour la lecture et l’utilisation des const opérations.
			for the default allocator: const value_type&
		*/
		typedef typename allocator_type::const_reference const_reference;

		/*
			Type qui fournit un pointeur vers un élément d'un vecteur.
			for the default allocator: value_type*
		*/
		typedef typename allocator_type::pointer pointer;
		
		/*
			Type qui fournit un pointeur vers un élément const d'un vecteur.
			for the default allocator: const value_type*
		*/
		typedef typename allocator_type::const_pointer const_pointer;

		typedef typename ft::vectorIterator<T> iterator;
		typedef typename ft::vectorConstIterator<T> const_iterator;

		typedef typename ft::vectorReverseIterator<iterator> reverse_iterator;
		typedef typename ft::vectorConstReverseIterator<iterator> const_reverse_iterator;

		/*
			Type qui compte le nombre d'éléments dans un vecteur.
			for the default allocator: const value_type*
		*/
		typedef typename allocator_type::size_type	size_type;

		typedef typename std::ptrdiff_t difference_type;



		// ---------------------- Constructor / Destructor / Asigment operator ---------------------------
		/* Le mot-clé explicit empêche le compilateur d'utiliser ce constructeur pour les conversions implicites
			-> https://webdevdesigner.com/q/what-does-the-explicit-keyword-mean-23047/ */

		// Default constructor. Constructs an empty container, with no elements.
		explicit vector(const allocator_type& alloc = allocator_type()): _alloc_size(0), _fill_size(0), _ptr(NULL), _alloc(alloc) {};

		// Fill constructor. Constructs a container with n elements. Each element is a copy of val. 
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
		{
			_ptr = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
			this->_fill_size = n;
			this->_alloc_size = n;
		};

		// Range constructor. Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		template<class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _alloc(alloc), _fill_size(0), _alloc_size(0), _ptr(NULL) {
			difference_type size = last - first;
			this->_alloc_size = size;
			this->_ptr = _alloc.allocate(size);
			for (; first != last; first++)
				this->push_back(*first);
		};

		// Copy constructor. Constructs a container with a copy of each of the elements in x, in the same order.
		vector(const vector& x) { 
			this->_alloc = x._alloc;
			this->_alloc_size = x._alloc_size;
			this->_ptr = this->_alloc.allocate(this->_alloc_size);
			for (size_type i = 0; i < x._fill_size; i++)
				this->_alloc.construct(this->_ptr + i, x[i]);
			this->_fill_size = x._fill_size;	
		};

		//Destructor
		~vector() {
			// if (_fill_size > 0)
			// {
			// 	for (size_type i = 0; i < _fill_size; i++)
			// 		_alloc.destroy(_ptr + i);
			// }
			// if (_alloc_size > 0)
			// 	_alloc.deallocate(_ptr, _alloc_size);
			// _alloc_size = 0;
			// _fill_size = 0;
		};

		//Asigment operator
		vector& operator=(const vector& x) {
			this->clear();
			for (iterator it(x.begin()); it != x.end(); it++)
				this->push_back(*it);
			return (*this);
		};


		// Iterators
		iterator begin() { return (iterator(this->_ptr)); };
		const_iterator begin() const { return (const_iterator(this->_ptr)); };

		iterator end() { 
			if (this->empty())
				return (this->begin());
			return (iterator(this->_ptr + this->size()));
		};
		const_iterator end() const {
			if (this->empty())
				return (this->begin());
			return (const_iterator(this->_ptr + this->size()));
		};
		
		reverse_iterator rbegin() { return (reverse_iterator(--(this->end()))); }; // A revoir pour la position de l'iterateur
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(--(this->end()))); }; // A revoir pour la position de l'iterateur

		reverse_iterator rend() { return (reverse_iterator(--(this->begin()))); }; // A revoir pour la position de l'iterateur
		const_reverse_iterator rend() const { return (const_reverse_iterator(--(this->begin()))); }; // A revoir pour la position de l'iterateur


		//Capacity
		size_type size() const { return (_fill_size); };
		size_type max_size() const { return (std::numeric_limits<size_type>::max()); };
		void resize (size_type n, value_type val = value_type()) {
			if (n > this->max_size())
			 	throw std::out_of_range("Vector:: resize error");
			else if (n < this->_fill_size)
			{
				for (size_type i = 0; i <= n; i++)
				{
					if (i == n)
					{
						for (; i <= this->_fill_size; i++)
						{
							if (i == this->_fill_size)
							{
								this->_fill_size = n;
								return ;
							}
							this->_alloc.destroy(this->_ptr + i);
						}
					}
				}
			}
			else
			{
				T *new_ptr;
				size_type size = get_new_alloc_size(n);
				new_ptr = this->_alloc.allocate(size);
				_alloc_size = size;
				for (size_type i = 0; i < this->_fill_size; i++)
					this->_alloc.construct(new_ptr + i, *(this->_ptr + i));
				for (size_type i = this->_fill_size; i < n; i++)
					this->_alloc.construct(new_ptr + i, val);
				_ptr = new_ptr;
				_fill_size = n;
				// Peut faire cette partie plus proprement avec la fontion insert (quand elle sera faite), qui allouera automatiquent.
			}
		};
		size_type capacity() const { return (_alloc_size); };
		bool empty() const {
			if (_fill_size == 0)
				return (true);
			return (false);
		};
		void reserve (size_type n) {
			if (n > this->max_size())
				throw std::length_error("Size is greater than the vector maximum size");
			if (n > this->_alloc_size)
			{
				T *new_ptr;
				// Fill new ptr with values of old one
				new_ptr = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_fill_size; i++)
					this->_alloc.construct(new_ptr + i, *(this->_ptr + i));
				// Free old ptr
				for (size_type i = 0; i < this->_fill_size; i++)
					this->_alloc.destroy(this->_ptr + i);
				this->_alloc.deallocate(this->_ptr, this->_alloc_size);
				this->_ptr = new_ptr;
				this->_alloc_size = n;
			}
		};


		// Element access
		reference operator[](size_type n) { return (this->_ptr[n]); };
		const_reference operator[](size_type n) const { return (this->_ptr[n]); };

	 	reference at(size_type n) {
			if (n >= this->size())
			 	throw std::out_of_range("Out of range");
			return (this->_ptr[n]);
		 };
		const_reference at(size_type n) const {
			if (n >= this->size())
			 	throw std::out_of_range("Out of range");
			return (this->_ptr[n]);
		};

		reference front() { return (*(this->_ptr)); };
		const_reference front() const { return (*(this->_ptr)); };

		reference back() { return (*(this->_ptr + (this->_fill_size - 1))); };
		const_reference back() const { return (*(this->_ptr + (this->_fill_size - 1))); };

		// Modifiers
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
			difference_type size = last - first;
			this->clear();
			if (this->_alloc_size < size)
				this->reserve(size);
			for (iterator it(first); first != last; it++)
				_alloc.construct(_ptr + this->_fill_size++, *it);
		};
		void assign (size_type n, const value_type& val) {
			this->clear();
			if (this->_alloc_size < n)
				this->reserve(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
			this->_fill_size = n;
		};

		void push_back (const value_type& val) {
			this->insert(this->end(), 1, val);
		};
		void pop_back() {
			if (this->empty())
				return ;
			this->_alloc.destroy(this->_ptr + this->_fill_size - 1);
			this->_fill_size--;
		};

		iterator insert(iterator position, const value_type& val) {
			difference_type idx = position - begin();
			this->insert(position, 1, val);
			return (iterator(this->_ptr + idx));
		};
		void insert (iterator position, size_type n, const value_type& val) {
			difference_type idx = position - begin();
			if (this->_fill_size + n > this->_alloc_size)
				this->reserve(get_new_alloc_size(this->_fill_size + n));
			if (_fill_size == idx)
			{
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_ptr + (this->_fill_size + i), val);
				_fill_size += n;
				return ;
			}
			// Alloue un nouveau element à la fin du tableau et décalle tout le tableau sur la droite
			for (size_type i = 0; i < n; i++) {
				_alloc.construct(_ptr + _fill_size, _ptr[_fill_size - 1 ]);
				for (size_type j = _fill_size - 1; j > idx; j--)
					_ptr[j] = _ptr[j - 1];
				_fill_size++;
			}
			for (size_type i = 0; i < n; i++)
				this->at(idx + i) = val;
		};
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = NULL ) {
			difference_type size = last - first;
			difference_type idx = position - begin();

			if (this->_fill_size + size > this->_alloc_size)
				this->reserve(get_new_alloc_size(this->_fill_size + size));
			if (_fill_size == idx)
			{
				for (iterator it(first); it != last; it++)
					_alloc.construct(_ptr + (this->_fill_size++), *it);
				// _fill_size += size;
				return ;
			}
			// Alloue un nouveau element à la fin du tableau et décalle tout le tableau sur la droite
			for (size_type i = 0; i < size; i++) {
				_alloc.construct(_ptr + _fill_size, _ptr[_fill_size - 1 ]);
				for (size_type j = _fill_size - 1; j > idx; j--)
					_ptr[j] = _ptr[j - 1];
				_fill_size++;
			}
			for (iterator it(first); it != last; it++)
				this->at(idx++) = *it;
		};

		iterator erase (iterator position) {
			difference_type idx = position - begin();
			if (_fill_size == idx)
				return (this->end()); // check si il faut renvoyer une erreur
			else if ((_fill_size - 1) == idx)
			{
				pop_back();
				return (this->end());
			}
			vector temp(position + 1, this->end());

			for (size_type i = 0; i <= temp.size(); i++)
				this->pop_back();
			for (iterator it = temp.begin(); it != temp.end(); it++)
				this->push_back(*it);
			return (iterator(this->_ptr + idx));
		};
		iterator erase (iterator first, iterator last) {
			for (iterator it(first); it != last; it++)
				this->erase(first);
			return (first); // !!!!!!!!!!!!!!!!! Probleme avec la valeur de retour
		};

		void swap (vector& x) {
			T *temp_ptr;
			size_t temp_alloc_size;
			size_t temp_fill_size;

			temp_ptr = this->_ptr;
			temp_alloc_size = this->_alloc_size;
			temp_fill_size = this->_fill_size;
			

			this->_ptr = x._ptr;
			this->_alloc_size = x._alloc_size;
			this->_fill_size = x._fill_size;

			x._ptr = temp_ptr;
			x._alloc_size = temp_alloc_size;
			x._fill_size = temp_fill_size;

		};

		void clear() {
			for (int i = 0; i < this->_fill_size; i++)
				this->_alloc.destroy(this->_ptr + i);
			this->_fill_size = 0;
		};

		//Allocator
		allocator_type get_allocator() const { return (this->_alloc); };


		private :
			Alloc _alloc;
			T *_ptr;
			size_t _alloc_size;
			size_t _fill_size;
			
			// Fonction qui sert pour realloc le container a la bonne taille
			size_t get_new_alloc_size(size_type n) {
				if (n > this->max_size())
					throw std::out_of_range("Vector:: resize error");
				else if (n <= this->_alloc_size)
					return (this->_alloc_size);
				if (this->_alloc_size * 2 >= n)
				{
					if (this->_alloc_size * 2 > this->max_size())
						throw std::out_of_range("Vector:: resize error");
					return (this->_alloc_size * 2);
				}
				else
					return (n);
			}
	};

template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	for(int i = 0; i < lhs.size(); i++)
		if (lhs.at(i) != rhs.at(i))
			return (false);
	return (true);
};	

	template <class T, class Alloc>
	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return (!(lhs == rhs)); };

	template <class T, class Alloc>
	bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
	bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return (!(rhs < lhs)); };


	template <class T, class Alloc>
	bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return (rhs < lhs); };


	template <class T, class Alloc>
	bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return (!(lhs < rhs)); };


	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
		x.swap(y);
	};
}

#endif