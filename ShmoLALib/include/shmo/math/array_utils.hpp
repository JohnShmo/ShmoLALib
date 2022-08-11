#ifndef ___SHMO_LA_ARRAY_UTILS_HPP___
#define ___SHMO_LA_ARRAY_UTILS_HPP___

#include "primitives.hpp"
#include <array>

namespace shmo::math
{
	constexpr std::array<double, 2> to_array(const vec2& v)
	{
		return { v.x, v.y };
	}

	constexpr std::array<double, 3> to_array(const vec3& v)
	{
		return { v.x, v.y, v.z };
	}

	constexpr std::array<double, 4> to_array(const vec4& v)
	{
		return { v.x, v.y, v.z, v.w };
	}

	constexpr std::array<double, 9> to_array(const mat3x3& m)
	{
		return { m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8] };
	}

	constexpr std::array<double, 16> to_array(const mat4x4& m)
	{
		return { m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15] };
	}
}

#endif