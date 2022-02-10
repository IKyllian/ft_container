#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>


namespace ft
{
	template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
    >
	class map 
	{
		public :
		
		// The first template parameter (Key)
		typedef Key key_type;

		// The second template parameter (T)
		typedef T mapped_type

		


		private :
	}
}
