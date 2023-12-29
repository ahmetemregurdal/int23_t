#pragma once
#include <bitset>
#include <iostream>
#include <string>
#include <type_traits>
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
		template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
		uint23_t(T const&a);
		template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
		operator T() const;
		uint23_t();
		uint23_t operator<<(int const&rhs) const;
		uint23_t operator>>(int const&rhs) const;
		uint23_t& operator+=(uint23_t const&rhs);
		uint23_t& operator-=(uint23_t const&rhs);
		uint23_t& operator*=(uint23_t const&rhs);
		uint23_t& operator/=(uint23_t const&rhs);
		uint23_t& operator%=(uint23_t const&rhs);
		uint23_t& operator++();
		uint23_t& operator--();
		uint23_t operator++(int);
		uint23_t operator--(int);
		bool operator==(uint23_t const&rhs) const;
		uint23_t operator/(uint23_t const&rhs) const;
		uint23_t operator%(uint23_t const&rhs) const;
		uint23_t& operator>>=(int const&rhs);
		uint23_t& operator<<=(int const&rhs);
		uint23_t operator&(uint23_t const&rhs) const;
		uint23_t operator|(uint23_t const&rhs) const;
		uint23_t operator^(uint23_t const&rhs) const;
		uint23_t& operator&=(uint23_t const&rhs);
		uint23_t& operator|=(uint23_t const&rhs);
		uint23_t& operator^=(uint23_t const&rhs);
		operator std::string() const;
	};
	std::ostream& operator<< (std::ostream&out, uint23_t const&num);
	std::istream& operator>> (std::istream&in, uint23_t&num);
}
