#include <iostream>
#include <map>

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

int main()
{
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
	std::map<int, int> map;
	std::map<int, int> map2;

	// std::cout << " !!!!!! 1 !!!!!"  << std::endl;
	map.insert(std::pair<int, int>(1, 1));
	std::cout << " ------------------ "  << std::endl;
	map.insert(std::pair<int, int>(4, 4));
	std::cout << " ------------------ "  << std::endl;
	map.insert(std::pair<int, int>(2, 2));
	std::cout << " ------------------ "  << std::endl;
	map.insert(std::pair<int, int>(6, 6));
	std::cout << " ------------------"  << std::endl;
	map.insert(std::pair<int, int>(5, 5));
	std::cout << " ------------------"  << std::endl;
	map.insert(std::pair<int, int>(3, 3));
	std::cout << " ------------------"  << std::endl;
	map.insert(std::pair<int, int>(9, 9));
	std::cout << " ------------------"  << std::endl;
	map.insert(std::pair<int, int>(7, 7));
	std::cout << " ------------------"  << std::endl;
	map.insert(std::pair<int, int>(10, 10));
	std::cout << " ------------------" << std::endl;

	std::pair<std::map<int, int>::iterator, bool> pair = map.insert(std::pair<int, int>(7, 11));

	std::cout << "First (Key) = " << pair.first->first << " - (Value) = " << pair.first->second << " - Second = " << pair.second << std::endl;


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

	return (0);	
}