#include "../include/shared.hpp"

char int23_t::fullAdder(char const&b1, char const&b2, char&carry) {
	const char ans = b1^b2^carry;
	carry = (b1&b2)|(b1&carry)|(b2&carry);
	return ans;
}
char int23_t::fullSub(char const&b1, char const&b2, char&borrow) {
	char diff;
	if(borrow) {
		diff = 1 ^ b1 ^ b2;
		borrow = (1^b1)|(b1&b2);
	}
	else {
		diff = b1^b2;
		borrow = (1^b1)&b2;
	}
	return diff;
}
