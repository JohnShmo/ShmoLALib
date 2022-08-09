#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using shmo::math::mat3x3;
	using shmo::math::vec2;
	using shmo::math::mat4x4;
	using shmo::math::vec3;

	mat4x4 trn = mat4x4::translation(4, 4, 4);
	mat4x4 scl = mat4x4::scale(1, 1, 1);

	mat4x4 res = trn * scl;
	mat4x4 inv = !res;

	vec3 v { 0, 0, 0 };

	v = res.forward(v);

	std::cout << v << '\n';

	v = inv.forward(v);

	std::cout << v << '\n';

	return 0;
}