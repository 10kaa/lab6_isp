#include <iostream>
#include "Stack2.h"
using namespace std;

int main()
{
	int data = 0;
	cout << "Stack length: ---" << endl;
	StackOnUnidirCyclicList<int> s;
	do
	{
		cout << "Add element? (0-no, 1-yes) ";
		cin >> data;
		if (data)
		{
			cout << "Element " << s.GetSize() + 1 << " from ---: ";
			cin >> data;
			s.Push(data);
		}
	} while (data);
	cout << endl << endl << "Stack: " << s << endl;

	do
	{
		cout << "Pop, peek, end? (0-end, 1-pop, 2-peek) ";
		cin >> data;
		if (data == 1)
			cout << "Element: " << s.Pop() << endl;
		else if (data == 2)
			cout << "Element: " << s.Peek() << endl;
	} while (data);
	return 0;
}