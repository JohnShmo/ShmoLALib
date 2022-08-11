#ifndef ___SHMO_LA_STRING_UTILS_HPP___
#define ___SHMO_LA_STRING_UTILS_HPP___

#include "primitives.hpp"
#include <format>
#include <ostream>

namespace shmo::math
{

	inline std::string to_string(const vec2& v)
	{
		return std::format("( {:10f} {:10f} )", v.x, v.y);
	}

	inline std::ostream& operator<<(std::ostream& os, const vec2& v)
	{
		return os << to_string(v);
	}

	inline std::string to_string(const vec3& v)
	{
		return std::format("( {:10f} {:10f} {:10f} )", v.x, v.y, v.z);
	}

	inline std::ostream& operator<<(std::ostream& os, const vec3& v)
	{
		return os << to_string(v);
	}

	inline std::string to_string(const vec4& v)
	{
		return std::format("( {:10f} {:10f} {:10f} {:10f} )", v.x, v.y, v.z, v.w);
	}

	inline std::ostream& operator<<(std::ostream& os, const vec4& v)
	{
		return os << to_string(v);
	}

	inline std::string to_string(const mat3x3& m)
	{
		return std::format
		(
			"| {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} |",
			m.c0r0, m.c1r0, m.c2r0,
			m.c0r1, m.c1r1, m.c2r1,
			m.c0r2, m.c1r2, m.c2r2
		);
	}

	inline std::ostream& operator<<(std::ostream& os, const mat3x3& m)
	{
		return os << to_string(m);
	}

	inline std::string to_string(const mat4x4& m)
	{
		return std::format
		(
			"| {:10f} {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} {:10f} |",
			m.c0r0, m.c1r0, m.c2r0, m.c3r0,
			m.c0r1, m.c1r1, m.c2r1, m.c3r1,
			m.c0r2, m.c1r2, m.c2r2, m.c3r2,
			m.c0r3, m.c1r3, m.c2r3, m.c3r3
		);
	}

	inline std::ostream& operator<<(std::ostream& os, const mat4x4& m)
	{
		return os << to_string(m);
	}
}

#endif