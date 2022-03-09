#include "map.hpp"
#include "node_tree.hpp"


struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

int main() {
		std::cout << "----------------------- FT CONSTRUCTOR -----------------------" << std::endl; 
		{
			std::cout << "Default constructor" << std::endl;
			std::cout << "explicit map (const key_compare& comp = key_compare() const allocator_type& alloc = allocator_type());" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::map<char, char> map2;
			ft::map<int, int, classcomp> map3;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(4, 4));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(6, 6));

			map3.insert(ft::pair<int, int>(1, 1));
			map3.insert(ft::pair<int, int>(2, 2));
			map3.insert(ft::pair<int, int>(3, 3));
			map3.insert(ft::pair<int, int>(4, 4));
			map3.insert(ft::pair<int, int>(5, 5));
			map3.insert(ft::pair<int, int>(6, 6));

			map2.insert(ft::pair<char, char>('a', 'C'));
			map2.insert(ft::pair<char, char>('b', 'e'));
			map2.insert(ft::pair<char, char>('c', 'u'));
			map2.insert(ft::pair<char, char>('d', 't'));
			map2.insert(ft::pair<char, char>('e', 'H'));
			map2.insert(ft::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map3.begin(); it!=map3.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Range constructor" << std::endl;
			std::cout << "map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(4, 4));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(6, 6));

			map2.insert(ft::pair<char, char>('a', 'C'));
			map2.insert(ft::pair<char, char>('b', 'e'));
			map2.insert(ft::pair<char, char>('c', 'u'));
			map2.insert(ft::pair<char, char>('d', 't'));
			map2.insert(ft::pair<char, char>('e', 'H'));
			map2.insert(ft::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			ft::map<int, int> map_cpy(map.begin(), map.end());
			std::cout << "map_cpy<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			ft::map<char, char> map2_cpy(map2.find('c'), map2.end());
			std::cout << "map2_cpy<char, char> (Start from c) contains:\n";
			for (ft::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Copy constructor" << std::endl;
			std::cout << "map (const map& x);" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(4, 4));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(6, 6));

			map2.insert(ft::pair<char, char>('a', 'C'));
			map2.insert(ft::pair<char, char>('b', 'e'));
			map2.insert(ft::pair<char, char>('c', 'u'));
			map2.insert(ft::pair<char, char>('d', 't'));
			map2.insert(ft::pair<char, char>('e', 'H'));
			map2.insert(ft::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;

			ft::map<int, int> map_cpy(map);
			std::cout << "map_cpy<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			ft::map<char, char> map2_cpy(map2);
			std::cout << "map2_cpy<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
		}

		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Operator =" << std::endl;
			std::cout << "map& operator= (const map& x);" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(4, 4));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(6, 6));

			map2.insert(ft::pair<char, char>('a', 'C'));
			map2.insert(ft::pair<char, char>('b', 'e'));
			map2.insert(ft::pair<char, char>('c', 'u'));
			map2.insert(ft::pair<char, char>('d', 't'));
			map2.insert(ft::pair<char, char>('e', 'H'));
			map2.insert(ft::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			
			ft::map<int, int> map_cpy = map;
			std::cout << "map_cpy<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
			ft::map<char, char> map2_cpy = map2;
			std::cout << "map2_cpy<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;
		}
		std::cout << "----------------------- FT Empty -----------------------" << std::endl; 
		{
			std::cout << "bool empty() const;" << std::endl << std::endl;

			ft::map<int, int> map;

			std::cout << "is Empty : " << map.empty() << std::endl;

			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(6, 6));

			std::cout << "is Empty : " << map.empty() << std::endl;

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			map.erase(1);
			map.erase(6);
			std::cout << "is Empty : " << map.empty() << std::endl;
		}
		std::cout << "----------------------- FT Size -----------------------" << std::endl; 
		{
			std::cout << "size_type size() const;" << std::endl << std::endl;

			ft::map<int, int> map;

			std::cout << "Size : " << map.size() << std::endl;

			map.insert(ft::pair<int, int>(6, 6));

			std::cout << "Size : " << map.size() << std::endl;

			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(9, 9));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << "Size : " << map.size() << std::endl;
			map.erase(10);
			map.erase(1);
			map.erase(1);
			std::cout << "Size : " << map.size() << std::endl;
			map.clear();
			std::cout << "Size : " << map.size() << std::endl;
		}

		std::cout << "----------------------- FT Operator[] -----------------------" << std::endl; 
		{
			std::cout << "mapped_type& operator[] (const key_type& k);" << std::endl << std::endl;

			ft::map<char, std::string> mymap;

			mymap['a']="an element";
			mymap['b']="another element";
			mymap['c']=mymap['b'];

			std::cout << "mymap['a'] is " << mymap['a'] << '\n';
			std::cout << "mymap['b'] is " << mymap['b'] << '\n';
			std::cout << "mymap['c'] is " << mymap['c'] << '\n';
			std::cout << "mymap['d'] is " << mymap['d'] << '\n';

			std::cout << "mymap now contains " << mymap.size() << " elements.\n";
		}
		std::cout << "----------------------- FT Insert -----------------------" << std::endl; 
		{
			std::cout << "pair<iterator,bool> insert (const value_type& val);" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::pair<ft::map<int, int>::iterator, bool> ret;

			std::cout << "Insert 6" << std::endl;
			ret = map.insert(ft::pair<int, int>(6, 6));
			std::cout << "Value it (Key) = " << ret.first->_pair.first << " - (Value) = " << ret.first->_pair.second << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert some values" << std::endl;
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));
			std::cout << "Insert 9" << std::endl;
			ret = map.insert(ft::pair<int, int>(9, 9));
			std::cout << "Value it (Key) = " << ret.first->_pair.first << " - (Value) = " << ret.first->_pair.second << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert 10 who already exists" << std::endl;
			ret = map.insert(ft::pair<int, int>(10, 10));
			std::cout << "Value it (Key) = " << ret.first->_pair.first << " - (Value) = " << ret.first->_pair.second << " - Bool = " << ret.second << std::endl;
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "iterator insert (iterator position, const value_type& val);" << std::endl << std::endl;

		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "void insert (InputIterator first, InputIterator last);" << std::endl << std::endl;
			ft::map<int, int> map;

			map.insert(ft::pair<int, int>(6, 6));
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(9, 9));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

			ft::map<int, int> map2;

			std::cout << "Insert from begin to end of map1" << std::endl;
			map2.insert(map.begin(), map.end());

			std::cout << "map2<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

			std::cout << std::endl;
			ft::map<char, std::string> map3;

			map3['a']="First Element";
			map3['b']="Second Element";
			map3['c']="Third Element";
			map3['d']="Fourth Element";
			map3['e']="Fifth Element";
			map3['f']="Sixth Element";

			std::cout << "map3<char, std::string> contains:\n";
			for (ft::map<char, std::string>::iterator it=map3.begin(); it!=map3.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

			ft::map<char, std::string> map4;
			std::cout << "Insert from c to e of map3" << std::endl;
			map4.insert(map3.find('c'), map3.find('f'));

			std::cout << "map4<char, std::string> contains:\n";
			for (ft::map<char, std::string>::iterator it=map4.begin(); it!=map4.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

			std::cout << std::endl;
			ft::map<char, std::string> map5;
			std::cout << "Insert from begin to begin of map4" << std::endl;

			std::cout << "Map 5 is empty " << map5.empty() << std::endl;

			std::cout << std::endl;
			ft::map<char, std::string> map6;
			ft::map<char, std::string>::iterator it = map4.begin();
			std::cout << "Insert from begin to begin++ of map4" << std::endl;
			map6.insert(it, ++it);			
			std::cout << "map6<char, std::string> contains:\n";
			for (ft::map<char, std::string>::iterator it=map6.begin(); it!=map6.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
		}

		std::cout << "----------------------- FT Erase -----------------------" << std::endl; 
		{
			std::cout << " void erase (iterator position);" << std::endl << std::endl;

			ft::map<int, int> map;

			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(30, 30));
			map.insert(ft::pair<int, int>(12, 12));
			map.insert(ft::pair<int, int>(15, 15));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5" << std::endl;
			map.erase(map.find(5));
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

			std::cout << std::endl;
			std::cout << "Erase 1, 3, 2" << std::endl;
			map.erase(map.find(1));
			map.erase(map.find(3));
			map.erase(map.find(2));
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "size_type erase (const key_type& k);" << std::endl << std::endl;

			ft::map<int, int> map;
			int ret;

			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(30, 30));
			map.insert(ft::pair<int, int>(12, 12));
			map.insert(ft::pair<int, int>(15, 15));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5" << std::endl;
			ret = map.erase(5);
			std::cout << "Ret = " << ret << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 1, 3, 2" << std::endl;
			map.erase(1);
			map.erase(3);
			map.erase(2);
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5 that has already been deleted " << std::endl;
			ret = map.erase(5);
			std::cout << "Ret = " << ret << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "void erase (iterator first, iterator last); " << std::endl << std::endl;

			ft::map<int, int> map;

			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(30, 30));
			map.insert(ft::pair<int, int>(12, 12));
			map.insert(ft::pair<int, int>(15, 15));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;

			std::cout << "Erase from begin to begin" << std::endl;
			map.erase(map.begin(), map.begin());
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;

			std::cout << "Erase from begin to 10" << std::endl;
			map.erase(map.begin(), map.find(10));
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << std::endl;

			std::cout << "Erase begin from end " << std::endl;
			map.erase(map.begin(), map.end());
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

			std::cout << "Map is empty = " << map.empty() << " - Size = " << map.size() << std::endl;
		}

		std::cout << "----------------------- FT Swap -----------------------" << std::endl; 
		{
			std::cout << "void swap (map& x);" << std::endl << std::endl;

			ft::map<char,int> foo,bar;

			foo['x']=100;
			foo['y']=200;

			bar['a']=11;
			bar['b']=22;
			bar['c']=33;

			foo.swap(bar);

			std::cout << "foo contains:\n";
			for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

			std::cout << "bar contains:\n";
			for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
		}
		std::cout << "----------------------- FT Clear -----------------------" << std::endl; 
		{
			std::cout << "void clear();" << std::endl << std::endl;

			 ft::map<char,int> mymap;

			mymap['x']=100;
			mymap['y']=200;
			mymap['z']=300;

			std::cout << "mymap contains:\n";
			for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

			mymap.clear();
			mymap['a']=1101;
			mymap['b']=2202;

			std::cout << "mymap contains:\n";
			for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			std::cout << "Clear all" << std::endl;
			mymap.clear();
			std::cout << "Map is empty " << mymap.empty() << std::endl;

			std::cout << "Try to clear on empty map" << std::endl;
			mymap.clear();
		}
		std::cout << "----------------------- FT Key Comp -----------------------" << std::endl; 
		{
			std::cout << "key_compare key_comp() const;" << std::endl << std::endl;

			ft::map<char,int> mymap;

			ft::map<char,int>::key_compare mycomp = mymap.key_comp();

			mymap['a']=100;
			mymap['b']=200;
			mymap['c']=300;

			std::cout << "mymap contains:\n";

			char highest = mymap.rbegin()->_pair.first;     // key value of last element

			ft::map<char,int>::iterator it = mymap.begin();
			do {
				std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
			} while ( mycomp((*it++)._pair.first, highest) );

			std::cout << '\n';

			ft::map<char,int> mymap2;

			ft::map<char,int>::key_compare mycomp2 = mymap2.key_comp();

			mymap2['a']=100;
			mymap2['b']=200;
			mymap2['c']=300;

			std::cout << "mymap2 contains:\n";

			char highest2 = mymap2.rbegin()->_pair.first;     // key value of last element

			ft::map<char,int>::iterator it2 = mymap2.begin();
			do {
				std::cout << it2->_pair.first << " => " << it2->_pair.second << '\n';
			} while ( mycomp2((*it2++)._pair.first, highest2) );

			std::cout << '\n';
		}



























































































	// ft::map<int, int> map;

	// std::cout << " !!!!!! 1 !!!!!"  << std::endl;
	// map.insert(ft::pair<int, int>(1, 1));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(4, 4));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(2, 2));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(6, 6));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(5, 5));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(3, 3));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(9, 9));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(7, 7));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(10, 10));
	// std::cout << " ------------------" << std::endl;

	// ft::pair<ft::map<int, int>::iterator, bool> pair = map.insert(ft::pair<int, int>(11, 11));
	// std::cout << " ------------------" << std::endl;

	// // std::cout << "First (Key) = " << pair.first->_pair.first << " - (Value) = " << pair.first->_pair.second << " - Second = " << pair.second << std::endl;

	// map.erase(7);


	// map.insert(ft::pair<int, int>(7, 7));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(3, 3));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(18, 18));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(10, 10));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(22, 22));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(26, 26));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(8, 8));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(11, 11));
	// std::cout << " ------------------"  << std::endl;


	// std::cout << "After Delete"  << std::endl << std::endl;
	// map.erase(18);

	// map.insert(ft::pair<int, int>(5, 5));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(2, 2));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(8, 8));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(1, 1));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(4, 4));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(7, 7));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(9, 9));
	// std::cout << " ------------------"  << std::endl;


	// std::cout << "After Delete"  << std::endl << std::endl;
	// map.erase(2);


	// map.insert(ft::pair<int, int>(7, 7));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(3, 3));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(18, 18));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(10, 10));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(22, 22));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(8, 8));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(11, 11));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(26, 26));
	// std::cout << " ------------------"  << std::endl;


	// std::cout << "After Delete"  << std::endl << std::endl;
	// map.erase(3);

	// map.insert(ft::pair<int, int>(13, 13));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(8, 8));
	// std::cout << " ------------------ "  << std::endl;
	// map.insert(ft::pair<int, int>(17, 17));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(1, 1));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(11, 11));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(6, 6));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(15, 15));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(25, 25));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(22, 22));
	// std::cout << " ------------------"  << std::endl;
	// map.insert(ft::pair<int, int>(27, 27));
	// std::cout << " ------------------"  << std::endl;

	// std::cout << "After Delete"  << std::endl << std::endl;
	// ft::map<int,int>::iterator it = map.find(11);
	// map.erase(it);


	// it++;
	// std::cout << "map contains:\n";
	// for (; it !=map.end(); ++it)
	// 	std::cout << it->_pair.first << " => " << it->_pair.second << '\n';
	// map.erase(it, map.end());

	// std::cout << "map contains:\n";
	// for (ft::map<int,int, classcomp>::iterator it=map.begin(); it!=map.end(); ++it)
	// 	std::cout << it->_pair.first << " => " << it->_pair.second << '\n';


	// ft::map<int, int> map2;

	// map2.insert(ft::pair<int, int>(1, 1));

	// map2.insert(map.begin(), map.end());

	// for (ft::map<int,int>::iterator it=map2.begin(); it!=map2.end(); ++it)
	// 	std::cout << it->_pair.first << " => " << it->_pair.second << '\n';


	

	// std::cout << "Count = " << map.count(0) << std::endl;

	// ft::map<int, int>::iterator const it = map.lower_bound(1);
	// std::cout << "Key = " << (*it)._pair.first << std::endl;

	// ft::map<int, int>::iterator  it2 = map.upper_bound(4);
	// std::cout << "Key = " << (*it2)._pair.first << std::endl;

	// ft::map<int, int>::iterator  it3 = map.find(7);
	// std::cout << "Key = " << (*it3)._pair.first << std::endl;

	// // ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> pair = map.equal_range(43);
	// // std::cout << "First Key = " << pair.first->_pair.first << " - Second Key = " << pair.second->_pair.second << std::endl;

	// ft::map<char,int> foo,bar;

	// foo.insert(ft::pair<char, int>('x', 100));
	// foo.insert(ft::pair<char, int>('y', 200));
	// bar.insert(ft::pair<char, int>('a', 11));
	// bar.insert(ft::pair<char, int>('b', 22));
	// bar.insert(ft::pair<char, int>('c', 233));
	// std::cout << "foo contains:\n";
	// for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	// 	std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

	// std::cout << "bar contains:\n";
	// for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	// 	std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

	// foo.swap(bar);

	// std::cout << "foo contains:\n";
	// for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	// 	std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

	// std::cout << "bar contains:\n";
	// for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	// 	std::cout << it->_pair.first << " => " << it->_pair.second << '\n';

	return (0);
}