#ifndef ___SHMO_LA_PRIMATIVES_VECTOR3_HPP___
#define ___SHMO_LA_PRIMATIVES_VECTOR3_HPP___

#include "vec2.hpp"

namespace shmo::math
{
	struct vec3
	{
		double x{}, y{}, z{};

		static constexpr size_t size() noexcept { return 3; }

		constexpr vec3() noexcept {}
		constexpr vec3(const vec3& other) noexcept :
			x(other.x), y(other.y), z(other.z)
		{}

		constexpr vec3(auto x, auto y) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y))
		{}
		constexpr vec3(auto x, auto y, auto z) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z))
		{}
		constexpr vec3(const vec2& v) noexcept :
			x(v.x), y(v.y)
		{}

		constexpr double operator[](size_t index) const noexcept
		{
			if (index == 0) return x;
			else if (index == 1) return y;
			else return z;
		}
		constexpr double& operator[](size_t index) noexcept
		{
			if (index == 0) return x;
			else if (index == 1) return y;
			else return z;
		}

		constexpr const double* data() const noexcept { return &x; }
		constexpr double* data() noexcept { return &x; }

		constexpr const double* begin() const noexcept { return &x; }
		constexpr double* begin() noexcept { return &x; }

		constexpr const double* end() const noexcept { return (&z) + 1; }
		constexpr double* end() noexcept { return (&z) + 1; }

		constexpr vec3& set(const vec3& v) noexcept
		{
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		constexpr vec3& set(auto x, auto y, auto z) noexcept
		{
			this->x = static_cast<double>(x);
			this->y = static_cast<double>(y);
			this->z = static_cast<double>(z);
			return *this;
		}
		constexpr vec3& operator=(const vec3& v) noexcept
		{
			return set(v);
		}

		constexpr bool equals(const vec3& v) const noexcept
		{
			return x == v.x && y == v.y && v.z == z;
		}
		constexpr bool operator==(const vec3& v) const noexcept
		{
			return equals(v);
		}
		constexpr bool operator!=(const vec3& v) const noexcept
		{
			return !equals(v);
		}

		constexpr vec3& add(const vec3& v) noexcept
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		constexpr vec3& operator+=(const vec3& v) noexcept
		{
			return add(v);
		}
		constexpr vec3 operator+(const vec3& v) const noexcept
		{
			return { x + v.x, y + v.y, z + v.z };
		}

		constexpr vec3& subtract(const vec3& v) noexcept
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		constexpr vec3& operator-=(const vec3& v) noexcept
		{
			return subtract(v);
		}
		constexpr vec3 operator-(const vec3& v) const noexcept
		{
			return { x - v.x, y - v.y, z - v.z };
		}

		constexpr vec3& multiply(double d) noexcept
		{
			x *= d;
			y *= d;
			z *= d;
			return *this;
		}
		constexpr vec3& operator*=(double d) noexcept
		{
			return multiply(d);
		}
		constexpr vec3 operator*(double d) const noexcept
		{
			return { x * d, y * d, z * d };
		}

		constexpr vec3& multiply(const vec3& v) noexcept
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			return *this;
		}
		constexpr vec3& operator*=(const vec3& v) noexcept
		{
			return multiply(v);
		}
		constexpr vec3 operator*(const vec3& v) const noexcept
		{
			return { x * v.z, y * v.z, y * v.z };
		}

		constexpr vec3& divide(double d) noexcept
		{
			x /= d;
			y /= d;
			z /= d;
			return *this;
		}
		constexpr vec3& operator/=(double d) noexcept
		{
			return divide(d);
		}
		constexpr vec3 operator/(double d) const noexcept
		{
			return { x / d, y / d, z / d };
		}

		constexpr vec3& divide(const vec3& v) noexcept
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
			return *this;
		}
		constexpr vec3& operator/=(const vec3& v) noexcept
		{
			return divide(v);
		}
		constexpr vec3 operator/(const vec3& v) const noexcept
		{
			return { x / v.z, y / v.z, y / v.z };
		}

		constexpr double magnitude_sqr() const noexcept
		{
			return (x * x) + (y * y) + (z * z);
		}
		inline double magnitude() const noexcept
		{
			return std::sqrt(magnitude_sqr());
		}

		inline vec3& normalize() noexcept
		{
			double mag = magnitude();
			if (mag == 0)
			{
				return *this;
			}
			else
			{
				return divide(mag);
			}
		}

		inline vec3& scale(double d) noexcept
		{
			normalize();
			multiply(d);
		}

		static inline vec3 normalize(const vec3& v) noexcept
		{
			return vec3(v).normalize();
		}

		static inline vec3 scale(const vec3& v, double d) noexcept
		{
			return vec3(v).scale(d);
		}

		constexpr vec3& negate() noexcept
		{
			x = -x;
			y = -y;
			z = -z;
			return *this;
		}

		constexpr vec3 operator-() const noexcept
		{
			return vec3(*this).negate();
		}

		constexpr double dot(const vec3& v) const noexcept
		{
			return (x * v.x) + (y * v.y) + (z * v.z);
		}

		constexpr vec3 cross(const vec3& v) const noexcept
		{
			vec3 result;
			result.x = y * v.z - z * v.y;
			result.y = -(x * v.z - z * v.x);
			result.z = x * v.y - y * v.x;
			return result;
		}
	};

	constexpr std::array<double, 3> to_array(const vec3& v)
	{
		return { v.x, v.y, v.z };
	}

	inline std::string to_string(const vec3& v)
	{
		return std::format("( {:10f} {:10f} {:10f} )", v.x, v.y, v.z);
	}

	inline std::ostream& operator<<(std::ostream& os, const vec3& v)
	{
		return os << to_string(v);
	}
}

#endif