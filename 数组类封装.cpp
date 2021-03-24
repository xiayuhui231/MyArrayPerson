#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>


//打印输出数组
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


//测试内置数据类型
void test01()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.push_Back(i);
	}
	cout << "array1打印输出：" << endl;
	PrintArray(array1);
	cout << "array1的大小：" << array1.getSize() << endl;
	cout << "array1的容量：" << array1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.pop_Back();
	cout << "array2打印输出：" << endl;
	PrintArray(array2);
	cout << "array2的大小：" << array2.getSize() << endl;
	cout << "array2的容量：" << array2.getCapacity() << endl;
}


//自定义数据类型
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
		cout << "姓名：" << arr[i].m_Name << " 年龄： " << arr[i].m_Age << endl;
	}
}



void test02()
{
	MyArray<Person>arrperson(5);
	//创建数组
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数组
	arrperson.push_Back(p1);
	arrperson.push_Back(p2);
	arrperson.push_Back(p3);
	arrperson.push_Back(p4);
	arrperson.push_Back(p5);
	PrintPerson(arrperson);

	cout << "容量大小为：" << arrperson.getCapacity() << endl;
	cout << "数组大小为：" << arrperson.getSize() << endl;

	arrperson.pop_Back();
	PrintPerson(arrperson);
	cout << "容量大小为：" << arrperson.getCapacity() << endl;
	cout << "数组大小为：" << arrperson.getSize() << endl;

}

int main() {

	//test01();
	test02();
	system("pause");
	return 0;

}