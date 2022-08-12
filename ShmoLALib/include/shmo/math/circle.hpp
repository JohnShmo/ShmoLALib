#ifndef ___SHMO_LA_CIRCLE_HPP___
#define ___SHMO_LA_CIRCLE_HPP___

#include "primitives/vec2.hpp"
#include "constants.hpp"

namespace shmo::math
{
	struct circle
	{
		vec2 position;
		double radius{};

		constexpr circle() noexcept {}
		constexpr circle(const vec2& position, auto radius) noexcept :
			position(position), radius(static_cast<double>(radius))
		{}
		constexpr circle(auto x, auto y, auto radius) noexcept :
			position(x, y), radius(static_cast<double>(radius))
		{}
		constexpr circle(const circle& other) noexcept :
			position(other.position), radius(other.radius)
		{}

		constexpr bool equals(const circle& c) const noexcept
		{
			return position == c.position && radius == c.radius;
		}
		constexpr bool operator==(const circle& c) const noexcept
		{
			return equals(c);
		}
		constexpr bool operator!=(const circle& c) const noexcept
		{
			return !equals(c);
		}
		 
		constexpr circle& set(const vec2& position, auto radius) noexcept
		{
			this->position = position;
			this->radius = static_cast<double>(radius);
			return *this;
		}
		constexpr circle& set(auto x, auto y, auto radius) noexcept
		{
			position = { static_cast<double>(x), static_cast<double>(y) };
			this->radius = static_cast<double>(radius);
			return *this;
		}
		constexpr circle& set(const circle& c) noexcept
		{
			position = c.position;
			radius = c.radius;
			return *this;
		}

		constexpr double diameter() const noexcept { return radius * 2.0; }
		constexpr double circumference() const noexcept { return 2.0 * constants::PI * radius; }
		constexpr double area() const noexcept { return constants::PI * (radius * radius); }
	};
}

#endif
