#ifndef ___SHMO_LA_COLOR_UTILS_HPP___
#define ___SHMO_LA_COLOR_UTILS_HPP___

#include "primitives.hpp"

namespace shmo::math
{
	constexpr vec3 rgb_to_vec3(uint8_t r, uint8_t g, uint8_t b) noexcept
	{
		return
		{
			static_cast<double>(r) / 255.0,
			static_cast<double>(g) / 255.0,
			static_cast<double>(b) / 255.0,
		};
	}

	constexpr void vec3_to_rgb(const vec3& v, uint8_t& o_r, uint8_t& o_g, uint8_t& o_b) noexcept
	{
		o_r = static_cast<uint8_t>(v.x * 255);
		o_g = static_cast<uint8_t>(v.y * 255);
		o_b = static_cast<uint8_t>(v.z * 255);
	}

	constexpr vec3 hex_to_vec3(uint32_t color) noexcept
	{
		uint8_t r = static_cast<uint8_t>((color / 256 / 256) % 256);
		uint8_t g = static_cast<uint8_t>((color / 256) % 256);
		uint8_t b = static_cast<uint8_t>((color) % 256);
		return rgb_to_vec3(r, g, b);
	}

	constexpr uint32_t vec3_to_hex(const vec3& v) noexcept
	{
		uint8_t r, g, b;
		vec3_to_rgb(v, r, g, b);
		uint32_t r32 = r * 256 * 256;
		uint32_t g32 = g * 256;
		uint32_t b32 = b;
		return r32 | g32 | b32;
	}

	constexpr vec4 rgba_to_vec4(uint8_t r, uint8_t g, uint8_t b, uint8_t a) noexcept
	{
		return
		{
			static_cast<double>(r) / 255.0,
			static_cast<double>(g) / 255.0,
			static_cast<double>(b) / 255.0,
			static_cast<double>(a) / 255.0
		};
	}

	constexpr void vec4_to_rgba(const vec4& v, uint8_t& o_r, uint8_t& o_g, uint8_t& o_b, uint8_t& o_a) noexcept
	{
		o_r = static_cast<uint8_t>(v.x * 255);
		o_g = static_cast<uint8_t>(v.y * 255);
		o_b = static_cast<uint8_t>(v.z * 255);
		o_a = static_cast<uint8_t>(v.w * 255);
	}

	constexpr vec4 hex_to_vec4(uint32_t color) noexcept
	{
		uint8_t r = static_cast<uint8_t>((color / 256 / 256 / 256) % 256);
		uint8_t g = static_cast<uint8_t>((color / 256 / 256      ) % 256);
		uint8_t b = static_cast<uint8_t>((color / 256            ) % 256);
		uint8_t a = static_cast<uint8_t>((color                  ) % 256);
		return rgba_to_vec4(r, g, b, a);
	}

	constexpr uint32_t vec4_to_hex(const vec4& v) noexcept
	{
		uint8_t r, g, b, a;
		vec4_to_rgba(v, r, g, b, a);
		uint32_t r32 = r * 256 * 256 * 256;
		uint32_t g32 = g * 256 * 256;
		uint32_t b32 = b * 256;
		uint32_t a32 = a;
		return r32 | g32 | b32 | a32;
	}
}

#endif