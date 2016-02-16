#include "constructor.h"

Test::Test(const char* theData){
	if(!theData)
		m_pData = nullptr;
	else{
		m_pData = new char[strlen(theData) + 1];
		strncpy(m_pData, theData, strlen(theData));
		m_pData[strlen(theData)] = '\0';
	}
}
