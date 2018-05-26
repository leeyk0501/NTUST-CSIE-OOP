// Name: �����Z
// Date: March 17, 2018
// Last Update: March 17, 2018
// Problem statement: C++ Homework "0302 - TextBasedHistogram"
#include<iostream>
#include<fstream>
#include<map> //use at map
#include<string>
#define SIZE 5

using namespace std;

// Intent: ��Xgrades.Output
// Pre: outputData�ܤ֭n���@�����
// Post: �N��Ƴv����X��grades.Output
void outputGrades(map<int, int> outputData)
{
	fstream ostream;
	ostream.open("grades.Output", fstream::out);

	for (pair<int, int> i : outputData)
	{
		ostream << i.second << " grade(s) of " << i.first << endl;
	}
	ostream.close();
	cout << "grades.Output" << endl;
}
int main()
{
	int n;
	string fileName;
	ifstream inputStream;
	ofstream outputStream;

	map<int, int> inputData;
	while (cin >> fileName)
	{
		//�}���ɮ�
		inputStream.open(fileName);

		//inputData��l�ơA�s�W0��SIZE��key
		inputData.clear();
		for (int i = 0; i <= SIZE; i++)
		{
			inputData.insert(make_pair(i, 0));
		}

		//�έp���Z
		while (inputStream >> n)
		{
			inputData[n]++;
		}

		//�����ɮ�
		inputStream.close();

		//�N�έp���G��X��grades.Output
		outputGrades(inputData);
	}
	return 0;
}