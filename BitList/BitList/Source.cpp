#include <stdlib.h>
#include <iostream>
#include "ListNode.h"
#include "BitList.h"
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	auto z = BitList();
	cin >> z;
	//auto q = BitList();
	//cin >> q;
	//cout << z - q << endl;
	--z;
	cout << z << endl;
	cout << ++z << endl;
	cout << ++z << endl;
	cout << ++z << endl;

	system("pause");


	return 0;
}