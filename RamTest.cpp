#include <iostream>
#include <random>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
//srand(time(NULL));
using namespace std;


 long long gbConverter(int gb, int unit)
{
	/*This function converts input gb sizes to unit*/
	long long bytes = 1024 * 1024 * 1000LL * gb;
	cout << "(FN)size: " << gb << " Gb, unit of " << unit <<"bytes:" << bytes<<endl;
	return (bytes / unit);
}

int main()
{
	long long v = gbConverter(4, 4);
	//for (int i = 0; i < 8; i++) {
	//	v = i * 1024 * 1024 * 1000LL;
	//	cout << "size:" << i <<"Gb, unit of bytes:"<< v << endl;
	//	cout << gbConverter(i, 4) << endl;
	//} 
	
	//int* p = new int[v];
	//int arr[1000000000];
	const int size = 400000000;
	static int arr[size]; // static ensures that arr locates on BSS segmentg of the heap
	int idx = 0;
	//vector<int> varr;
	uniform_int_distribution<> d(1, 14620);
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 10) + 1;
		//try {
		//	}
		//catch (...) {
		//	cout << "value of i: " << i << endl;
		//}
		//varr.push_back(arr[i]);
		//cout << arr[i] << endl;

	}
	double av = 0;
	double num = 1;
	for (int i = 0; i < size; i++) {
		//cout << i<<" "<<arr[i] << endl;
		av = (num - 1) / num * av + arr[i] / num;
		++num;
	}
	cout << av<<endl;
	//double mean = accumulate(varr.cbegin(), varr.cend(), 0.0) / varr.size();
	//cout << mean << endl;
	system("pause");
	return 0;
}