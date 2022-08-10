#ifndef ___SHMO_LA_PRIMATIVES_VECTOR4_HPP___
#define ___SHMO_LA_PRIMATIVES_VECTOR4_HPP___

#include "vec3.hpp"

namespace shmo::math
{
	struct vec4
	{
		double x{}, y{}, z{}, w{};

		static constexpr size_t size() noexcept { return 3; }

		constexpr vec4() noexcept {}
		constexpr vec4(const vec4& other) noexcept :
			x(other.x), y(other.y), z(other.z), w(other.w)
		{}

		constexpr vec4(auto x, auto y) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y))
		{}
		constexpr vec4(auto x, auto y, auto z) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z))
		{}
		constexpr vec4(auto x, auto y, auto z, auto w) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z)), w(static_cast<double>(w))
		{}
		constexpr vec4(const vec2& v) noexcept :
			x(v.x), y(v.y)
		{}		
		constexpr vec4(const vec3& v) noexcept :
			x(v.x), y(v.y), z(v.z)
		{}

		constexpr double operator[](size_t index) const noexcept
		{
			if (index % 4 == 0) return x;
			else if (index % 4 == 1) return y;
			else if (index % 4 == 2) return z;
			else return w;
		}
		constexpr double& operator[](size_t index) noexcept
		{
			if (index % 4 == 0) return x;
			else if (index % 4 == 1) return y;
			else if (index % 4 == 2) return z;
			else return w;
		}

		constexpr const double* data() const noexcept { return &x; }
		constexpr double* data() noexcept { return &x; }

		constexpr const double* begin() const noexcept { return &x; }
		constexpr double* begin() noexcept { return &x; }

		constexpr const double* end() const noexcept { return (&w) + 1; }
		constexpr double* end() noexcept { return (&w) + 1; }

		constexpr vec4& set(const vec4& v) noexcept
		{
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
			return *this;
		}
		constexpr vec4& set(auto x, auto y, auto z, auto w) noexcept
		{
			this->x = static_cast<double>(x);
			this->y = static_cast<double>(y);
			this->z = static_cast<double>(z);
			this->w = static_cast<double>(w);
			return *this;
		}
		constexpr vec4& operator=(const vec4& v) noexcept
		{
			return set(v);
		}

		constexpr bool equals(const vec4& v) const noexcept
		{
			return x == v.x && y == v.y && z == v.z && w == v.w;
		}
		constexpr bool operator==(const vec4& v) const noexcept
		{
			return equals(v);
		}

		constexpr vec4& add(const vec4& v) noexcept
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}
		constexpr vec4& operator+=(const vec4& v) noexcept
		{
			return add(v);
		}
		constexpr vec4 operator+(const vec4& v) const noexcept
		{
			return { x + v.x, y + v.y, z + v.z, w + v.w };
		}

		constexpr vec4& subtract(const vec4& v) noexcept
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}
		constexpr vec4& operator-=(const vec4& v) noexcept
		{
			return subtract(v);
		}
		constexpr vec4 operator-(const vec4& v) const noexcept
		{
			return { x - v.x, y - v.y, z - v.z, w - v.w };
		}

		constexpr vec4& multiply(double d) noexcept
		{
			x *= d;
			y *= d;
			z *= d;
			w *= d;
			return *this;
		}
		constexpr vec4& operator*=(double d) noexcept
		{
			return multiply(d);
		}
		constexpr vec4 operator*(double d) const noexcept
		{
			return { x * d, y * d, z * d, w * d };
		}

		constexpr vec4& multiply(const vec4& v) noexcept
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			w *= v.w;
			return *this;
		}
		constexpr vec4& operator*=(const vec4& v) noexcept
		{
			return multiply(v);
		}
		constexpr vec4 operator*(const vec4& v) const noexcept
		{
			return { x * v.z, y * v.z, y * v.z, w * v.w };
		}

		constexpr vec4& divide(double d) noexcept
		{
			x /= d;
			y /= d;
			z /= d;
			w /= d;
			return *this;
		}
		constexpr vec4& operator/=(double d) noexcept
		{
			return divide(d);
		}
		constexpr vec4 operator/(double d) const noexcept
		{
			return { x / d, y / d, z / d, w / d };
		}

		constexpr vec4& divide(const vec4& v) noexcept
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
			w /= v.w;
			return *this;
		}
		constexpr vec4& operator/=(const vec4& v) noexcept
		{
			return divide(v);
		}
		constexpr vec4 operator/(const vec4& v) const noexcept
		{
			return { x / v.z, y / v.z, y / v.z, w / v.w };
		}

		constexpr double magnitude_sqr() const noexcept
		{
			return (x * x) + (y * y) + (z * z) + (w * w);
		}
		inline double magnitude() const noexcept
		{
			return std::sqrt(magnitude_sqr());
		}

		inline vec4& normalize() noexcept
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

		inline vec4& scale(double d) noexcept
		{
			normalize();
			multiply(d);
		}

		static inline vec4 normalize(const vec4& v) noexcept
		{
			return vec4(v).normalize();
		}

		static inline vec4 scale(const vec4& v, double d) noexcept
		{
			return vec4(v).scale(d);
		}

		constexpr double dot(const vec4& v) const noexcept
		{
			return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w);
		}
	};

	constexpr std::array<double, 4> to_array(const vec4& v)
	{
		return { v.x, v.y, v.z, v.w };
	}

	inline std::string to_string(const vec4& v)
	{
		return std::format("( {:10f} {:10f} {:10f} {:10f} )", v.x, v.y, v.z, v.w);
	}

	inline std::ostream& operator<<(std::ostream& os, const vec4& v)
	{
		return os << to_string(v);
	}
}

#endif