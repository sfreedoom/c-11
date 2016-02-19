#ifndef __CONSTRUCTOR_H
#define __CONSTRUCTOR_H

#include <iostream>

//Normal class.
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

//class with template.
template<typename T> class Employe_T{
public:
	Employe_T(int theAge, const char* theData = nullptr);
	Employe_T(Employe_T&& t);
	Employe_T(const Employe_T& t);
	Employe_T& operator=(Employe_T&& t);
	Employe_T& operator=(Employe_T& t);
	~Employe_T();

public:
	friend T;
	friend std::ostream& operator<<(std::ostream& theOutput, const Employe_T<T>& t){
		return theOutput << " age: " << t.m_age << '\t' << " name: " << t.m_pData;
	}
	friend std::istream& operator>>(std::istream& theInput, const Employe_T<T>& t){
		return theInput >> t.m_age >> t.m_pData;	
	}

private:
	//void setEmploye(int theAge, const char* theName);
	void setEmploye(int theAge, const char* theName){
		m_age = theAge;
		if(!theName)
			m_pData = nullptr;
		else{
			delete [] m_pData;
			m_pData = new char[strlen(theName) + 1];
			strncpy(m_pData, theName, strlen(theName));
			m_pData[strlen(theName)] = '\0';
		}
	}

private:
	int m_age;
	char* m_pData;
		
};

using  Employe = Employe_T<int>;

template<typename T>
Employe_T<T>::Employe_T(int theAge, const char* theData) : m_age(theAge){
	if(!theData)
		m_pData = nullptr;
	else{
		m_pData = new char[strlen(theData) + 1];
		strncpy(m_pData, theData, strlen(theData));
		m_pData[strlen(theData)] = '\0';
	}
}

template<typename T>
Employe_T<T>::Employe_T(Employe_T<T>&& t) : m_age(t.m_age), m_pData(std::move(t.m_pData)){
	t.m_pData = nullptr;
}

template<typename T>
Employe_T<T>::Employe_T(const Employe_T<T>& t){
	if(!t.m_pData)
		m_pData = nullptr;
	else{
		m_pData = new char [strlen(t.m_pData) + 1];
		strncpy(m_pData, t.m_pData, strlen(t.m_pData));
		m_pData[strlen(m_pData)] = '\0';
		m_age = t.m_age;
	}
}

template<typename T>
Employe_T<T>& Employe_T<T>::operator=(Employe_T<T>&& t){
	assert(this != &t);

	m_pData = nullptr;
	m_pData = std::move(t.m_pData);
	t.m_pData = nullptr;

	m_age = t.m_age;

	return *this;
}

template<typename T>
Employe_T<T>& Employe_T<T>::operator=(Employe_T<T>& t){
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

template<typename T>
Employe_T<T>::~Employe_T(){
	if(m_pData){
		delete [] m_pData;	
		m_pData = nullptr;
	}
}

//#ifdef UNIT_TEST
class TValidator;
using Employe_Test = Employe_T<TValidator>;

class TValidator{
	public:
	void validate(const char* theValidateString, Employe_Test& theTest){
		theTest.setEmploye(31, "fucking source code.");
	}
};
//#endif //UNIT_TEST

#endif //__CONSTRUCTOR
