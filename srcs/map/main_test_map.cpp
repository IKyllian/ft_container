#include <iostream>
#include <map>

int main()
{
	std::map<char, int> mp;
	std::cout << " Size = " << mp.size() << std::endl;
	mp['a']=10;
	mp['b']=30;
	mp['c']=50;
	mp['f']=70;
	std::cout << " Size = " << mp.size() << std::endl;
	for (std::map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << "Elem First = " << (*it).first << " Second = " << (*it).second << std::endl;
	std::cout << std::endl;
	std::map<char, int> second(mp.begin(), mp.end());
	for (std::map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << "Elem First = " << (*it).first << " Second = " << (*it).second << std::endl;

	return (0);	
}