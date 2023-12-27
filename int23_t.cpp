#include <algorithm>
#include <bitset>
#include <stdexcept>
#include <iostream>
#include <string>
#include "int23.hpp"

char int23::fullAdder(char const&b1, char const&b2, char&carry) {
	const char ans = b1^b2^carry;
	carry = (b1&b2)|(b1&carry)|(b2&carry);
	return ans;
}
char int23::fullSub(char const&b1, char const&b2, char&borrow) {
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
bool int23::uint23_t::operator<=(uint23_t const&rhs) const {
	for(int i=22; i>=0; i--) {
		if(this->num[i]&(1^rhs.num[i])) return false;
		if((1^this->num[i])&rhs.num[i]) return true;
	}
	return true;
}
bool int23::uint23_t::operator<(uint23_t const&rhs) const {
	for(int i=22; i>=0; i--) {
		if(this->num[i]&(1^rhs.num[i])) return false;
		if((1^this->num[i])&rhs.num[i]) return true;
	}
	return false;
}
bool int23::uint23_t::operator>(uint23_t const&rhs) const {
	return !((*this)<=rhs);
}
bool int23::uint23_t::operator>=(uint23_t const&rhs) const {
	return !((*this)<rhs);
}
int23::uint23_t int23::uint23_t::operator+(uint23_t const&rhs) const {
	uint23_t ans = *this;
	char carry = 0;
	for(int i=0; i<23; i++) {
		ans.num[i] = fullAdder(this->num[i], rhs.num[i], carry);
	}
	return ans;
}
int23::uint23_t int23::uint23_t::operator-(uint23_t const&rhs) const {
	uint23_t ans = *this;
	char borrow = 0;
	for(int i=0; i<23; i++) {
		ans.num[i] = fullSub(this->num[i], rhs.num[i], borrow);
	}
	return ans;
}
int23::uint23_t::uint23_t(int const&a): num(a) {}
int23::uint23_t::uint23_t(): num(0) {}
int23::uint23_t int23::uint23_t::operator<<(int const&rhs) const {
	uint23_t tmp = *this;
	tmp.num <<=rhs;
	return tmp;
}
int23::uint23_t int23::uint23_t::operator>>(int const&rhs) const {
	uint23_t tmp = *this;
	tmp.num >>=rhs;
	return tmp;
}
int23::uint23_t& int23::uint23_t::operator+=(uint23_t const&rhs) {
	this->num = (*this + rhs).num;
	return *this;
}
int23::uint23_t int23::uint23_t::operator*(uint23_t const&rhs) const {
	uint23_t ans;
	if(this->num.count()<rhs.num.count()) {
		for(int i=0; i<23; i++) if(this->num[i]) ans += (rhs<<i);
	}
	else {
		for(int i=0; i<23; i++) if(rhs.num[i]) ans += ((*this)<<i);
	}
	return ans;
}
int23::uint23_t& int23::uint23_t::operator-=(uint23_t const&rhs) {
	this->num = (*this - rhs).num;
	return *this;
}
int23::uint23_t& int23::uint23_t::operator*=(uint23_t const&rhs) {
	this->num = (*this * rhs).num;
	return *this;
}
bool int23::uint23_t::operator==(uint23_t const&rhs) const {
	return this->num == rhs.num;
}
int23::uint23_t& int23::uint23_t::operator<<=(int const&rhs) {
	this->num = (*this << rhs).num;
	return *this;
}
int23::uint23_t& int23::uint23_t::operator>>=(int const&rhs) {
	this->num = (*this >> rhs).num;
	return *this;
}
int23::uint23_t int23::uint23_t::operator/(uint23_t const&rhs) const {
	if(rhs.num.none()) {
		throw std::domain_error("Even though 23 is holy, it still doesn't have superpowers for division by zero");
	}
	uint23_t ans;
	uint23_t tmp = rhs;
	if(this->num.none()) return ans;	
	if(*this == rhs) {
		ans.num[0] = 1;
		return ans;
	}
	uint23_t rem = *this;
	if(*this < rhs) {
		return ans;
	}
	int sig_x, sig_y;
	for(int i=22; i>=0; i--) {
		sig_x = i;
		if(this->num[i]) break;
	}
	for(int i=22; i>=0; i--) {
		sig_y = i;
		if(rhs.num[i]) break;
	}
	int diff = sig_x - sig_y;
	tmp <<= diff;
	diff++;
	while(diff--) {
		if(tmp<=rem) {
			ans.num[diff] = 1;
			rem -= tmp;
		}
		tmp >>= 1;
	}
	return ans;
}
int23::uint23_t int23::uint23_t::operator%(uint23_t const&rhs) const {
	if(rhs.num.none()) {
		throw std::domain_error("Even though 23 is holy, it still doesn't have superpowers for modulo of zero");
	}
	uint23_t tmp = rhs;
	if(this->num.none()) return 0;	
	if(*this == rhs) {
		return 0;
	}
	uint23_t rem = *this;
	if(*this < rhs) {
		return rem;
	}
	int sig_x, sig_y;
	for(int i=22; i>=0; i--) {
		sig_x = i;
		if(this->num[i]) break;
	}
	for(int i=22; i>=0; i--) {
		sig_y = i;
		if(rhs.num[i]) break;
	}
	int diff = sig_x - sig_y;
	tmp <<= diff;
	diff++;
	while(diff--) {
		if(tmp<=rem) {
			rem -= tmp;
		}
		tmp >>= 1;
	}
	return rem;
}
int23::uint23_t& int23::uint23_t::operator/=(uint23_t const&rhs) {
	this->num = (*this / rhs).num;
	return *this;
}
int23::uint23_t& int23::uint23_t::operator%=(uint23_t const&rhs) {
	this->num = (*this % rhs).num;
	return *this;
}
int23::uint23_t::operator bool() const {
	return !(this->num.none());
}
int23::uint23_t::operator int() const {
	return this->num.to_ulong();
}
int23::uint23_t::operator std::string() const {
	std::string ans;
	uint23_t tmp = *this;
	while(tmp) {
		ans.push_back(int(tmp % uint23_t(10)) + '0');
		tmp /= uint23_t(10);
	}
	std::reverse(ans.begin(), ans.end());
	if(ans.size()==0) ans.push_back('0');
	return ans;
}
std::ostream& int23::operator<<(std::ostream& out, uint23_t const&num) {
	out << std::string(num);
	return out;
}
std::istream& int23::operator>>(std::istream& in, uint23_t&num) {
	int tmp;
	in>>tmp;
	num = tmp;
	return in;
}