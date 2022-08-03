#include <iostream>
#include <shmo/math.hpp>

int main()
{
	shmo::math::vector2 vec1{2, 4};
	shmo::math::vector2 vec2 = vec1 + vec1;
	vec2.add({ 1, 2 });

	std::cout << vec2.x << '\n';
	std::cout << vec2.y << '\n';
	return 0;
}