#include "vector.hpp"
#include "vector_iterator.hpp"

template < class T >
void show_vector(ft::vector<T> vect) {
	std::cout << "vect contains:";
	for (int i=0;i<vect.size();i++)
		std::cout << ' ' << vect[i];
	std::cout << std::endl << std::endl;
}

int main()
{

	std::cout << "----------------------- INSERT -----------------------" << std::endl;
	std::cout << "iterator insert(iterator position, const value_type& val)" << std::endl << std::endl;

	{
		// -------------- Container size of 4 -----------
		std::cout << "Test a container with a size of 4 :" <<  std::endl << std::endl;
		ft::vector<int> vect(4, 100);
		ft::vectorIterator<int> it;
		// ft::vector<std::string> vect(4, "Ceci est un test");

		// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		std::cout << "At start vect contains:";
		show_vector(vect);

		// vect.insert(vect.end(), "Hello World");
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

		// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;

		//------------ Empty container ---------
		std::cout << "Test an empty container :" <<  std::endl << std::endl;

		ft::vector<int> empty_vect;

		// std::cout << "Fill Size = " << empty_vect.size() << " - Alloc Size = " << empty_vect.capacity() << std::endl;
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

		// std::cout << "After Changes ------> Fill Size = " << empty_vect.size() << " - Alloc Size = " << empty_vect.capacity() << std::endl << std::endl;
	}

	{
		//------------ container size of 1 ---------
		std::cout << "Test a container with a size of 1:" <<  std::endl << std::endl;

		ft::vector<int> vect(1, 0);
		ft::vectorIterator<int> it;

		// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		std::cout << "At start vect contains:";
		show_vector(vect);

		std::cout << "Insert 120 at the end of the vector" << std::endl;
		it = vect.insert(vect.end(), 120);
		std::cout << "return value = " << *it << std::endl;
		show_vector(vect);
		// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;



		std::cout << "Insert 42 at the beginning of the vector" << std::endl;
		it = vect.insert(vect.begin(), 42);
		std::cout << "return value = " << *it << std::endl;
		show_vector(vect);

		// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}

	{
		std::cout << "void insert (iterator position, size_type n, const value_type& val)" << std::endl << std::endl;

		// -------------- Container size of 4 -----------
		std::cout << "Test a container with a size of 4 :" <<  std::endl << std::endl;
		ft::vector<int> vect(4, 100);
		// ft::vector<std::string> vect(4, "Ceci est un test");

		std::cout << "At start vect contains:";
		show_vector(vect);

		// vect.insert(vect.end(), "Hello World");
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
		// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}
	{
		std::cout << "void insert (iterator position, size_type n, const value_type& val)" << std::endl << std::endl;

		// -------------- Container size of 4 -----------
		std::cout << "Test a empty container :" <<  std::endl << std::endl;
		ft::vector<int> vect;
		// ft::vector<std::string> vect(4, "Ceci est un test");

		// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl;
		std::cout << "At start vect contains:";
		show_vector(vect);

		// vect.insert(vect.end(), "Hello World");
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
		// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}

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
		// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
  		
	}












	std::cout << "----------------------- ERASE -----------------------" << std::endl;
	std::cout << "iterator erase (iterator position)" << std::endl << std::endl;	
	{
		ft::vector<int> vect;
		ft::vectorIterator<int> it;

		for (int i=0;i<=10;i++) vect.push_back(i);
		show_vector(vect);
		
		std::cout << "Erase the last element" << std::endl;
		vect.erase(vect.end() - 1);
		show_vector(vect);

		std::cout << "Erase the third element" << std::endl;
		vect.erase(vect.begin() + 3);
		show_vector(vect);

		// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}
	std::cout << "iterator erase (iterator first, iterator last)" << std::endl << std::endl;
	{
		ft::vector<int> vect;
		ft::vectorIterator<int> it;

		for (int i=0;i<=10;i++) vect.push_back(i);

		// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


		std::cout << "Erase first three elements" << std::endl;
		it = vect.erase(vect.begin(), vect.begin() + 3);
		std::cout << "return = " << *it << std::endl;
		show_vector(vect);
		// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


		std::cout << "Erase two last elements" << std::endl;
		it = vect.erase(vect.end() - 3, vect.end());
		std::cout << "return = " << *it << std::endl;
		show_vector(vect);
		// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


		std::cout << "Erase 1 element on the middle" << std::endl;
		it = vect.erase(vect.begin() + 2, vect.begin() + 3);
		std::cout << "return = " << *it << std::endl;
		show_vector(vect);
		// std::cout << "Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;


		std::cout << "Erase all" << std::endl;
		it = vect.erase(vect.begin(), vect.end());
		std::cout << "return = " << *it << std::endl;
		show_vector(vect);

		// std::cout << "After Changes ------> Fill Size = " << vect.size() << " - Alloc Size = " << vect.capacity() << std::endl << std::endl;
	}





	std::cout << "----------------------- ASSIGN -----------------------" << std::endl;
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


	return (0);
}

