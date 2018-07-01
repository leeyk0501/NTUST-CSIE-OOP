// Name: 李聿鎧
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1101- ClassInheritance"
#pragma once
#include "document.h"

class File : public Document //繼承Document
{
public:
	// Intent: File建構子
	// Pre: body & pathname
	// Post: File建構子
	File(string body, string pathname) :Document(body), pathname(pathname) {}
	// Intent: 設定路徑名稱
	// Pre: pathname為路徑名稱
	// Post: 設定路徑名稱
	void setPathname(string pathname);
	// Intent: 取得路徑名稱
	// Pre: NULL
	// Post: 取得路徑名稱
	string getPathname();
	// Intent: File 的 operator overloading
	// Pre: File &file
	// Post: File 的 operator overloading
	File operator=(File &file);
private:
	//路徑名稱
	string pathname;
};

