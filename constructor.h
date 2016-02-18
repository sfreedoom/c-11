#ifndef __CONSTRUCTOR_H
#define __CONSTRUCTOR_H

#include <iostream>

class Test{
public:
	Test(int theAge, const char* theData = nullptr);
	Test(Test&& t);
	Test(const Test& t);
	Test& operator=(Test&& t);
	Test& operator=(Test& t);
	~Test();

public:
	friend std::ostream& operator<<(std::ostream& theOutput, const Test& t);

private:
	int m_age;
	char* m_pData;
};

#endif //__CONSTRUCTOR
