#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{

		cout << "���캯������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[capacity];
	}
	~MyArray()
	{
		
		if (this->pAddress != NULL)
		{
			cout << "���캯������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;  //��ֹҰָ��
		}
	}

	MyArray(const MyArray &arr)
	{
		cout << "�������캯������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddress = new T[arr.m_Capacity];
		//��arr�е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	//operator = ��ֹǳ����
	MyArray& operator=(const MyArray &arr)
	{
		cout << "operator =�������캯������" << endl;
		//���ж�ԭ���Ƿ��ж�������������ͷ�
		if (this->pAddress != NULL)
		{
			
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}

		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

//����[]
	T& operator[] (int index)
	{
		return this->pAddress[index];
	}

	//β�巨
	void push_Back(const T &val)
	
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}


		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//��ȡ����
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��ȡ�����С
	int getSize()
	{
		return this->m_Size;
	}
private:
	T *pAddress;      //ָ��ָ�����������ʵ����
	int m_Capacity;  // ��������
	int m_Size;      //�����С

};