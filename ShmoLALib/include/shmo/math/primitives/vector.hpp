#ifndef ___SHMO_LA_PRIMATIVES_VECTOR_HPP___
#define ___SHMO_LA_PRIMATIVES_VECTOR_HPP___

#include <algorithm>
#include <array>
#include <cmath>
#include <stdexcept>

namespace shmo::math
{
	struct vector2
	{
		float x{}, y{};

		static constexpr size_t size() noexcept { return 2; }

		constexpr vector2() noexcept {}
		constexpr vector2(const vector2& other) noexcept :
			x(other.x), y(other.y)
		{}

		constexpr vector2(auto v) noexcept :
			x(static_cast<float>(v)), y(static_cast<float>(v))
		{}
		constexpr vector2(auto x, auto y) noexcept :
			x(static_cast<float>(x)), y(static_cast<float>(y))
		{}
		constexpr vector2(const auto& other) noexcept :
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

		constexpr vector2& set(const vector2& v) noexcept
		{
			x = v.x;
			y = v.y;
			return *this;
		}
		constexpr vector2& set(auto x, auto y) noexcept
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
			return *this;
		}
		constexpr vector2& operator=(const vector2& v) noexcept
		{
			return set(v);
		}

		constexpr vector2& add(const vector2& v) noexcept
		{
			x += v.x;
			y += v.y;
			return *this;
		}
		constexpr vector2& operator+=(const vector2& v) noexcept
		{
			return add(v);
		}
		constexpr vector2 operator+(const vector2& v) noexcept
		{
			return { x + v.x, y + v.y };
		}

		constexpr vector2& subtract(const vector2& v) noexcept
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}
		constexpr vector2& operator-=(const vector2& v) noexcept
		{
			return subtract(v);
		}
		constexpr vector2 operator-(const vector2& v) noexcept
		{
			return { x - v.x, y - v.y };
		}
	};

	struct vector3
	{
		float x{}, y{}, z{};

		static constexpr size_t size() noexcept { return 3; }

		constexpr vector3() noexcept {}
		constexpr vector3(const vector3& other) noexcept :
			x(other.x), y(other.y), z(other.z)
		{}

		constexpr vector3(auto v) noexcept :
			x(static_cast<float>(v)), y(static_cast<float>(v))
		{}
		constexpr vector3(auto x, auto y) noexcept :
			x(static_cast<float>(x)), y(static_cast<float>(y))
		{}
		constexpr vector3(auto x, auto y, auto z) noexcept :
			x(static_cast<float>(x)), y(static_cast<float>(y)), z(static_cast<float>(z))
		{}
		constexpr vector3(const auto& other) noexcept :
			x(static_cast<float>(other.x)), y(static_cast<float>(other.y)), z(static_cast<float>(other.z))
		{}
		constexpr vector3(const vector2& other) noexcept :
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

		constexpr vector3& set(const vector3& v) noexcept
		{
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		constexpr vector3& set(auto x, auto y, auto z) noexcept
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
			this->z = static_cast<float>(z);
			return *this;
		}
		constexpr vector3& operator=(const vector3& v) noexcept
		{
			return set(v);
		}

		constexpr vector3& add(const vector3& v) noexcept
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		constexpr vector3& operator+=(const vector3& v) noexcept
		{
			return add(v);
		}
		constexpr vector3 operator+(const vector3& v) noexcept
		{
			return { x + v.x, y + v.y, z + v.z };
		}

		constexpr vector3& subtract(const vector3& v) noexcept
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		constexpr vector3& operator-=(const vector3& v) noexcept
		{
			return subtract(v);
		}
		constexpr vector3 operator-(const vector3& v) noexcept
		{
			return { x - v.x, y - v.y, z - v.z };
		}
	};
}

#endif