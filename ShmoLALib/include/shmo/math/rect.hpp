#ifndef ___SHMO_LA_BOX2D_HPP___
#define ___SHMO_LA_BOX2D_HPP___

#include "primitives/vec2.hpp"

namespace shmo::math
{
	struct rect
	{
		vec2 position, size;

		constexpr rect() noexcept {}
		constexpr rect(const rect& other) noexcept :
			position(other.position), size(other.size)
		{}
		constexpr rect(auto x, auto y, auto width, auto height) noexcept :
			position{ x, y }, size{ width, height }
		{}
		constexpr rect(const vec2& position, const vec2& size) noexcept :
			position(position), size(size)
		{}

		constexpr bool equals(const rect& b) const noexcept
		{
			return position == b.position && size == b.size;
		}
		constexpr bool operator==(const rect& b) const noexcept
		{
			return equals(b);
		}
		constexpr bool operator!=(const rect& b) const noexcept
		{
			return !equals(b);
		}

		constexpr vec2 top_left() const noexcept
		{
			return position;
		}
		constexpr vec2 top_right() const noexcept
		{
			return vec2(position).add({ size.x, 0 });
		}
		constexpr vec2 bottom_left() const noexcept
		{
			return vec2(position).add({ 0, size.y });
		}
		constexpr vec2 bottom_right() const noexcept
		{
			return vec2(position).add(size);
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
			return size.x;
		}
		constexpr double height() const noexcept
		{
			return size.y;
		}

		constexpr rect& set(const rect& b) noexcept
		{
			position = b.position;
			size = b.size;
			return *this;
		}
		constexpr rect& set(auto x, auto y, auto width, auto height) noexcept
		{
			position.set(x, y);
			size.set(width, height);
			return *this;
		}
		constexpr rect& set(const vec2& position, const vec2& size)
		{
			this->position = position;
			this->size = size;
			return *this;
		}

		constexpr double perimeter() const noexcept { return 2.0 * (width() + height()); }
		constexpr double area() const noexcept { return width() * height(); }
	};
}

#endif