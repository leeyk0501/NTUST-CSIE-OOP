// Name: ßı¶÷ÒZ
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1101- ClassInheritance"
#include "email.h"

Email Email::operator=(Email &email)
{
	return Email(email.getText(), email.sender, email.recipient, email.title);
}
