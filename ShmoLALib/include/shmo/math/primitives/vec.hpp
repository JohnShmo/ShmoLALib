#ifndef ___SHMO_LA_PRIMATIVES_VECTOR_HPP___
#define ___SHMO_LA_PRIMATIVES_VECTOR_HPP___

#include <algorithm>
#include <array>
#include <cmath>
#include <stdexcept>
#include <format>
#include <ostream>

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

		constexpr vec2(auto v) noexcept :
			x(static_cast<double>(v)), y(static_cast<double>(v))
		{}
		constexpr vec2(auto x, auto y) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y))
		{}
		constexpr vec2(const auto& other) noexcept :
			x(static_cast<double>(other.x)), y(static_cast<double>(other.y))
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
		inline vec2 make_normalized() const noexcept
		{
			double mag = magnitude();
			if (mag == 0)
			{
				return { 1, 0 };
			}
			else
			{
				return { x / mag, y / mag};
			}
		}

		inline vec2& scale(double d) noexcept
		{
			normalize();
			multiply(d);
		}
		inline vec2 make_scaled(double d) const noexcept
		{
			double mag = magnitude();
			if (mag == 0)
			{
				return { 1 * d, 0 };
			}
			else
			{
				return { (x / mag) * d, (y / mag) * d };
			}
		}
		inline vec2 operator%(double d) const noexcept
		{
			return make_scaled(d);
		}

		constexpr double dot(vec2 v) const noexcept
		{
			return x * v.x + y * v.y;
		}
		constexpr double cross(vec2 v) const noexcept
		{
			return x * v.y - y * v.x;
		}
	};

	struct vec3
	{
		double x{}, y{}, z{};

		static constexpr size_t size() noexcept { return 3; }

		constexpr vec3() noexcept {}
		constexpr vec3(const vec3& other) noexcept :
			x(other.x), y(other.y), z(other.z)
		{}

		constexpr vec3(auto v) noexcept :
			x(static_cast<double>(v)), y(static_cast<double>(v))
		{}
		constexpr vec3(auto x, auto y) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y))
		{}
		constexpr vec3(auto x, auto y, auto z) noexcept :
			x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z))
		{}
		constexpr vec3(const auto& other) noexcept :
			x(static_cast<double>(other.x)), y(static_cast<double>(other.y)), z(static_cast<double>(other.z))
		{}
		constexpr vec3(const vec2& other) noexcept :
			x(other.x), y(other.y)
		{}

		constexpr double operator[](size_t index) const noexcept
		{
			if (index % 3 == 0) return x;
			else if (index % 3 == 1) return y;
			else return z;
		}
		constexpr double& operator[](size_t index) noexcept
		{
			if (index % 3 == 0) return x;
			else if (index % 3 == 1) return y;
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
				x = 1;
				y = 0;
				z = 0;
				return *this;
			}
			else
			{
				return divide(mag);
			}
		}
		inline vec3 make_normalized() const noexcept
		{
			double mag = magnitude();
			if (mag == 0)
			{
				return { 1, 0, 0 };
			}
			else
			{
				return { x / mag, y / mag, z / mag };
			}
		}

		inline vec3& scale(double d) noexcept
		{
			normalize();
			multiply(d);
		}
		inline vec3 make_scaled(double d) const noexcept
		{
			double mag = magnitude();
			if (mag == 0)
			{
				return { 1 * d, 0, 0 };
			}
			else
			{
				return { (x / mag) * d, (y / mag) * d, (z / mag) * d};
			}
		}
		inline vec3 operator%(double d) const noexcept
		{
			make_scaled(d);
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

	constexpr std::array<double, 2> to_array(const vec2& v)
	{
		return { v.x, v.y };
	}
	
	constexpr std::array<double, 3> to_array(const vec3& v)
	{
		return { v.x, v.y, v.z };
	}
	
	inline std::string to_string(const vec2& v)
	{
		return std::format("( x : {}, y : {} )", v.x, v.y);
	}
	
	inline std::string to_string(const vec3& v)
	{
		return std::format("( x : {}, y : {}, z : {} )", v.x, v.y, v.z);
	}

	inline std::ostream& operator<<(std::ostream& os, const vec2& v)
	{
		return os << to_string(v);
	}
	
	inline std::ostream& operator<<(std::ostream& os, const vec3& v)
	{
		return os << to_string(v);
	}
}

#endif