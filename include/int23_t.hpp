#pragma once
#include <bitset>
#include <iostream>
#include <string>
#include <type_traits>
#include "shared.hpp"
/*!
 * @file include/int23_t.hpp
 * @brief Main header file for int23_t class
 *
 * Contiains Functions required to make int23_t work
 */
namespace int23_t {
	/*! @brief 23 bit integer */
	class int23_t {
	public:
		std::bitset<23> num; /*!< The main variable of the class, contains bits of an int23_t, see also https://en.cppreference.com/w/cpp/utility/bitset */
		/*! @brief An operator to find if left int23_t is smaller or equal to right int23_t
		 * @param[in] rhs Right hand side int23_t
		 *
		 * If two bitsets are same, function returns true. Else it finds the first
		 * location where bits differ, and returns false if left side integers that bit
		 * is 1, returns true otherwise
		 */
		bool operator<= (int23_t const& rhs) const;
		/*! @brief An operator to find if left int23_t is smaller than right int23_t
		 * @param[in] rhs Right hand side int23_t
		 *
		 * If two bitsets are same, function returns false. Else it finds the first
		 * location where bits differ, and returns false if left side integers that bit
		 * is 1, returns false true
		 */
		bool operator< (int23_t const& rhs) const;
		/*! @brief An operator to find if left int23_t is greater or equal to right int23_t
		 * @param[in] rhs Right hand side int23_t
		 *
		 * If two bitsets are same, function returns true. Else it finds the first
		 * location where bits differ, and returns true if left side integers that bit
		 * is 1, returns false otherwise
		 */
		bool operator>= (int23_t const& rhs) const;
		/*! @brief An operator to find if left int23_t is greater than right int23_t
		 * @param[in] rhs Right hand side int23_t
		 *
		 * If two bitsets are same, function returns false. Else it finds the first
		 * location where bits differ, and returns true if left side integers that bit
		 * is 1, returns false otherwise
		 */
		bool operator> (int23_t const& rhs) const;
		/*! @brief An operator to add two int23_t's together
		 * @param[in] rhs Right hand side int23_t
		 * 
		 * Uses fullAdder() function to calculate sum of two int23_t's
		 */
		int23_t operator+ (int23_t const& rhs) const;
		/*! @brief An operator to substract an int23_t from another
		 * @param[in] rhs Right hand side int23_t
		 *
		 * Uses fullSub() function to calculate difference of two int23_t's
		 */
		int23_t operator- (int23_t const& rhs) const;
		/*! @brief An operator to multiply an int23_t with another
		 * @param[in] rhs Right hand side int23_t
		 * @sa int23_t.cpp
		 */
		int23_t operator* (int23_t const& rhs) const;
		/*! @brief A constructor to create int23_t from classes that can easily be represented as binary
		 * @param[in] a the value of int23_t that is being constructed.
		 * Has to be an arithmetic type like int or char, see also
		 * https://en.cppreference.com/w/c/language/arithmetic_types
		 *
		 * Constructs int23_t using std::bitset's constructor, see also
		 * https://en.cppreference.com/w/cpp/utility/bitset/bitset
		 */
		template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
		int23_t (T const& a);
		/*! @brief An operator for converting int23_t to arithmetic types. see also
		 * https://en.cppreference.com/w/c/language/arithmetic_types
		 * 
		 * Uses std::bitset::to_ulong function. See also https://en.cppreference.com/w/cpp/utility/bitset/to_ulong
		 */
		template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
		operator T () const;
		/*! @brief Default constructor for int23_t, sets the value to 0.
		 * 
		 * Does the same thing as ::int23_t(T const& 0)
		 */
		int23_t();
		/*! @brief Left bitshift operator, same thing as multiplying by 2 n times.
		 * @param[in] rhs The number of times int23_t's bits are shifted.
		 *
		 * Uses std::bitset::operator<< internally, see also https://en.cppreference.com/w/cpp/utility/bitset/operator_ltltgtgt
		 */
		int23_t operator<< (int const& rhs) const;
		/*! @brief Right bitshift operator, same thing as dividing by 2 n times.
		 * @param[in] rhs The number of times int23_t's bits are shifted.
		 */
		int23_t operator>> (int const& rhs) const;
		/*! @brief Operator for adding an int23_t's value to the left int23_t
		 * @param[in] rhs The number added to current number
		 *
		 * The value of rhs is added to current number and current number is returned.
		 * See also ::operator+()
		 */
		int23_t& operator+= (int23_t const& rhs);
		/*! @brief Operator for substracting an int23_t's value from the left int23_t
		 * @param[in] rhs The number substracted from the current number
		 *
		 * The value of rhs is substracted from current number and current number is returned.
		 * See also ::operator-()
		 */
		int23_t& operator-= (int23_t const& rhs);
		/*! @brief Operator for multiplying an int23_t with the one in the right
		 * @param[in] rhs the number current number is multiplied by.
		 *
		 * The value of current number is multiplied by rhs and then returned. See also ::operator*()
		 */
		int23_t& operator*= (int23_t const& rhs);
		/*! @brief Operator for dividing an int23_t with the right hand side int23_t
		 * @param[in] rhs The number current number is multiplied by
		 *
		 * The value of current number is divided by rhs and then returned. See also ::operator/()
		 */
		int23_t& operator/= (int23_t const& rhs);
		/*! @brief Operator for modulo-ing the current number in module rhs
		 * @param[in] rhs The modulo that is currently being used.
		 *
		 * The value of current number is equalised to the modulo of that number in modulo rhs. See also ::operator%()
		 */
		int23_t& operator%= (int23_t const& rhs);
		/*! @brief prefix increment operator
		 *
		 * Same as ::operator+=(int23_t const& 1)
		 */
		int23_t& operator++ ();
		/*! @brief prefix decrement operator
		 *
		 * Same as ::operator-=(int23_t const& 1)
		 */
		int23_t& operator-- ();
		/*! @brief postfix increment operator
		 *
		 * The current value is returned and than 1 is added to the current value.
		 * Same as ::operator++() return ::operator-(1)
		 */
		int23_t operator++ (int);
		/*! @brief postfix decrement operator
		 *
		 * The current value is returned and than 1 is substracted from the current value.
		 * Same as ::operator--() return ::operator+(1)
		 */
		int23_t operator-- (int);
		/*! @brief Checks if two int23_t are same
		 * @param[in] rhs Right hand side int23_t
		 * 
		 * Individualy checks every bit and if a single is different returns false, else returns true.
		 */
		bool operator== (int23_t const& rhs) const;
		/*! @brief Operator for dividing an int23_t with another
		 * @param[in] rhs Right hand side int23_t
		 *
		 * Divides two int23_t's and returns the value.
		 */
		int23_t operator/ (int23_t const& rhs) const;
		/*! @brief Operator for modulo-ing an int23_t modulo another int23_t
		 * @param[in] rhs Right hand side int23_t, the modulo
		 *
		 * Returns left int23_t modulo right int23_t
		 */
		int23_t operator% (int23_t const& rhs) const;
		/*! @brief Operator for shifting current int23_t's internal bitset
		 * @param[in] rhs The number of times bits are shifted
		 *
		 * Shifts the current int23_t's bits, see also ::operator>>()
		 */
		int23_t& operator>>= (int const& rhs);
		/*! @brief Operator for shifting current int23_t's internal bitset
		 * @param[in] rhs The number of times bits are shifted
		 *
		 * Shifts the current int23_t's bits, see also ::operator<<()
		 */
		int23_t& operator<<= (int const& rhs);
		/*! @brief Bitwise and operator
		 * @param[in] rhs Right hand side int23_t
		 *
		 * Uses std::bitset member function internally, see also https://en.cppreference.com/w/cpp/utility/bitset/operator_logic2
		 */
		int23_t operator& (int23_t const& rhs) const;
		/*! @brief Bitwise or operator
		 * @param[in] rhs Right hand side int23_t
		 *
		 * Uses std::bitset member function internally, see also https://en.cppreference.com/w/cpp/utility/bitset/operator_logic2
		 */
		int23_t operator| (int23_t const& rhs) const;
		/*! @brief Bitwise xor operator
		 * @param[in] rhs Right hand side int23_t
		 *
		 * Uses std::bitset member function internally, see also https://en.cppreference.com/w/cpp/utility/bitset/operator_logic2
		 */
		int23_t operator^ (int23_t const& rhs) const;
		/*! @brief Bitwise operator for and-ing the current int23_t
		 * @param[in] rhs Right hand side int23_t
		 *
		 * Sets the current uitn23_t's value to bitwise and of current and rhs's internal bitset. See also ::operator&()
		 */
		int23_t& operator&= (int23_t const& rhs);
		/*! @brief Bitwise operator for or-ing the current int23_t
		 * @param[in] rhs Right hand side int23_t
		 *
		 * Sets the current uitn23_t's value to bitwise or of current and rhs's internal bitset. See also ::operator|()
		 */
		int23_t& operator|= (int23_t const& rhs);
		/*! @brief Bitwise operator for xor-ing the current int23_t
		 * @param[in] rhs Right hand side int23_t
		 *
		 * Sets the current uitn23_t's value to bitwise xor of current and rhs's internal bitset. See also ::operator^()
		 */
		int23_t& operator^= (int23_t const& rhs);
		/*! @brief Converts int23_t to string in base 10
		 */
		operator std::string() const;
		/*! @brief Invert every bit operator
		 */
		int23_t operator~() const;
	};
	const int23_t INT23_MAX(8388607); /*!< The maximum value of integers of class int23_t */
	const int23_t INT23_MIN(0); /*!< The minimum value of integers of class int23_t, 0 because it is unsigned */
	/*! @brief Operator for outputting an int23_t using std::ostream class
	 * @param[in] out Variable used for outputting, from std::ostream class like std::cout, see also https://en.cppreference.com/w/cpp/io/basic_ostream
	 * @param[in] num Variable thats outputted, from int23_t class
	 *
	 * Converts int23_t to std::string to output integer
	 */
	std::ostream& operator<< (std::ostream&out, int23_t const&num);
	/*! @brief Operator for inputting an int23_t using std::istream class
	 * @param[in] in Variable used for inputting, from std::istream class like std::cin, see also https://en.cppreference.com/w/cpp/io/basic_istream
	 * @param[in] num Variable thats inputted, from int23_t class
	 *
	 * Inputs int32_t and converts it to int23_t internally
	 */
	std::istream& operator>> (std::istream&in, int23_t&num);
}

