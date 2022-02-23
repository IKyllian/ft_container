#include "map.hpp"
#include "node_tree.hpp"


int main() {
	ft::map<int, int> map;
	ft::map<int, int> map2;

	// std::cout << " !!!!!! 1 !!!!!"  << std::endl;
	map.insert(ft::pair<int, int>(1, 1));
	std::cout << " ------------------ "  << std::endl;
	map.insert(ft::pair<int, int>(4, 4));
	std::cout << " ------------------ "  << std::endl;
	map.insert(ft::pair<int, int>(2, 2));
	std::cout << " ------------------ "  << std::endl;
	map.insert(ft::pair<int, int>(6, 6));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(5, 5));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(3, 3));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(9, 9));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(7, 7));
	std::cout << " ------------------"  << std::endl;
	map.insert(ft::pair<int, int>(10, 10));
	std::cout << " ------------------" << std::endl;


	std::cout << "Count = " << map.count(0) << std::endl;

	ft::map<int, int>::iterator const it = map.lower_bound(1);
	std::cout << "Key = " << (*it)._pair.first << std::endl;

	ft::map<int, int>::iterator  it2 = map.upper_bound(4);
	std::cout << "Key = " << (*it2)._pair.first << std::endl;

	ft::map<int, int>::iterator  it3 = map.find(7);
	std::cout << "Key = " << (*it3)._pair.first << std::endl;
	// std::cout << "Key = " << (*it)._pair.first << " - Value = " << (*it)._pair.second << std::endl;
	// it++;
	// std::cout << "Key = " << (*it)._pair.first << " - Value = " << (*it)._pair.second << std::endl;


	// map.get_tree().printMap();

	// map2 = map;


	return (0);
}