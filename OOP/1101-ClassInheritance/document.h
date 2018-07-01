// Name: 李聿鎧
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
	// Intent: Document建構子
	// Pre: text
	// Post: Document建構子
	Document(string text) :text(text) {}
	// Intent: 取得文字內容
	// Pre: NULL
	// Post: 取得文字內容
	string getText() const;
	// Intent: Document 的 operator overloading
	// Pre: Document &document
	// Post: Document 的 operator overloading
	Document operator=(Document &document);
private:
	//文字內容
	string text;
};
