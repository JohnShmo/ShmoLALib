#ifndef ___SHMO_LA_LINE2d_HPP___
#define ___SHMO_LA_LINE2d_HPP___

#include "primitives/vec2.hpp"

namespace shmo::math
{
	struct line2d
	{
		vec2 points[2]{};

		static constexpr size_t size() noexcept { return 2; }

		constexpr line2d() noexcept {}
		constexpr line2d(const line2d& other) noexcept :
			points { other.points[0], other.points[1] }
		{}
		constexpr line2d(auto p0x, auto p0y, auto p1x, auto p1y) noexcept :
			points{ { p0x, p0y }, { p1x, p1y } }
		{}
		constexpr line2d(const vec2& p0, const vec2& p1) noexcept :
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

		constexpr bool equals(const line2d& l) const noexcept
		{
			return points[0] == l[0] && points[1] == l[1];
		}
		constexpr bool operator==(const line2d& l) const noexcept
		{
			return equals(l);
		}
		constexpr bool operator!=(const line2d& l) const noexcept
		{
			return !equals(l);
		}

		constexpr line2d& set(const line2d& l) noexcept
		{
			points[0] = l.points[0];
			points[1] = l.points[1];
			return *this;
		}
		constexpr line2d& set(auto p0x, auto p0y, auto p1x, auto p1y) noexcept
		{
			points[0].set(p0x, p0y);
			points[1].set(p1x, p1y);
			return *this;
		}
		constexpr line2d& set(const vec2& p0, const vec2& p1)
		{
			points[0] = p0;
			points[1] = p1;
			return *this;
		}

		constexpr double slope() const noexcept
		{
			return (points[1].y - points[0].y) / (points[1].x - points[0].x);
		}

		constexpr bool parallel(const line2d& l) const noexcept
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