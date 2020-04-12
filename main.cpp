#include <iostream>

#include "constructor.h"
#include "template.h"
#include "log.h"

#define UNIT_TEST

int main(){
	Test TA(12, "Jam");
	Test TB(TA);
	std::cout << "Value TA : " << TA << std::endl;
	std::cout << "Value TB : " << TB << std::endl;

	Employe tmpA(12, "Tom");
	Employe tmpB(tmpA);
	std::cout << "ValueA : " << tmpA << std::endl;
	std::cout << "ValueB : " << tmpB << std::endl;

	Employe&& tmpC = std::move(tmpA);
	std::cout << "Rvalue: " << tmpC << std::endl;

	//Employe_Test aTestEmploye(1, "theTest");
	//TValidator aValidate;
	//aValidate.validate("the test", aTestEmploye);

	//long long int x = 899877663ll;
	//LOG("x = %lld", x);

	//DefenderTest d;
	//AttackerTest a;

	//a.Move(15, 30);
	//d.Defence(15, 30);
	//a.SpeedUp(1.5f);
	//d.Defence(15,30);

	//Validator v;
	//v.Validate(7, 0, d);
	//v.Validate(1, -10, a);

	//std::cout << "funcT(int) : " << funcT(23, 67) << std::endl;
	//std::cout << "funcT(double) : " << funcT(23.56, 67.89) << std::endl;
	//std::cout << "sizeof(m_pData) : " << sizeof(Test::m_pData) << std::endl;
	//std::cout << "c11 sizeof(m_age) : " << sizeof(Test::m_age) << std::endl;
	//std::cout << "c99 sizeof(m_age) : " << sizeof(((Test*)0)->m_age) << std::endl;
	//std::cout << " cplusplus size: " << __cplusplus << std::endl;

return 0;
}
