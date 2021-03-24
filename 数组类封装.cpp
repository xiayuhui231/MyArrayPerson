#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>


//��ӡ�������
void PrintArray(MyArray<int> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

//
//void test01()
//{
//	MyArray<int>arr1(5);
//	/*MyArray<int>arr2(arr1);
//	MyArray<int>arr3(100);*/
//	/*arr3 = arr1;*/
//
//}


//����������������
void test01()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.push_Back(i);
	}
	cout << "array1��ӡ�����" << endl;
	PrintArray(array1);
	cout << "array1�Ĵ�С��" << array1.getSize() << endl;
	cout << "array1��������" << array1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.pop_Back();
	cout << "array2��ӡ�����" << endl;
	PrintArray(array2);
	cout << "array2�Ĵ�С��" << array2.getSize() << endl;
	cout << "array2��������" << array2.getCapacity() << endl;
}


//�Զ�����������
class Person
{
public:

	Person() {}
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	string m_Name;
	int m_Age;
};

void PrintPerson(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "������" << arr[i].m_Name << " ���䣺 " << arr[i].m_Age << endl;
	}
}



void test02()
{
	MyArray<Person>arrperson(5);
	//��������
	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);

	//��������
	arrperson.push_Back(p1);
	arrperson.push_Back(p2);
	arrperson.push_Back(p3);
	arrperson.push_Back(p4);
	arrperson.push_Back(p5);
	PrintPerson(arrperson);

	cout << "������СΪ��" << arrperson.getCapacity() << endl;
	cout << "�����СΪ��" << arrperson.getSize() << endl;

	arrperson.pop_Back();
	PrintPerson(arrperson);
	cout << "������СΪ��" << arrperson.getCapacity() << endl;
	cout << "�����СΪ��" << arrperson.getSize() << endl;

}

int main() {

	//test01();
	test02();
	system("pause");
	return 0;

}