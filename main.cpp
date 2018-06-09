#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "MyList.h"

using namespace std;


template<class T>
void show(const List<T>& ml)
{
	for (int i = 0; i < ml.get_size(); i++)
		cout << ml[i] << endl;
}

int main()
{

	setlocale(LC_ALL, "ru");
	List<int> list;
	int size = 10;

	for (int i = 0; i < size; i++)
		list.push_back(rand() % 50);


	show(list);
	cout << "------------------------\n";

	cout << "\n size = " << list.get_size() << endl;

	//for (int i = 0; i < size; i++)
	//{
	//	for (int j = i + 1; j < size; j++)
	//	{
	//		arr[j] < arr[i]
	//		{
	//			temp = arr[i];
	//			arr[i] = arr[j];
	//			arr[j] = temp;
	//		}
	//	}
	//}
	return 0;
}