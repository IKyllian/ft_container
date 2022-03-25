#include <iostream>
#include <set>

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

int main() {
	std::set<int> set;
	std::cout << "Max Size = " << set.max_size() << std::endl;
		std::cout << "----------------------- CONSTRUCTOR / Operator -----------------------" << std::endl; 
		{
			std::cout << "Default constructor" << std::endl;
			std::cout << "explicit set (const key_compare& comp = key_compare() const allocator_type& alloc = allocator_type());" << std::endl << std::endl;

			std::set<int> set;
			std::set<char> set2;
			std::set<int, classcomp> set3;

			std::cout << "is Empty : " << set.empty() << std::endl;
			for (int i = 1; i <= 20; i++)
				set.insert(i);

			for (int i = 1; i <= 20; i++)
				set3.insert(i);

			set2.insert('a');
			set2.insert('b');
			set2.insert('c');
			set2.insert('d');
			set2.insert('e');
			set2.insert('f');

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::cout << "set2<char, char> contains:\n";
			for (std::set<char>::iterator it=set2.begin(); it!=set2.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::cout << "set<int, int, classcomp> contains:\n";
			for (std::set<int, classcomp>::iterator it=set3.begin(); it!=set3.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Range constructor" << std::endl;
			std::cout << "set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());" << std::endl << std::endl;

			std::set<int> set;
			std::set<char> set2;

			std::cout << "is Empty : " << set.empty() << std::endl;
			for (int i = 1; i <= 40; i++)
				set.insert(i);

			set2.insert('a');
			set2.insert('b');
			set2.insert('c');
			set2.insert('d');
			set2.insert('e');
			set2.insert('f');

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::cout << "set2<char, char> contains:\n";
			for (std::set<char>::iterator it=set2.begin(); it!=set2.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::set<int> set_cpy(set.begin(), set.end());
			std::cout << "set_cpy<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::set<char> set2_cpy(set2.find('c'), set2.end());
			std::cout << "set2_cpy<char, char> (Start from c) contains:\n";
			for (std::set<char>::iterator it=set2_cpy.begin(); it!=set2_cpy.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Copy constructor" << std::endl;
			std::cout << "set (const set& x);" << std::endl << std::endl;

			std::set<int> set;
			std::set<char> set2;

			std::cout << "is Empty : " << set.empty() << std::endl;

			for (int i = 1; i <= 6; i++)
				set.insert(i);

			set2.insert('a');
			set2.insert('b');
			set2.insert('c');
			set2.insert('d');
			set2.insert('e');
			set2.insert('f');

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::cout << "set2<char, char> contains:\n";
			for (std::set<char>::iterator it=set2.begin(); it!=set2.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;

			std::set<int> set_cpy(set);
			std::cout << "set_cpy<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::set<char> set2_cpy(set2);
			std::cout << "set2_cpy<char, char> contains:\n";
			for (std::set<char>::iterator it=set2_cpy.begin(); it!=set2_cpy.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
		}

		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "Operator =" << std::endl;
			std::cout << "set& operator= (const set& x);" << std::endl << std::endl;

			std::set<int> set;
			std::set<char> set2;

			std::cout << "is Empty : " << set.empty() << std::endl;

			for (int i = 1; i <= 6; i++)
				set.insert(i);

			set2.insert('a');
			set2.insert('b');
			set2.insert('c');
			set2.insert('d');
			set2.insert('e');
			set2.insert('f');

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::cout << "set2<char, char> contains:\n";
			for (std::set<char>::iterator it=set2.begin(); it!=set2.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			
			std::set<int> set_cpy = set;
			std::cout << "set_cpy<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
			std::set<char> set2_cpy = set2;
			std::cout << "set2_cpy<char, char> contains:\n";
			for (std::set<char>::iterator it=set2_cpy.begin(); it!=set2_cpy.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;
		}
		std::cout << "----------------------- Empty -----------------------" << std::endl; 
		{
			std::cout << "bool empty() const;" << std::endl << std::endl;

			std::set<int> set;

			std::cout << "is Empty : " << set.empty() << std::endl;

			set.insert(1);
			set.insert(6);

			std::cout << "is Empty : " << set.empty() << std::endl;

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			set.erase(1);
			set.erase(6);
			std::cout << "is Empty : " << set.empty() << std::endl;
		}
		std::cout << "----------------------- Size -----------------------" << std::endl; 
		{
			std::cout << "size_type size() const;" << std::endl << std::endl;

			std::set<int> set;

			std::cout << "Size : " << set.size() << std::endl;

			set.insert(6);

			std::cout << "Size : " << set.size() << std::endl;

			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);
			set.insert(9);

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << "Size : " << set.size() << std::endl;
			set.erase(10);
			set.erase(1);
			set.erase(1);
			std::cout << "Size : " << set.size() << std::endl;
			set.clear();
			std::cout << "Size : " << set.size() << std::endl;
		}

		std::cout << "----------------------- Insert -----------------------" << std::endl; 
		{
			std::cout << "pair<iterator,bool> insert (const value_type& val);" << std::endl << std::endl;

			std::set<int> set;
			std::pair<std::set<int>::iterator, bool> ret;

			std::cout << "Insert 6" << std::endl;
			ret = set.insert(6);
			std::cout << "Value it (Key) = " << *ret.first << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert some values" << std::endl;
			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);
			std::cout << "Insert 9" << std::endl;
			ret = set.insert(9);
			std::cout << "Value it (Key) = " << *ret.first << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert 10 who already exists" << std::endl;
			ret = set.insert(10);
			std::cout << "Value it (Key) = " << *ret.first << " - Bool = " << ret.second << std::endl;

			std::cout << "Insert 100 elements" << std::endl;
			for (int i = 15; i <= 120; i++)
				set.insert(i);
			std::cout << "set contains : " << std::endl;
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "iterator insert (iterator position, const value_type& val);" << std::endl << std::endl;

			std::set<int> set;

			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);

			std::set<int>::iterator it = set.begin();
			set.insert(it, 300);
			set.insert(it, 400);

			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
std::cout << "void insert (InputIterator first, InputIterator last);" << std::endl << std::endl;
			std::set<int> set;

			set.insert(6);
			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);
			set.insert(9);

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';

			std::set<int> set2;

			std::cout << "Insert from begin to end of set1" << std::endl;
			set2.insert(set.begin(), set.end());

			std::cout << "set2<int, int> contains:\n";
			for (std::set<int>::iterator it=set2.begin(); it!=set2.end(); ++it)
				std::cout << *it << " => " << *it << '\n';

			std::cout << std::endl;
			std::set<char> set3;

			set3.insert('a');
			set3.insert('b');
			set3.insert('c');
			set3.insert('d');
			set3.insert('e');
			set3.insert('f');

			std::cout << "set3<char, char> contains:\n";
			for (std::set<char>::iterator it=set3.begin(); it!=set3.end(); ++it)
				std::cout << *it << " => " << *it << '\n';

			std::set<char> set4;
			std::cout << "Insert from c to e of set3" << std::endl;
			set4.insert(set3.find('e'), set3.find('f'));

			std::cout << "set4<char, char> contains:\n";
			for (std::set<char>::iterator it=set4.begin(); it!=set4.end(); ++it)
				std::cout << *it << " => " << *it << '\n';

			std::cout << std::endl;
			std::set<char> set5;
			std::cout << "Insert from begin to begin of set4" << std::endl;

			std::cout << "set 5 is empty " << set5.empty() << std::endl;

			std::cout << std::endl;
			std::set<char> set6;
			std::set<char>::iterator it = set4.begin();
			std::cout << "Insert from begin to begin++ of set4" << std::endl;
			set6.insert(it, ++it);			
			std::cout << "set6<char, char> contains:\n";
			for (std::set<char>::iterator it=set6.begin(); it!=set6.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::set<int> set;
			std::set<int>::iterator it;

			set.insert(6);
			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);

			it = set.find(2);
			std::cout << "Insert 4 and 9" << std::endl;
			set.insert(4);
			set.insert(9);

			std::cout << "Print from It : " << std::endl; 
			for (; it!=set.end(); it++)
				std::cout << *it << " => " << *it << '\n';
		}
		std::cout << "----------------------- Erase -----------------------" << std::endl; 
		{
			std::cout << " void erase (iterator position);" << std::endl << std::endl;

			std::set<int> set;

			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);
			set.insert(5);
			set.insert(30);
			set.insert(12);
			set.insert(15);

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5" << std::endl;
			set.erase(set.find(5));
			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';

			std::cout << std::endl;
			std::cout << "Erase 1, 3, 2" << std::endl;
			set.erase(set.find(1));
			set.erase(set.find(3));
			set.erase(set.find(2));
			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "size_type erase (const key_type& k);" << std::endl << std::endl;

			std::set<int> set;
			int ret;

			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);
			set.insert(5);
			set.insert(30);
			set.insert(12);
			set.insert(15);

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5" << std::endl;
			ret = set.erase(5);
			std::cout << "Ret = " << ret << std::endl;
			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;

			std::cout << "Erase 1, 3, 2" << std::endl;
			set.erase(1);
			set.erase(3);
			set.erase(2);
			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;

			std::cout << "Erase 5 that has already been deleted " << std::endl;
			ret = set.erase(5);
			std::cout << "Ret = " << ret << std::endl;
			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::cout << "void erase (iterator first, iterator last); " << std::endl << std::endl;

			std::set<int> set;

			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);
			set.insert(5);
			set.insert(30);
			set.insert(12);
			set.insert(15);

			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;

			std::cout << "Erase from begin to begin" << std::endl;
			set.erase(set.begin(), set.begin());
			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;

			std::cout << "Erase from begin to 10" << std::endl;
			set.erase(set.begin(), set.find(10));
			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
			std::cout << std::endl;

			std::cout << "Erase begin from end " << std::endl;
			set.erase(set.begin(), set.end());
			std::cout << "set<int, int> contains:\n";
			for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';

			std::cout << "set is empty = " << set.empty() << " - Size = " << set.size() << std::endl;
		}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
		{
			std::set<int> set;
			std::set<int>::iterator it;

			set.insert(3);
			set.insert(2);
			set.insert(10);
			set.insert(1);
			set.insert(5);
			set.insert(30);
			set.insert(12);
			set.insert(15);

			it = set.find(5);

			std::cout << "Erase 10 and 12" << std::endl;
			set.erase(10);
			set.erase(12);

			std::cout << "Print from it (5)" << std::endl;

			for (;it!=set.end(); ++it)
				std::cout << *it << " => " << *it << '\n';
		}

		std::cout << "----------------------- Swap -----------------------" << std::endl; 
		{
			int myints[]={12,75,10,32,20,25};
			std::set<int> first (myints,myints+3);
			std::set<int> second (myints+3,myints+6);

			first.swap(second);

			std::cout << "first contains:";
			for (std::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			std::cout << "second contains:";
			for (std::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
		}
		std::cout << "----------------------- Clear -----------------------" << std::endl; 
		{
			std::set<int> myset;

			myset.insert (100);
			myset.insert (200);
			myset.insert (300);

			std::cout << "myset contains:";
			for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			myset.clear();
			myset.insert (1101);
			myset.insert (2202);

			std::cout << "myset contains:";
			for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
		}
		std::cout << "----------------------- Key_comp -----------------------" << std::endl; 
		{
			std::set<int> myset;
			int highest;

			std::set<int>::key_compare mycomp = myset.key_comp();

			for (int i=0; i<=5; i++) myset.insert(i);

			std::cout << "myset contains:";

			highest=*myset.rbegin();
			std::set<int>::iterator it=myset.begin();
			do {
				std::cout << ' ' << *it;
			} while ( mycomp(*(++it),highest) );

			std::cout << '\n';


			std::set<int, classcomp> myset2;
			int highest2;

			std::set<int, classcomp>::key_compare mycomp2 = myset2.key_comp();

			for (int i=0; i<=5; i++) myset2.insert(i);

			std::cout << "myset2 contains:";

			highest2=*myset2.rbegin();
			std::set<int, classcomp>::iterator it2=myset2.begin();
			do {
				std::cout << ' ' << *it2;
			} while ( mycomp2(*(++it2),highest2) );

			std::cout << '\n';
		}
		std::cout << "----------------------- Value_Comp -----------------------" << std::endl; 
		{
			std::set<int> myset;

			std::set<int>::value_compare mycomp = myset.value_comp();

			for (int i=0; i<=5; i++) myset.insert(i);

			std::cout << "myset contains:";

			int highest=*myset.rbegin();
			std::set<int>::iterator it=myset.begin();
			do {
				std::cout << ' ' << *it;
			} while ( mycomp(*(++it),highest) );

			std::cout << '\n';
		}
		std::cout << "----------------------- Find -----------------------" << std::endl; 
		{
			std::set<int> myset;
			std::set<int>::iterator it;

			// set some initial values:
			for (int i=1; i<=5; i++) myset.insert(i*10);

			it=myset.find(20);
			myset.erase (it);
			myset.erase (myset.find(40));

			std::cout << "myset contains:";
			for (it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
		}
		std::cout << "----------------------- Count -----------------------" << std::endl; 
		{
			std::set<int> myset;

			// set some initial values:
			for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

			for (int i=0; i<10; ++i)
			{
				std::cout << i;
				if (myset.count(i)!=0)
				std::cout << " is an element of myset.\n";
				else
				std::cout << " is not an element of myset.\n";
			}
		}
		std::cout << "----------------------- Lower/Upper Bound -----------------------" << std::endl; 
		{
			std::cout << "iterator lower_bound (const key_type& k);" << std::endl << std::endl;
			std::cout << "iterator upper_bound (const key_type& k);" << std::endl << std::endl;


			std::set<int> myset;
			std::set<int>::iterator itlow,itup;

			for (int i=1; i<10; i++) myset.insert(i*10); 

			itlow=myset.lower_bound (30); 
			itup=myset.upper_bound (60);

			myset.erase(itlow,itup);

			std::cout << "myset contains:";
			for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			std::set<int> set;

			set.insert(4);
			set.insert(5);
			set.insert(1);
			set.insert(2);
			set.insert(6);
			set.insert(3);
			set.insert(8);

			std::cout << "Lower(1) = " << *(set.lower_bound(1)) << std::endl;
			std::cout << "Lower(6) = " << *(set.lower_bound(6)) << std::endl;
			std::cout << "Lower(3) = " << *(set.lower_bound(3)) << std::endl;
			std::cout << "Lower(-1) = " << *(set.lower_bound(-1)) << std::endl;
			std::cout << "Lower(7) = " << *(set.lower_bound(7)) << std::endl;

			std::cout << "Upper(1) = " << *(set.upper_bound(1)) << std::endl;
			std::cout << "Upper(5) = " << *(set.upper_bound(5)) << std::endl;
			std::cout << "Upper(3) = " << *(set.upper_bound(3)) << std::endl;
			std::cout << "Upper(-1) = " << *(set.upper_bound(-1)) << std::endl;
			std::cout << "Upper(7) = " << *(set.upper_bound(7)) << std::endl;
		}
		std::cout << "----------------------- Equal_range -----------------------" << std::endl; 
		{
			std::cout << "pair<iterator,iterator>equal_range (const key_type& k);" << std::endl << std::endl;

			std::set<int> myset;

			for (int i=1; i<=5; i++) myset.insert(i*10);

			std::pair<std::set<int>::iterator,std::set<int>::iterator> ret;
			ret = myset.equal_range(30);

			std::cout << "the lower bound points to: " << *ret.first << '\n';
			std::cout << "the upper bound points to: " << *ret.second << '\n';
		}
		std::cout << "----------------------- Get_allocator -----------------------" << std::endl; 
		{
			std::cout << "allocator_type get_allocator() const;" << std::endl << std::endl;

			std::set<int> myset;
			int * p;
			unsigned int i;

			// allocate an array of 5 elements using myset's allocator:
			p=myset.get_allocator().allocate(5);

			// assign some values to array
			for (i=0; i<5; i++) p[i]=(i+1)*10;

			std::cout << "The allocated array contains:";
			for (i=0; i<5; i++) std::cout << ' ' << p[i];
			std::cout << '\n';

			myset.get_allocator().deallocate(p,5);
		}

		std::cout << "----------------------- Iterators -----------------------" << std::endl; 
		{
			std::cout << "iterator begin();" << std::endl;
			std::cout << "iterator end();" << std::endl;
			std::cout << "reverse_iterator rbegin();" << std::endl;
			std::cout << "reverse_iterator rend();" << std::endl << std::endl;


			std::set<int> set;

			set.insert(4);
			set.insert(5);
			set.insert(1);
			set.insert(2);
			set.insert(6);
			set.insert(3);
			set.insert(8);

			std::set<int>::iterator it = set.end();
			std::set<int>::reverse_iterator reverse_it = set.rend();

			std::cout << "set Begin = " << *(set.begin()) << " - End (-1) = " << *(--it) << std::endl;
			std::cout << "set RBegin = " << *(set.rbegin()) << " - REnd (-1) = " << *(--reverse_it) << std::endl;
			std::cout << std::endl;
			
			std::cout << "set Contain : " << std::endl;
			for (std::set<int>::iterator begin = set.begin(); begin != set.end(); begin++)
				std::cout << "First = " << *begin << std::endl;
			std::cout << std::endl;

			std::cout << "set Contain (Reverse) : " << std::endl;
			for (std::set<int>::iterator end = set.end(); end != set.begin();) {
				end--;
				std::cout << "First = " << *end << std::endl;
			}
			std::cout << std::endl;

			std::set<int>::iterator begin = set.begin();
			std::set<int>::iterator cpy_begin = begin;

			std::cout << "Begin Copy Iterator = " << *cpy_begin << std::endl;

			std::cout << "set Contain (With Copy Iterator): " << std::endl;
			for (; cpy_begin != set.end(); cpy_begin++)
				std::cout << "First = " << *cpy_begin << std::endl;

			std::cout << "Original Begin Iterator = " << *begin << std::endl;

			std::cout << std::endl;
			std::cout << std::endl;
			std::set<int> set2;
			std::cout << "set of Size 1" << std::endl;
			set2.insert(112);
			std::set<int>::iterator it2 = set2.end();
			std::set<int>::reverse_iterator reverse_it2 = set2.rend();

			std::cout << "set2 Begin = " << *(set2.begin()) << " - End (-1) = " << *(--it2) << std::endl;
			std::cout << "set2 RBegin = " << *(set2.rbegin()) << " - REnd (-1) = " << *(--reverse_it2) << std::endl;

		}
		{
			std::set<int> set;

			set.insert(4);
			set.insert(5);
			set.insert(1);
			set.insert(2);
			set.insert(6);
			set.insert(3);
			set.insert(8);

			std::set<int>::const_iterator it = set.begin();

			std::cout << *it << std::endl;
			it++;
			std::cout << *(++it) << std::endl;
			std::cout << *(--it) << std::endl;

			std::set<int>::const_reverse_iterator it2 = set.rbegin();

			std::cout << *it2 << std::endl;
			it2++;
			std::cout << *(++it2) << std::endl;
			std::cout << *(--it2) << std::endl;
		}
	return (0);
}