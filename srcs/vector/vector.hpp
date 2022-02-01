#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "vector_iterator.hpp"
#include "vector_const_iterator.hpp"
#include "vector_reverse_iterator.hpp"
#include "vector_const_reverse_iterator.hpp"

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
			//need to allocate ptr before loop (could be with allocate function of allocator class or reserve function of vector class)
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
			this->_fill_size = n;
			this->_alloc_size = n;
		};

		// Range constructor. Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		// template <class InputIterator>
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		// Copy constructor. Constructs a container with a copy of each of the elements in x, in the same order.
		vector(const vector& x) { *this = x; };

		//Destructor
		~vector() {
			if (_fill_size > 0)
			{
				for (size_type i = 0; i < _fill_size; i++)
					_alloc.destroy(_ptr + i);
			}
			if (_alloc_size > 0)
				_alloc.deallocate(_ptr, _alloc_size);
			_alloc_size = 0;
			_fill_size = 0;
		};

		//Asigment operator
		// vector& operator=(const vector& x);


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
			return (iterator(this->_ptr + this->size()));
		};
		
		reverse_iterator rbegin() { return (reverse_iterator(this->end())); }; // A revoir pour la position de l'iterateur
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }; // A revoir pour la position de l'iterateur

		reverse_iterator rend() { return (reverse_iterator(this->begin())); }; // A revoir pour la position de l'iterateur
		const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }; // A revoir pour la position de l'iterateur


		//Capacity
		size_type size() const { return (_fill_size); };
		size_type max_size() const { return (std::numeric_limits<size_type>::max()); };
		void resize (size_type n, value_type val = value_type()) {
			if (n < this->_fill_size)
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

				if (n > this->_alloc_size)
					new_ptr = this->_alloc.allocate(n);
				else
					new_ptr = this->_alloc.allocate(this->_alloc_size);
				for (size_type i = 0; i < this->_fill_size; i++)
					this->_alloc.construct(this->_ptr + i, *(this->_ptr + i));
				for (size_type i = this->_fill_size; i < n; i++)
					this->_alloc.construct(this->_ptr + i, val);
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

		reference front() { return (this->*_ptr); };
		const_reference front() const { return (this->*_ptr); };

		reference back() { return (*(this->_ptr + (this->_fill_size - 1))); };
		const_reference back() const { return (*(this->_ptr + (this->_fill_size - 1))); };

		// Modifiers
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last) {
			this->clear();
			
		};
		// void assign (size_type n, const value_type& val);

		// void push_back (const value_type& val);
		// void pop_back();

		iterator insert(iterator position, const value_type& val) {
			difference_type diff = position - begin();
			if (this->_fill_size + 1 > this->_alloc_size)
				this->reserve(this->_alloc_size + 1);
			if (_fill_size == diff)
			{
				_alloc.construct(_ptr + _fill_size, val);
				_fill_size++;
				return (position + 1);
			}
			_alloc.construct(_ptr + _fill_size, _ptr[_fill_size - 1]);
			for (size_type i = _fill_size - 1; i > diff; i--)
				_ptr[i] = _ptr[i - 1];
			this->at(diff) = val;
			_fill_size++;
			return (position + 1);
		};
		// void insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator>
    	// void insert (iterator position, InputIterator first, InputIterator last);

		// iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);

		// void swap (vector& x);
		void clear() {
			for (int i = 0; i < this->_fill_size; i++)
				this->_alloc.destroy(this->_ptr + i);
			this->_fill_size = 0;
		};

		//Allocator
		// allocator_type get_allocator() const;

		private :
			Alloc _alloc;
			T *_ptr;
			// T *_end_ptr; // Sert pour resize plus facilement le container
			size_t _alloc_size;
			size_t _fill_size;
	};
}

#endif