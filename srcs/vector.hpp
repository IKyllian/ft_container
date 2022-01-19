#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

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

		//typedef iterator

		//typedef reverse_iterator


		/*
			Type qui compte le nombre d'éléments dans un vecteur.
			for the default allocator: const value_type*
		*/
		typedef typename allocator_type::size_type	syze_type;



		// ---------------------- Constructor / Destructor / Asigment operator ---------------------------
		/* Le mot-clé explicit empêche le compilateur d'utiliser ce constructeur pour les conversions implicites
			-> https://webdevdesigner.com/q/what-does-the-explicit-keyword-mean-23047/ */

		// Default constructor. Constructs an empty container, with no elements.
		explicit vector(const allocator_type& alloc = allocator_type());

		// Fill constructor. Constructs a container with n elements. Each element is a copy of val. 
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

		// Range constructor. Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		// Copy constructor. Constructs a container with a copy of each of the elements in x, in the same order.
		vector(const vector& x);

		//Destructor
		~vector();

		//Asigment operator
		vector& operator= (const vector& x);


		// Iterators
		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;
		
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;


		//Capacity
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);


		// Element access
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;

	 	reference at (size_type n);
		const_reference at (size_type n) const;

		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		// Modifiers
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);

		void push_back (const value_type& val);
		void pop_back();

		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void swap (vector& x);
		void clear();

		//Allocator
		allocator_type get_allocator() const;

	};
}

#endif