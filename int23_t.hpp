#pragma once
#include <bitset>
#include <iostream>
#include <string>
namespace int23_t {
	char fullAdder(char const&b1, char const&b2, char&carry);
	char fullSub(char const&b1, char const&b2, char&borrow);
	class uint23_t {
	private:
		std::bitset<23> num;
	public:
		bool operator<=(uint23_t const&rhs) const;
		bool operator<(uint23_t const&rhs) const;
		bool operator>=(uint23_t const&rhs) const;
		bool operator>(uint23_t const&rhs) const;
		uint23_t operator+(uint23_t const&rhs) const;
		uint23_t operator-(uint23_t const&rhs) const;
		uint23_t operator*(uint23_t const&rhs) const;
		uint23_t(int const&a);
		uint23_t();
		uint23_t operator<<(int const&rhs) const;
		uint23_t operator>>(int const&rhs) const;
		uint23_t& operator+=(uint23_t const&rhs);
		uint23_t& operator-=(uint23_t const&rhs);
		uint23_t& operator*=(uint23_t const&rhs);
		uint23_t& operator/=(uint23_t const&rhs);
		uint23_t& operator%=(uint23_t const&rhs);
		bool operator==(uint23_t const&rhs) const;
		uint23_t operator/(uint23_t const&rhs) const;
		uint23_t operator%(uint23_t const&rhs) const;
		uint23_t& operator>>=(int const&rhs);
		uint23_t& operator<<=(int const&rhs);
		operator int() const;
		operator std::string() const;
		operator bool() const;
	};
	std::ostream& operator<< (std::ostream&out, uint23_t const&num);
	std::istream& operator>> (std::istream&in, uint23_t&num);
}
