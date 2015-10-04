// Daily 215 Easy CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


unsigned long my_pow(unsigned long a, unsigned p) {
	unsigned long tmp = a;
	for (unsigned i = 0; i != p - a; ++i) {
		a *= tmp;
	}
	return a;
}

unsigned long sum_digit_powers(unsigned long n, unsigned p) {
	unsigned long s = 0;
	while (n > 0) {
		s += my_pow(n % 10, p);
		n /= 10;
	}
	return s;
}

std::vector<unsigned long> find_cycle(unsigned long n, unsigned p) {
	std::unordered_set<unsigned long> map;
	std::vector<unsigned long> v;
	unsigned long tmp = n;

	// Loop until we find a number that we have seen before.
	while (map.find(tmp) == map.end()) {
		map.insert(tmp);
		tmp = sum_digit_powers(tmp, p);
	}

	// Build up the list of numbers in the cycle.
	unsigned long start = tmp;
	do {
		v.push_back(tmp);
		tmp = sum_digit_powers(tmp,p);
	} while (tmp != start)
		return v;
}

int main()
{
    return 0;
}

