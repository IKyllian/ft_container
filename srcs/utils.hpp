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
	
	template<class T, T v>
	struct integral_constant {
		const static T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator value_type() const { return value; }
		value_type operator()() const { return value; }
	};

	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;

	template <class T>	struct is_integral_type                     		: public false_type {};
	template <>			struct is_integral_type<bool>						: public true_type {};
	template <>			struct is_integral_type<char>						: public true_type {};
	template <>			struct is_integral_type<signed char>				: public true_type {};
	template <>			struct is_integral_type<unsigned char>				: public true_type {};
	template <>			struct is_integral_type<wchar_t>					: public true_type {};
	template <>			struct is_integral_type<char16_t>					: public true_type {};
	template <>			struct is_integral_type<char32_t>					: public true_type {};
	template <>			struct is_integral_type<short>						: public true_type {};
	template <>			struct is_integral_type<int>						: public true_type {};
	template <>			struct is_integral_type<unsigned short int>			: public true_type {};
	template <>			struct is_integral_type<unsigned int>				: public true_type {};
	template <>			struct is_integral_type<long>						: public true_type {};
	template <>			struct is_integral_type<unsigned long>				: public true_type {};
	template <>			struct is_integral_type<long long>					: public true_type {};
	template <>			struct is_integral_type<unsigned long long>			: public true_type {};

	template <class T>	struct is_integral : public is_integral_type<T> {};

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