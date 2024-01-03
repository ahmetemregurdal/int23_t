#include <bits/stdc++.h>
#include "include/int23_t.hpp"

int main() {
	int23_t::int23_t abc(5);
	std::cout<<abc<<'\n';
	std::cout<<int23_t::int23_t(-1).num.to_string()<<'\n';
	std::cout << (abc * int23_t::int23_t(-1)).num.to_string() << '\n';
}
