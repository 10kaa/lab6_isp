#pragma once
#include "StackBase.h"
#include "UnidirCyclicList.h"
#include <iostream>
using namespace std;

template <typename T>
class StackOnUnidirCyclicList : public StackBase<T>
{
private:
	UnidirCyclicList<T>* data{ nullptr };
	int count{ 0 };

public:
	StackOnUnidirCyclicList() 
	{
		count = 0;
		data = new UnidirCyclicList<T>();
	}
	StackOnUnidirCyclicList(const StackOnUnidirCyclicList& copy)
	{
		data = new UnidirCyclicList<T>();
		count = copy.count;
		for (int i = 0; i < count; ++i)
			data->AddBack(data->ElementAt(count - i));
	}
	StackOnUnidirCyclicList(StackOnUnidirCyclicList&& move)
	{
		data = move.data;
		count = move.count;
		move.data = nullptr;
	}
	~StackOnUnidirCyclicList()
	{
		delete data;
	}

	StackOnUnidirCyclicList& operator=(const StackOnUnidirCyclicList& copy)
	{
		if (this == &copy) return *this;
		delete data;
		data = new UnidirCyclicList<T>();
		count = copy.count;
		for (int i = 0; i < count; ++i)
			data->AddBack(data->ElementAt(count - i));
	}
	StackOnUnidirCyclicList& operator=(StackOnUnidirCyclicList&& move)
	{
		if (this == &move) return *this;
		delete data;
		data = move.data;
		count = move.count;
		move.data = nullptr;
	}

	int GetSize() override
	{
		return count;
	}
	T Pop() override
	{
		if (count == 0) throw exception("stack is empty");
		T ret = data->ElementAt(--count);
		data->RemoveBack();
		return ret;
	}
	void Push(const T& element) override
	{
		data->AddFront(element);
		++count;
	}
	T Peek() override
	{
		if (count == 0) throw exception("stack is empty");
		return data->ElementAt(count - 1);
	}

	template <typename T>
	friend std::ostream& operator<<(std::ostream& stream, const StackOnUnidirCyclicList<T>& data);
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const StackOnUnidirCyclicList<T>& data)
{
	for (int i = 0; i < data.count; ++i)
		cout << data.data->ElementAt(i) << " ";
	return stream;
}
