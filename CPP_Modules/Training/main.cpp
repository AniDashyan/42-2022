// include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

namespace apple {
	namespace func {
		void print(const char* text)
		{
			std::cout << text << std::endl;
		}
	}
	void print_again() {
		std::cout << "Bye bye\n";
	}
}

namespace orange {
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
	void print_again() {
		std::cout << "Bye bye\n";
	}
 }

int main() {
	namespace a = apple::func;

	a::print("Hello World!");
	apple::print_again();
	return (0);
}