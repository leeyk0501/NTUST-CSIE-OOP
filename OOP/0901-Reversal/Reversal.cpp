// Name: �����Z
// Date: 20180508
// Last Update: 20180508
// Problem statement: C++ Homework "0901 - Reversal"
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#define FILENAME "words.txt" //�ɦW
using namespace std;

// Intent: ��r��p�g
// Pre: word��string
// Post: ��X���p�g����r
string toLower(string word)
{
	int cut = 'a' - 'A';
	for (int i = 0; i < word.size(); i++)word[i] = (word[i] >= 'A' && word[i] <= 'Z') ? word[i] + cut : word[i];
	return word;
}
int main()
{
	map<string, int> wordData;	//�����Ƹ��
	vector<string> wordFile;	//�������
	ifstream in(FILENAME); // Ū���ɮ�FILENAME
	stringstream strStream(static_cast<stringstream const&>(stringstream() << in.rdbuf()).str()); //Ū����󤺩Ҧ����
	string str, lStr, rStr;
	int i = 0;
	while (getline(strStream, str, '\n')) //����Ū��
	{
		if (str.size() > 0) //�D�ų�r
		{
			lStr = toLower(str);
			bool find;
			find = wordData.count(lStr); //�N��r(key)�H�άy����(value)��Jmap(�����j�p�g)
			if (!find)wordData[lStr] = i;

			wordFile.push_back(str); //�N�Ҧ���r��Jvector(�����j�p�g)

			i++;//�y����
		}
	}

	int max = -1; //�ثe�̪��ŦX���󪺳�r
	int nowID = i; // �ثe�̪��ŦX���󪺳�r�y����
	map<string, int>::iterator temp = wordData.end();
	for (vector<string>::iterator iter = wordFile.begin(); iter != wordFile.end(); iter++)
	{
		rStr = iter->c_str();
		reverse(rStr.begin(), rStr.end()); //����r��
		rStr = toLower(rStr); //�r���p�g
		map<string, int>::iterator itit = wordData.find(rStr);
		if (itit != wordData.end())
		{
			int size = itit->first.size();

			//�p�G���ŦX����B���ק������r�A�άO���ŦX����B���ר����B����m��e������r
			if (size > max || (size >= max && itit->second < nowID)) 
			{
				max = size;
				nowID = itit->second;
				temp = itit;
			}
		}
	}
	if (temp != wordData.end())cout << wordFile[temp->second] << endl; //�ŦX���󪺳�r�N��X(�P�˪��״N��X�̥���쪺)
	
	system("pause");
	return 0;
}