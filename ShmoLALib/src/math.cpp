#include <iostream>
#include <shmo/math.hpp>

int main()
{
	using namespace shmo::math;

	mat4x4 trn, rot, scl, fin, inv;
	vec3 v = { 0, 0, 0 };

	trn = mat4x4::translation(5, 0, 0);
	rot = mat4x4::rotation(0, 0, 0);
	scl = mat4x4::scale(1, 1, 1);

	fin = trn * rot * scl;
	inv = !fin;

	std::cout << fin << '\n' << '\n';
	std::cout << inv << '\n' << '\n';

	v = fin.forward(v);

	std::cout << v << '\n' << '\n';

	v = inv.forward(v);

	std::cout << v << '\n' << '\n';

	return 0;
}