#pragma once

template <typename T>
class StackBase
{
public:
	virtual ~StackBase() = default;

	virtual void Push(const T& element) = 0;
	virtual T Pop() = 0;
	virtual T Peek() = 0;
	virtual int GetSize() = 0;
};