// hello.cpp: Maggie Johnson
// Description: a program that prints the immortal saying "hello world"

#include <iostream>
#include <iomanip>
// using namespace std;

int main() {
  
  for (int i = 0; i < 6; i++)
  {
	  for (int j = 0; j < 4; j++)
	  {
		//   for (int k = 0; k < 17; k++)
		//   	cout << " ";
		//   cout << "Hello World!";
		
		//setw(int) sets the column width
		std::cout << std::setw(17) << "Hello World!";
	  } 
	  std::cout << std::endl;
  }
  return 0;
}
