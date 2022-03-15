#include "../../srcs/map/map.hpp"
#include "../../srcs/map/node_tree.hpp"


struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

int main() {
	ft::map<int, int> map;
	std::cout << "Max Size = " << map.max_size() << std::endl;
		std::cout << "----------------------- FT CONSTRUCTOR / Operator -----------------------" << std::endl; 
		{
			std::cout << "Default constructor" << std::endl;
			std::cout << "explicit map (const key_compare& comp = key_compare() const allocator_type& alloc = allocator_type());" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::map<char, char> map2;
			ft::map<int, int, classcomp> map3;

			std::cout << "is Empty : " << map.empty() << std::endl;
			for (int i = 1; i <= 20; i++)
				map.insert(ft::pair<int, int>(i, i));

			for (int i = 1; i <= 20; i++)
				map3.insert(ft::pair<int, int>(i, i));

			map2.insert(ft::pair<char, char>('a', 'C'));
			map2.insert(ft::pair<char, char>('b', 'e'));
			map2.insert(ft::pair<char, char>('c', 'u'));
			map2.insert(ft::pair<char, char>('d', 't'));
			map2.insert(ft::pair<char, char>('e', 'H'));
			map2.insert(ft::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int, classcomp>::iterator it=map3.begin(); it!=map3.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Range constructor" << std::endl;
			std::cout << "map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;
			for (int i = 1; i <= 40; i++)
				map.insert(ft::pair<int, int>(i, i));

			map2.insert(ft::pair<char, char>('a', 'C'));
			map2.insert(ft::pair<char, char>('b', 'e'));
			map2.insert(ft::pair<char, char>('c', 'u'));
			map2.insert(ft::pair<char, char>('d', 't'));
			map2.insert(ft::pair<char, char>('e', 'H'));
			map2.insert(ft::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			ft::map<int, int> map_cpy(map.begin(), map.end());
			std::cout << "map_cpy<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			ft::map<char, char> map2_cpy(map2.find('c'), map2.end());
			std::cout << "map2_cpy<char, char> (Start from c) contains:\n";
			for (ft::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Copy constructor" << std::endl;
			std::cout << "map (const map& x);" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;

			for (int i = 1; i <= 6; i++)
				map.insert(ft::pair<int, int>(i, i));

			map2.insert(ft::pair<char, char>('a', 'C'));
			map2.insert(ft::pair<char, char>('b', 'e'));
			map2.insert(ft::pair<char, char>('c', 'u'));
			map2.insert(ft::pair<char, char>('d', 't'));
			map2.insert(ft::pair<char, char>('e', 'H'));
			map2.insert(ft::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			ft::map<int, int> map_cpy(map);
			std::cout << "map_cpy<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			ft::map<char, char> map2_cpy(map2);
			std::cout << "map2_cpy<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
		}

		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Operator =" << std::endl;
			std::cout << "map& operator= (const map& x);" << std::endl << std::endl;

			ft::map<int, int> map;
			ft::map<char, char> map2;

			std::cout << "is Empty : " << map.empty() << std::endl;

			for (int i = 1; i <= 6; i++)
				map.insert(ft::pair<int, int>(i, i));

			map2.insert(ft::pair<char, char>('a', 'C'));
			map2.insert(ft::pair<char, char>('b', 'e'));
			map2.insert(ft::pair<char, char>('c', 'u'));
			map2.insert(ft::pair<char, char>('d', 't'));
			map2.insert(ft::pair<char, char>('e', 'H'));
			map2.insert(ft::pair<char, char>('f', 'W'));

			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			std::cout << "map2<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			
			ft::map<int, int> map_cpy = map;
			std::cout << "map_cpy<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;
			ft::map<char, char> map2_cpy = map2;
			std::cout << "map2_cpy<char, char> contains:\n";
			for (ft::map<char, char>::iterator it=map2_cpy.begin(); it!=map2_cpy.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
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
				std::cout << it->first << " => " << it->second << '\n';
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
				std::cout << it->first << " => " << it->second << '\n';
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
			std::cout << "Value it (Key) = " << ret.first->first << " - (Value) = " << ret.first->second << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert some values" << std::endl;
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));
			std::cout << "Insert 9" << std::endl;
			ret = map.insert(ft::pair<int, int>(9, 9));
			std::cout << "Value it (Key) = " << ret.first->first << " - (Value) = " << ret.first->second << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert 10 who already exists" << std::endl;
			ret = map.insert(ft::pair<int, int>(10, 10));
			std::cout << "Value it (Key) = " << ret.first->first << " - (Value) = " << ret.first->second << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert 100 elements" << std::endl;
			for (int i = 15; i <= 120; i++)
				map.insert(ft::pair<int, int>(i, i));
			std::cout << "Map contains : " << std::endl;
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "iterator insert (iterator position, const value_type& val);" << std::endl << std::endl;

			ft::map<int, int> map;

			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));

			ft::map<int,int>::iterator it = map.begin();
			map.insert(it, ft::pair<int,int>(300,300));
			map.insert(it, ft::pair<int,int>(400,400));

			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
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
				std::cout << it->first << " => " << it->second << '\n';

			ft::map<int, int> map2;

			std::cout << "Insert from begin to end of map1" << std::endl;
			map2.insert(map.begin(), map.end());

			std::cout << "map2<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map2.begin(); it!=map2.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

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
				std::cout << it->first << " => " << it->second << '\n';

			ft::map<char, std::string> map4;
			std::cout << "Insert from c to e of map3" << std::endl;
			map4.insert(map3.find('c'), map3.find('f'));

			std::cout << "map4<char, std::string> contains:\n";
			for (ft::map<char, std::string>::iterator it=map4.begin(); it!=map4.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

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
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			ft::map<int, int> map;
			ft::map<int, int>::iterator it;

			map.insert(ft::pair<int, int>(6, 6));
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));

			it = map.find(2);
			std::cout << "Insert 4 and 9" << std::endl;
			map.insert(ft::pair<int, int>(4, 4));
			map.insert(ft::pair<int, int>(9, 9));

			std::cout << "Print from It : " << std::endl; 
			for (; it!=map.end(); it++)
				std::cout << it->first << " => " << it->second << '\n';
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
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5" << std::endl;
			map.erase(map.find(5));
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << std::endl;
			std::cout << "Erase 1, 3, 2" << std::endl;
			map.erase(map.find(1));
			map.erase(map.find(3));
			map.erase(map.find(2));
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
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
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5" << std::endl;
			ret = map.erase(5);
			std::cout << "Ret = " << ret << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 1, 3, 2" << std::endl;
			map.erase(1);
			map.erase(3);
			map.erase(2);
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5 that has already been deleted " << std::endl;
			ret = map.erase(5);
			std::cout << "Ret = " << ret << std::endl;
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
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
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase from begin to begin" << std::endl;
			map.erase(map.begin(), map.begin());
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase from begin to 10" << std::endl;
			map.erase(map.begin(), map.find(10));
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << std::endl;

			std::cout << "Erase begin from end " << std::endl;
			map.erase(map.begin(), map.end());
			std::cout << "map<int, int> contains:\n";
			for (ft::map<int, int>::iterator it=map.begin(); it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "Map is empty = " << map.empty() << " - Size = " << map.size() << std::endl;
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			ft::map<int, int> map;
			ft::map<int, int>::iterator it;

			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(10, 10));
			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(30, 30));
			map.insert(ft::pair<int, int>(12, 12));
			map.insert(ft::pair<int, int>(15, 15));

			it = map.find(5);

			std::cout << "Erase 10 and 12" << std::endl;
			map.erase(10);
			map.erase(12);

			std::cout << "Print from it (5)" << std::endl;

			for (;it!=map.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
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
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "bar contains:\n";
			for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
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
				std::cout << it->first << " => " << it->second << '\n';

			mymap.clear();
			mymap['a']=1101;
			mymap['b']=2202;

			std::cout << "mymap contains:\n";
			for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << "Clear all" << std::endl;
			mymap.clear();
			std::cout << "Map is empty " << mymap.empty() << std::endl;

			std::cout << "Try to clear on empty map" << std::endl;
			mymap.clear();
		}
		std::cout << "----------------------- FT Key_comp -----------------------" << std::endl; 
		{
			std::cout << "key_compare key_comp() const;" << std::endl << std::endl;

			ft::map<char,int> mymap;

			ft::map<char,int>::key_compare mycomp = mymap.key_comp();

			mymap['a']=100;
			mymap['b']=200;
			mymap['c']=300;

			std::cout << "mymap contains:\n";

			char highest = mymap.rbegin()->first;     // key value of last element


			ft::map<char,int>::iterator it = mymap.begin();
			do {
				std::cout << it->first << " => " << it->second << '\n';
			} while ( mycomp((*it++).first, highest) );

			std::cout << '\n';

			ft::map<char,int, classcomp> mymap2;

			ft::map<char,int, classcomp>::key_compare mycomp2 = mymap2.key_comp();

			mymap2['a']=100;
			mymap2['b']=200;
			mymap2['c']=300;

			std::cout << "mymap2 contains:\n";

			char highest2 = mymap2.rbegin()->first;     // key value of last element

			ft::map<char,int, classcomp>::iterator it2 = mymap2.begin();
			do {
				std::cout << it2->first << " => " << it2->second << '\n';
			} while ( mycomp2((*it2++).first, highest2) );

			std::cout << '\n';
		}
		std::cout << "----------------------- FT Value_Comp -----------------------" << std::endl; 
		{
			std::cout << "value_compare value_comp() const;" << std::endl << std::endl;

			ft::map<char,int> mymap;

			mymap['x']=1001;
			mymap['y']=2002;
			mymap['z']=3003;

			std::cout << "mymap contains:\n";

			ft::pair<char,int> highest = *mymap.rbegin();          // last element

			ft::map<char,int>::iterator it = mymap.begin();
			do {
				std::cout << it->first << " => " << it->second << '\n';
  			} while ( mymap.value_comp()(*it++, highest) );
		}
		std::cout << "----------------------- FT Find -----------------------" << std::endl; 
		{
			std::cout << "iterator find (const key_type& k);" << std::endl << std::endl;

			ft::map<char,int> mymap;
			ft::map<char,int>::iterator it;

			mymap['a']=50;
			mymap['b']=100;
			mymap['c']=150;
			mymap['d']=200;

			it = mymap.find('b');
			if (it != mymap.end())
				mymap.erase (it);

			// print content:
			std::cout << "elements in mymap:" << '\n';
			std::cout << "a => " << mymap.find('a')->second << '\n';
			std::cout << "c => " << mymap.find('c')->second << '\n';
			std::cout << "d => " << mymap.find('d')->second << '\n';
		}
		std::cout << "----------------------- FT Count -----------------------" << std::endl; 
		{
			std::cout << "size_type count (const key_type& k) const;" << std::endl << std::endl;

			ft::map<char,int> mymap;
			char c;

			mymap ['a']=101;
			mymap ['c']=202;
			mymap ['f']=303;

			for (c = 'a'; c < 'h'; c++)
			{
				std::cout << c;
				if (mymap.count(c)>0)
					std::cout << " is an element of mymap.\n";
				else 
					std::cout << " is not an element of mymap.\n";
			}
		}
		std::cout << "----------------------- FT Lower/Upper Bound -----------------------" << std::endl; 
		{
			std::cout << "iterator lower_bound (const key_type& k);" << std::endl << std::endl;
			std::cout << "iterator upper_bound (const key_type& k);" << std::endl << std::endl;


			ft::map<char,int> mymap;
			ft::map<char,int>::iterator itlow,itup;

			mymap['a']=20;
			mymap['b']=40;
			mymap['c']=60;
			mymap['d']=80;
			mymap['e']=100;

			itlow=mymap.lower_bound ('b');  // itlow points to b
			std::cout << "Lower = " << itlow->first << std::endl;
			itup=mymap.upper_bound ('d');   // itup points to e (not d!)
			std::cout << "Upper = " << itup->first << std::endl;
			mymap.erase(itlow,itup);        // erases [itlow,itup)

			//	print content:
			for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			ft::map<int, int> map;

			map.insert(ft::pair<int, int>(4, 4));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(6, 6));
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(8, 8));

			std::cout << "Lower(1) = " << map.lower_bound(1)->first << std::endl;
			std::cout << "Lower(6) = " << map.lower_bound(6)->first << std::endl;
			std::cout << "Lower(3) = " << map.lower_bound(3)->first << std::endl;
			std::cout << "Lower(-1) = " << map.lower_bound(-1)->first << std::endl;
			std::cout << "Lower(7) = " << map.lower_bound(7)->first << std::endl;

			std::cout << "Upper(1) = " << map.upper_bound(1)->first << std::endl;
			std::cout << "Upper(5) = " << map.upper_bound(5)->first << std::endl;
			std::cout << "Upper(3) = " << map.upper_bound(3)->first << std::endl;
			std::cout << "Upper(-1) = " << map.upper_bound(-1)->first << std::endl;
			std::cout << "Upper(7) = " << map.upper_bound(7)->first << std::endl;
		}
		std::cout << "----------------------- FT Equal_range -----------------------" << std::endl; 
		{
			std::cout << "pair<iterator,iterator>equal_range (const key_type& k);" << std::endl << std::endl;

			ft::map<char,int> mymap;

			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;

			ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
			ret = mymap.equal_range('b');

			std::cout << "lower bound points to: ";
			std::cout << ret.first->first << " => " << ret.first->second << '\n';

			std::cout << "upper bound points to: ";
			std::cout << ret.second->first << " => " << ret.second->second << '\n';
		}
		std::cout << "----------------------- Ft Get_allocator -----------------------" << std::endl; 
		{
			std::cout << "allocator_type get_allocator() const;" << std::endl << std::endl;

			int psize;
			ft::map<char,int> mymap;
			ft::pair<const char,int>* p;

			// allocate an array of 5 elements using mymap's allocator:
			p=mymap.get_allocator().allocate(5);

			// assign some values to array
			psize = sizeof(ft::map<char,int>::value_type)*5;

			std::cout << "The allocated array has a size of " << psize << " bytes.\n";

			mymap.get_allocator().deallocate(p,5);
		}

		std::cout << "----------------------- Ft Iterators -----------------------" << std::endl; 
		{
			std::cout << "iterator begin();" << std::endl;
			std::cout << "iterator end();" << std::endl;
			std::cout << "reverse_iterator rbegin();" << std::endl;
			std::cout << "reverse_iterator rend();" << std::endl << std::endl;


			ft::map<int, int> map;

			map.insert(ft::pair<int, int>(4, 4));
			map.insert(ft::pair<int, int>(5, 5));
			map.insert(ft::pair<int, int>(1, 1));
			map.insert(ft::pair<int, int>(2, 2));
			map.insert(ft::pair<int, int>(6, 6));
			map.insert(ft::pair<int, int>(3, 3));
			map.insert(ft::pair<int, int>(8, 8));

			ft::map<int, int>::iterator it = map.end();
			ft::map<int, int>::reverse_iterator reverse_it = map.rend();

			std::cout << "Map Begin = " << map.begin()->first << " - End (-1) = " << (--it)->first << std::endl;
			std::cout << "Map RBegin = " << map.rbegin()->first << " - REnd (-1) = " << (--reverse_it)->first << std::endl;
			std::cout << std::endl;
			
			std::cout << "Map Contain : " << std::endl;
			for (ft::map<int, int>::iterator begin = map.begin(); begin != map.end(); begin++)
				std::cout << "First = " << begin->first << " - Second = " << begin->second << std::endl;
			std::cout << std::endl;

			std::cout << "Map Contain (Reverse) : " << std::endl;
			for (ft::map<int, int>::iterator end = map.end(); end != map.begin();) {
				end--;
				std::cout << "First = " << end->first << " - Second = " << end->second << std::endl;
			}
			std::cout << std::endl;

			ft::map<int, int>::iterator begin = map.begin();
			ft::map<int, int>::iterator cpy_begin = begin;

			std::cout << "Begin Copy Iterator = " << cpy_begin->first << std::endl;

			std::cout << "Map Contain (With Copy Iterator): " << std::endl;
			for (; cpy_begin != map.end(); cpy_begin++)
				std::cout << "First = " << cpy_begin->first << " - Second = " << cpy_begin->second << std::endl;

			std::cout << "Original Begin Iterator = " << begin->first << std::endl;

			std::cout << std::endl;
			std::cout << std::endl;
			ft::map<char, int> map2;
			std::cout << "Map of Size 1" << std::endl;
			map2.insert(ft::pair<char, int>('a', 112));
			ft::map<char, int>::iterator it2 = map2.end();
			ft::map<char, int>::reverse_iterator reverse_it2 = map2.rend();

			std::cout << "Map2 Begin = " << map2.begin()->first << " - End (-1) = " << (--it2)->first << std::endl;
			std::cout << "Map2 RBegin = " << map2.rbegin()->first << " - REnd (-1) = " << (--reverse_it2)->first << std::endl;

		}
		// {
		// 	ft::map<char,int> mymap;

		// 	mymap['a']=20;
		// 	mymap['b']=40;
		// 	mymap['c']=60;
		// 	mymap['d']=80;
		// 	mymap['e']=100;


		// 	ft::map<char,int>::const_iterator it = mymap.begin();
		// }
	return (0);
}