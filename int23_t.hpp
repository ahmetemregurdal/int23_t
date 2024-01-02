#pragma once
#include <bitset>
#include <iostream>
#include <string>
#include <type_traits>
/*!
 * @file int23_t.hpp
 * @brief Main header file for int23_t library
 *
 * Contiains Functions required to make uint23_t work
 */
namespace int23_t {
    /*! @brief An adder which adds carry and 2 bits together and calculates
     * new carry and sum
     * @param[in] b1 Bit 1, left side of addition
     * @param[in] b2 Bit 2, right side of addition
     * @param[in] carry Carry of the addition, passes the reference and updates
     * it with the new carry
     */
	char fullAdder(char const&b1, char const&b2, char&carry);
    /*! @brief A substractor function, similar to the adder function. Substracts
     * left side from right side
     * @param[in] b1 Bit 1, left side of substraction
     * @param[in] b2 Bit 2, right side of substraction
     * @param[in] borrow Borrow of the addition, passes the reference and updates
     * it with new borrow
     */ 
	char fullSub(char const&b1, char const&b2, char&borrow);
    /*! @brief Unsigned 23 bit integer */
	class uint23_t {
	private:
		std::bitset<23> num; /*!< The main variable of the class, contains bits of an uint23_t */
	public:
        /*! @brief An operator to find if left side is smaller or equal to right side
         * @param[in] rhs Right hand side integer
         *
         * If two bitsets are same, function returns true. Else it finds the first
         * location where bits differ, and returns false if left side integers that bit
         * is 1, returns true otherwise
         */
		bool operator<=(uint23_t const&rhs) const;
        /*! @brief An operator to find if left side is smaller than right side
         * @param[in] rhs Right hand side integer
         *
         * If two bitsets are same, function returns false. Else it finds the first
         * location where bits differ, and returns false if left side integers that bit
         * is 1, returns false true
         */
		bool operator<(uint23_t const&rhs) const;
        /*! @brief An operator to find if left side is greater or equal to right side
         * @param[in] rhs Right hand side integer
         *
         * If two bitsets are same, function returns true. Else it finds the first
         * location where bits differ, and returns true if left side integers that bit
         * is 1, returns false otherwise
         */
		bool operator>=(uint23_t const&rhs) const;
        /*! @brief An operator to find if left side is greater than right side
         * @param[in] rhs Right hand side integer
         *
         * If two bitsets are same, function returns false. Else it finds the first
         * location where bits differ, and returns true if left side integers that bit
         * is 1, returns false otherwise
         */
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
	const uint23_t UINT23_MAX(8388607); /*!< The maximum value of integers of class uint23_t */
	const uint23_t UINT23_MIN(0); /*!< The minimum value of integers of class uint23_t, 0 because it is unsigned */
	std::ostream& operator<< (std::ostream&out, uint23_t const&num);
	std::istream& operator>> (std::istream&in, uint23_t&num);
}
