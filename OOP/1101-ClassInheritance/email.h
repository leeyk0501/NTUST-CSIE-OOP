// Name: 李聿鎧
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1101- ClassInheritance"
#pragma once
#include "document.h"

class Email : public Document //繼承Document
{
public:
	// Intent: Email建構子
	// Pre: body & sender & recipient & title
	// Post: Email建構子
	Email(string body, string sender, string recipient, string title) :Document(body), sender(sender), recipient(recipient), title(title) {}
	// Intent: Email 的 operator overloading
	// Pre: Email &email
	// Post: Email 的 operator overloading
	Email operator=(Email &email);
private:
	string sender;
	string recipient;
	string title;
};

