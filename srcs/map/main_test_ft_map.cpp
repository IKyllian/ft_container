#include "map.hpp"

int main() {
	ft::map<int, char> map;
	ft::map<int, char> map2;

	map.insert(ft::pair<int, char>(1, 'a'));

	map2 = map;


	return (0);
}