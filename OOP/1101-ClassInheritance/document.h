// Name: �����Z
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1101- ClassInheritance"
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Document
{
public:
	// Intent: Document�غc�l
	// Pre: text
	// Post: Document�غc�l
	Document(string text) :text(text) {}
	// Intent: ���o��r���e
	// Pre: NULL
	// Post: ���o��r���e
	string getText() const;
	// Intent: Document �� operator overloading
	// Pre: Document &document
	// Post: Document �� operator overloading
	Document operator=(Document &document);
private:
	//��r���e
	string text;
};
