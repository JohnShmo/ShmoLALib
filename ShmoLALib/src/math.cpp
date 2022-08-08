#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using shmo::math::mat3x3;

	mat3x3 trn = mat3x3::translation(1, 1);
	mat3x3 rot = mat3x3::rotation(3.14159265359);
	mat3x3 scl = mat3x3::scale(2, 2);

	mat3x3 result = mat3x3::identity();

	result.multiply(trn).multiply(rot).multiply(scl);

	std::cout << result << '\n';

	return 0;
}