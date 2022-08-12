#ifndef ___SHMO_LA_TRANSFORM2D_HPP___
#define ___SHMO_LA_TRANSFORM2D_HPP___

#include "primitives/mat3x3.hpp"

namespace shmo::math
{
	struct transform2d
	{
		mat3x3 translation, rotation, scale;

		static constexpr size_t size() noexcept { return 3; }

		transform2d() noexcept:
			translation(mat3x3::translation(0.0, 0.0)), rotation(mat3x3::rotation(0)), scale(mat3x3::scale(1.0, 1.0))
		{}
		
		constexpr transform2d(const transform2d& other) noexcept:
			translation(other.translation), rotation(other.rotation), scale(other.scale)
		{}

		transform2d(const vec2& translation, auto rotation = 0, const vec2& scale = { 1.0, 1.0 }) noexcept :
			translation(mat3x3::translation(translation)), rotation(mat3x3::rotation(rotation)), scale(mat3x3::scale(scale))
		{}

		constexpr bool equals(const transform2d& trn) const noexcept
		{
			return translation == trn.translation && rotation == trn.rotation && scale == trn.scale;
		}
		constexpr bool operator==(const transform2d& trn) const noexcept
		{
			return equals(trn);
		}
		constexpr bool operator!=(const transform2d& trn) const noexcept
		{
			return !equals(trn);
		}

		constexpr mat3x3 result() const noexcept
		{
			return translation * rotation * scale;
		}

		constexpr mat3x3 inverse() const noexcept
		{
			return ~result();
		}

		inline transform2d& set(const vec2& translation, double rotation = 0, const vec2& scale = { 1.0, 1.0 }) noexcept
		{
			this->translation = mat3x3::translation(translation);
			this->rotation = mat3x3::rotation(rotation);
			this->scale = mat3x3::scale(scale);
			return *this;
		}
		
		constexpr transform2d& set(const transform2d& trn) noexcept
		{
			translation = trn.translation;
			rotation = trn.rotation;
			scale = trn.scale;
			return *this;
		}

		constexpr transform2d& set_translation(const vec2& translation) noexcept
		{
			this->translation = mat3x3::translation(translation);
			return *this;
		}
		constexpr transform2d& set_translation(auto x, auto y) noexcept
		{
			this->translation = mat3x3::translation(x, y);
			return *this;
		}
		
		constexpr transform2d& set_scale(const vec2& scale) noexcept
		{
			this->scale = mat3x3::scale(scale);
			return *this;
		}
		constexpr transform2d& set_scale(auto x, auto y) noexcept
		{
			this->scale = mat3x3::scale(x, y);
			return *this;
		}

		inline transform2d& set_rotation(auto theta) noexcept
		{
			this->rotation = mat3x3::rotation(theta);
			return *this;
		}

		constexpr vec2 translation_vector() const noexcept
		{
			return { translation.c2r0, translation.c2r1 };
		}
		
		constexpr vec2 scale_vector() const noexcept
		{
			return { scale.c0r0, scale.c1r1 };
		}

		inline double rotation_angle() const noexcept
		{
			return std::acos(rotation.c0r0);
		}
	};
}

#endif