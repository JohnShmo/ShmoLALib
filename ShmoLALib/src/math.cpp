#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using shmo::math::mat3x3;
	using shmo::math::vec2;

	mat3x3 trn = mat3x3::translation(0, 0);
	mat3x3 rot = mat3x3::rotation(0);
	mat3x3 scl = mat3x3::scale(1, 1);

	mat3x3 result = mat3x3::identity();

	result.multiply(trn).multiply(rot).multiply(scl);

	vec2 v1 = { 1, 1 };
	vec2 v2 = vec2::normalize(v1);

	std::cout << result << '\n';
	std::cout << v1 << '\n';
	std::cout << v2 << '\n';

	return 0;
}