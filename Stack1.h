#pragma once
#include "StackBase.h"
#include <iostream>
using namespace std;

template <typename T>
class StackOnArray : public StackBase<T>
{
private:
	T* data{ nullptr };
	int count{ -1 }, capacity{ 0 };
public:
	StackOnArray(int capacity)
	{
		this->capacity = capacity;
		this->count = -1;
		data = new T[capacity];
	}
	StackOnArray(const StackOnArray& copy)
	{
		data = new T[copy.capacity];
		capacity = copy.capacity;
		count = copy.count;
		for (int i = 0; i <= count; ++i)
			data[i] = copy.data[i];
	}
	StackOnArray(StackOnArray&& move)
	{
		data = move.data;
		capacity = move.capacity;
		count = move.count;
		move.data = nullptr;
	}
	~StackOnArray()
	{
		delete[] data;
	}

	StackOnArray& operator=(const StackOnArray& copy)
	{
		if (this == &copy) return *this;
		delete[] data;
		data = new T[copy.capacity];
		capacity = copy.capacity;
		count = copy.count;
		for (int i = 0; i <= count; ++i)
			data[i] = copy.data[i];
	}
	StackOnArray& operator=(StackOnArray&& move)
	{
		if (this == &move) return *this;
		delete[] data;
		data = move.data;
		count = move.count;
		capacity = move.capacity;
		move.data = nullptr;
	}

	int GetCapacity()
	{
		return capacity;
	}
	int GetSize() override
	{
		return count;
	}
	T Pop() override
	{
		if (count == -1) throw exception("stack is empty");
		return data[count--];
	}
	void Push(const T& element) override
	{
		if (count + 1 >= capacity) throw exception("stack is full");
		data[++count] = element;
	}
	T Peek() override
	{
		if (count == -1) throw exception("stack is empty");
		return data[count];
	}

	friend ostream& operator<<(ostream& stream, const StackOnArray& data);
};

template <typename T>
ostream& operator<<(ostream& stream, const StackOnArray<T>& data)
{
	for (int i = 0; i <= data.count; ++i)
		cout << data.data[i] << " ";
	return stream;
}
