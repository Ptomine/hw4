#pragma once

class Worker {
private:
	char* name;
	char* position;
	int receiptYear;
	int salary;
public:
	// constructors and destructors
	Worker();
	Worker(const char* nName, const char* nPosition, const int nYear, const int nSalary);
	~Worker();
	Worker(const Worker& other);
	// operators
	Worker& operator= (const Worker& other);
	// seters
	void setName(const char* nName);
	void setPosition(const char* nPosition);
	void setYear(const int nYear);
	void setSalary(const int nSalary);
	// geters
	char* getName() const;
	char* getPosition() const;
	int getYear() const;
	int getSalary() const;

	void show() const;
};