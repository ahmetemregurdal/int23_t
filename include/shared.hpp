#pragma once

/*! @file include/shared.hpp
 * @brief Header for shared functions accross headers
 */

namespace int23_t {
    /*! @brief An adder which adds carry and 2 bits together and calculates
     * new carry and sum
     * @param[in] b1 Bit 1, left side of addition
     * @param[in] b2 Bit 2, right side of addition
     * @param[in] carry Carry of the addition, passes the reference and updates
     * it with the new carry
     */
	char fullAdder (char const& b1, char const& b2, char& carry);
    /*! @brief A substractor function, similar to the adder function. Substracts
     * left side from right side
     * @param[in] b1 Bit 1, left side of substraction
     * @param[in] b2 Bit 2, right side of substraction
     * @param[in] borrow Borrow of the addition, passes the reference and updates
     * it with new borrow
     */ 
	char fullSub (char const& b1, char const& b2, char& borrow);
}
