#include "Worker.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

Worker::Worker()
	:receiptYear(0),
	salary(0) {
	name = new char[1];
	name[0]='\0';
	position = new char[1];
	position[0]='\0';
}

Worker::Worker(const char* nName, const char* nPosition, const int nYear, const int nSalary)
	:receiptYear(nYear),
	salary(nSalary) {
		name = new char[strlen(nName) +1];
		strcpy(name, nName);
		position = new char[strlen(nPosition)+1];
		strcpy(position, nPosition);
	}

Worker::~Worker() {
	delete[] name;	
	delete[] position;
	receiptYear = 0;
	salary = 0;
}

Worker::Worker(const Worker& other) {
	name = new char[strlen(other.name)+1];
	strcpy(name, other.name);
	position = new char[strlen(other.position)+1];
	strcpy(position, other.position);
	receiptYear = other.receiptYear;
	salary = other.salary;
}

Worker& Worker::operator= (const Worker& other) {
	char* tmpName = new char[strlen(other.name)+1];
	strcpy(tmpName, other.name);
	delete[] name;
	name = tmpName;
	char* tmpPosition = new char[strlen(other.position)+1];
	strcpy(tmpPosition, other.position);
	delete[] position;
	position = tmpPosition;
	receiptYear = other.receiptYear;
	salary = other.salary;
	return *this;
}

void Worker::setName(const char* nName) {
	char* tmpName = new char[strlen(nName)+1];
	strcpy(tmpName, nName);
	delete[] name;
	name = tmpName;
}

void Worker::setPosition(const char* nPosition) {
	char* tmpPosition = new char[strlen(tmpPosition)+1];
	strcpy(tmpPosition, nPosition);
	delete[] position;
	position = tmpPosition;
}

void Worker::setYear(const int nYear) {
	receiptYear = nYear;
}

void Worker::setSalary(const int nSalary) {
	salary = nSalary;
}

char* Worker::getName() const {
	return name;
}

char* Worker::getPosition() const {
	return position;
}

int Worker::getYear() const {
	return receiptYear;
}

int Worker::getSalary() const {
	return salary;
}
void Worker::show() const {
	std::cout << name << " " << position << " " << receiptYear << " " << salary << std::endl;
}