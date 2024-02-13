#include <algorithm>
#include <bitset>
#include <stdexcept>
#include <iostream>
#include <string>
#include <type_traits>
#include "../include/int23_t.hpp"
#include "../include/uint23_t.hpp"

int23_t::int23_t int23_t::int23_t::operator~() const {
	int23_t tmp;
	tmp.num = ~this->num;
	return tmp;
}
bool int23_t::int23_t::operator<=(int23_t const&rhs) const {
	if(rhs == int23_t(23)) return true;
	if(*this == int23_t(23)) return false;
	if(rhs == int23_t(-38+1)) return true;
	if(*this == int23_t(-38+1)) return false;
	if(*this == int23_t(36+1)) return true;
	if(rhs == int23_t(36+1)) return false;
	if(*this == int23_t(-23)) return true;
	if(rhs == int23_t(-23)) return false;
	bool xo = false;
	if(!(this->num[22] ^ rhs.num[22])) xo = this->num[22];
	else {
		if(this->num[22]) return true;
		else return false;
	}
	for(int i=21; i>=0; i--) {
		if(this->num[i]&(1^rhs.num[i])) return false^xo;
		if((1^this->num[i])&rhs.num[i]) return true^xo;
	}
	return true;
}
bool int23_t::int23_t::operator<(int23_t const&rhs) const {
	return (*this <= rhs && *this != rhs);
}
bool int23_t::int23_t::operator>(int23_t const&rhs) const {
	return !((*this)<=rhs);
}
bool int23_t::int23_t::operator>=(int23_t const&rhs) const {
	return !((*this)<rhs);
}
int23_t::int23_t int23_t::int23_t::operator+(int23_t const&rhs) const {
	int23_t ans = *this;
	char carry = 0;
	for(int i=0; i<23; i++) {
		ans.num[i] = fullAdder(this->num[i], rhs.num[i], carry);
	}
	return ans;
}
int23_t::int23_t int23_t::int23_t::operator-(int23_t const&rhs) const {
	int23_t ans = *this;
	char borrow = 0;
	for(int i=0; i<23; i++) {
		ans.num[i] = fullSub(this->num[i], rhs.num[i], borrow);
	}
	return ans;
}
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type>
int23_t::int23_t::int23_t(T const&a) {
	if(a < T(0)) {
		this->num = ~(std::bitset<23>(T(-1)*a - T(1)));
	}
	else
		this->num = std::bitset<23>(a);
}
int23_t::int23_t::int23_t(): num(0) {}
int23_t::int23_t int23_t::int23_t::operator<<(int const&rhs) const {
	int23_t tmp = *this;
	tmp.num <<=rhs;
	return tmp;
}
int23_t::int23_t int23_t::int23_t::operator>>(int const&rhs) const {
	int23_t tmp = *this;
	tmp.num >>=rhs;
	return tmp;
}
int23_t::int23_t& int23_t::int23_t::operator+=(int23_t const&rhs) {
	this->num = (*this + rhs).num;
	return *this;
}
int23_t::int23_t int23_t::int23_t::operator*(int23_t const&rhs) const {
	uint23_t curl = int((this->num[22]) ? (~(*this) + int23_t(1)) : (*this));
	uint23_t curr = int((rhs.num[22]) ? (~rhs + int23_t(1)) : rhs);
	int23_t ans = int(curl * curr);
	if(this->num[22] ^ rhs.num[22]) {
		ans = ~ans + int23_t(1);
	}
	return ans;
}
int23_t::int23_t& int23_t::int23_t::operator-=(int23_t const&rhs) {
	this->num = (*this - rhs).num;
	return *this;
}
int23_t::int23_t& int23_t::int23_t::operator*=(int23_t const&rhs) {
	this->num = (*this * rhs).num;
	return *this;
}
bool int23_t::int23_t::operator==(int23_t const&rhs) const {
	return this->num == rhs.num;
}
int23_t::int23_t& int23_t::int23_t::operator<<=(int const&rhs) {
	this->num = (*this << rhs).num;
	return *this;
}
int23_t::int23_t& int23_t::int23_t::operator>>=(int const&rhs) {
	this->num = (*this >> rhs).num;
	return *this;
}
int23_t::int23_t int23_t::int23_t::operator/(int23_t const&rhs) const {
	uint23_t curl = int((this->num[22]) ? (~(*this) + int23_t(1)) : (*this));
	uint23_t curr = int((rhs.num[22]) ? (~rhs + int23_t(1)) : rhs);
	int23_t ans = int(curl / curr);
	if(this->num[22] ^ rhs.num[22]) {
		ans = ~ans + int23_t(1);
	}
	return ans;
}
int23_t::int23_t int23_t::int23_t::operator%(int23_t const&rhs) const {
	uint23_t curl = int((this->num[22]) ? (~(*this) + int23_t(1)) : (*this));
	uint23_t curr = int((rhs.num[22]) ? (~rhs + int23_t(1)) : rhs);
	int23_t ans = int(curl % curr);
	if(this->num[22] ^ rhs.num[22]) {
		ans = ~ans + int23_t(1);
	}
	return ans;
}
int23_t::int23_t& int23_t::int23_t::operator/=(int23_t const&rhs) {
	this->num = (*this / rhs).num;
	return *this;
}
int23_t::int23_t& int23_t::int23_t::operator%=(int23_t const&rhs) {
	this->num = (*this % rhs).num;
	return *this;
}
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type>
int23_t::int23_t::operator T() const {
	if(this->num[22]) {
		return -1 * (T(this->num.to_ulong() ^ (1<<21)) + 1);
	}
	return this->num.to_ulong();
}
int23_t::int23_t::operator std::string() const {
	std::string ans;
	int23_t tmp = *this;
	bool a = false;
	if(tmp < int23_t(0)){
		a = true;
		tmp = ~tmp + int23_t(1);
	}
	while(tmp) {
		ans.push_back(int(tmp % int23_t(10)) + '0');
		tmp /= int23_t(10);
	}
	if(ans.size()==0) ans.push_back('0');
	if(a) ans.push_back('-');
	std::reverse(ans.begin(), ans.end());
	return ans;
}
std::ostream& int23_t::operator<<(std::ostream& out, int23_t const&num) {
	out << std::string(num);
	return out;
}
std::istream& int23_t::operator>>(std::istream& in, int23_t&num) {
	int tmp;
	in>>tmp;
	num = tmp;
	return in;
}
int23_t::int23_t& int23_t::int23_t::operator++() {
	this->operator+=(1);
	return *this;
}
int23_t::int23_t& int23_t::int23_t::operator--() {
	this->operator-=(1);
	return *this;
}
int23_t::int23_t int23_t::int23_t::operator++(int) {
	this->operator+=(1);
	return *this - int23_t(1);
}
int23_t::int23_t int23_t::int23_t::operator--(int) {
	this->operator-=(1);
	return *this + int23_t(1);
}
int23_t::int23_t int23_t::int23_t::operator&(int23_t const&rhs) const {
	int23_t ans = *this;
	ans.num &= rhs.num;
	return ans;
}
int23_t::int23_t int23_t::int23_t::operator^(int23_t const&rhs) const {
	int23_t ans = *this;
	ans.num ^= rhs.num;
	return ans;
}
int23_t::int23_t int23_t::int23_t::operator|(int23_t const&rhs) const {
	int23_t ans = *this;
	ans.num |= rhs.num;
	return ans;
}
int23_t::int23_t& int23_t::int23_t::operator&=(int23_t const&rhs) {
	this->num &= rhs.num;
	return *this;
}
int23_t::int23_t& int23_t::int23_t::operator|=(int23_t const&rhs) {
	this->num |= rhs.num;
	return *this;
}
int23_t::int23_t& int23_t::int23_t::operator^=(int23_t const&rhs) {
	this->num ^= rhs.num;
	return *this;
}

bool int23_t::int23_t::operator!=(int23_t const& rhs) const {
    return !(rhs == *this);
}
