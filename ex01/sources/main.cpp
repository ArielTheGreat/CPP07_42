#include "iter.hpp"
#include <iostream>

int main(void)
{
	int int_arr[] = {5, 4, 3, 2, 1};
	::iter(int_arr, 5, my_print<int>);
	std::cout << std::endl;

	float float_arr[] = {5.5, 4.4, 3.3, 2.2, 1.1};
	::iter(float_arr, 5, my_print<float>);
	std::cout << std::endl;

	char char_arr[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(char_arr, 5, my_print<char>);
	std::cout << std::endl;

	std::string string_arr[] = {"Hello", "World", "!"};
	::iter(string_arr, 3, my_print<std::string>);
	std::cout << std::endl;
	
	return (0);
}