// Name: �����Z
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1101- ClassInheritance"
#pragma once
#include "document.h"

class File : public Document //�~��Document
{
public:
	// Intent: File�غc�l
	// Pre: body & pathname
	// Post: File�غc�l
	File(string body, string pathname) :Document(body), pathname(pathname) {}
	// Intent: �]�w���|�W��
	// Pre: pathname�����|�W��
	// Post: �]�w���|�W��
	void setPathname(string pathname);
	// Intent: ���o���|�W��
	// Pre: NULL
	// Post: ���o���|�W��
	string getPathname();
	// Intent: File �� operator overloading
	// Pre: File &file
	// Post: File �� operator overloading
	File operator=(File &file);
private:
	//���|�W��
	string pathname;
};

