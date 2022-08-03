#include <iostream>
#include <shmo/math.hpp>

int main()
{
	shmo::math::vec2 v1{1, 1};
	auto v2 = v1.normalized();

	std::cout << v1.magnitude() << '\n';
	std::cout << v2.magnitude() << '\n';
	return 0;
}