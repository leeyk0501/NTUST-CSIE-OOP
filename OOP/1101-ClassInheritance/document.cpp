// Name: §õ¦ÖñZ
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1101- ClassInheritance"
#include "document.h"

string Document::getText() const
{
	return this->text;
}

Document Document::operator=(Document &document)
{
	return Document(document.text);
}
