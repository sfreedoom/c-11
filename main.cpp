#include <iostream>

#include "constructor.h"
#include "template.h"
#include "log.h"

#define UNIT_TEST

int main(){
	Test tmpA(12, "Tom");
	std::cout << "Value: " << tmpA << std::endl;

	Test&& tmpB = std::move(tmpA);
	std::cout << "Rvalue: " << tmpB << std::endl;

	long long int x = 899877663ll;
	LOG("x = %lld", x);

	DefenderTest d;
	AttackerTest a;

	a.Move(15, 30);
	d.Defence(15, 30);
	a.SpeedUp(1.5f);
	d.Defence(15,30);

	Validator v;
	v.Validate(7, 0, d);
	v.Validate(1, -10, a);

	//std::cout << "sizeof(m_pData) : " << sizeof(Test::m_pData) << std::endl;
	//std::cout << "c11 sizeof(m_age) : " << sizeof(Test::m_age) << std::endl;
	//std::cout << "c99 sizeof(m_age) : " << sizeof(((Test*)0)->m_age) << std::endl;
	//std::cout << " cplusplus size: " << __cplusplus << std::endl;

return 0;
}
