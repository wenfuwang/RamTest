#include <iostream>
#include <random>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>

#include <chrono>
using namespace std;

/*
The following struct code is snippet from username 'Martin York' on stack Exchange
Source: https://codereview.stackexchange.com/questions/48872/measuring-execution-time-in-c
*/
template<typename TimeT = std::chrono::milliseconds>
struct measure
{
	template<typename F, typename ...Args>
	static typename TimeT::rep execution(F func, Args&&... args)
	{
		auto start = std::chrono::system_clock::now();

		// Now call the function with all the parameters you need.
		func(std::forward<Args>(args)...);

		auto duration = std::chrono::duration_cast<TimeT>(std::chrono::system_clock::now() - start);

		return duration.count();
	}
};


long long gbConverter(int gb, int unit)
{
	/*This function converts input gb sizes to unit*/
	long long bytes = 1024 * 1024 * 1000LL * gb;
	cout << "size: " << gb << " Gb, unit of " << unit << "bytes:" << bytes << endl;
	return (bytes / unit);
}
void foo()
{
	//cout << "Hello World!" << endl;
	return;
}
//int* initArray() {
   // static int arr[GLOBAL_VAR];
   // return arr;
//}
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
	std::generate(varr.begin(), varr.end(), []() {
		return rand() % 10;
	});
	//varr.reserve(size);
	//uniform_int_distribution<> d(1, 14620);

	//for (int i = 0; i < size; i++) {// to be changed to large size
	   //int m = rand() % 10 + 1;
	   ////arr[i] = m;
	   //varr.push_back(m);
	//}


	//cout << measure<std::chrono::nanoseconds>::execution([]() {
	   // return rand() % 10;
	//}) << endl;

	//cout << measure <std::chrono::microseconds>::execution(foo) << endl; // just name, not foo()

	double av = 0;
	double num = 1;

	cout << measure <std::chrono::milliseconds>::execution([&]() {

		for (int i = 0; i < size; i++) {
			av = (num - 1) / num * av + varr[i] / num;
			++num;
		}
	}) << endl;



	cout << "average val:" << av << endl;

	//double mean = accumulate(varr.cbegin(), varr.cend(), 0.0) / varr.size();
	//cout << mean << endl;
	system("pause");
	return 0;
}