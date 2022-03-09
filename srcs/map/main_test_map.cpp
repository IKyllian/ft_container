#include <iostream>
#include <map>

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

int main()
{
		std::cout << "----------------------- CONSTRUCTOR -----------------------" << std::endl; 
		{
			std::cout << "Default constructor" << std::endl;
			std::cout << "explicit map (const key_compare& comp = key_compare() const allocator_type& alloc = allocator_type());" << std::endl << std::endl;

			std::map<int, int> map;
			std::map<char, char> map2;
			std::map<int, int, classcomp> map3;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(4, 4));
			map.insert(std::pair<int, int>(5, 5));
			map.insert(std::pair<int, int>(6, 6));

			map3.insert(std::pair<int, int>(1, 1));
			map3.insert(std::pair<int, int>(2, 2));
			map3.insert(std::pair<int, int>(3, 3));
			map3.insert(std::pair<int, int>(4, 4));
			map3.insert(std::pair<int, int>(5, 5));
			map3.insert(std::pair<int, int>(6, 6));

			map2.insert(std::pair<char, char>('a', 'C'));
			map2.insert(std::pair<char, char>('b', 'e'));
			map2.insert(std::pair<char, char>('c', 'u'));
			map2.insert(std::pair<char, char>('d', 't'));
			map2.insert(std::pair<char, char>('e', 'H'));
			map2.insert(std::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (std::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map3.begin(); it!=map3.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Range constructor" << std::endl;
			std::cout << "map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());" << std::endl << std::endl;

			std::map<int, int> map;
			std::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(4, 4));
			map.insert(std::pair<int, int>(5, 5));
			map.insert(std::pair<int, int>(6, 6));

			map2.insert(std::pair<char, char>('a', 'C'));
			map2.insert(std::pair<char, char>('b', 'e'));
			map2.insert(std::pair<char, char>('c', 'u'));
			map2.insert(std::pair<char, char>('d', 't'));
			map2.insert(std::pair<char, char>('e', 'H'));
			map2.insert(std::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (std::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::map<int, int> map_cpy(map.begin(), map.end());
			std::cout << "map_cpy<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::map<char, char> map2_cpy(map2.find('c'), map2.end());
			std::cout << "map2_cpy<char, char> (Start from c) contains:\n";
			for (std::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Copy constructor" << std::endl;
			std::cout << "map (const map& x);" << std::endl << std::endl;

			std::map<int, int> map;
			std::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(4, 4));
			map.insert(std::pair<int, int>(5, 5));
			map.insert(std::pair<int, int>(6, 6));

			map2.insert(std::pair<char, char>('a', 'C'));
			map2.insert(std::pair<char, char>('b', 'e'));
			map2.insert(std::pair<char, char>('c', 'u'));
			map2.insert(std::pair<char, char>('d', 't'));
			map2.insert(std::pair<char, char>('e', 'H'));
			map2.insert(std::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (std::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::map<int, int> map_cpy(map);
			std::cout << "map_cpy<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::map<char, char> map2_cpy(map2);
			std::cout << "map2_cpy<char, char> contains:\n";
			for (std::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
		}

		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Operator =" << std::endl;
			std::cout << "map& operator= (const map& x);" << std::endl << std::endl;

			std::map<int, int> map;
			std::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(4, 4));
			map.insert(std::pair<int, int>(5, 5));
			map.insert(std::pair<int, int>(6, 6));

			map2.insert(std::pair<char, char>('a', 'C'));
			map2.insert(std::pair<char, char>('b', 'e'));
			map2.insert(std::pair<char, char>('c', 'u'));
			map2.insert(std::pair<char, char>('d', 't'));
			map2.insert(std::pair<char, char>('e', 'H'));
			map2.insert(std::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (std::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			
			std::map<int, int> map_cpy = map;
			std::cout << "map_cpy<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::map<char, char> map2_cpy = map2;
			std::cout << "map2_cpy<char, char> contains:\n";
			for (std::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
		}
		std::cout << "----------------------- Empty -----------------------" << std::endl; 
		{
			std::cout << "bool empty() const;" << std::endl << std::endl;

			std::map<int, int> map;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(6, 6));

			std::cout << "is Empty : " << map.empty() << std::endl;

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			map.erase(1);
			map.erase(6);
			std::cout << "is Empty : " << map.empty() << std::endl;
		}
		std::cout << "----------------------- Size -----------------------" << std::endl; 
		{
			std::cout << "size_type size() const;" << std::endl << std::endl;

			std::map<int, int> map;

			std::cout << "Size : " << map.size() << std::endl;

			map.insert(std::pair<int, int>(6, 6));

			std::cout << "Size : " << map.size() << std::endl;

			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(10, 10));
			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(9, 9));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << "Size : " << map.size() << std::endl;
			map.erase(10);
			map.erase(1);
			map.erase(1);
			std::cout << "Size : " << map.size() << std::endl;
			map.clear();
			std::cout << "Size : " << map.size() << std::endl;
		}
		std::cout << "----------------------- Operator[] -----------------------" << std::endl; 
		{
			std::cout << "mapped_type& operator[] (const key_type& k);" << std::endl << std::endl;

			std::map<char, std::string> mymap;

			mymap['a']="an element";
			mymap['b']="another element";
			mymap['c']=mymap['b'];

			std::cout << "mymap['a'] is " << mymap['a'] << '\n';
			std::cout << "mymap['b'] is " << mymap['b'] << '\n';
			std::cout << "mymap['c'] is " << mymap['c'] << '\n';
			std::cout << "mymap['d'] is " << mymap['d'] << '\n';

			std::cout << "mymap now contains " << mymap.size() << " elements.\n";
		}
		std::cout << "----------------------- Insert -----------------------" << std::endl; 
		{
			std::cout << "pair<iterator,bool> insert (const value_type& val);" << std::endl << std::endl;

			std::map<int, int> map;
			std::pair<std::map<int, int>::iterator, bool> ret;

			std::cout << "Insert 6" << std::endl;
			ret = map.insert(std::pair<int, int>(6, 6));
			std::cout << "Value it (Key) = " << ret.first->first << " - (Value) = " << ret.first->second << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert some values" << std::endl;
			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(10, 10));
			map.insert(std::pair<int, int>(1, 1));
			std::cout << "Insert 9" << std::endl;
			ret = map.insert(std::pair<int, int>(9, 9));
			std::cout << "Value it (Key) = " << ret.first->first << " - (Value) = " << ret.first->second << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert 10 who already exists" << std::endl;
			ret = map.insert(std::pair<int, int>(10, 10));
			std::cout << "Value it (Key) = " << ret.first->first << " - (Value) = " << ret.first->second << " - Bool = " << ret.second << std::endl;
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "iterator insert (iterator position, const value_type& val);" << std::endl << std::endl;

		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "void insert (InputIterator first, InputIterator last);" << std::endl << std::endl;
			std::map<int, int> map;

			map.insert(std::pair<int, int>(6, 6));
			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(10, 10));
			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(9, 9));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::map<int, int> map2;

			std::cout << "Insert from begin to end of map1" << std::endl;
			map2.insert(map.begin(), map.end());

			std::cout << "map2<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << std::endl;
			std::map<char, std::string> map3;

			map3['a']="First Element";
			map3['b']="Second Element";
			map3['c']="Third Element";
			map3['d']="Fourth Element";
			map3['e']="Fifth Element";
			map3['f']="Sixth Element";

			std::cout << "map3<char, std::string> contains:\n";
			for (std::map<char, std::string>::iterator it=map3.begin(); it!=map3.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::map<char, std::string> map4;
			std::cout << "Insert from c to e of map3" << std::endl;
			map4.insert(map3.find('c'), map3.find('f'));

			std::cout << "map4<char, std::string> contains:\n";
			for (std::map<char, std::string>::iterator it=map4.begin(); it!=map4.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << std::endl;
			std::map<char, std::string> map5;
			std::cout << "Insert from begin to begin of map4" << std::endl;

			std::cout << "Map 5 is empty " << map5.empty() << std::endl;

			std::cout << std::endl;
			std::map<char, std::string> map6;
			std::map<char, std::string>::iterator it = map4.begin();
			std::cout << "Insert from begin to begin++ of map4" << std::endl;
			map6.insert(it, ++it);			
			std::cout << "map6<char, std::string> contains:\n";
			for (std::map<char, std::string>::iterator it=map6.begin(); it!=map6.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "----------------------- Erase -----------------------" << std::endl; 
		{
			std::cout << " void erase (iterator position);" << std::endl << std::endl;

			std::map<int, int> map;

			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(10, 10));
			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(5, 5));
			map.insert(std::pair<int, int>(30, 30));
			map.insert(std::pair<int, int>(12, 12));
			map.insert(std::pair<int, int>(15, 15));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5" << std::endl;
			map.erase(map.find(5));
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 1, 3, 2" << std::endl;
			map.erase(map.find(1));
			map.erase(map.find(3));
			map.erase(map.find(2));
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "size_type erase (const key_type& k);" << std::endl << std::endl;

			std::map<int, int> map;
			int ret;

			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(10, 10));
			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(5, 5));
			map.insert(std::pair<int, int>(30, 30));
			map.insert(std::pair<int, int>(12, 12));
			map.insert(std::pair<int, int>(15, 15));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5" << std::endl;
			ret = map.erase(5);
			std::cout << "Ret = " << ret << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 1, 3, 2" << std::endl;
			map.erase(1);
			map.erase(3);
			map.erase(2);
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5 that has already been deleted " << std::endl;
			ret = map.erase(5);
			std::cout << "Ret = " << ret << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "void erase (iterator first, iterator last); " << std::endl << std::endl;

			std::map<int, int> map;

			map.insert(std::pair<int, int>(3, 3));
			map.insert(std::pair<int, int>(2, 2));
			map.insert(std::pair<int, int>(10, 10));
			map.insert(std::pair<int, int>(1, 1));
			map.insert(std::pair<int, int>(5, 5));
			map.insert(std::pair<int, int>(30, 30));
			map.insert(std::pair<int, int>(12, 12));
			map.insert(std::pair<int, int>(15, 15));

			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase from begin to begin" << std::endl;
			map.erase(map.begin(), map.begin());
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase from begin to 10" << std::endl;
			map.erase(map.begin(), map.find(10));
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase begin from end " << std::endl;
			map.erase(map.begin(), map.end());
			std::cout << "map<int, int> contains:\n";
			for (std::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "Map is empty = " << map.empty() << " - Size = " << map.size() << std::endl;
		}
		std::cout << "----------------------- Swap -----------------------" << std::endl; 
		{
			std::cout << "void swap (map& x);" << std::endl << std::endl;

			std::map<char,int> foo,bar;

			foo['x']=100;
			foo['y']=200;

			bar['a']=11;
			bar['b']=22;
			bar['c']=33;

			foo.swap(bar);

			std::cout << "foo contains:\n";
			for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "bar contains:\n";
			for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "----------------------- Clear -----------------------" << std::endl; 
		{
			std::cout << "void clear();" << std::endl << std::endl;

			 std::map<char,int> mymap;

			mymap['x']=100;
			mymap['y']=200;
			mymap['z']=300;

			std::cout << "mymap contains:\n";
			for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			mymap.clear();
			mymap['a']=1101;
			mymap['b']=2202;

			std::cout << "mymap contains:\n";
			for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << "Clear all" << std::endl;
			mymap.clear();
			std::cout << "Map is empty " << mymap.empty() << std::endl;
			
			std::cout << "Try to clear on empty map" << std::endl;
			mymap.clear();
		}

























	// std::map<int, char, classcomp> mp;
	// std::cout << " Size = " << mp.size() << std::endl;
	// mp[5]= 'd';
	// mp[3]= 'c';
	// mp[1]= 'a';
	// mp[2]= 'b';
	// std::cout << " Size = " << mp.size() << std::endl;
	// for (std::map<int, char>::iterator it = mp.begin(); it != mp.end(); it++)
	// 	std::cout << "Elem First = " << (*it).first << " Second = " << (*it).second << std::endl;
	// std::cout << std::endl;
	// std::map<int, char> second(mp.begin(), mp.end());
	// for (std::map<int, char>::iterator it = mp.begin(); it != mp.end(); it++)
	// 	std::cout << "Elem First = " << (*it).first << " Second = " << (*it).second << std::endl;
	// std::cout << std::endl;

	// std::map<int, char, classcomp> mp2;

	// mp2 = mp;
	// for (std::map<int, char>::iterator it = mp2.begin(); it != mp2.end(); it++)
	// 	std::cout << "Elem First = " << (*it).first << " Second = " << (*it).second << std::endl;
	// std::map<int, int> map;
	// std::map<int, int> map2;

	// std::cout << " !!!!!! 1 !!!!!"  << std::endl;
	// map.insert(std::pair<int, int>(1, 1));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(std::pair<int, int>(4, 4));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(std::pair<int, int>(2, 2));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(std::pair<int, int>(6, 6));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(5, 5));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(3, 3));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(9, 9));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(7, 7));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(10, 10));
	// std::cout << " ------------------" << std::endl;

	// std::pair<std::map<int, int>::iterator, bool> pair = map.insert(std::pair<int, int>(7, 11));

	// std::cout << "First (Key) = " << pair.first->first << " - (Value) = " << pair.first->second << " - Second = " << pair.second << std::endl;


	// std::cout << "Count = " << map.count(0) << std::endl;

	// std::map<int, int>::iterator it = map.lower_bound(1);
	// std::cout << "Key = " << (*it).first << std::endl;

	// std::map<int, int>::iterator it2 = map.upper_bound(4);
	// std::cout << "Key = " << (*it2).first << std::endl;

	// std::map<int, int>::iterator  it3 = map.find(7);
	// std::cout << "Key = " << (*it3).first << std::endl;

	// std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> pair = map.equal_range(5);
	// std::cout << "First Key = " << pair.first->first << " - Second Key = " << pair.second->second << std::endl;

	// std::map<char,int> foo,bar;

	// foo['x']=100;
	// foo['y']=200;

	// bar['a']=11;
	// bar['b']=22;
	// bar['c']=33;

	// foo.swap(bar);

	// std::cout << "foo contains:\n";
	// for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

	// std::cout << "bar contains:\n";
	// for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';








	// map.insert(std::pair<int, int>(13, 13));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(std::pair<int, int>(8, 8));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(std::pair<int, int>(17, 17));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(1, 1));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(11, 11));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(6, 6));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(15, 15));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(25, 25));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(22, 22));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(std::pair<int, int>(27, 27));
	// std::cout << " ------------------"  << std::endl;

	// std::cout << "astder Delete"  << std::endl << std::endl;
	// std::map<int,int>::iterator it = map.find(11);
	// map.erase(it);
	// map.erase(11);
	// it++;

	// std::cout << "map contains:\n";
	// for (std::map<int,int>::iterator it2= map.begin(); it2 !=map.end(); ++it2)
	// 	std::cout << it2->first << " => " << it2->second << '\n';

	// std::cout << "map contains:\n";
	// for (; it!=map.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

	return (0);	
}