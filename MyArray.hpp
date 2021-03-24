#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{

		cout << "构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[capacity];
	}
	~MyArray()
	{
		
		if (this->pAddress != NULL)
		{
			cout << "析造函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;  //防止野指针
		}
	}

	MyArray(const MyArray &arr)
	{
		cout << "拷贝构造函数调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	//operator = 防止浅拷贝
	MyArray& operator=(const MyArray &arr)
	{
		cout << "operator =拷贝构造函数调用" << endl;
		//先判断原来是否有堆区，如果有先释放
		if (this->pAddress != NULL)
		{
			
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

//重载[]
	T& operator[] (int index)
	{
		return this->pAddress[index];
	}

	//尾插法
	void push_Back(const T &val)
	
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}


		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//获取容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//获取数组大小
	int getSize()
	{
		return this->m_Size;
	}
private:
	T *pAddress;      //指针指向堆区开辟真实数组
	int m_Capacity;  // 数组容量
	int m_Size;      //数组大小

};