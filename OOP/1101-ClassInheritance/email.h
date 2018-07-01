// Name: �����Z
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1101- ClassInheritance"
#pragma once
#include "document.h"

class Email : public Document //�~��Document
{
public:
	// Intent: Email�غc�l
	// Pre: body & sender & recipient & title
	// Post: Email�غc�l
	Email(string body, string sender, string recipient, string title) :Document(body), sender(sender), recipient(recipient), title(title) {}
	// Intent: Email �� operator overloading
	// Pre: Email &email
	// Post: Email �� operator overloading
	Email operator=(Email &email);
private:
	string sender;
	string recipient;
	string title;
};

