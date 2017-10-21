#include "Worker.h"
#pragma once

class Workers {
private:	
	Worker* staff;
	int size;
public:
	// constructors and destructors
	Workers();
	~Workers();
	Workers(const Workers& other);

	Workers& operator= (const Workers& other);


	// methods
	int setBack(const Worker& pushElem);
	Worker getByIndex(const int index) const;
	int getSize() const;
	void show() const;

	void experience(const int yearsCount) const;
	void searchBySalary(const int salarySearch) const;
	void searchByPosition(const char* positionSearch) const;
};