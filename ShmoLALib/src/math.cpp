#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using shmo::math::mat3x3;
	using shmo::math::vec2;
	using shmo::math::mat4x4;
	using shmo::math::vec3;

	mat4x4 trn = mat4x4::translation(5, 0, 0);
	mat4x4 rot = mat4x4::rotation(0, 0, 0);
	mat4x4 scl = mat4x4::scale(1, 1, 1);

	mat4x4 fin = trn * rot * scl;
	mat4x4 inv = !fin;

	std::cout << fin << '\n' << '\n';
	std::cout << inv << '\n' << '\n';

	vec3 v { 0, 0, 0 };

	v = fin.forward(v);

	std::cout << v << '\n' << '\n';

	v = inv.forward(v);

	std::cout << v << '\n' << '\n';

	return 0;
}