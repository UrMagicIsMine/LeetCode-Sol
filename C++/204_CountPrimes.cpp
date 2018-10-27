/*Description:

Count the number of prime numbers less than a non-negative number, n.
*/

#include <vector>
#include <stack>
#include <cassert>
using namespace std;

bool isPrimes(int num) {

	if (num == 2 || num == 3)
		return true;

	int sqr = sqrt(num);
	for (int i = 2; i <= sqr; i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}

/* Brute force algorithm, O(N^2) */

int countPrimes_Sln1(int n) {

	int cnt = 0;

	for (int i = 2; i < n; i++) {
		if (isPrimes(i))
			cnt++;
	}
	return cnt;
}

/* Sieve of Eratosthenes algorithm, O(NloglogN) */

int countPrimes_Sln2(int n) {

	vector<bool> prime(n, true);
	prime[0] = false;
	prime[1] = false;
	double sqr = sqrt(n);
	for (int i = 2; i < sqr; i++) {
		if (prime[i]) {
			for (int j = i * i; j < n; j = j + i)
				prime[j] = false;
		}
	}
	return count(prime.begin(), prime.end(), true);
}

int main()
{
	int num = 499979;
	int ans = 41537;
	int ret1 = countPrimes_Sln1(num);
	assert(ret1 == ans);
	int ret2 = countPrimes_Sln1(num);
	assert(ret2 == ans);
	return 0;
}
