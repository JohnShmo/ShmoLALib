#ifndef ___SHMO_LA_PRIMATIVES_VECTOR2_HPP___
#define ___SHMO_LA_PRIMATIVES_VECTOR2_HPP___

#include "internal/math_primitive_includes.hpp"

namespace shmo::math
{
	struct vec2
	{
		double x{}, y{};

		static constexpr size_t size() noexcept { return 2; }

		constexpr vec2() noexcept {}
		constexpr vec2(const vec2& other) noexcept :
			x(other.x), y(other.y)
		{}

		constexpr vec2(auto x, auto y) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y))
		{}

		constexpr double operator[](size_t index) const noexcept
		{
			if (index % 2 == 0) return x;
			else return y;
		}
		constexpr double& operator[](size_t index) noexcept
		{
			if (index % 2 == 0) return x;
			else return y;
		}

		constexpr const double* data() const noexcept { return &x; }
		constexpr double* data() noexcept { return &x; }

		constexpr const double* begin() const noexcept { return &x; }
		constexpr double* begin() noexcept { return &x; }

		constexpr const double* end() const noexcept { return (&y) + 1; }
		constexpr double* end() noexcept { return (&y) + 1; }

		constexpr vec2& set(const vec2& v) noexcept
		{
			x = v.x;
			y = v.y;
			return *this;
		}
		constexpr vec2& set(auto x, auto y) noexcept
		{
			this->x = static_cast<double>(x);
			this->y = static_cast<double>(y);
			return *this;
		}
		constexpr vec2& operator=(const vec2& v) noexcept
		{
			return set(v);
		}

		constexpr bool equals(const vec2& v) const noexcept
		{
			return x == v.x && y == v.y;
		}
		constexpr bool operator==(const vec2& v) const noexcept
		{
			return equals(v);
		}

		constexpr vec2& add(const vec2& v) noexcept
		{
			x += v.x;
			y += v.y;
			return *this;
		}
		constexpr vec2& operator+=(const vec2& v) noexcept
		{
			return add(v);
		}
		constexpr vec2 operator+(const vec2& v) const noexcept
		{
			return { x + v.x, y + v.y };
		}

		constexpr vec2& subtract(const vec2& v) noexcept
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}
		constexpr vec2& operator-=(const vec2& v) noexcept
		{
			return subtract(v);
		}
		constexpr vec2 operator-(const vec2& v) const noexcept
		{
			return { x - v.x, y - v.y };
		}

		constexpr vec2& multiply(double d) noexcept
		{
			x *= d;
			y *= d;
			return *this;
		}
		constexpr vec2& operator*=(double d) noexcept
		{
			return multiply(d);
		}
		constexpr vec2 operator*(double d) const noexcept
		{
			return { x * d, y * d };
		}
		
		constexpr vec2& divide(double d) noexcept
		{
			x /= d;
			y /= d;
			return *this;
		}
		constexpr vec2& operator/=(double d) noexcept
		{
			return divide(d);
		}
		constexpr vec2 operator/(double d) const noexcept
		{
			return { x / d, y / d };
		}

		constexpr double magnitude_sqr() const noexcept
		{
			return x * x + y * y;
		}
		inline double magnitude() const noexcept
		{
			return std::sqrt(magnitude_sqr());
		}

		inline vec2& normalize() noexcept
		{
			double mag = magnitude();
			if (mag == 0)
			{
				x = 1;
				y = 0;
				return *this;
			}
			else
			{
				return divide(mag);
			}
		}

		inline vec2& scale(double d) noexcept
		{
			normalize();
			multiply(d);
		}

		constexpr vec2& negate() noexcept
		{
			x = -x;
			y = -y;
			return *this;
		}

		constexpr vec2 operator-() noexcept
		{
			return vec2(*this).negate();
		}

		static inline vec2 normalize(const vec2& v) noexcept
		{
			return vec2(v).normalize();
		}

		static inline vec2 scale(const vec2& v, double d) noexcept
		{
			return vec2(v).scale(d);
		}

		constexpr double dot(const vec2& v) const noexcept
		{
			return x * v.x + y * v.y;
		}
		constexpr double cross(const vec2& v) const noexcept
		{
			return x * v.y - y * v.x;
		}
	};

	constexpr std::array<double, 2> to_array(const vec2& v)
	{
		return { v.x, v.y };
	}
	
	inline std::string to_string(const vec2& v)
	{
		return std::format("( {:10f} {:10f} )", v.x, v.y);
	}
	
	inline std::ostream& operator<<(std::ostream& os, const vec2& v)
	{
		return os << to_string(v);
	}	
}

#endif