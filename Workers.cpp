#include "Workers.h"
#include "Worker.h"
#include <string.h>
#include <iostream>
#include <ctime>

Workers::Workers()
	:staff(nullptr),
	size(0) {}

Workers::~Workers() {
	delete[] staff;
	size = 0;
}

Workers::Workers(const Workers& other) {
	if(other.size > 0) {
		size = other.size;
		staff = new Worker[size];
		for(int i = 0; i < size; i++) {
			staff[i] = other.staff[i];
		}
	} else {
		size = 0;
		staff = nullptr;
	}
}

Workers& Workers::operator= (const Workers& other) {
	if(other.size > 0) {
		size = other.size;
		staff = new Worker[size];
		for(int i = 0; i < size; i++) {
			staff[i] = other.staff[i];
		}
	} else {
		size = 0;
		staff = nullptr;
	}
}

int Workers::setBack(const Worker& pushElem) {
	if(size == 0) { 
		staff = new Worker[1];
		size++;
		staff[0] = pushElem;
		return (size-1);
	} else { 
		Worker* tmpStaff = new Worker[size+1];
		tmpStaff[size] = pushElem;
		for(int i = 0; i < size; i++) {
			tmpStaff[i] = staff[i];
		}
		delete[] staff;
		staff = tmpStaff;
		size++;
		return (size-1);
	}
}

Worker Workers::getByIndex(const int index) const {
	return staff[index];
}

int Workers::getSize() const {
	return size;
}

void Workers::show() const {
	for(int i = 0; i < size; i++) {
		staff[i].show();
	}
}

void Workers::experience(const int yearsCount) const {
	std::cout << "Searching for workers with experience more than " << yearsCount << " year(s):" << std::endl;
	time_t seconds = time(nullptr);
	const int INITIAL_YEAR = 1900;
	tm* timeinfo = localtime(&seconds);
	int neededYear = INITIAL_YEAR + timeinfo->tm_year - yearsCount;
	int k = 0;
	for(int i = 0; i < size; i++) {
		if(staff[i].getYear() <= neededYear) {
			std::cout<<k+1<<". "<<staff[i].getName()<<std::endl;
			k++;
		}
	}	
	if(k==0) {
		std::cout<<"Search has not given any results."<<std::endl;
	}
	return;
}

void Workers::searchBySalary(const int salarySearch) const {
	std::cout << "Searching for workers with salry more than " << salarySearch << ":" << std::endl;
	int k = 0;
	for(int i = 0; i < size; i++) {
		if(staff[i].getSalary() > salarySearch) {
			std::cout<<k+1<<". "<<staff[i].getName()<<std::endl;
			k++;
		}
	}
	if(k == 0) {
		std::cout<<"Search has not given any results."<<std::endl;
	}
	return;
}

void Workers::searchByPosition(const char* positionSearch) const {
	std::cout << "Searching for workers who is takes " << positionSearch << " position:" << std::endl;
	int k = 0;
	for(int i  = 0; i < size; i++) {
		if(strcmp(positionSearch, staff[i].getPosition()) == 0) {
			std::cout<<k+1<<". "<<staff[i].getName()<<std::endl;
			k++;
		}
	}
	if(k == 0) {
		std::cout<<"Search has not given any results."<<std::endl;	
	}
	return;
}