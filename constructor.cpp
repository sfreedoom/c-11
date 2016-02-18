#include <string.h>
#include <assert.h>

#include "constructor.h"

Test::Test(int theAge, const char* theData) : m_age(theAge){
	if(!theData)
		m_pData = nullptr;
	else{
		m_pData = new char[strlen(theData) + 1];
		strncpy(m_pData, theData, strlen(theData));
		m_pData[strlen(theData)] = '\0';
	}
}

Test::Test(Test&& t) : m_age(t.m_age), m_pData(std::move(t.m_pData)){
	t.m_pData = nullptr;
}

Test::Test(const Test& t){
	if(!t.m_pData)
		m_pData = nullptr;
	else{
		m_pData = new char [strlen(t.m_pData) + 1];
		strncpy(m_pData, t.m_pData, strlen(t.m_pData));
		m_pData[strlen(m_pData)] = '\0';
		m_age = t.m_age;
	}
}

Test& Test::operator=(Test&& t){
	assert(this != &t);

	m_pData = nullptr;
	m_pData = std::move(t.m_pData);
	t.m_pData = nullptr;

	m_age = t.m_age;

	return *this;
}

Test& Test::operator=(Test& t){
	if(this != &t)
		delete [] m_pData;
	else{
		m_pData = new char [strlen(t.m_pData) + 1];
		strncpy(m_pData, t.m_pData, strlen(t.m_pData));
		m_pData[strlen(t.m_pData)] = '\0';

		m_age = t.m_age;
	}

	return *this;
}

Test::~Test(){
	if(m_pData){
		delete [] m_pData;	
		m_pData = nullptr;
	}
}

std::ostream& operator<<(std::ostream& theOutput, const Test& t){
	return theOutput << " age: " << t.m_age << '\t' << " name: " << t.m_pData;
}
