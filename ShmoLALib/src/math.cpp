#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using shmo::math::vec2;

	vec2 v1 = { 5, 1 };
	vec2 v2 = v1.make_normalized();

	std::cout << v1 << '\n';
	std::cout << v2 << '\n';

	return 0;
}