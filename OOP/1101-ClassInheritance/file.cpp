// Name: §õ¦ÖñZ
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1101- ClassInheritance"
#include "file.h"

void File::setPathname(string pathname)
{
	this->pathname = pathname;
}

string File::getPathname()
{
	return pathname;
}

File File::operator=(File &file)
{
	return File(file.getText(), file.getPathname());
}

