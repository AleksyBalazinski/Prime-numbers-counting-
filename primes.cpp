#include "pch.h"
#include <iostream>
#include <vector> 
#include <cmath>
#include <chrono> 
using std::cout;
using std::cin;
using namespace std::chrono;

int main()
{
	cout << "This part of the program checks if given number n is prime\n" << "please insert n: ";
	int n;
	cin >> n;
	int divisor = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			divisor++;
		}
	}
	if (divisor <= 2 && divisor != 1)
	{
		cout << n << " is prime\n";
	}
	else
	{
		cout << n << " is not prime!\n";
	}
	cout << "This part of the program prints all primes less than given integer n\n" << "please insert n: ";
	cin >> n;
	divisor = 0;
	std::vector<int> primes;
	auto start1 = high_resolution_clock::now();
	for (int k = 1; k <= n; k++)
	{
		divisor = 0;
		for (int i = 1; i <= k; i++)
		{
			if (k % i == 0)
			{
				divisor++;
			}
			if (divisor >= 3) break;
		}
		if (divisor <= 2 && divisor != 1)
		{
			primes.push_back(k);
		}
	}
	auto stop1 = high_resolution_clock::now();
	cout << "\nFollowing primes were found in range between 1 and " << n << "\n";
	cout << "That is " << primes.size() << " in total\n";
	for (auto elem : primes) cout << elem << "\t";
	cout << "biggest prime is: " << primes[primes.size() - 1] << "\n";
	double estimate1 = n / log(n);
	cout << "\nNumber of primes determined by Gauss's formula x/ln(x) is: " << estimate1 << "\n";
	cout << "That's " << estimate1 / static_cast<double>(primes.size()) * 100 << "% accurate\n";
	auto duration2 = duration_cast<microseconds>(stop1 - start1); //counts in microseconds
	cout << "Now it took " << duration2.count() / 1000000 << "s"; //result in seconds (ms)
}
