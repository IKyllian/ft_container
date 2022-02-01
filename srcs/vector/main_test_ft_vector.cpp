#include "vector.hpp"
#include "vector_iterator.hpp"
int main()
{
	ft::vector<int> vect(4, 100);
	// ft::vector<std::string> vect(4, "Ceci est un test");

	std::cout << "vect contains:";
	for (int i=0;i<vect.size();i++)
		std::cout << ' ' << vect[i];
	std::cout << '\n';

	vect.reserve(6);

	// vect.insert(vect.end(), "Hello World");
	vect.insert(vect.end(), 42);

	std::cout << "vect contains:";
	for (int i=0;i<vect.size();i++)
		std::cout << ' ' << vect[i];
	std::cout << '\n';


	return (0);
}

