#include <iostream>
#include "constructor.h"

int main(){
	Test a("It's a Test Value.");
	std::cout << "Value: " << a << std::endl;

	Test&& tmp = std::move(a);
	std::cout << "Rvalue: " << tmp << std::endl;

return 0;
}
