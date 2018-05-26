// Name: �����Z
// Date: March 17, 2018
// Last Update: March 17, 2018
// Problem statement: C++ Homework "0301 - occurrencCounting"
#include<iostream>
#include<fstream>
#include<map> //use at map
#include<functional> //use at std::greater
#include<string>

using namespace std;

// Intent: ��Xoutput.txt
// Pre: outputData�̦ܤ֭n���@�����
// Post: �N��Ƴv����X��output.txt
void outputFile(map<int, int, std::greater<int>> outputData)
{
	fstream ostream;
	ostream.open("output.txt", fstream::out);

	ostream << "N\tCount" << endl;
	for (pair<int,int> i : outputData)
	{
		ostream << i.first << "\t" << i.second << endl;
	}
	ostream.close();
	cout << "output.txt" << endl;
}
int main()
{
	int n;
	string fileName;
	ifstream inputStream;
	ofstream outputStream;
	
	map<int, int, std::greater<int>> inputData;
	while (cin >> fileName)
	{
		//�}���ɮ�
		inputStream.open(fileName);

		inputData.clear();

		while (inputStream >> n)
		{
			//�M��inputData���L��n�Ȫ�key
			map<int, int, std::greater<int>>::iterator iter;
			iter = inputData.find(n);

			if (iter == inputData.end()) 
			{
				//�p�G�binputData�S�����key�A�N�s�W�@��key-value
				inputData.insert(make_pair(n, 1));
			}
			else
			{
				//�p�G�binputData���key�A�N�����b��key��value+=1
				inputData[n]++;
			}
		}
		//�����ɮ�
		inputStream.close();

		//�N�έp���G��X��output.txt
		outputFile(inputData);
	}
	return 0;
}