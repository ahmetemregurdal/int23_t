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
		std::bitset<23> num; /*!< The main variable of the class, contains bits of an uint23_t, see also https://en.cppreference.com/w/cpp/utility/bitset */
	public:
        /*! @brief An operator to find if left uint23_t is smaller or equal to right uint23_t
         * @param[in] rhs Right hand side uint23_t
         *
         * If two bitsets are same, function returns true. Else it finds the first
         * location where bits differ, and returns false if left side integers that bit
         * is 1, returns true otherwise
         */
		bool operator<=(uint23_t const&rhs) const;
        /*! @brief An operator to find if left uint23_t is smaller than right uint23_t
         * @param[in] rhs Right hand side uint23_t
         *
         * If two bitsets are same, function returns false. Else it finds the first
         * location where bits differ, and returns false if left side integers that bit
         * is 1, returns false true
         */
		bool operator<(uint23_t const&rhs) const;
        /*! @brief An operator to find if left uint23_t is greater or equal to right uint23_t
         * @param[in] rhs Right hand side uint23_t
         *
         * If two bitsets are same, function returns true. Else it finds the first
         * location where bits differ, and returns true if left side integers that bit
         * is 1, returns false otherwise
         */
		bool operator>=(uint23_t const&rhs) const;
        /*! @brief An operator to find if left uint23_t is greater than right uint23_t
         * @param[in] rhs Right hand side uint23_t
         *
         * If two bitsets are same, function returns false. Else it finds the first
         * location where bits differ, and returns true if left side integers that bit
         * is 1, returns false otherwise
         */
		bool operator>(uint23_t const&rhs) const;
		/*! @brief An operator to add two uint23_t's together
		 * @param[in] rhs Right hand side uint23_t
		 * 
		 * Uses fullAdder() function to calculate sum of two uint23_t's
		 */
		uint23_t operator+(uint23_t const&rhs) const;
		/*! @brief An operator to substract an uint23_t from another
		 * @param[in] rhs Right hand side uint23_t
		 *
		 * Uses fullSub() function to calculate difference of two uint23_t's
		 */
		uint23_t operator-(uint23_t const&rhs) const;
		/*! @brief An operator to multiply an uint23_t with another
		 * @param[in] rhs Right hand side uint23_t
		 * @sa int23_t.cpp
		 */
		uint23_t operator*(uint23_t const&rhs) const;
		/*! @brief A constructor to create uint23_t from classes that can easily be represented as binary
		 * @param[in] a the value of uint23_t that is being constructed.
		 * Has to be an arithmetic type like int or char, see also
		 * https://en.cppreference.com/w/c/language/arithmetic_types
		 *
		 * Constructs uint23_t using std::bitset's constructor, see also
		 * https://en.cppreference.com/w/cpp/utility/bitset/bitset
		 */
		template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
		uint23_t(T const&a);
		/*! @brief An operator for converting uint23_t to arithmetic types. see also
		 * https://en.cppreference.com/w/c/language/arithmetic_types
		 * 
		 * Uses std::bitset::to_ulong function. See also https://en.cppreference.com/w/cpp/utility/bitset/to_ulong
		 */
		template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
		operator T() const;
		/*! @brief Default constructor for uint23_t, sets the value to 0.
		 * 
		 * Does the same thing as ::uint23_t(T const& 0)
		 */
		uint23_t();
		/*! @brief Left bitshift operator, same thing as multiplying by 2 n times.
		 * @param[in] rhs The number of times uint23_t's bits are shifted.
		 *
		 * Uses std::bitset::operator<< internally, see also https://en.cppreference.com/w/cpp/utility/bitset/operator_ltltgtgt
		 */
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
