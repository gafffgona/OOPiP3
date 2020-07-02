#include <iostream>
#include "clist.h"

int main()
{
	clist list1, list2;
	list1 += 'A';
	list1 = list1 + 'D';

	list2 += 'A';
	list2 = list2 + 'C';
	list2 = list2 + 'D';

	list1.print();
	list2.print();
	std::cout << "\n Delete elements. \n" << std::endl;

	--list1;
	--list2;
	--list2;

	list1.print();
	list2.print();

	if (list1 == list2)
		std::cout << "Lists equal" << std::endl;
	else
		std::cout << "Lists not equal" << std::endl;

	return 0;
}
