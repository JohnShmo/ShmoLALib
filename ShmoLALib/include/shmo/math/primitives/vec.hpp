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
		float x{}, y{};

		static constexpr size_t size() noexcept { return 2; }

		constexpr vec2() noexcept {}
		constexpr vec2(const vec2& other) noexcept :
			x(other.x), y(other.y)
		{}

		constexpr vec2(auto v) noexcept :
			x(static_cast<float>(v)), y(static_cast<float>(v))
		{}
		constexpr vec2(auto x, auto y) noexcept :
			x(static_cast<float>(x)), y(static_cast<float>(y))
		{}
		constexpr vec2(const auto& other) noexcept :
			x(static_cast<float>(other.x)), y(static_cast<float>(other.y))
		{}

		constexpr float operator[](size_t index) const noexcept
		{
			if (index % 2 == 0) return x;
			else return y;
		}
		constexpr float& operator[](size_t index) noexcept
		{
			if (index % 2 == 0) return x;
			else return y;
		}

		constexpr const float* data() const noexcept { return &x; }
		constexpr float* data() noexcept { return &x; }

		constexpr const float* begin() const noexcept { return &x; }
		constexpr float* begin() noexcept { return &x; }

		constexpr const float* end() const noexcept { return (&y) + 1; }
		constexpr float* end() noexcept { return (&y) + 1; }

		constexpr vec2& set(const vec2& v) noexcept
		{
			x = v.x;
			y = v.y;
			return *this;
		}
		constexpr vec2& set(auto x, auto y) noexcept
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
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

		constexpr vec2& multiply(float f) noexcept
		{
			x *= f;
			y *= f;
			return *this;
		}
		constexpr vec2& operator*=(float f) noexcept
		{
			return multiply(f);
		}
		constexpr vec2 operator*(float f) const noexcept
		{
			return { x * f, y * f };
		}
		
		constexpr vec2& divide(float f) noexcept
		{
			x /= f;
			y /= f;
			return *this;
		}
		constexpr vec2& operator/=(float f) noexcept
		{
			return divide(f);
		}
		constexpr vec2 operator/(float f) const noexcept
		{
			return { x / f, y / f };
		}

		constexpr float magnitude_sqr() const noexcept
		{
			return x * x + y * y;
		}
		inline float magnitude() const noexcept
		{
			return std::sqrtf(magnitude_sqr());
		}

		inline vec2& normalize() noexcept
		{
			float mag = magnitude();
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
		inline vec2 normalized() const noexcept
		{
			float mag = magnitude();
			if (mag == 0)
			{
				return { 1, 0 };
			}
			else
			{
				return { x / mag, y / mag };
			}
		}
	};

	struct vec3
	{
		float x{}, y{}, z{};

		static constexpr size_t size() noexcept { return 3; }

		constexpr vec3() noexcept {}
		constexpr vec3(const vec3& other) noexcept :
			x(other.x), y(other.y), z(other.z)
		{}

		constexpr vec3(auto v) noexcept :
			x(static_cast<float>(v)), y(static_cast<float>(v))
		{}
		constexpr vec3(auto x, auto y) noexcept :
			x(static_cast<float>(x)), y(static_cast<float>(y))
		{}
		constexpr vec3(auto x, auto y, auto z) noexcept :
			x(static_cast<float>(x)), y(static_cast<float>(y)), z(static_cast<float>(z))
		{}
		constexpr vec3(const auto& other) noexcept :
			x(static_cast<float>(other.x)), y(static_cast<float>(other.y)), z(static_cast<float>(other.z))
		{}
		constexpr vec3(const vec2& other) noexcept :
			x(other.x), y(other.y)
		{}

		constexpr float operator[](size_t index) const noexcept
		{
			if (index % 3 == 0) return x;
			else if (index % 3 == 1) return y;
			else return z;
		}
		constexpr float& operator[](size_t index) noexcept
		{
			if (index % 3 == 0) return x;
			else if (index % 3 == 1) return y;
			else return z;
		}

		constexpr const float* data() const noexcept { return &x; }
		constexpr float* data() noexcept { return &x; }

		constexpr const float* begin() const noexcept { return &x; }
		constexpr float* begin() noexcept { return &x; }

		constexpr const float* end() const noexcept { return (&z) + 1; }
		constexpr float* end() noexcept { return (&z) + 1; }

		constexpr vec3& set(const vec3& v) noexcept
		{
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		constexpr vec3& set(auto x, auto y, auto z) noexcept
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
			this->z = static_cast<float>(z);
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

		constexpr vec3& multiply(float f) noexcept
		{
			x *= f;
			y *= f;
			z *= f;
			return *this;
		}
		constexpr vec3& operator*=(float f) noexcept
		{
			return multiply(f);
		}
		constexpr vec3 operator*(float f) const noexcept
		{
			return { x * f, y * f, z * f };
		}

		constexpr vec3& divide(float f) noexcept
		{
			x /= f;
			y /= f;
			z /= f;
			return *this;
		}
		constexpr vec3& operator/=(float f) noexcept
		{
			return divide(f);
		}
		constexpr vec3 operator/(float f) const noexcept
		{
			return { x / f, y / f, z / f };
		}

		constexpr float magnitude_sqr() const noexcept
		{
			return x * x + y * y + z * z;
		}
		inline float magnitude() const noexcept
		{
			return std::sqrtf(magnitude_sqr());
		}

		inline vec3& normalize() noexcept
		{
			float mag = magnitude();
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
		inline vec3 normalized() const noexcept
		{
			float mag = magnitude();
			if (mag == 0)
			{
				return { 1, 0, 0 };
			}
			else
			{
				return { x / mag, y / mag, z / mag };
			}
		}
	};

	constexpr std::array<float, 2> to_array(const vec2& v)
	{
		return { v.x, v.y };
	}
	
	constexpr std::array<float, 3> to_array(const vec3& v)
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