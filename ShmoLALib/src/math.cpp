#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using namespace shmo::math;

	vec3 col = hex_to_vec3(0xffe5b0);
	std::cout << col << '\n';
	uint32_t h = vec3_to_hex(col);
	std::cout << h << '\n';
	col = hex_to_vec3(h);
	std::cout << col << '\n';

	return 0;
}