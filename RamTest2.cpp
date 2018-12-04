#include <iostream>
#include <random>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>

//srand(time(NULL));

using namespace std;
const int GLOBAL_VAR = 40;

 long long gbConverter(int gb, int unit)
{
	/*This function converts input gb sizes to unit*/
	long long bytes = 1024 * 1024 * 1000LL * gb;
	cout << "size: " << gb << " Gb, unit of " << unit <<"bytes:" << bytes<<endl;
	return (bytes / unit);
}

 int* initArray() {
	 static int arr[GLOBAL_VAR];
	 return arr;
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
	 const int size = 600000000; // safe for 1e^8, when array singly used, safe up to 4e^8
	 //static int arr[size]; // static ensures that arr locates on BSS segmentg of the heap
	 int idx = 0;
	 vector<int> varr(size);
	 //varr.reserve(size);
	 //uniform_int_distribution<> d(1, 14620);
 
	 //for (int i = 0; i < size; i++) {// to be changed to large size
		//int m = rand() % 10 + 1;
		////arr[i] = m;
		//varr.push_back(m);
	 //}

	 std::generate(varr.begin(), varr.end(), []() {
		 return rand() % 10;
	 });
	double av = 0;
	double num = 1;
	int a = 1;
	for (int i = 0; i < size; i++) {
		//cout << i<<" "<<arr[i] << endl;
	
		av = (num - 1) / num * av +  varr[i] / num;
		++num;
	}
	//cout << "num:" << num << endl;
	///*cout.precision(4);*/
	cout << "average val:"<<av<<endl;
	
	//double mean = accumulate(varr.cbegin(), varr.cend(), 0.0) / varr.size();
	//cout << mean << endl;
	system("pause");
	return 0;
}