#ifndef ___SHMO_LA_PRIMATIVES_MAT4X4_HPP___
#define ___SHMO_LA_PRIMATIVES_MAT4X4_HPP___

#include "vec3.hpp"

namespace shmo::math
{
	struct mat4x4
	{
		union
		{
			struct
			{
				double c0r0, c0r1, c0r2, c0r3;
				double c1r0, c1r1, c1r2, c1r3;
				double c2r0, c2r1, c2r2, c2r3;
				double c3r0, c3r1, c3r2, c3r3;
			};
			double v[16]{};
		};

		static constexpr size_t size() noexcept { return 16; }

		constexpr mat4x4() noexcept {}
		constexpr mat4x4(const mat4x4& other) noexcept :
			c0r0(other.c0r0), c1r0(other.c1r0), c2r0(other.c2r0), c3r0(other.c3r0),
			c0r1(other.c0r1), c1r1(other.c1r1), c2r1(other.c2r1), c3r1(other.c3r1),
			c0r2(other.c0r2), c1r2(other.c1r2), c2r2(other.c2r2), c3r2(other.c3r2),
			c0r3(other.c0r3), c1r3(other.c1r3), c2r3(other.c2r3), c3r3(other.c3r3)
		{}

		constexpr mat4x4
		(
			auto c0r0, auto c1r0, auto c2r0, auto c3r0,
			auto c0r1, auto c1r1, auto c2r1, auto c3r1,
			auto c0r2, auto c1r2, auto c2r2, auto c3r2,
			auto c0r3, auto c1r3, auto c2r3, auto c3r3
		) noexcept :
			c0r0(static_cast<double>(c0r0)), c1r0(static_cast<double>(c1r0)), c2r0(static_cast<double>(c2r0)),  c3r0(static_cast<double>(c3r0)),
			c0r1(static_cast<double>(c0r1)), c1r1(static_cast<double>(c1r1)), c2r1(static_cast<double>(c2r1)),  c3r1(static_cast<double>(c3r1)),
			c0r2(static_cast<double>(c0r2)), c1r2(static_cast<double>(c1r2)), c2r2(static_cast<double>(c2r2)),  c3r2(static_cast<double>(c3r2)),
			c0r3(static_cast<double>(c0r3)), c1r3(static_cast<double>(c1r3)), c2r3(static_cast<double>(c2r3)),  c3r3(static_cast<double>(c3r3))
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

		constexpr mat4x4& set
		(
			auto c0r0, auto c1r0, auto c2r0, auto c3r0,
			auto c0r1, auto c1r1, auto c2r1, auto c3r1,
			auto c0r2, auto c1r2, auto c2r2, auto c3r2,
			auto c0r3, auto c1r3, auto c2r3, auto c3r3
		) noexcept
		{
			this->c0r0 = static_cast<double>(c0r0); this->c1r0 = static_cast<double>(c1r0); this->c2r0 = static_cast<double>(c2r0);	this->c3r0 = static_cast<double>(c3r0);
			this->c0r1 = static_cast<double>(c0r1); this->c1r1 = static_cast<double>(c1r1); this->c2r1 = static_cast<double>(c2r1);	this->c3r1 = static_cast<double>(c3r1);
			this->c0r2 = static_cast<double>(c0r2); this->c1r2 = static_cast<double>(c1r2); this->c2r2 = static_cast<double>(c2r2);	this->c3r2 = static_cast<double>(c3r2);
			this->c0r3 = static_cast<double>(c0r3); this->c1r3 = static_cast<double>(c1r3); this->c2r3 = static_cast<double>(c2r3);	this->c3r3 = static_cast<double>(c3r3);
			return *this;
		}

		constexpr mat4x4& set(const mat4x4& m) noexcept
		{
			for (size_t i = 0; i < size(); ++i)
			{
				v[i] = m[i];
			}
			return *this;
		}

		constexpr bool equals(const mat4x4& m) const noexcept
		{
			for (size_t i = 0; i < size(); ++i)
			{
				if (v[i] != m[i]) return false;
			}
			return true;
		}
		constexpr bool operator==(const mat4x4& m) const noexcept
		{
			return equals(m);
		}

		constexpr mat4x4& multiply(const mat4x4& m) noexcept
		{
			mat4x4 r;

			r.c0r0 = (c0r0 * m.c0r0) + (c1r0 * m.c0r1) + (c2r0 * m.c0r2) + (c3r0 * m.c0r3);
			r.c0r1 = (c0r1 * m.c0r0) + (c1r1 * m.c0r1) + (c2r1 * m.c0r2) + (c3r1 * m.c0r3);
			r.c0r2 = (c0r2 * m.c0r0) + (c1r2 * m.c0r1) + (c2r2 * m.c0r2) + (c3r2 * m.c0r3);
			r.c0r3 = (c0r3 * m.c0r0) + (c1r3 * m.c0r1) + (c2r3 * m.c0r2) + (c3r3 * m.c0r3);

			r.c1r0 = (c0r0 * m.c1r0) + (c1r0 * m.c1r1) + (c2r0 * m.c1r2) + (c3r0 * m.c1r3);
			r.c1r1 = (c0r1 * m.c1r0) + (c1r1 * m.c1r1) + (c2r1 * m.c1r2) + (c3r1 * m.c1r3);
			r.c1r2 = (c0r2 * m.c1r0) + (c1r2 * m.c1r1) + (c2r2 * m.c1r2) + (c3r2 * m.c1r3);
			r.c1r3 = (c0r3 * m.c1r0) + (c1r3 * m.c1r1) + (c2r3 * m.c1r2) + (c3r3 * m.c1r3);

			r.c2r0 = (c0r0 * m.c2r0) + (c1r0 * m.c2r1) + (c2r0 * m.c2r2) + (c3r0 * m.c2r3);
			r.c2r1 = (c0r1 * m.c2r0) + (c1r1 * m.c2r1) + (c2r1 * m.c2r2) + (c3r1 * m.c2r3);
			r.c2r2 = (c0r2 * m.c2r0) + (c1r2 * m.c2r1) + (c2r2 * m.c2r2) + (c3r2 * m.c2r3);
			r.c2r3 = (c0r3 * m.c2r0) + (c1r3 * m.c2r1) + (c2r3 * m.c2r2) + (c3r3 * m.c2r3);

			r.c3r0 = (c0r0 * m.c3r0) + (c1r0 * m.c3r1) + (c2r0 * m.c3r2) + (c3r0 * m.c3r3);
			r.c3r1 = (c0r1 * m.c3r0) + (c1r1 * m.c3r1) + (c2r1 * m.c3r2) + (c3r1 * m.c3r3);
			r.c3r2 = (c0r2 * m.c3r0) + (c1r2 * m.c3r1) + (c2r2 * m.c3r2) + (c3r2 * m.c3r3);
			r.c3r3 = (c0r3 * m.c3r0) + (c1r3 * m.c3r1) + (c2r3 * m.c3r2) + (c3r3 * m.c3r3);

			return set(r);
		}
		constexpr mat4x4& operator*=(const mat4x4& m) noexcept
		{
			return multiply(m);
		}
		constexpr mat4x4 operator*(const mat4x4& m) const noexcept
		{
			return mat4x4(*this).multiply(m);
		}

		constexpr vec3 forward(const vec3& v) noexcept
		{
			double x, y, z;

			x = (c0r0 * v.x) + (c1r0 * v.y) + (c2r0 * v.z) + (c3r0);
			y = (c0r1 * v.x) + (c1r1 * v.y) + (c2r1 * v.z) + (c3r1);
			z = (c0r2 * v.x) + (c1r2 * v.y) + (c2r2 * v.z) + (c3r2);

			return { x, y, z };
		}

		constexpr mat4x4& invert() noexcept
		{
			mat4x4 r;
			double inv[16]{}, det, idet;
			size_t i;

			inv[0] = 
				v[5] * v[10] * v[15] -
				v[5] * v[11] * v[14] -
				v[9] * v[6] * v[15] +
				v[9] * v[7] * v[14] +
				v[13] * v[6] * v[11] -
				v[13] * v[7] * v[10];

			inv[4] = 
				-v[4] * v[10] * v[15] +
				v[4] * v[11] * v[14] +
				v[8] * v[6] * v[15] -
				v[8] * v[7] * v[14] -
				v[12] * v[6] * v[11] +
				v[12] * v[7] * v[10];

			inv[8] = 
				v[4] * v[9] * v[15] -
				v[4] * v[11] * v[13] -
				v[8] * v[5] * v[15] +
				v[8] * v[7] * v[13] +
				v[12] * v[5] * v[11] -
				v[12] * v[7] * v[9];

			inv[12] = 
				-v[4] * v[9] * v[14] +
				v[4] * v[10] * v[13] +
				v[8] * v[5] * v[14] -
				v[8] * v[6] * v[13] -
				v[12] * v[5] * v[10] +
				v[12] * v[6] * v[9];

			inv[1] = 
				-v[1] * v[10] * v[15] +
				v[1] * v[11] * v[14] +
				v[9] * v[2] * v[15] -
				v[9] * v[3] * v[14] -
				v[13] * v[2] * v[11] +
				v[13] * v[3] * v[10];

			inv[5] = 
				v[0] * v[10] * v[15] -
				v[0] * v[11] * v[14] -
				v[8] * v[2] * v[15] +
				v[8] * v[3] * v[14] +
				v[12] * v[2] * v[11] -
				v[12] * v[3] * v[10];

			inv[9] =
				-v[0] * v[9] * v[15] +
				v[0] * v[11] * v[13] +
				v[8] * v[1] * v[15] -
				v[8] * v[3] * v[13] -
				v[12] * v[1] * v[11] +
				v[12] * v[3] * v[9];

			inv[13] = 
				v[0] * v[9] * v[14] -
				v[0] * v[10] * v[13] -
				v[8] * v[1] * v[14] +
				v[8] * v[2] * v[13] +
				v[12] * v[1] * v[10] -
				v[12] * v[2] * v[9];

			inv[2] = 
				v[1] * v[6] * v[15] -
				v[1] * v[7] * v[14] -
				v[5] * v[2] * v[15] +
				v[5] * v[3] * v[14] +
				v[13] * v[2] * v[7] -
				v[13] * v[3] * v[6];

			inv[6] = 
				-v[0] * v[6] * v[15] +
				v[0] * v[7] * v[14] +
				v[4] * v[2] * v[15] -
				v[4] * v[3] * v[14] -
				v[12] * v[2] * v[7] +
				v[12] * v[3] * v[6];

			inv[10] = 
				v[0] * v[5] * v[15] -
				v[0] * v[7] * v[13] -
				v[4] * v[1] * v[15] +
				v[4] * v[3] * v[13] +
				v[12] * v[1] * v[7] -
				v[12] * v[3] * v[5];

			inv[14] = 
				-v[0] * v[5] * v[14] +
				v[0] * v[6] * v[13] +
				v[4] * v[1] * v[14] -
				v[4] * v[2] * v[13] -
				v[12] * v[1] * v[6] +
				v[12] * v[2] * v[5];

			inv[3] =
				-v[1] * v[6] * v[11] +
				v[1] * v[7] * v[10] +
				v[5] * v[2] * v[11] -
				v[5] * v[3] * v[10] -
				v[9] * v[2] * v[7] +
				v[9] * v[3] * v[6];

			inv[7] = 
				v[0] * v[6] * v[11] -
				v[0] * v[7] * v[10] -
				v[4] * v[2] * v[11] +
				v[4] * v[3] * v[10] +
				v[8] * v[2] * v[7] -
				v[8] * v[3] * v[6];

			inv[11] = 
				-v[0] * v[5] * v[11] +
				v[0] * v[7] * v[9] +
				v[4] * v[1] * v[11] -
				v[4] * v[3] * v[9] -
				v[8] * v[1] * v[7] +
				v[8] * v[3] * v[5];

			inv[15] = 
				v[0] * v[5] * v[10] -
				v[0] * v[6] * v[9] -
				v[4] * v[1] * v[10] +
				v[4] * v[2] * v[9] +
				v[8] * v[1] * v[6] -
				v[8] * v[2] * v[5];

			det = v[0] * inv[0] + v[1] * inv[4] + v[2] * inv[8] + v[3] * inv[12];

			idet = 1.0 / det;

			for (i = 0; i < size(); i++)
			{
				v[i] = inv[i] * det;
			}

			return *this;
		}

		constexpr mat4x4 operator!()
		{
			return mat4x4(*this).invert();
		}

		static constexpr mat4x4 identity() noexcept
		{
			return
			{
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
			};
		}

		static constexpr mat4x4 translation(auto x, auto y, auto z) noexcept
		{
			return
			{
				1, 0, 0, x,
				0, 1, 0, y,
				0, 0, 1, z,
				0, 0, 0, 1
			};
		}

		static constexpr mat4x4 translation(const vec3& v) noexcept
		{
			return translation(v.x, v.y, v.z);
		}

		static constexpr mat4x4 scale(auto x, auto y, auto z) noexcept
		{
			return
			{
				x, 0, 0, 0,
				0, y, 0, 0,
				0, 0, z, 0,
				0, 0, 0, 1
			};
		}

		static constexpr mat4x4 scale(const vec3& v) noexcept
		{
			return scale(v.x, v.y, v.z);
		}

		static inline mat4x4 rotation_yaw(auto theta) noexcept
		{
			double c = std::cos(static_cast<double>(theta));
			double s = std::sin(static_cast<double>(theta));

			return
			{
				1, 0, 0, 0,
				0, c, -s, 0,
				0, s, c, 0,
				0, 0, 0, 1
			};
		}
		
		static inline mat4x4 rotation_pitch(auto theta) noexcept
		{
			double c = std::cos(static_cast<double>(theta));
			double s = std::sin(static_cast<double>(theta));

			return
			{
				c, 0, s, 0,
				0, 1, 0, 0,
				-s, 0, c, 0,
				0, 0, 0, 1
			};
		}
		
		static inline mat4x4 rotation_roll(auto theta) noexcept
		{
			double c = std::cos(static_cast<double>(theta));
			double s = std::sin(static_cast<double>(theta));

			return
			{
				c, -s, 0, 0,
				s, c, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
			};
		}

		static inline mat4x4 rotation(auto yaw, auto pitch, auto roll)
		{
			return rotation_roll(roll).multiply(rotation_pitch(pitch)).multiply(rotation_yaw(yaw));
		}
		static inline mat4x4 rotation(const vec3& v)
		{
			return rotation(v.x, v.y, v.z);
		}

	};

	constexpr std::array<double, 16> to_array(const mat4x4& m)
	{
		return { m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15] };
	}

	inline std::string to_string(const mat4x4& m)
	{
		return std::format
		(
			"| {:10f} {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} {:10f} |\n| {:10f} {:10f} {:10f} {:10f} |",
			m.c0r0, m.c1r0, m.c2r0,	m.c3r0,
			m.c0r1, m.c1r1, m.c2r1,	m.c3r1,
			m.c0r2, m.c1r2, m.c2r2,	m.c3r2,
			m.c0r3, m.c1r3, m.c2r3,	m.c3r3
		);
	}

	inline std::ostream& operator<<(std::ostream& os, const mat4x4& m)
	{
		return os << to_string(m);
	}
}


#endif