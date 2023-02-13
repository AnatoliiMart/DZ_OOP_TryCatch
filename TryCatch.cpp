#include<iostream>
using namespace std;

void TryFoo()
{
	int digit = 0;
	cout << "Enter 6-num digit: ";
	cin >> digit; 
	if (digit < 100000)
	{
		throw "The number contains 5 or less digits";
	}
	else if (digit > 999999)
	{
		throw exception("The number contains 7 or more digits");
	}
	int tmp  = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (size_t i = 0; i < 6; i++)
	{
		tmp = digit % 10;
		digit /= 10;
		(i >= 3) ? sum2 += tmp : sum1 += tmp;
	}
	cout << "1) - " << sum1 << endl;
	cout << "2) - " << sum2 << endl;
	string res;
	(sum1 == sum2) ? res = "Your number is lucky)" : res = "Your number is not lucky(";
	cout << res << endl;
}

int main()
{
	try
	{
		TryFoo();
	}
	catch (const std::exception& ex)
	{
		cout << "Class Exception warning!" << endl;
		cout << ex.what() << endl;
	}
	catch (const char* ex)
	{
		cout << "Const char* warning!" << endl;
		cout << ex << endl;
	}
}