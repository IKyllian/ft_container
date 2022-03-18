#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

	template <bool Cond, typename T = void>
	struct enable_if { };

	template <typename T>
	struct enable_if<true, T> {
    	typedef T type;
	};

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                	InputIterator2 first2, InputIterator2 last2,
                                	Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
	

	template <bool is_integral, typename T>
    struct integral_const {
		typedef T type;
		static const bool value = is_integral;
    };

    template <typename>
        struct is_integral_type : public integral_const<false, bool> {};

    template <>
        struct is_integral_type<bool> : public integral_const<true, bool> {};

	template <>
        struct is_integral_type<int> : public integral_const<true, int> {};

    template <>
        struct is_integral_type<long int> : public integral_const<true, long int> {};

    template <>
        struct is_integral_type<long long int> : public integral_const<true, long long int> {};

    template <>
        struct is_integral_type<unsigned char> : public integral_const<true, unsigned char> {};

    template <>
        struct is_integral_type<unsigned short int> : public integral_const<true, unsigned short int> {};

    template <>
        struct is_integral_type<unsigned int> : public integral_const<true, unsigned int> {};

    template <>
        struct is_integral_type<unsigned long int> : public integral_const<true, unsigned long int> {};
    
    template <>
        struct is_integral_type<unsigned long long int> : public integral_const<true, unsigned long long int> {};

    template <>
        struct is_integral_type<char> : public integral_const<true, char> {};

    template <>
        struct is_integral_type<signed char> : public integral_const<true, signed char> {};

    template <>
        struct is_integral_type<short int> : public integral_const<true, short int> {};

    template <typename T>
        struct is_integral : public is_integral_type<T> { };

	template <class T1, class T2>
	class pair
	{
		public :

			typedef T1 first_type;
			typedef T2 second_type;

			// Default constructor
			pair() : first(), second() {};

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
			
			pair& operator=(const pair &src) {
				if (*this == src)
					return (*this);
				this->first = src.first;
				this->second = src.second;
				return (*this);
			};
			
			// Member Type
			first_type	first;
			second_type	second;
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first==rhs.first && lhs.second==rhs.second);
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
		return (rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs<rhs);
	}

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y) {
		return (ft::pair<T1,T2>(x,y));
	};

}

#endif