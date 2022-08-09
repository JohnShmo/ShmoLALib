#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using shmo::math::mat3x3;
	using shmo::math::vec2;

	mat3x3 trn = mat3x3::translation(1, 0);
	mat3x3 rot = mat3x3::rotation(0);
	mat3x3 scl = mat3x3::scale(1, 1);

	mat3x3 result = trn * rot * scl;
	mat3x3 inverse = !result;

	std::cout << result << '\n' << '\n';
	std::cout << inverse << '\n' << '\n';

	vec2 v1 = { -5, 1 };

	v1 = result.transform(v1);

	std::cout << v1 << '\n';

	v1 = inverse.transform(v1);

	std::cout << v1 << '\n';

	return 0;
}