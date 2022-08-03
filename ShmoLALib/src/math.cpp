#include <iostream>
#include <shmo/math.hpp>

int main()
{
	shmo::math::vector2 vec2{2, 4};
	shmo::math::vector3 vec3{vec2};
	std::cout << vec2.x << '\n' << vec2.y << '\n';
	return 0;
}