#include "../srcs/vector/vector.hpp"
#include "../srcs/vector/vector_iterator.hpp"
#include "../srcs/vector/vector_reverse_iterator.hpp"
#include "../srcs/stack/stack.hpp"
#include "../srcs/map/map.hpp"
#include "../srcs/map/node_tree.hpp"
#include <deque>
#include <list>

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

template < class T >
void show_vector(ft::vector<T> &vect) {
	std::cout << "vect contains:";
	for (size_t i=0;i<vect.size();i++)
		std::cout << ' ' << vect[i];
	std::cout << std::endl << std::endl;
}

int main()
{
	std::cout << "======================== Vector ========================s" << std::endl; 
	std::cout << "----------------------- FT CONSTRUCTOR -----------------------" << std::endl; 
	{
		std::cout << "Default constructor" << std::endl;
		std::cout << "explicit vector(const allocator_type& alloc = allocator_type())" << std::endl << std::endl;
		
		ft::vector<int> vect;

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);
	}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;

	{
		std::cout << "Fill constructor" << std::endl;
		std::cout << "explicit vector (size_type n, const value_type& val = ;value_type(), const allocator_type& alloc = allocator_type())" << std::endl << std::endl;

		ft::vector<int> vect(4, 42);
		ft::vector<std::string> vect2(2, "Hello World");
		ft::vector<char> vect3(10, 'z');
		ft::vector<float> vect4(5, 42.42);
		ft::vector<int> vect5(0, 100);
		ft::vector<int> vect6(400, 1);
		ft::vector<int> vect7(std::numeric_limits<unsigned int>::max() + 1, 1);

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);

		std::cout << "Fill Size = " << vect3.size() << " - Alloc Size = " << vect3.capacity() << std::endl;
		show_vector(vect3);

		std::cout << "Fill Size = " << vect4.size() << " - Alloc Size = " << vect4.capacity() << std::endl;
		show_vector(vect4);

		std::cout << "Fill Size = " << vect5.size() << " - Alloc Size = " << vect5.capacity() << std::endl;
		show_vector(vect5);

		std::cout << "Fill Size = " << vect6.size() << " - Alloc Size = " << vect6.capacity() << std::endl;
		show_vector(vect6);

		std::cout << "Fill Size = " << vect7.size() << " - Alloc Size = " << vect7.capacity() << std::endl;
		show_vector(vect7);
	}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "Range constructor" << std::endl;
		std::cout << "vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()" << std::endl << std::endl;

		ft::vector<int> vect(50,42);
		ft::vector<int> vect2(vect.begin(),vect.end());
		int myints[] = {16,2,77,29};
		ft::vector<int> vect3(myints, myints + sizeof(myints) / sizeof(int));
		ft::vector<int> vect4(vect.begin(),vect.begin() + 20);
		ft::vector<int> vect5(vect.begin(),vect.begin());

		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);

		std::cout << "Fill Size = " << vect3.size() << " - Alloc Size = " << vect3.capacity() << std::endl;
		show_vector(vect3);
		
		std::cout << "Fill Size = " << vect4.size() << " - Alloc Size = " << vect4.capacity() << std::endl;
		show_vector(vect4);

		std::cout << "Fill Size = " << vect5.size() << " - Alloc Size = " << vect5.capacity() << std::endl;
		show_vector(vect5);
	}
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "Copy constructor" << std::endl;
		std::cout << "vector(const vector& x)" << std::endl << std::endl;

		ft::vector<int> vect(50,42);
		ft::vector<int> vect2;
		ft::vector<int> vect3(vect);
		ft::vector<int> vect4(vect2);

		std::cout << "Fill Size = " << vect3.size() << " - Alloc Size = " << vect3.capacity() << std::endl;
		show_vector(vect3);
		
		std::cout << "Fill Size = " << vect4.size() << " - Alloc Size = " << vect4.capacity() << std::endl;
		show_vector(vect4);
	}

	std::cout << "----------------------- FT OPERATOR =() -----------------------" << std::endl;
	std::cout << "vector& operator= (const vector& x)" << std::endl << std::endl;
	{
		ft::vector<int> vect(50, 42);
		ft::vector<int> vect2;
		ft::vector<std::string> vect3(10, "Hello World");

		ft::vector<int> cpy_vect = vect;
		ft::vector<int> cpy_vect2 = vect2;
		ft::vector<std::string> cpy_vect3 = vect3;

		std::cout << "VECT = Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "VECT2 = Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);

		std::cout << "VECT3 = Fill Size = " << vect3.size() << " - Alloc Size = " << vect3.capacity() << std::endl;
		show_vector(vect3);

		
		std::cout << "CPY_VECT = Fill Size = " << cpy_vect.size() << " - Alloc Size = " << cpy_vect.capacity() << std::endl;
		show_vector(cpy_vect);

		std::cout << "CPY_VECT2 = Fill Size = " << cpy_vect2.size() << " - Alloc Size = " << cpy_vect2.capacity() << std::endl;
		show_vector(cpy_vect2);

		std::cout << "CPY_VECT3 = Fill Size = " << cpy_vect3.size() << " - Alloc Size = " << cpy_vect3.capacity() << std::endl;
		show_vector(cpy_vect3);
			
	}

		std::cout << "----------------------- FT RESIZE -----------------------" << std::endl;
		std::cout << "void resize (size_type n, value_type val = value_type())" << std::endl << std::endl;

	{
		ft::vector<int> vect(10, 42);

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		vect.resize(5);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		vect.resize(8, 100);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);


		vect.resize(12);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		vect.resize(42);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		vect.resize(0);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		vect.resize(84);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);
	}

		std::cout << "----------------------- FT RESERVE -----------------------" << std::endl;
		std::cout << "void reserve (size_type n)" << std::endl << std::endl;

	{
		ft::vector<int> vect(5, 42);
		

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);
		
		vect.reserve(3);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		vect.reserve(7);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		vect.reserve(25);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "Empty vector" << std::endl;
		ft::vector<int> vect2;

		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);

		vect2.reserve(2);
		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);
	}

		std::cout << "----------------------- FT MAX SIZE / EMPTY -----------------------" << std::endl;
		std::cout << "bool empty() const" << std::endl;
		std::cout << "size_type max_size() const" << std::endl << std::endl;

	{
		ft::vector<int> vect(1,1);
		ft::vector<int> vect2(3,10);
		ft::vector<int> vect3;
		std::cout << "Max size = " << vect.max_size() << std::endl;

		std::cout << "Vect Is empty = " << vect.empty() << std::endl;
		vect.clear();
		std::cout << "Vect Is empty = " << vect.empty() << std::endl;
		
		std::cout << "Vect2 Is empty = " << vect2.empty() << std::endl;
		vect2.resize(0);
		std::cout << "Vect2 Is empty = " << vect2.empty() << std::endl;

		std::cout << "Vect3 Is empty = " << vect3.empty() << std::endl;
		vect3.resize(3,3);
		std::cout << "Vect3 Is empty = " << vect3.empty() << std::endl;
	}

		std::cout << "----------------------- FT AT -----------------------" << std::endl;
		std::cout << "reference at (size_type n)" << std::endl << std::endl;

	{
		ft::vector<int> vect(10);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		for (unsigned i=0; i<vect.size(); i++)
    		vect.at(i)=i;
		for (unsigned i=0; i<vect.size(); i++)
			std::cout << ' ' << vect.at(i);
		std::cout << "With [] :" << std::endl;
		for (unsigned i=0; i<vect.size(); i++)
    		vect[i];
		std::cout << '\n';


		vect.clear();

		const ft::vector<int> vect2(10, 2);

		vect2.at(3);
	}

	std::cout << "----------------------- FT FRONT/BACK -----------------------" << std::endl;
	std::cout << "reference at (size_type n)" << std::endl << std::endl;

	{
		ft::vector<int> vect(5, 3);

		std::cout << "Front = " << vect.front() << std::endl;
		vect.reserve(6);
		vect.at(vect.size() - 1) = 42;
		std::cout << "Back = " << vect.back() << std::endl;
		vect.clear();
		std::cout << "Front = " << vect.front() << std::endl;
	}

	std::cout << "----------------------- FT PUSH_BACK/POP_BACK -----------------------" << std::endl;
	std::cout << "void push_back (const value_type& val)" << std::endl;
	std::cout << "void pop_back()" << std::endl << std::endl;

	{
		ft::vector<int> vect;

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		for (int i = 0; i < 10; i++)
			vect.push_back(i);

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		for (int i = 0; i < 10; i++)
			vect.pop_back();

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

	}


	std::cout << "-----------------------FT INSERT -----------------------" << std::endl;
	std::cout << "iterator insert(iterator position, const value_type& val)" << std::endl << std::endl;

	{
		// -------------- Container size of 4 -----------
		std::cout << "Test a container with a size of 4 :" <<  std::endl << std::endl;
		ft::vector<int> vect(4, 100);
		ft::vector<int>::iterator it;

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		std::cout << "At start vect contains:";
		show_vector(vect);

		std::cout << "Insert 42 at the beginning of the vector" << std::endl;
		it = vect.insert(vect.begin(), 42);
		std::cout << "return value = " << *it << std::endl;
		show_vector(vect);

		std::cout << "Insert 43 at the beginning + 2 of the vector" << std::endl;
		it = vect.insert(vect.begin() + 2, 43);
		std::cout << "return value = " << *it << std::endl;
		show_vector(vect);

		std::cout << "Insert 1921 at the end of the vector" << std::endl;
		it = vect.insert(vect.end(), 1921);
		std::cout << "return value = " << *it << std::endl;
		show_vector(vect);

		std::cout << "Insert 442 at the end - 1 of the vector" << std::endl;
		it = vect.insert(vect.end() - 1, 442);
		std::cout << "return value = " << *it << std::endl;
		show_vector(vect);

		std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;

		//------------ Empty container ---------
		std::cout << "Test an empty container :" <<  std::endl << std::endl;

		ft::vector<int> empty_vect;

		std::cout << "Fill Size = " << empty_vect.size() << " - Alloc Size = " << empty_vect.capacity() << std::endl;
		std::cout << "At start vect contains:";
		show_vector(empty_vect);

		std::cout << "Insert 42 at the beginning of the vector" << std::endl;
		it = empty_vect.insert(empty_vect.begin(), 42);
		std::cout << "return value = " << *it << std::endl;
		show_vector(empty_vect);

		std::cout << "Insert 43 at the beginning of the vector" << std::endl;
		it = empty_vect.insert(empty_vect.begin(), 43);
		std::cout << "return value = " << *it << std::endl;
		show_vector(empty_vect);

		std::cout << "Insert 120 at the end of the vector" << std::endl;
		it = empty_vect.insert(empty_vect.end(), 120);
		std::cout << "return value = " << *it << std::endl;
		show_vector(empty_vect);

		std::cout << "Insert 400 at the end - 1 of the vector" << std::endl;
		it = empty_vect.insert(empty_vect.end() - 1, 400);
		std::cout << "return value = " << *it << std::endl;
		show_vector(empty_vect);

		std::cout << "After Changes ------> Fill Size = " << empty_vect.size() << " - Alloc Size = " << empty_vect.capacity() << std::endl << std::endl;
	}

	{
		//------------ container size of 1 ---------
		std::cout << "Test a container with a size of 1:" <<  std::endl << std::endl;

		ft::vector<int> vect(1, 0);
		ft::vector<int>::iterator it;

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		std::cout << "At start vect contains:";
		show_vector(vect);

		std::cout << "Insert 120 at the end of the vector" << std::endl;
		it = vect.insert(vect.end(), 120);
		std::cout << "return value = " << *it << std::endl;
		show_vector(vect);
		std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;



		std::cout << "Insert 42 at the beginning of the vector" << std::endl;
		it = vect.insert(vect.begin(), 42);
		std::cout << "return value = " << *it << std::endl;
		show_vector(vect);

		std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "void insert (iterator position, size_type n, const value_type& val)" << std::endl << std::endl;

		// -------------- Container size of 4 -----------
		std::cout << "Test a container with a size of 4 :" <<  std::endl << std::endl;
		ft::vector<int> vect(4, 100);

		std::cout << "At start vect contains:";
		show_vector(vect);

		std::cout << "Insert 21 4 time at the beginning of the vector" << std::endl;
		vect.insert(vect.begin(), 4, 21);
		show_vector(vect);

		std::cout << "Insert 10 4 time at the end of the vector" << std::endl;
		vect.insert(vect.end(), 4, 10);
		show_vector(vect);

		std::cout << "Insert 342 2 time at the end - 1 of the vector" << std::endl;
		vect.insert(vect.end() - 1, 2, 342);
		show_vector(vect);

		std::cout << "Insert 2 1 time at the beginning + 2 of the vector" << std::endl;
		vect.insert(vect.begin() + 2, 1, 2);
		show_vector(vect);
		std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "void insert (iterator position, size_type n, const value_type& val)" << std::endl << std::endl;

		// -------------- Empty container -----------
		std::cout << "Test a empty container :" <<  std::endl << std::endl;
		ft::vector<int> vect;

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		std::cout << "At start vect contains:";
		show_vector(vect);

		std::cout << "Insert 21 4 time at the beginning of the vector" << std::endl;
		vect.insert(vect.begin(), 4, 21);
		show_vector(vect);

		std::cout << "Insert 10 4 time at the end of the vector" << std::endl;
		vect.insert(vect.end(), 4, 10);
		show_vector(vect);

		std::cout << "Insert 342 2 time at the end - 1 of the vector" << std::endl;
		vect.insert(vect.end() - 1, 2, 342);
		show_vector(vect);

		std::cout << "Insert 2 1 time at the beginning + 2 of the vector" << std::endl;
		vect.insert(vect.begin() + 2, 1, 2);
		show_vector(vect);
		std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "void insert (iterator position, InputIterator first, InputIterator last)" << std::endl << std::endl;

		ft::vector<int> vect (3,100);
		show_vector(vect);
		int myarray [] = { 501,502,503 };

		std::cout << "Insert array of three elements at the beginning of the vector" << std::endl;
		vect.insert (vect.begin(), myarray, myarray+3);
		show_vector(vect);

		std::cout << "Insert array of three elements at the end of the vector" << std::endl;
		vect.insert (vect.end(), myarray, myarray+3);
		show_vector(vect);

		std::cout << "Insert array of three elements at the middle of the vector" << std::endl;
		vect.insert (vect.begin() + 5, myarray, myarray+3);
		show_vector(vect);

		std::cout << "Insert an element of the current vector" << std::endl;
		vect.insert (vect.begin() + 4, vect.begin(), vect.begin() + 1);
		show_vector(vect);
		std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
  		
	}





	std::cout << "----------------------- FT SWAP -----------------------" << std::endl;
	std::cout << "void swap (vector& x)" << std::endl << std::endl;

	{
		ft::vector<int> vect(10, 42);
		ft::vector<int> vect2(40, 100);

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);

		
		vect.swap(vect2);
		
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);
			
	}
	{
		ft::vector<int> vect;
		ft::vector<int> vect2;

		for (int i=0;i<=10;i++) vect.push_back(i);
		for (int i=50;i<=60;i++) vect2.push_back(i);

		ft::vector<int>::iterator begin = vect.begin();
		ft::vector<int>::iterator it = begin + 3;
		ft::vector<int>::iterator end = vect.end() - 1;

		ft::vector<int>::iterator begin2 = vect2.begin();
		ft::vector<int>::iterator it2 = begin2 + 3;
		ft::vector<int>::iterator end2 = vect2.end() - 1;



		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);

		std::cout << "Before the swap : " << std::endl;
		std::cout << "Vect -----> begin = " << *begin << " - It = " << *it << " - End = " << *end << std::endl;

		std::cout << "Vect2 -----> begin = " << *begin2 << " - It = " << *it2 << " - End = " << *end2 << std::endl;
		std::cout << std::endl;
		
		vect.swap(vect2);
		
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);

		std::cout << "After the swap : " << std::endl;
		std::cout << "Vect -----> begin = " << *begin << " - It = " << *it << " - End = " << *end << std::endl;

		std::cout << "Vect2 -----> begin = " << *begin2 << " - It = " << *it2 << " - End = " << *end2 << std::endl;

		std::cout << "Print Vect2 from Begin : " << std::endl;
		for (; begin != vect2.end(); begin++)
			std::cout << *begin << std::endl;
		std::cout << std::endl;
		std::cout << "Print Vect from Begin : " << std::endl;
		for (; begin2 != vect.end(); begin2++)
			std::cout << *begin2 << std::endl;
			
	}



	std::cout << "----------------------- FT ERASE -----------------------" << std::endl;
	std::cout << "iterator erase (iterator position)" << std::endl << std::endl;	
	{
		ft::vector<int> vect;
		ft::vector<int>::iterator it;

		for (int i=0;i<=10;i++) vect.push_back(i);
		show_vector(vect);
		
		std::cout << "Erase the last element" << std::endl;
		vect.erase(vect.end() - 1);
		show_vector(vect);

		std::cout << "Erase the third element" << std::endl;
		vect.erase(vect.begin() + 3);
		show_vector(vect);

		std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	std::cout << "iterator erase (iterator first, iterator last)" << std::endl << std::endl;
	{
		ft::vector<int> vect;
		ft::vector<int>::iterator it;

		for (int i=0;i<=10;i++) vect.push_back(i);

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
		show_vector(vect);

		std::cout << "Erase first three elements" << std::endl;
		it = vect.erase(vect.begin(), vect.begin() + 3);
		std::cout << "return = " << *it << std::endl;
		show_vector(vect);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


		std::cout << "Erase two last elements" << std::endl;
		vect.erase(vect.end() - 3, vect.end());
		show_vector(vect);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


		std::cout << "Erase 1 element on the middle" << std::endl;
		it = vect.erase(vect.begin() + 2, vect.begin() + 3);
		std::cout << "return = " << *it << std::endl;
		show_vector(vect);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


		std::cout << "Erase all" << std::endl;
		vect.erase(vect.begin(), vect.end());
		show_vector(vect);

		std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}



	std::cout << "----------------------- FT ASSIGN -----------------------" << std::endl;
	std::cout << "void assign (size_type n, const value_type& val)" << std::endl << std::endl;

	{
		ft::vector<int> vect(5, 100);
		ft::vector<int> vect2;
		
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "assign 7 elements of 42" << std::endl;
		vect.assign(7, 42);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		std::cout << "assign 3 elements of 1" << std::endl;
		vect.assign(3, 1);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);


		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		std::cout << "vect2 contains:";
		show_vector(vect2);

		std::cout << "assign 2 elements of 93" << std::endl;
		vect2.assign(2, 93);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		std::cout << "vect2 contains:";
		show_vector(vect2);
	}

	std::cout << "----------------------- FT CLEAR -----------------------" << std::endl;
	std::cout << "void clear()" << std::endl << std::endl;

	{
		ft::vector<int> vect(10, 42);

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);
		
		vect.clear();
		
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		vect.clear();

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);
			
	}

	std::cout << "----------------------- FT BEGIN/END -----------------------" << std::endl;
	std::cout << "void clear()" << std::endl << std::endl;

	{
		ft::vector<int> vect;

		for (int i = 0; i <= 10; i++)
			vect.push_back(i);
		ft::vector<int>::iterator it = vect.begin();
		ft::vector<int>::iterator it_end = vect.end();

		show_vector(vect);
		std::cout << "Vect Begin = " << *it << " - End = " << *(it_end - 1) << std::endl;
		
		std::cout << "Begin to End" << std::endl;
		for (; it != vect.end(); it++)
			std::cout << "Elem = " << *it << std::endl;
		std::cout << std::endl;
		
		std::cout << "End to Begin" << std::endl;
		for (; it_end - 1 >= vect.begin(); it_end--)
			std::cout << "Elem = " << *(it_end - 1) << std::endl;
		std::cout << std::endl;

		vect.push_back(42);
		std::cout << "Begin = " << *(vect.begin()) << " - End = " << *(vect.end() - 1) << std::endl;

		vect.pop_back();
		vect.pop_back();
		vect.pop_back();
		std::cout << "Begin = " << *(vect.begin()) << " - End = " << *(vect.end() - 1) << std::endl;

	}

	std::cout << "----------------------- FT RBEGIN/REND -----------------------" << std::endl;
	std::cout << "void clear()" << std::endl << std::endl;

	{
		ft::vector<int> vect;
		for (int i = 1; i <= 10; i++)
			vect.push_back(i);

		ft::vector<int>::reverse_iterator it;
		ft::vector<int>::reverse_iterator it_end;


		it = vect.rbegin();
		it_end = vect.rend();

		show_vector(vect);
		std::cout << "Vect Begin = " << *it << " - End = " << *(--it_end) << std::endl;
		
		std::cout << "Reverse Begin to Reverse End" << std::endl;
		for (; it != vect.rend(); it++)
			std::cout << "Elem = " << *it << std::endl;
		std::cout << std::endl;
		
		std::cout << "Reverse End to Reverse Begin" << std::endl;
		--it_end;
		for (; it_end != vect.rbegin(); it_end--)
			std::cout << "Elem = " << *it_end << std::endl;
		std::cout << std::endl;

		vect.push_back(42);
		show_vector(vect);
		std::cout << "Begin = " << *(vect.rbegin()) << " - End = " << *(--vect.rend()) << std::endl;

		vect.pop_back();
		vect.pop_back();
		vect.pop_back();
		show_vector(vect);
		std::cout << "Begin = " << *(vect.rbegin()) << " - End = " << *(--vect.rend()) << std::endl;
	}
	std::cout << "----------------------- Ft Iterators -----------------------" << std::endl; 
	{
		std::cout << "iterator begin();" << std::endl;
		std::cout << "iterator end();" << std::endl;
		std::cout << "reverse_iterator rbegin();" << std::endl;
		std::cout << "reverse_iterator rend();" << std::endl << std::endl;


		ft::vector<int> vect;

		for (int i=0;i<=15;i++) vect.push_back(i);

		ft::vector<int>::iterator it = vect.end();
		ft::vector<int>::reverse_iterator reverse_it = vect.rend();

		std::cout << "Vect Begin = " << (*vect.begin()) << " - End (-1) = " << *(--it) << std::endl;
		std::cout << "Vect RBegin = " << (*vect.rbegin()) << " - REnd (-1) = " << *(--reverse_it) << std::endl;
		std::cout << std::endl;
		
		std::cout << "Vect Contain : " << std::endl;
		for (ft::vector<int>::iterator begin = vect.begin(); begin != vect.end(); begin++)
			std::cout << "First = " << *begin << " - Second = " << *begin << std::endl;
		std::cout << std::endl;

		std::cout << "Vect Contain (Reverse) : " << std::endl;
		for (ft::vector<int>::iterator end = vect.end(); end != vect.begin();) {
			end--;
			std::cout << "First = " << *end << " - Second = " << *end << std::endl;
		}
		std::cout << std::endl;

		ft::vector<int>::iterator begin = vect.begin();
		ft::vector<int>::iterator cpy_begin = vect.begin();

		std::cout << "Begin Copy Iterator = " << *cpy_begin << std::endl;

		std::cout << "Vect Contain (With Copy Iterator): " << std::endl;
		for (; cpy_begin != vect.end(); cpy_begin++)
			std::cout << "First = " << *cpy_begin << " - Second = " << *cpy_begin << std::endl;

		std::cout << "Original Begin Iterator = " << *begin << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		ft::vector<char> vect2;
		std::cout << "Vect of Size 1" << std::endl;
		vect2.push_back('A');
		ft::vector<char>::iterator it2 = vect2.end();
		ft::vector<char>::reverse_iterator reverse_it2 = vect2.rend();

		std::cout << "Vect2 Begin = " << (*vect2.begin()) << " - End (-1) = " << *(--it2) << std::endl;
		std::cout << "Vect2 RBegin = " << (*vect2.rbegin()) << " - REnd (-1) = " << *(--reverse_it2) << std::endl;
		std::cout << std::endl;

		ft::vector<int>::iterator iterator = vect.begin();
		ft::vector<int>::iterator iterator_end = vect.end();
		ft::vector<int>::iterator tmp_it(iterator);


		std::cout << "Begin + 2 = " << *(iterator + 2) << " - Begin + 6 = " << *(iterator + 6) << std::endl;
		std::cout << "End - 9 = " << *(iterator_end - 9) << " - End - 2 = " << *(iterator_end - 2) << std::endl;

		tmp_it += 5;

		std::cout << "Tmp It =  " << *tmp_it << std::endl;

		tmp_it -= 2;
		
		std::cout << "Tmp It =  " << *tmp_it << std::endl;

		std::cout << "Iterator [14] = " << iterator[14] << "Iterator [0] = " << iterator[0] << std::endl;

		std::cout << std::endl;
		if (tmp_it > iterator)
			std::cout << "tmp_it lower than iterator" << std::endl;
		else
			std::cout << "iterator lower than tmp_it" << std::endl;

		if (tmp_it < iterator)
			std::cout << "iterator lower than tmp_it" << std::endl;
		else
			std::cout << "tmp_it lower than iterator" << std::endl;

		if (tmp_it != iterator)
			std::cout << "tmp_it Not equal to iterator" << std::endl;

		if (iterator == vect.begin())
			std::cout << "iterator equal to begin()" << std::endl;

	}
	{
		std::cout << std::endl;
		ft::vector<int> vect;

		for (int i=0;i<=15;i++) vect.push_back(i);
		ft::vector<int>::reverse_iterator iterator = vect.rbegin();
		ft::vector<int>::reverse_iterator iterator_end = vect.rend();
		ft::vector<int>::reverse_iterator tmp_it(iterator);


		std::cout << "Rbegin = " << *iterator << " - RBegin + 2 = " << *(iterator + 2) << " - RBegin + 6 = " << *(iterator + 6) << std::endl;
		std::cout << "REnd = " << *(iterator_end - 1) << " - REnd - 9 = " << *(iterator_end - 9) << " - REnd - 2 = " << *(iterator_end - 2) << std::endl;

		tmp_it += 5;

		std::cout << "Tmp It =  " << *tmp_it << std::endl;

		tmp_it -= 2;
		
		std::cout << "Tmp It =  " << *tmp_it << std::endl;

		std::cout << "Iterator [14] = " << iterator[14] << "Iterator [0] = " << iterator[0] << std::endl;

		std::cout << std::endl;
		if (tmp_it > iterator)
			std::cout << "tmp_it lower than iterator" << std::endl;
		else
			std::cout << "iterator lower than tmp_it" << std::endl;

		if (tmp_it < iterator)
			std::cout << "iterator lower than tmp_it" << std::endl;
		else
			std::cout << "tmp_it lower than iterator" << std::endl;

		if (tmp_it != iterator)
			std::cout << "tmp_it Not equal to iterator" << std::endl;

		if (iterator == vect.rbegin())
			std::cout << "iterator equal to begin()" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		ft::vector<int> vect;

		for (int i=0;i<=15;i++) vect.push_back(i);
		ft::vector<int>::const_iterator it = vect.begin();
		ft::vector<int>::iterator it3 = vect.begin();

		if (it == it3)
			std::cout << "Same iterator" << std::endl;

		std::cout << *it << std::endl;
		it++;
		std::cout << *(++it) << std::endl;
		std::cout << *(--it) << std::endl;

		ft::vector<int>::const_reverse_iterator it2 = vect.rbegin();

		std::cout << *it2 << std::endl;
		it2++;
		std::cout << *(++it2) << std::endl;
		std::cout << *(--it2) << std::endl;
	}
	{
        ft::vector<int> v;
		for (int i=0;i<=3;i++) v.push_back(i);
		ft::vector<int>::reverse_iterator ri1= v.rbegin();
        std::cout << *ri1 << std::endl;
		ft::vector<int>::reverse_iterator ri2= 2 + ri1;
        std::cout << *ri2 << std::endl; 
	}
	std::cout << "----------------------- Ft Non member function -----------------------" << std::endl; 
	{
		ft::vector<int> vect;
		for (int i=0;i<=15;i++) vect.push_back(i);

		ft::vector<int> vect2(vect);
		ft::vector<int> vect3;
		for (int i=30;i<=40;i++) vect3.push_back(i);

		ft::vector<int> vect4;
		for (int i=50;i<=900;i++) vect4.push_back(i);

		if (vect == vect2)
			std::cout << "Vect == Vect2" << std::endl;
		else
			std::cout << "Vect != Vect2" << std::endl;

		if (vect != vect3)
			std::cout << "Vect != Vect3" << std::endl;
		else
			std::cout << "Vect == Vect3" << std::endl;

		if (vect < vect4)
			std::cout << "Vect < Vect4" << std::endl;
		else
			std::cout << "Vect > Vect4" << std::endl;

		if (vect4 > vect3)
			std::cout << "Vect4 > Vect3" << std::endl;
		else
			std::cout << "Vect4 < Vect3" << std::endl;

		if (vect >= vect2)
			std::cout << "Vect >= Vect2" << std::endl;
		else
			std::cout << "Vect < Vect2" << std::endl;

		if (vect <= vect2)
			std::cout << "Vect <= Vect2" << std::endl;
		else
			std::cout << "Vect > Vect2" << std::endl;

		show_vector(vect2);
		show_vector(vect4);

		swap(vect2, vect4);

		show_vector(vect2);
		show_vector(vect4);
	}









	std::cout << std::endl << std::endl; 
	std::cout << "======================== Stack ========================s" << std::endl; 

	std::cout << "----------------------- FT CONSTRUCTOR -----------------------" << std::endl;
	std::cout << "explicit stack (const container_type& ctnr = container_type())" << std::endl << std::endl;

	{
		std::deque<int> deque(5, 42);
        ft::stack<int> stack;
        ft::stack<int, std::deque<int> > stack2(deque);

		std::cout << "Stack Size = " << stack.size() << std::endl;
        std::cout << "Stack2 Size = " << stack2.size() << std::endl;
		for (; !stack.empty(); )
        {
            std::cout << "Elem = " << stack2.top() << std::endl;
            stack2.pop();
        }		
	}

    std::cout << std::endl << "----------------------- FT EMPTY -----------------------" << std::endl;
	std::cout << "bool empty() const" << std::endl << std::endl;

	{
		std::list<int> list(1, 42);
        ft::stack<int> stack;
        ft::stack<int, std::list<int> > stack2(list);

		std::cout << "Stack is empty = " << stack.empty() << std::endl;
        std::cout << "Stack2 is empty = " << stack.empty() << std::endl;
        stack2.pop();
        std::cout << "Stack2 is empty = " << stack.empty() << std::endl;
	}

    std::cout << std::endl << "----------------------- FT SIZE -----------------------" << std::endl;
	std::cout << "size_type size() const" << std::endl << std::endl;

	{
        ft::vector<int> vector(10000, 42);
        ft::stack<int> stack;
        ft::stack<int> stack2(vector);

		std::cout << "Stack Size = " << stack.size() << std::endl;
        for (int i = 0; i < 2; i++)
            stack.push(i);
		std::cout << "Stack Size = " << stack.size() << std::endl;
        stack2.pop();
		std::cout << "Stack Size = " << stack.size() << std::endl;
        stack2.pop();
		std::cout << "Stack Size = " << stack.size() << std::endl;

	}

    std::cout << std::endl << "----------------------- FT TOP -----------------------" << std::endl;
	std::cout << "value_type& top()" << std::endl << std::endl;

	{
        ft::vector<int> vector(5, 42);
        ft::stack<int> stack(vector);

		std::cout << "Stack Size = " << stack.size() << std::endl;
		for (; !stack.empty(); )
        {
            std::cout << "Elem = " << stack.top() << std::endl;
            stack.pop();
        }
		std::cout << std::endl;
        stack.push(20);
        stack.top() += 5;
        std::cout << "Top Elem = " << stack.top() << std::endl;
		stack.top() -= 20;
        std::cout << "Top Elem = " << stack.top() << std::endl;
	}

	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	std::cout << "const value_type& top() const" << std::endl << std::endl;

	{
        ft::vector<int> vector(5, 42);
        const ft::stack<int> stack(vector);

        std::cout << "Top Elem = " << stack.top() << std::endl;
    }

	std::cout << std::endl << "----------------------- FT PUSH -----------------------" << std::endl;
	std::cout << "void push (const value_type& val)" << std::endl << std::endl;

	{
        ft::stack<int> stack;

		std::cout << "Stack Size = " << stack.size() << std::endl;
		for (int i = 0; i < 100; i++)
            stack.push(i);
		std::cout << "Stack Size = " << stack.size() << std::endl;
	}

	std::cout << std::endl << "----------------------- FT POP -----------------------" << std::endl;
	std::cout << "void pop()" << std::endl << std::endl;

	{
        ft::stack<int> stack;

		std::cout << "Stack Size = " << stack.size() << std::endl;
		for (int i = 0; i < 10; i++)
            stack.push(i);
		std::cout << "Stack Size = " << stack.size() << std::endl;
		for (; !stack.empty(); )
        {
            std::cout << "Elem = " << stack.top() << std::endl;
            stack.pop();
        }
		std::cout << "Stack Size = " << stack.size() << std::endl;
	}


    std::cout << "----------------------- Ft Non member function -----------------------" << std::endl; 
	{
		ft::stack<int> stack;
		for (int i=0;i<=15;i++) stack.push(i);

		ft::stack<int> stack2(stack);
		ft::stack<int> stack3;
		for (int i=30;i<=40;i++) stack3.push(i);

		ft::stack<int> stack4;
		for (int i=50;i<=900;i++) stack4.push(i);

		if (stack == stack2)
			std::cout << "stack == stack2" << std::endl;
		else
			std::cout << "stack != stack2" << std::endl;

		if (stack != stack3)
			std::cout << "stack != stack3" << std::endl;
		else
			std::cout << "stack == stack3" << std::endl;

		if (stack < stack4)
			std::cout << "stack < stack4" << std::endl;
		else
			std::cout << "stack > stack4" << std::endl;

		if (stack4 > stack3)
			std::cout << "stack4 > stack3" << std::endl;
		else
			std::cout << "stack4 < stack3" << std::endl;

		if (stack >= stack2)
			std::cout << "stack >= stack2" << std::endl;
		else
			std::cout << "stack < stack2" << std::endl;

		if (stack <= stack2)
			std::cout << "stack <= stack2" << std::endl;
		else
			std::cout << "stack > stack2" << std::endl;
	}




















	std::cout << std::endl << std::endl; 
	std::cout << "======================== Map ========================s" << std::endl; 

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
	{
		ft::map<char,int> mymap;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		ft::map<char,int>::const_iterator it = mymap.begin();

		std::cout << it->first << std::endl;
		it++;
		it++;
		std::cout << it->first << std::endl;
		it--;
		std::cout << it->first << std::endl;

		ft::map<char, int>::const_reverse_iterator it2 = mymap.rbegin();

		std::cout << it2->first << std::endl;
		it2++;
		it2++;
		std::cout << it2->first << std::endl;
		it2--;
		std::cout << it2->first << std::endl;
	}
	return (0);
}

