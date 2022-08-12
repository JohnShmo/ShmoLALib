#ifndef ___SHMO_LA_LINE_HPP___
#define ___SHMO_LA_LINE_HPP___

#include "primitives/vec2.hpp"

namespace shmo::math
{
	struct line
	{
		vec2 points[2]{};

		static constexpr size_t size() noexcept { return 2; }

		constexpr line() noexcept {}
		constexpr line(const line& other) noexcept :
			points { other.points[0], other.points[1] }
		{}
		constexpr line(auto p0x, auto p0y, auto p1x, auto p1y) noexcept :
			points{ { p0x, p0y }, { p1x, p1y } }
		{}
		constexpr line(const vec2& p0, const vec2& p1) noexcept :
			points{ p0, p1 }
		{}

		constexpr vec2 operator[](size_t index) const noexcept
		{
			if (index == 0) return points[0];
			else return points[1];
		}
		constexpr vec2& operator[](size_t index) noexcept
		{
			if (index == 0) return points[0];
			else return points[1];
		}

		constexpr const vec2* data() const noexcept
		{
			return &points[0];
		}
		constexpr vec2* data() noexcept
		{
			return &points[0];
		}
		
		constexpr const vec2* begin() const noexcept
		{
			return &points[0];
		}
		constexpr vec2* begin() noexcept
		{
			return &points[0];
		}
		
		constexpr const vec2* end() const noexcept
		{
			return (&points[1]) + 1;
		}
		constexpr vec2* end() noexcept
		{
			return (&points[1]) + 1;
		}

		constexpr bool equals(const line& l) const noexcept
		{
			return points[0] == l[0] && points[1] == l[1];
		}
		constexpr bool operator==(const line& l) const noexcept
		{
			return equals(l);
		}
		constexpr bool operator!=(const line& l) const noexcept
		{
			return !equals(l);
		}

		constexpr double slope() const noexcept
		{
			return (points[1].y - points[0].y) / (points[1].x - points[0].x);
		}

		constexpr bool parallel(const line& l) const noexcept
		{
			return slope() == l.slope();
		}

		inline double length() const noexcept
		{
			return points[0].distance(points[1]);
		}
	};
}

#endif