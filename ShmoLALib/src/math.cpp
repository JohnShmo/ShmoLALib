#include <iostream>
#include <shmo/math.hpp>

void print_box(const shmo::math::vec2& tl, const shmo::math::vec2& tr, const shmo::math::vec2& bl, const shmo::math::vec2& br)
{
	std::cout << "Top left:     " << tl << '\n';
	std::cout << "Top right:    " << tr << '\n';
	std::cout << "Bottom left:  " << bl << '\n';
	std::cout << "Bottom right: " << br << "\n\n";
}

void mat3x3_forward_box(const shmo::math::mat3x3& m, shmo::math::vec2& tl, shmo::math::vec2& tr, shmo::math::vec2& bl, shmo::math::vec2& br)
{
	tl = m.forward(tl);
	tr = m.forward(tr);
	bl = m.forward(bl);
	br = m.forward(br);
}

int main()
{
	using namespace shmo::math;

	box2d box = { -0.5, -0.5, 1.0, 1.0 };
	transform2d trn;
	vec2 tl, tr, bl, br;

	trn.set_translation(0, 0);
	trn.set_rotation(constants::PI_OVER_FOUR);
	trn.set_scale(1.0, 1.0);

	box.get_corners(tl, tr, bl, br);

	print_box(tl, tr, bl, br);

	mat3x3_forward_box(trn.result(), tl, tr, bl, br);

	print_box(tl, tr, bl, br);

	mat3x3_forward_box(trn.inverse(), tl, tr, bl, br);

	print_box(tl, tr, bl, br);

	std::cout << trn.rotation_angle() << '\n';

	return 0;
}