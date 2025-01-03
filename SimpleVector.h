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

//생성자
//capacity값이 입력되지 않으면 default 10의 값으로 생성됨
template <typename T>
SimpleVector<T>::SimpleVector(int capacity)
{
	data_ = new T[capacity];
	current_size_ = 0;
	current_capacity_ = capacity;
}

//복사 생성자
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other)
{
	int cp = other.current_capacity_;
	current_capacity_ = cp;
	current_size_ = other.current_size_;

	data_ = new int[cp];
	copy(other.data_, other.data_ + cp, data_);
}

//배열이 넘칠 때 사이즈를 재정의
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

//배열을 정렬해주는 함수
template <typename T>
void SimpleVector<T>::SortData()
{
	sort(data_, data_+current_size_);
}

//배열의 마지막 원소 뒤에 새로운 값을 추가해줌
template <typename T>
void SimpleVector<T>::PushBack(const T& value)
{
	if (current_capacity_ == current_size_)
		Resize(current_size_ + 5);

	data_[current_size_++] = value;
}

//배열의 마지막 원소를 삭제
template <typename T>
void SimpleVector<T>::PopBack()
{
	if (current_size_ == 0)
		return;

	--current_size_;
}

//현재 배열의 원소 개수를 반환
template <typename T>
int SimpleVector<T>::Size()
{
	return current_size_;
}

//현재 배열의 크기를 반환
template <typename T>
int SimpleVector<T>::Capacity()
{
	return current_capacity_;
}

//배열의 원소들을 출력
template <typename T>
void SimpleVector<T>::PrintData()
{
	for (int i=0; i<current_size_; i++)
	{
		cout << data_[i] << ' ';
	}
	cout << '\n';
}

//소멸자
template <typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data_;
}