#include <iostream>
#include <vector>

int main()
{
	// std::vector<int> myvector;
	// // std::vector<char> myvector;

	// // set some initial content:
	// for (int i=1;i<10;i++) myvector.push_back(i);
	// // for (int i=1;i<=10;i++) myvector.push_back('a' + i);

	// std::vector<int>::iterator it = myvector.insert(myvector.begin(), 11);

	// std::cout << *it << std::endl;
	// // myvector.assign(myvector.begin(), myvector.begin() + 12);

	// // myvector.resize(6, 2);
	// // myvector.resize(8,100);
	// // myvector.resize(12);



	// std::cout << "myvector contains:";
	// for (int i=0;i<myvector.size();i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';



	std::vector<int> vect(4, 100);
	// std::vector<std::string> vect(4, "Ceci est un test");

	std::cout << "vect contains:";
	for (int i=0;i<vect.size();i++)
		std::cout << ' ' << vect[i];
	std::cout << '\n';

	vect.reserve(6);

	// vect.insert(vect.begin() + 1, "TEst");
	vect.insert(vect.begin() + 3, 42);

	std::cout << "vect contains:";
	for (int i=0;i<vect.size();i++)
		std::cout << ' ' << vect[i];
	std::cout << '\n';


	return 0;
}