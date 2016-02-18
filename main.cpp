#include <iostream>

#include "constructor.h"
#include "log.h"

int main(){
	Test a(12, "Tom");
	std::cout << "Value: " << a << std::endl;

	Test&& tmp = std::move(a);
	std::cout << "Rvalue: " << tmp << std::endl;

	long long int x = 899877663ll;
	LOG("x = %lld", x);

	//std::cout << "sizeof(m_pData) : " << sizeof(Test::m_pData) << std::endl;
	//std::cout << "c11 sizeof(m_age) : " << sizeof(Test::m_age) << std::endl;
	//std::cout << "c99 sizeof(m_age) : " << sizeof(((Test*)0)->m_age) << std::endl;
	//std::cout << " cplusplus size: " << __cplusplus << std::endl;

return 0;
}
