#include <iostream>
#include <string>

/* TheCherno: References in C++

void Increment(int& value) {
	value++;
} 

 int main() {

	int a = 5;
	int b = 8;

	int *ref = &a;
	*ref = 2;
	ref = &b;
	*ref = 3;
// 	Increment(a);
// 	std::cout << "a: " << a << std::endl;
// 	// int& ref = a;
// 	// ref = 2;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	return (0);
} 
*/


/* Caleb Curry: References in C++ explained */

/* Overview */
/* void work(int x) { //passing by value
 
}

void workRef(int& x) { //passing by reference
	x++;
}

int main() {
	int a = 7;
	work(a); // when we call this function the value of a gets copied to x
	workRef(a); // when we call this function x is going to refer to a. In otehr words x becomes alias for a
	std::cout << "a: " << a << std::endl;
	return (0);
} */

/* Bad example of the use of references */
/* class User {
	public:
		std::string name;
	public:
		User(){}
		~User(){}
};

// This is bad from the calling side, because we won't expect it at all based on the name of the function
void printInfo(User& u) {
	u.name = "Leroy Jenkins";
}

int main() {
	User u;

	u.name = "Ani Dashyan";
	printInfo(u);
	std::cout << "name: " << u.name << std::endl;
	return (0);
} */

/* Good example of the use of references */
/* // Swapping data
void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

int main() {
	int a = 7;
	int b = -7;
	std::cout << "before swap\n" << "a: " << a << std::endl << "b: " << b << std::endl;
	swap(a, b);
	std::cout << "after swap\n" << "a: " << a << std::endl << "b: " << b << std::endl;
	return (0);
} */

/* int main() {
	int a = 7;
	int &ref = a;
	std::cout << "ref: " << ref << "\n";
	int c = 777;
	ref = c;
	std::cout << "ref: " << ref << "\n";
	return (0);
} */

/* Intra video on new and delete */
// class Student {
// 	private:
// 		std::string _login;
// 	public:
// 		// : _login(login) initialization list
// 		// This is often done to set up the initial state of the object.
// 		Student(std::string login) : _login(login)  {
// 			std::cout << "Student " << this->_login << " is born" << std::endl;
// 		}

// 		~Student() {
// 			std::cout << "Student " << this->_login << " is dead" << std::endl;
// 		} 
// };

/* class Student {
	private:
		std::string _login;
	public:
		// : _login(login) initialization list
		// This is often done to set up the initial state of the object.
		Student() : _login("ldefault")  {
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}
		
		~Student() {
			std::cout << "Student " << this->_login << " is dead" << std::endl;
		} 
};
*/

// int main() {
	// Intro to new and delete
	/* Student bob("Bob"); // stack
	Student *jim = new Student("Jim"); // heap

	delete jim; // jim is destroyed */

	// Creating multiple objects
	// Student *students = new Student[42];

	// delete [] students;
	// return (0); // bob is destroyed
// } 