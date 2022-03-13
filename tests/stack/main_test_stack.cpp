#include <stack>
#include <deque>
#include <iostream>

int main()
{
    std::cout << "----------------------- CONSTRUCTOR -----------------------" << std::endl;
	std::cout << "explicit stack (const container_type& ctnr = container_type())" << std::endl << std::endl;

	{
		std::deque<int> deque(5, 42);
        std::stack<int> stack;
        std::stack<int> stack2(deque);

		std::cout << "Stack Size = " << stack.size() << std::endl;
        std::cout << "Stack2 Size = " << stack2.size() << std::endl;
		for (; !stack.empty(); )
        {
            std::cout << "Elem = " << stack2.top() << std::endl;
            stack2.pop();
        }		
	}

    std::cout << std::endl << "----------------------- EMPTY -----------------------" << std::endl;
	std::cout << "bool empty() const" << std::endl << std::endl;

	{
		std::deque<int> deque(1, 42);
        std::stack<int> stack;
        std::stack<int> stack2(deque);

		std::cout << "Stack is empty = " << stack.empty() << std::endl;
        std::cout << "Stack2 is empty = " << stack.empty() << std::endl;
        stack2.pop();
        std::cout << "Stack2 is empty = " << stack.empty() << std::endl;
	}

    std::cout << std::endl << "----------------------- SIZE -----------------------" << std::endl;
	std::cout << "size_type size() const" << std::endl << std::endl;

	{
        std::deque<int> deque(10000, 42);
        std::stack<int> stack;
        std::stack<int> stack2(deque);

		std::cout << "Stack Size = " << stack.size() << std::endl;
        for (int i = 0; i < 2; i++)
            stack.push(i);
		std::cout << "Stack Size = " << stack.size() << std::endl;
        stack2.pop();
		std::cout << "Stack Size = " << stack.size() << std::endl;
        stack2.pop();
		std::cout << "Stack Size = " << stack.size() << std::endl;

        std::cout << "Stack2 Size = " << stack2.size() << std::endl;
	}

    std::cout << std::endl << "----------------------- TOP -----------------------" << std::endl;
	std::cout << "value_type& top()" << std::endl << std::endl;

	{
        std::deque<int> deque(5, 42);
        std::stack<int> stack(deque);

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
        std::deque<int> deque(5, 42);
        const std::stack<int> stack(deque);

        std::cout << "Top Elem = " << stack.top() << std::endl;
    }

    std::cout << std::endl << "----------------------- PUSH -----------------------" << std::endl;
	std::cout << "void push (const value_type& val)" << std::endl << std::endl;

	{
        std::stack<int> stack;

		std::cout << "Stack Size = " << stack.size() << std::endl;
		for (int i = 0; i < 100; i++)
            stack.push(i);
		std::cout << "Stack Size = " << stack.size() << std::endl;
	}

    std::cout << std::endl << "----------------------- POP -----------------------" << std::endl;
	std::cout << "void pop()" << std::endl << std::endl;

	{
        std::stack<int> stack;

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
     std::cout << "----------------------- Non member function -----------------------" << std::endl; 
	{
		std::stack<int> stack;
		for (int i=0;i<=15;i++) stack.push(i);

		std::stack<int> stack2(stack);
		std::stack<int> stack3;
		for (int i=30;i<=40;i++) stack3.push(i);

		std::stack<int> stack4;
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
}