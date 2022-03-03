#include "map.hpp"
#include "node_tree.hpp"


int main() {
	ft::map<int, int> map;

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

	map.insert(ft::pair<int, int>(13, 13));
	std::cout << " ------------------ "  << std::endl;
	map.insert(ft::pair<int, int>(8, 8));
	std::cout << " ------------------ "  << std::endl;
	map.insert(ft::pair<int, int>(17, 17));
	std::cout << " ------------------ "  << std::endl;
	map.insert(ft::pair<int, int>(1, 1));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(11, 11));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(6, 6));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(15, 15));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(25, 25));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(22, 22));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(27, 27));
	std::cout << " ------------------"  << std::endl;


	std::cout << "After Delete"  << std::endl << std::endl;
	map.erase(13);


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
	// map.erase(25);


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