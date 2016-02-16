#ifndef __CONSTRUCTOR_H
#define __CONSTRUCTOR_H

class Test{
public:
	Test(const char* theData = nullptr);
	Test(Test&& t);
	Test(Test& t);
	Test& operator=(Test&& t);
	Test& operator=(Test& t);
	~Test();

pubilc:
	friend std::ostream& operator<<(std::ostream& theOutput, Test& t);

private:
	char* m_pData;
};

#endif //__CONSTRUCTOR
