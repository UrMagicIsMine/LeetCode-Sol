/*
* At the heart of bit manipulation are the bit-wise operators & (and), | (or),
* ~ (not) and ^ (exclusive-or, xor) and shift operators a << b and a >> b.

-- Set union: A | B
-- Set intersection: A & B
-- Set subtraction: A & ~B
-- Set negation: ^A or ~A
-- Set bit: A |= 1 << bit
-- Clear bit: A &= ~(1 << bit)
-- Test bit: (A & 1 << bit) != 0
-- Extract last bit: A&-A or A&~(A-1)
-- Remove last bit: A&(A-1)
-- Get all 1-bits: ~0
*/

/*******************************************************************************
*    Tricks of N & (N-1)
*******************************************************************************/

/*1)	Count the number of ones in the binary representation of the given number
*/
int count_one(int n) {
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}

/* 2)	Is power of two or four (actually map-checking, iterative and recursive
* methods can do the same)
*/

bool isPowerOfTwo(int n) {
    return !(n & (n-1)) && (n >0);
}

bool isPowerOfFour(int n) {
    return !(n&(n-1)) && (n&0x55555555);
    //check the 1-bit location;
}

/*******************************************************************************
*    Tricks of ^
* Use ^ to remove the numbers that appeared in even time
*******************************************************************************/

/* Given an array containing n distinct numbers taken from 0, 1, 2, …, n, find
* the one that is missing from the array. For example, Given nums = [0, 1, 3]
* return 2. (Of course, you can do this by math.)
*/

int missingNumber(vector<int>& nums) {
    int ret = 0;
    for(int i = 0; i < nums.size(); ++i) {
        ret ^= i;
        ret ^= nums[i];
    }
    return ret^=nums.size();
}

/*******************************************************************************
*    Tricks of |
* Keep as many 1-bits as possible
*******************************************************************************/

/* Given an array containing n distinct numbers taken from 0, 1, 2, …, n, find
* the one that is missing from the array. For example, Given nums = [0, 1, 3]
* return 2. (Of course, you can do this by math.)
*/

long largest_power(long N) {
    //changing all right side bits to 1.
    N = N | (N>>1);
    N = N | (N>>2);
    N = N | (N>>4);
    N = N | (N>>8);
    N = N | (N>>16);
    return (N+1)>>1;
}

/* Reverse Bits
* Reverse bits of a given 32 bits unsigned integer.
*/

uint32_t reverseBits_Sln3(uint32_t n) {

		uint32_t mask = 1 << 31, ret = 0;
		while(n){
				if(n&1)
						ret |= mask;
				n >>= 1;
				mask >>= 1;
		}
		return ret;
}

/*******************************************************************************
*    Tricks of &
* Just selecting certain bits
*******************************************************************************/
/*
* Bitwise AND of Numbers Range
* Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of
* all numbers in this range, inclusive. For example, given the range [5, 7], you
* should return 4.
*/

int rangeBitwiseAnd(int m, int n) {
    int cnt = 0;
    while(m!= n){
        m >>= 1;
        n >>= 1;
        cnt++;
    }
    return m << cnt;
}

/*
* Write a function that takes an unsigned integer and returns the number of ’1’
* bits it has (also known as the Hamming weight).
*/

int hammingWeight(uint32_t n) {
	int count = 0;
	while(n) {
		n = n&(n-1);
		count++;
	}
	return count;
}
