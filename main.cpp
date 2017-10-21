#include <iostream>
#include <string.h>

#define STR_LEN 64

#include "Workers.h"

int parser(char* stringToParse, char** name, char** position, int* receiptYear, int* salary) { // generation data for constructor
	char tmpStr[STR_LEN] = "";
	sscanf(stringToParse, "%s", tmpStr);
	char* nameTmp = new char[strlen(tmpStr)+1];
	strcpy(nameTmp, tmpStr);
	sscanf(stringToParse+strlen(nameTmp)+1, "%s", tmpStr);
	*name = new char[strlen(nameTmp)+strlen(tmpStr)+2];
	strcpy(*name, nameTmp);
	strcat(*name, " ");
	strcat(*name, tmpStr);
	delete[] nameTmp;
	sscanf(stringToParse+strlen(*name)+1, "%s", tmpStr);
	*position = new char[strlen(tmpStr)+1];
	strcpy(*position, tmpStr);
	sscanf(stringToParse+strlen(*name)+strlen(*position)+2, "%i %i", receiptYear, salary);
}

Workers makeFromFile(const char* path) {
	FILE* list = fopen(path, "r");
	Workers workers;
	if(list == nullptr) {
		std::cout << "File " << path << " can\'t be read.";
		return workers;
	}
	char tmpStr[STR_LEN] = "";
	while(!feof(list)) {
		char* strToParse = fgets(tmpStr, STR_LEN, list);
		if(strToParse != nullptr) {
			char* pName = nullptr;
			char* pPosition = nullptr;
			int pYear = 0;
			int pSalary = 0;
			parser(strToParse, &pName, &pPosition, &pYear, &pSalary);
			if((pName != nullptr) && (pPosition != nullptr) && (pYear > 0) && (pSalary > 0)) {
				Worker tmpWorker(pName, pPosition, pYear, pSalary);
				workers.setBack(tmpWorker);
			} else {
				std::cout << "String \"" << strToParse << "\" don\'t contain an object description." << std::endl;
			}
		}
	}
	return workers;
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		std::cout << "Invalid input." << std::endl;
		return -1;
	}
	Workers company = makeFromFile(argv[1]);
	company.show();
	company.experience(10);
	company.searchBySalary(50000);
	company.searchByPosition("economist");
	company.searchByPosition("operator");
	Worker newWorker;
	newWorker.setName("Zaycev A.S.");
	newWorker.setPosition("newbie");
	newWorker.setYear(2017);
	newWorker.setSalary(10000);
	newWorker.show();
	company.setBack(newWorker);
	company.getByIndex(7).show();
	return 0;
}