#pragma once

using namespace std;

template<typename T>
struct UCLNode
{
	T data;
	UCLNode* ptrnext{ nullptr };
	UCLNode* ptrprev{ nullptr };
};

template<typename T>
class UnidirCyclicList
{
private:
	UCLNode<T>* first{ nullptr };
	UCLNode<T>* last{ nullptr };

public:
	UnidirCyclicList()
	{
		first = nullptr;
		last = nullptr;
	}
	~UnidirCyclicList()
	{
		while (first != last)
		{
			UCLNode<T>* tmp = first;
			first = first->ptrprev;
			delete tmp;
		}
		delete last;
	}
	void AddBack(T dt)
	{
		UCLNode<T>* newlink = new UCLNode<T>;
		newlink->data = dt;

		if (first)
		{
			newlink->ptrprev = first;
			first->ptrnext = newlink;
		}
		else last = newlink;

		newlink->ptrnext = last;
		last->ptrprev = newlink;
		first = newlink;
	}
	void AddFront(T dt)
	{
		UCLNode<T>* newlink = new UCLNode<T>;
		newlink->data = dt;
		if (last)
		{
			newlink->ptrnext = last;
			last->ptrprev = newlink;
		}
		else first = newlink;

		newlink->ptrprev = first;
		first->ptrnext = newlink;
		last = newlink;
	}
	T RemoveFront()
	{
		T data = first->data;
		DeleteLink(first);
		return data;
	}
	T RemoveBack()
	{
		T data = last->data;
		DeleteLink(last);
		return data;
	}
	T ElementAt(int index)
	{
		if (index > Length()) return -1;
		UCLNode<T>* temp = first;
		int i = 0;
		do
		{
			if (i == index) return temp->data;
			temp = temp->ptrprev;
			i++;
		} while (temp != first);
		return -1;
	}
	void DeleteLink(UCLNode<T>* temp)
	{
		if (first)
		{
			if (temp->ptrnext == temp)
			{
				first = nullptr;
				last = nullptr;
			}
			else
			{
				if (temp == last) last = last->ptrnext;
				if (temp == first) first = first->ptrprev;
				(temp->ptrnext)->ptrprev = temp->ptrprev;
				(temp->ptrprev)->ptrnext = temp->ptrnext;
				delete temp;
			}
		}
	}
	UnidirCyclicList operator=(UnidirCyclicList& l)
	{
		if (l.first)
		{
			UCLNode<T>* temp = l.first;
			do
			{
				AddFront(temp->data);
				temp = temp->ptrprev;
			} while (temp != l.first);
		}
		return *this;
	}
	int Length()
	{
		if (first)
		{
			UCLNode<T>* temp = first;
			int i = 0;
			do
			{
				temp = temp->ptrprev;
				i++;
			} while (temp != first);
			return i;
		}
		else return 0;
	}
	void Clear()
	{
		while (first->ptrprev != last)
		{
			UCLNode<T>* temp = first->ptrprev;
			first = first->ptrprev;
			delete temp;
		}
		last = nullptr;
		first = nullptr;
	}
};