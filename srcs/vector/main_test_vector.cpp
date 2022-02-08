#include <iostream>
#include <vector>

template < class T >
void show_vector(std::vector<T> vect) {
	std::cout << "vect contains:";
	for (int i=0;i<vect.size();i++)
		std::cout << ' ' << vect[i];
	std::cout << std::endl << std::endl;
}
int main()
{

	std::cout << "----------------------- CONSTRUCTOR -----------------------" << std::endl; 
	{
		std::cout << "Default constructor" << std::endl;
		std::cout << "explicit vector(const allocator_type& alloc = allocator_type())" << std::endl << std::endl;
		
		std::vector<int> vect;

		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);
	}
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;

	{
		std::cout << "Fill constructor" << std::endl;
		std::cout << "explicit vector (size_type n, const value_type& val = ;value_type(), const allocator_type& alloc = allocator_type())" << std::endl << std::endl;

		std::vector<int> vect(4, 42);
		std::vector<std::string> vect2(2, "Hello World");
		std::vector<char> vect3(10, 'z');
		std::vector<float> vect4(5, 42.42);
		std::vector<int> vect5(0, 100);
		std::vector<int> vect6(400, 1);
		std::vector<int> vect7(std::numeric_limits<unsigned int>::max() + 1, 1);


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

		std::vector<int> vect(50,42);
		std::vector<int> vect2(vect.begin(),vect.end());
		int myints[] = {16,2,77,29};
		std::vector<int> vect3(myints, myints + sizeof(myints) / sizeof(int));
		std::vector<int> vect4(vect.begin(),vect.begin() + 20);
		std::vector<int> vect5(vect.begin(),vect.begin());

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

		std::vector<int> vect(50,42);
		std::vector<int> vect2;
		std::vector<int> vect3(vect);
		std::vector<int> vect4(vect2);


		std::cout << "Fill Size = " << vect3.size() << " - Alloc Size = " << vect3.capacity() << std::endl;
		show_vector(vect3);
		
		std::cout << "Fill Size = " << vect4.size() << " - Alloc Size = " << vect4.capacity() << std::endl;
		show_vector(vect4);
	}

	std::cout << "----------------------- RESIZE -----------------------" << std::endl;
	std::cout << "void resize (size_type n, value_type val = value_type())" << std::endl << std::endl;

	{
		std::vector<int> vect(10, 42);

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

	std::cout << "----------------------- RESERVE -----------------------" << std::endl;
	std::cout << "void reserve (size_type n)" << std::endl << std::endl;

	{
		std::vector<int> vect(5, 42);
		

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
		std::vector<int> vect2;

		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);

		vect2.reserve(2);
		std::cout << "Fill Size = " << vect2.size() << " - Alloc Size = " << vect2.capacity() << std::endl;
		show_vector(vect2);
	}

		std::cout << "----------------------- MAX SIZE / EMPTY -----------------------" << std::endl;
		std::cout << "bool empty() const" << std::endl;
		std::cout << "size_type max_size() const" << std::endl << std::endl;

	{
		std::vector<int> vect(1,1);
		std::vector<int> vect2(3,10);
		std::vector<int> vect3;
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

		std::cout << "----------------------- AT -----------------------" << std::endl;
		std::cout << "reference at (size_type n)" << std::endl;

	{
		std::vector<int> vect(10);
		std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		show_vector(vect);

		for (unsigned i=0; i<vect.size(); i++)
    		vect.at(i)=i;
		for (unsigned i=0; i<vect.size(); i++)
			std::cout << ' ' << vect.at(i);
		std::cout << '\n';

		// vect.at(vect.size());

		vect.clear();
		// vect.at(0);

		const std::vector<int> vect2(10, 2);

		vect2.at(3);
	}

	std::cout << "----------------------- FRONT/BACK -----------------------" << std::endl;
	std::cout << "reference at (size_type n)" << std::endl << std::endl;

	{
		std::vector<int> vect(5, 3);

		std::cout << "Front = " << vect.front() << std::endl;
		vect.reserve(6);
		vect.at(vect.size() - 1) = 42;
		std::cout << "Back = " << vect.back() << std::endl;
		vect.clear();
		std::cout << "Front = " << vect.front() << std::endl;
	}












	// std::cout << "----------------------- INSERT -----------------------" << std::endl;
	// std::cout << "iterator insert(iterator position, const value_type& val)" << std::endl << std::endl;

	// {
	// 	// -------------- Container size of 4 -----------
	// 	std::cout << "Test a container with a size of 4 :" <<  std::endl << std::endl;
	// 	std::vector<int> vect(4, 100);
	// 	std::vector<int>::iterator it;
	// 	// std::vector<std::string> vect(4, "Ceci est un test");

	// 	// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
	// 	std::cout << "At start vect contains:";
	// 	show_vector(vect);

	// 	// vect.insert(vect.end(), "Hello World");
	// 	std::cout << "Insert 42 at the beginning of the vector" << std::endl;
	// 	it = vect.insert(vect.begin(), 42);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(vect);

	// 	std::cout << "Insert 43 at the beginning + 2 of the vector" << std::endl;
	// 	it = vect.insert(vect.begin() + 2, 43);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(vect);

	// 	std::cout << "Insert 1921 at the end of the vector" << std::endl;
	// 	it = vect.insert(vect.end(), 1921);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(vect);

	// 	std::cout << "Insert 442 at the end - 1 of the vector" << std::endl;
	// 	it = vect.insert(vect.end() - 1, 442);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(vect);

	// 	// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;

	// 	//------------ Empty container ---------
	// 	std::cout << "Test an empty container :" <<  std::endl << std::endl;

	// 	std::vector<int> empty_vect;

	// 	// std::cout << "Fill Size = " << empty_vect.size() << " - Alloc Size = " << empty_vect.capacity() << std::endl;
	// 	std::cout << "At start vect contains:";
	// 	show_vector(empty_vect);

	// 	std::cout << "Insert 42 at the beginning of the vector" << std::endl;
	// 	it = empty_vect.insert(empty_vect.begin(), 42);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(empty_vect);

	// 	std::cout << "Insert 43 at the beginning of the vector" << std::endl;
	// 	it = empty_vect.insert(empty_vect.begin(), 43);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(empty_vect);

	// 	std::cout << "Insert 120 at the end of the vector" << std::endl;
	// 	it = empty_vect.insert(empty_vect.end(), 120);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(empty_vect);

	// 	std::cout << "Insert 400 at the end - 1 of the vector" << std::endl;
	// 	it = empty_vect.insert(empty_vect.end() - 1, 400);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(empty_vect);

	// 	// std::cout << "After Changes ------> Fill Size = " << empty_vect.size() << " - Alloc Size = " << empty_vect.capacity() << std::endl << std::endl;
	// }

	// {
	// 	//------------ container size of 1 ---------
	// 	std::cout << "Test a container with a size of 1:" <<  std::endl << std::endl;

	// 	std::vector<int> vect(1, 0);
	// 	std::vector<int>::iterator it;

	// 	// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
	// 	std::cout << "At start vect contains:";
	// 	show_vector(vect);

	// 	std::cout << "Insert 120 at the end of the vector" << std::endl;
	// 	it = vect.insert(vect.end(), 120);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(vect);
	// 	// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;



	// 	std::cout << "Insert 42 at the beginning of the vector" << std::endl;
	// 	it = vect.insert(vect.begin(), 42);
	// 	std::cout << "return value = " << *it << std::endl;
	// 	show_vector(vect);

	// 	// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	// }

	// {
	// 	std::cout << "void insert (iterator position, size_type n, const value_type& val)" << std::endl << std::endl;

	// 	// -------------- Container size of 4 -----------
	// 	std::cout << "Test a container with a size of 4 :" <<  std::endl << std::endl;
	// 	std::vector<int> vect(4, 100);
	// 	// std::vector<std::string> vect(4, "Ceci est un test");

	// 	std::cout << "At start vect contains:";
	// 	show_vector(vect);

	// 	// vect.insert(vect.end(), "Hello World");
	// 	std::cout << "Insert 21 4 time at the beginning of the vector" << std::endl;
	// 	vect.insert(vect.begin(), 4, 21);
	// 	show_vector(vect);

	// 	std::cout << "Insert 10 4 time at the end of the vector" << std::endl;
	// 	vect.insert(vect.end(), 4, 10);
	// 	show_vector(vect);

	// 	std::cout << "Insert 342 2 time at the end - 1 of the vector" << std::endl;
	// 	vect.insert(vect.end() - 1, 2, 342);
	// 	show_vector(vect);

	// 	std::cout << "Insert 2 1 time at the beginning + 2 of the vector" << std::endl;
	// 	vect.insert(vect.begin() + 2, 1, 2);
	// 	show_vector(vect);
	// 	// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	// }
	// {
	// 	std::cout << "void insert (iterator position, size_type n, const value_type& val)" << std::endl << std::endl;

	// 	// -------------- Container size of 4 -----------
	// 	std::cout << "Test a empty container :" <<  std::endl << std::endl;
	// 	std::vector<int> vect;
	// 	// std::vector<std::string> vect(4, "Ceci est un test");

	// 	// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
	// 	std::cout << "At start vect contains:";
	// 	show_vector(vect);

	// 	// vect.insert(vect.end(), "Hello World");
	// 	std::cout << "Insert 21 4 time at the beginning of the vector" << std::endl;
	// 	vect.insert(vect.begin(), 4, 21);
	// 	show_vector(vect);

	// 	std::cout << "Insert 10 4 time at the end of the vector" << std::endl;
	// 	vect.insert(vect.end(), 4, 10);
	// 	show_vector(vect);

	// 	std::cout << "Insert 342 2 time at the end - 1 of the vector" << std::endl;
	// 	vect.insert(vect.end() - 1, 2, 342);
	// 	show_vector(vect);

	// 	std::cout << "Insert 2 1 time at the beginning + 2 of the vector" << std::endl;
	// 	vect.insert(vect.begin() + 2, 1, 2);
	// 	show_vector(vect);
	// 	std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	// }

	// {
	// 	std::cout << "void insert (iterator position, InputIterator first, InputIterator last)" << std::endl << std::endl;

	// 	std::vector<int> vect (3,100);
	// 	show_vector(vect);
	// 	int myarray [] = { 501,502,503 };

	// 	std::cout << "Insert array of three elements at the beginning of the vector" << std::endl;
	// 	vect.insert (vect.begin(), myarray, myarray+3);
	// 	show_vector(vect);

	// 	std::cout << "Insert array of three elements at the end of the vector" << std::endl;
	// 	vect.insert (vect.end(), myarray, myarray+3);
	// 	show_vector(vect);

	// 	std::cout << "Insert array of three elements at the middle of the vector" << std::endl;
	// 	vect.insert (vect.begin() + 5, myarray, myarray+3);
	// 	show_vector(vect);

	// 	std::cout << "Insert an element of the current vector" << std::endl;
	// 	vect.insert (vect.begin() + 4, vect.begin(), vect.begin() + 1);
	// 	show_vector(vect);
	// 	// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
  		
	// }












	// std::cout << "----------------------- ERASE -----------------------" << std::endl;
	// std::cout << "iterator erase (iterator position)" << std::endl << std::endl;	
	// {
	// 	std::vector<int> vect;
	// 	std::vector<int>::iterator it;

	// 	for (int i=0;i<=10;i++) vect.push_back(i);
	// 	show_vector(vect);
		
	// 	std::cout << "Erase the last element" << std::endl;
	// 	vect.erase(vect.end() - 1);
	// 	show_vector(vect);

	// 	std::cout << "Erase the third element" << std::endl;
	// 	vect.erase(vect.begin() + 3);
	// 	show_vector(vect);

	// 	// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	// }
	// std::cout << "iterator erase (iterator first, iterator last)" << std::endl << std::endl;
	// {
	// 	std::vector<int> vect;
	// 	std::vector<int>::iterator it;

	// 	for (int i=0;i<=10;i++) vect.push_back(i);

	// 	// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


	// 	std::cout << "Erase first three elements" << std::endl;
	// 	it = vect.erase(vect.begin(), vect.begin() + 3);
	// 	std::cout << "return = " << *it << std::endl;
	// 	show_vector(vect);
	// 	// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


	// 	std::cout << "Erase two last elements" << std::endl;
	// 	it = vect.erase(vect.end() - 3, vect.end());
	// 	std::cout << "return = " << *it << std::endl;
	// 	show_vector(vect);
	// 	// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


	// 	std::cout << "Erase 1 element on the middle" << std::endl;
	// 	it = vect.erase(vect.begin() + 2, vect.begin() + 3);
	// 	std::cout << "return = " << *it << std::endl;
	// 	show_vector(vect);
	// 	// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


	// 	std::cout << "Erase all" << std::endl;
	// 	it = vect.erase(vect.begin(), vect.end());
	// 	std::cout << "return = " << *it << std::endl;
	// 	show_vector(vect);

	// 	// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	// }





	// std::cout << "----------------------- ASSIGN -----------------------" << std::endl;
	// std::cout << "void assign (size_type n, const value_type& val)" << std::endl << std::endl;

	// {
	// 	std::vector<int> vect(5, 100);
	// 	std::vector<int> vect2;
		
	// 	std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
	// 	show_vector(vect);

	// 	std::cout << "assign 7 elements of 42" << std::endl;
	// 	vect.assign(7, 42);
	// 	std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
	// 	show_vector(vect);

	// 	std::cout << "assign 3 elements of 1" << std::endl;
	// 	vect.assign(3, 1);
	// 	std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
	// 	show_vector(vect);


	// 	std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
	// 	std::cout << "vect2 contains:";
	// 	show_vector(vect2);

	// 	std::cout << "assign 2 elements of 93" << std::endl;
	// 	vect2.assign(2, 93);
	// 	std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
	// 	std::cout << "vect2 contains:";
	// 	show_vector(vect2);
	// }

	return 0;
}