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
	auto start = high_resolution_clock::now(); //start measuring how long it takes to execute this loop
	for (int k = 1; k <= n; k++)
	{
		divisor = 0;
		for (int i = 1; i <= k; i++)
		{
			if (k % i == 0)
			{
				divisor++;
			}
		}
		if (divisor <= 2 && divisor != 1)
		{
			primes.push_back(k);
		}
	}
	auto stop = high_resolution_clock::now(); //here we stop the experiment
	cout << "\nFollowing primes were found in range between 1 and " << n << "\n";
	cout << "That is " << primes.size() << " in total\n";
	for (auto elem : primes) cout << elem << "\t";
	double estimate = n / log(n);
	cout << "\nNumber of primes determined by Gauss's formula x/ln(x) is: " << estimate << "\n";
	cout << "That's " << estimate / static_cast<double>(primes.size()) * 100 << "% accurate\n";
	auto duration = duration_cast<microseconds>(stop - start); //counts in microseconds
	cout << "It took " << duration.count()/1000 << "ms"; //result in miliseconds (ms)
}

