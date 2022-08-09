#ifndef ___SHMO_LA_PRIMATIVES_MAT3X3_HPP___
#define ___SHMO_LA_PRIMATIVES_MAT3X3_HPP___

#include "vec2.hpp"

namespace shmo::math
{
	struct mat3x3
	{
		union
		{
			struct
			{
				double c0r0, c0r1, c0r2;
				double c1r0, c1r1, c1r2;
				double c2r0, c2r1, c2r2;
			};
			double v[9]{};
		};

		static constexpr size_t size() noexcept { return 9; }

		constexpr mat3x3() noexcept {}
		constexpr mat3x3(const mat3x3& other) noexcept :
			c0r0(other.c0r0), c1r0(other.c1r0), c2r0(other.c2r0),
			c0r1(other.c0r1), c1r1(other.c1r1), c2r1(other.c2r1),
			c0r2(other.c0r2), c1r2(other.c1r2), c2r2(other.c2r2)
		{}

		constexpr mat3x3
		(
			auto c0r0, auto c1r0, auto c2r0,
			auto c0r1, auto c1r1, auto c2r1,
			auto c0r2, auto c1r2, auto c2r2
		) noexcept :
			c0r0(static_cast<double>(c0r0)), c1r0(static_cast<double>(c1r0)), c2r0(static_cast<double>(c2r0)),
			c0r1(static_cast<double>(c0r1)), c1r1(static_cast<double>(c1r1)), c2r1(static_cast<double>(c2r1)),
			c0r2(static_cast<double>(c0r2)), c1r2(static_cast<double>(c1r2)), c2r2(static_cast<double>(c2r2))
		{}

		constexpr double operator[](size_t index) const noexcept
		{
			return v[index % size()];
		}
		constexpr double& operator[](size_t index) noexcept
		{
			return v[index % size()];
		}

		constexpr const double* data() const noexcept { return &c0r0; }
		constexpr double* data() noexcept { return &c0r0; }

		constexpr const double* begin() const noexcept { return &c0r0; }
		constexpr double* begin() noexcept { return &c0r0; }

		constexpr const double* end() const noexcept { return (&c2r2) + 1; }
		constexpr double* end() noexcept { return (&c2r2) + 1; }

		constexpr mat3x3& set
		(
			auto c0r0, auto c1r0, auto c2r0,
			auto c0r1, auto c1r1, auto c2r1,
			auto c0r2, auto c1r2, auto c2r2
		) noexcept
		{
			this->c0r0 = static_cast<double>(c0r0); this->c1r0 = static_cast<double>(c1r0); this->c2r0 = static_cast<double>(c2r0);
			this->c0r1 = static_cast<double>(c0r1); this->c1r1 = static_cast<double>(c1r1); this->c2r1 = static_cast<double>(c2r1);
			this->c0r2 = static_cast<double>(c0r2); this->c1r2 = static_cast<double>(c1r2); this->c2r2 = static_cast<double>(c2r2);
			return *this;
		}

		constexpr mat3x3& set(const mat3x3& m) noexcept
		{
			for (size_t i = 0; i < size(); ++i)
			{
				v[i] = m[i];
			}
			return *this;
		}

		constexpr bool equals(const mat3x3& m) const noexcept
		{
			for (size_t i = 0; i < size(); ++i)
			{
				if (v[i] != m[i]) return false;
			}
			return true;
		}
		constexpr bool operator==(const mat3x3& m) const noexcept
		{
			return equals(m);
		}

		constexpr mat3x3& multiply(const mat3x3& m) noexcept
		{
			mat3x3 r;

			r.c0r0 = (c0r0 * m.c0r0) + (c1r0 * m.c0r1) + (c2r0 * m.c0r2);
			r.c0r1 = (c0r1 * m.c0r0) + (c1r1 * m.c0r1) + (c2r1 * m.c0r2);
			r.c0r2 = (c0r2 * m.c0r0) + (c1r2 * m.c0r1) + (c2r2 * m.c0r2);

			r.c1r0 = (c0r0 * m.c1r0) + (c1r0 * m.c1r1) + (c2r0 * m.c1r2);
			r.c1r1 = (c0r1 * m.c1r0) + (c1r1 * m.c1r1) + (c2r1 * m.c1r2);
			r.c1r2 = (c0r2 * m.c1r0) + (c1r2 * m.c1r1) + (c2r2 * m.c1r2);

			r.c2r0 = (c0r0 * m.c2r0) + (c1r0 * m.c2r1) + (c2r0 * m.c2r2);
			r.c2r1 = (c0r1 * m.c2r0) + (c1r1 * m.c2r1) + (c2r1 * m.c2r2);
			r.c2r2 = (c0r2 * m.c2r0) + (c1r2 * m.c2r1) + (c2r2 * m.c2r2);

			return set(r);
		}
		constexpr mat3x3& operator*=(const mat3x3& m) noexcept
		{
			return multiply(m);
		}
		constexpr mat3x3 operator*(const mat3x3& m) const noexcept
		{
			mat3x3 r = *this;
			return r.multiply(m);
		}

		constexpr vec2 forward(const vec2& v) noexcept
		{
			double x, y;

			x = (c0r0 * v.x) + (c1r0 * v.y) + (c2r0);
			y = (c0r1 * v.x) + (c1r1 * v.y) + (c2r1);
			
			return { x, y };
		}

		constexpr mat3x3& invert() noexcept
		{
			mat3x3 r;

			double det =
				c0r0 * (c1r1 * c2r2 - c1r2 * c2r1) -
				c1r0 * (c0r1 * c2r2 - c2r1 * c0r2) +
				c2r0 * (c0r1 * c1r2 - c1r1 * c0r2);

			double idet = 1.0 / det;

			r.c0r0 = (c1r1 * c2r2 - c1r2 * c2r1) * idet;
			r.c1r0 = (c2r0 * c1r2 - c1r0 * c2r2) * idet;
			r.c2r0 = (c1r0 * c2r1 - c2r0 * c1r1) * idet;

			r.c0r1 = (c2r1 * c0r2 - c0r1 * c2r2) * idet;
			r.c1r1 = (c0r0 * c2r2 - c2r0 * c0r2) * idet;
			r.c2r1 = (c0r1 * c2r0 - c0r0 * c2r1) * idet;

			r.c0r2 = (c0r1 * c1r2 - c0r2 * c1r1) * idet;
			r.c1r2 = (c0r2 * c1r0 - c0r0 * c1r2) * idet;
			r.c2r2 = (c0r0 * c1r1 - c0r1 * c1r0) * idet;

			return set(r);
		}

		constexpr mat3x3 operator!()
		{
			return mat3x3(*this).invert();
		}

		static constexpr mat3x3 identity() noexcept
		{
			return
			{
				1, 0, 0,
				0, 1, 0,
				0, 0, 1
			};
		}

		static constexpr mat3x3 translation(auto x, auto y) noexcept
		{
			return
			{
				1, 0, x,
				0, 1, y,
				0, 0, 1
			};
		}
		static constexpr mat3x3 translation(const vec2& v) noexcept
		{
			return translation(v.x, v.y);
		}

		static constexpr mat3x3 reflection() noexcept
		{
			return
			{
				-1, 0, 0,
				0, 1, 0,
				0, 0, 1
			};
		}

		static constexpr mat3x3 scale(auto x, auto y) noexcept
		{
			return
			{
				x, 0, 0,
				0, y, 0,
				0, 0, 1
			};
		}
		static constexpr mat3x3 scale(const vec2& v) noexcept
		{
			return scale(v.x, v.y);
		}

		static inline mat3x3 rotation(auto theta) noexcept
		{
			double c = std::cos(static_cast<double>(theta));
			double s = std::sin(static_cast<double>(theta));

			return
			{
				c, -s, 0,
				s, c, 0,
				0, 0, 1
			};
		}

		static constexpr mat3x3 shear(auto x, auto y) noexcept
		{
			return
			{
				1, x, 0,
				y, 1, 0,
				0, 0, 1
			};
		}
		static constexpr mat3x3 shear(const vec2& v) noexcept
		{
			return shear(v.x, v.y);
		}
	};

	constexpr std::array<double, 9> to_array(const mat3x3& m)
	{
		return { m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8] };
	}

	inline std::string to_string(const mat3x3& m)
	{
		return std::format
		(
			"| {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} |",
			m.c0r0, m.c1r0, m.c2r0,
			m.c0r1, m.c1r1, m.c2r1,
			m.c0r2, m.c1r2, m.c2r2
		);
	}

	inline std::ostream& operator<<(std::ostream& os, const mat3x3& m)
	{
		return os << to_string(m);
	}
}


#endif