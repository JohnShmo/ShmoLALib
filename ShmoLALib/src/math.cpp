#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using namespace shmo::math;

	mat3x3 translation, rotation, scale, result;

	translation = mat3x3::translation(5, 0);
	rotation = mat3x3::rotation(constants::PI);
	scale = mat3x3::scale(2, 2);

	result = translation * rotation * scale;

	vec2 position = { 3, 9 };

	std::cout << position << '\n';

	position = result.forward(position);

	std::cout << position << '\n';

	result.invert();

	position = result.forward(position);

	std::cout << position << '\n';

	return 0;
}