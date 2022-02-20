#include <iostream>
#include <map>

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

int main()
{
	std::map<int, char, classcomp> mp;
	std::cout << " Size = " << mp.size() << std::endl;
	mp[5]= 'd';
	mp[3]= 'c';
	mp[1]= 'a';
	mp[2]= 'b';
	std::cout << " Size = " << mp.size() << std::endl;
	for (std::map<int, char>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << "Elem First = " << (*it).first << " Second = " << (*it).second << std::endl;
	std::cout << std::endl;
	std::map<int, char> second(mp.begin(), mp.end());
	for (std::map<int, char>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << "Elem First = " << (*it).first << " Second = " << (*it).second << std::endl;

	return (0);	
}