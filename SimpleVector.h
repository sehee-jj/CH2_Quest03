#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector
{
public:
	SimpleVector(int capacity = 10);
	SimpleVector(const SimpleVector& other);

	void PushBack(const T& value);
	void PopBack();
	int Size();
	int Capacity();
	void SortData();

	void PrintData();

	~SimpleVector();

private:
	T* data_;
	int current_size_;
	int current_capacity_;

	void Resize(int new_capacity);
};

//������
//capacity���� �Էµ��� ������ default 10�� ������ ������
template <typename T>
SimpleVector<T>::SimpleVector(int capacity)
{
	data_ = new T[capacity];
	current_size_ = 0;
	current_capacity_ = capacity;
}

//���� ������
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other)
{
	int cp = other.current_capacity_;
	current_capacity_ = cp;
	current_size_ = other.current_size_;

	data_ = new int[cp];
	copy(other.data_, other.data_ + cp, data_);
}

//�迭�� ��ĥ �� ����� ������
template <typename T>
void SimpleVector<T>::Resize(int new_capacity)
{
	if (current_capacity_ > new_capacity)
		return;

	T* temp = new T[new_capacity];
	copy(data_, data_ + current_capacity_, temp);
	delete[] data_;
	data_ = temp;
	current_capacity_ = new_capacity;
}

//�迭�� �������ִ� �Լ�
template <typename T>
void SimpleVector<T>::SortData()
{
	sort(data_, data_+current_size_);
}

//�迭�� ������ ���� �ڿ� ���ο� ���� �߰�����
template <typename T>
void SimpleVector<T>::PushBack(const T& value)
{
	if (current_capacity_ == current_size_)
		Resize(current_size_ + 5);

	data_[current_size_++] = value;
}

//�迭�� ������ ���Ҹ� ����
template <typename T>
void SimpleVector<T>::PopBack()
{
	if (current_size_ == 0)
		return;

	--current_size_;
}

//���� �迭�� ���� ������ ��ȯ
template <typename T>
int SimpleVector<T>::Size()
{
	return current_size_;
}

//���� �迭�� ũ�⸦ ��ȯ
template <typename T>
int SimpleVector<T>::Capacity()
{
	return current_capacity_;
}

//�迭�� ���ҵ��� ���
template <typename T>
void SimpleVector<T>::PrintData()
{
	for (int i=0; i<current_size_; i++)
	{
		cout << data_[i] << ' ';
	}
	cout << '\n';
}

//�Ҹ���
template <typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data_;
}