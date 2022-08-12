#ifndef ___SHMO_LA_BOX2D_HPP___
#define ___SHMO_LA_BOX2D_HPP___

#include "primitives/vec2.hpp"

namespace shmo::math
{
	struct box2d
	{
		vec2 position, dimension;

		static constexpr size_t size() noexcept { return 2; }

		constexpr box2d() noexcept {}
		constexpr box2d(const box2d& other) noexcept :
			position(other.position), dimension(other.dimension)
		{}
		constexpr box2d(auto x, auto y, auto width, auto height) noexcept :
			position{ x, y }, dimension{ width, height }
		{}
		constexpr box2d(const vec2& position, const vec2& dimension) noexcept :
			position(position), dimension(dimension)
		{}

		constexpr vec2 operator[](size_t index) const noexcept
		{
			if (index == 0) return position;
			else return dimension;
		}
		constexpr vec2& operator[](size_t index) noexcept
		{
			if (index == 0) return position;
			else return dimension;
		}

		constexpr const vec2* data() const noexcept
		{
			return &position;
		}
		constexpr vec2* data() noexcept
		{
			return &position;
		}

		constexpr const vec2* begin() const noexcept
		{
			return &position;
		}
		constexpr vec2* begin() noexcept
		{
			return &position;
		}

		constexpr const vec2* end() const noexcept
		{
			return (&dimension) + 1;
		}
		constexpr vec2* end() noexcept
		{
			return (&dimension) + 1;
		}

		constexpr bool equals(const box2d& b) const noexcept
		{
			return position == b.position && dimension == b.dimension;
		}
		constexpr bool operator==(const box2d& b) const noexcept
		{
			return equals(b);
		}
		constexpr bool operator!=(const box2d& b) const noexcept
		{
			return !equals(b);
		}

		constexpr vec2 top_left() const noexcept
		{
			return position;
		}
		constexpr vec2 top_right() const noexcept
		{
			return vec2(position).add({ dimension.x, 0 });
		}
		constexpr vec2 bottom_left() const noexcept
		{
			return vec2(position).add({ 0, dimension.y });
		}
		constexpr vec2 bottom_right() const noexcept
		{
			return vec2(position).add(dimension);
		}

		constexpr void get_corners(vec2& o_tl, vec2& o_tr, vec2& o_bl, vec2& o_br) const noexcept
		{
			o_tl = top_left();
			o_tr = top_right();
			o_bl = bottom_left();
			o_br = bottom_right();
		}

		constexpr double x() const noexcept
		{
			return position.x;
		}
		constexpr double y() const noexcept
		{
			return position.y;
		}
		constexpr double width() const noexcept
		{
			return dimension.x;
		}
		constexpr double height() const noexcept
		{
			return dimension.y;
		}

		constexpr box2d& set(const box2d& b) noexcept
		{
			position = b.position;
			dimension = b.dimension;
			return *this;
		}
		constexpr box2d& set(auto x, auto y, auto width, auto height) noexcept
		{
			position.set(x, y);
			dimension.set(width, height);
			return *this;
		}
		constexpr box2d& set(const vec2& position, const vec2& dimension)
		{
			this->position = position;
			this->dimension = dimension;
			return *this;
		}
	};
}

#endif