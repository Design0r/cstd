#pragma once

#ifdef __cplusplus
#include <cmath>
#define VEC_INLINE inline
#define STRUCT_LIT(type) type
#else
#include <math.h>
#include <stdbool.h>
#define VEC_INLINE static inline
#define STRUCT_LIT(type) (type)
#endif

#if defined(__cplusplus) && __cplusplus >= 201703L
#define VEC_NODISCARD [[nodiscard]]
#elif !defined(__cplusplus) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#define VEC_NODISCARD [[nodiscard]]
#elif defined(__GNUC__) || defined(__clang__)
#define VEC_NODISCARD __attribute__((warn_unused_result))
#else
#define VEC_NODISCARD
#endif

#define VEC2_FMT "Vec2: x: %f, y: %f"
#define VEC2_SPREAD(vec) vec.x, vec.y

#define VEC3_FMT "Vec3: x: %f, y: %f, z: %f"
#define VEC3_SPREAD(vec) vec.x, vec.y, vec.z

#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#define MIN(x, y) ((x) < (y)) ? (x) : (y)

typedef struct Vec2 {
	float x, y;

#ifdef __cplusplus
	VEC_NODISCARD float len() const;
	VEC_NODISCARD Vec2 normalize() const;
	VEC_NODISCARD Vec2 dir(Vec2 b) const;
	VEC_NODISCARD float angle() const;
	VEC_NODISCARD bool eq(Vec2 b, float delta) const;
	VEC_NODISCARD Vec2 max(float b) const;
	VEC_NODISCARD Vec2 max(Vec2 b) const;
	VEC_NODISCARD Vec2 min(float b) const;
	VEC_NODISCARD Vec2 min(Vec2 b) const;
	VEC_NODISCARD Vec2 invert() const;
	VEC_NODISCARD float dist_sq(Vec2) const;
	VEC_NODISCARD bool is_zero() const;
#endif
} Vec2;

typedef struct IVec2 {
	int x, y;
} IVec2;

typedef struct Vec3 {
	float x, y, z;

#ifdef __cplusplus
	VEC_NODISCARD float len() const;
	VEC_NODISCARD Vec3 normalize() const;
	VEC_NODISCARD Vec3 dir(Vec3 b) const;
	VEC_NODISCARD float angle_y() const;
	VEC_NODISCARD bool eq(Vec3 b, float delta) const;
	VEC_NODISCARD Vec3 max(float b) const;
	VEC_NODISCARD Vec3 max(Vec3 b) const;
	VEC_NODISCARD Vec3 min(float b) const;
	VEC_NODISCARD Vec3 min(Vec3 b) const;
	VEC_NODISCARD Vec3 invert() const;
	VEC_NODISCARD float dist_sq(Vec3) const;
	VEC_NODISCARD bool is_zero() const;
#endif
} Vec3;

// ==================================
// Vec 2
// ==================================

VEC_INLINE Vec2 vec2(float x, float y);
VEC_INLINE Vec2 vec2_add(Vec2 a, Vec2 b);
VEC_INLINE Vec2 vec2_addf(Vec2 a, float b);
VEC_INLINE Vec2 vec2_sub(Vec2 a, Vec2 b);
VEC_INLINE Vec2 vec2_subf(Vec2 a, float b);
VEC_INLINE Vec2 vec2_mul(Vec2 a, Vec2 b);
VEC_INLINE Vec2 vec2_mulf(Vec2 a, float b);
VEC_INLINE Vec2 vec2_div(Vec2 a, Vec2 b);
VEC_INLINE Vec2 vec2_divf(Vec2 a, float b);
VEC_INLINE float vec2_len(Vec2 v);
VEC_INLINE Vec2 vec2_normalize(Vec2 a);
VEC_INLINE Vec2 vec2_dir(Vec2 a, Vec2 b);
VEC_INLINE float vec2_angle(Vec2 a);
VEC_INLINE bool vec2_eq(Vec2 a, Vec2 b, float delta);
VEC_INLINE Vec2 vec2_max(Vec2 a, Vec2 b);
VEC_INLINE Vec2 vec2_maxf(Vec2 a, float b);
VEC_INLINE Vec2 vec2_min(Vec2 a, Vec2 b);
VEC_INLINE Vec2 vec2_minf(Vec2 a, float b);
VEC_INLINE Vec2 vec2_invert(Vec2 a);
VEC_INLINE float vec2_dist_sq(Vec2 a, Vec2);
VEC_INLINE bool vec2_is_zero(Vec2 a);

#ifdef __cplusplus

VEC_INLINE float Vec2::len() const {
	return vec2_len(*this);
}

VEC_INLINE Vec2 Vec2::normalize() const {
	return vec2_normalize(*this);
}

VEC_INLINE Vec2 Vec2::dir(const Vec2 b) const {
	return vec2_dir(*this, b);
}

VEC_INLINE float Vec2::angle() const {
	return vec2_angle(*this);
}

VEC_INLINE bool Vec2::eq(const Vec2 b, const float delta) const {
	return vec2_eq(*this, b, delta);
}

VEC_INLINE Vec2 Vec2::max(const float b) const {
	return vec2_maxf(*this, b);
}

VEC_INLINE Vec2 Vec2::max(const Vec2 b) const {
	return vec2_max(*this, b);
}

VEC_INLINE Vec2 Vec2::min(const float b) const {
	return vec2_minf(*this, b);
}

VEC_INLINE Vec2 Vec2::min(const Vec2 b) const {
	return vec2_min(*this, b);
}

VEC_INLINE Vec2 Vec2::invert() const {
	return vec2_invert(*this);
}

VEC_INLINE float Vec2::dist_sq(const Vec2 b) const {
	return vec2_dist_sq(*this, b);
}

VEC_INLINE bool Vec2::is_zero() const {
	return vec2_is_zero(*this);
}

VEC_NODISCARD VEC_INLINE Vec2 operator+(Vec2 a, Vec2 b);
VEC_NODISCARD VEC_INLINE Vec2 operator+(Vec2 a, float b);
VEC_NODISCARD VEC_INLINE Vec2 operator+(float a, Vec2 b);
VEC_INLINE Vec2 &operator+=(Vec2 &a, Vec2 b);
VEC_INLINE Vec2 &operator+=(Vec2 &a, float b);

VEC_NODISCARD VEC_INLINE Vec2 operator-(Vec2 a, Vec2 b);
VEC_INLINE Vec2 &operator-=(Vec2 &a, Vec2 b);

VEC_NODISCARD VEC_INLINE Vec2 operator *(Vec2 a, Vec2 b);
VEC_NODISCARD VEC_INLINE Vec2 operator *(Vec2 a, float b);
VEC_NODISCARD VEC_INLINE Vec2 operator *(float a, Vec2 b);
VEC_INLINE Vec2 &operator*=(Vec2 &a, Vec2 b);
VEC_INLINE Vec2 &operator*=(Vec2 &a, float b);

VEC_NODISCARD VEC_INLINE Vec2 operator/(Vec2 a, Vec2 b);
VEC_NODISCARD VEC_INLINE Vec2 operator/(Vec2 a, float b);
VEC_NODISCARD VEC_INLINE Vec2 operator/(float a, Vec2 b);
VEC_INLINE Vec2 &operator/=(Vec2 &a, Vec2 b);
VEC_INLINE Vec2 &operator/=(Vec2 &a, float b);
#endif

// ==================================
// IVec 2
// ==================================

VEC_INLINE IVec2 ivec2(int x, int y);
VEC_INLINE IVec2 vec2_to_ivec2(Vec2 a);
VEC_INLINE Vec2 ivec2_to_vec2(IVec2 a);

// ==================================
// Vec 3
// ==================================

VEC_INLINE Vec3 vec3(float x, float y, float z);
VEC_INLINE Vec3 vec3_add(Vec3 a, Vec3 b);
VEC_INLINE Vec3 vec3_addf(Vec3 a, float b);
VEC_INLINE Vec3 vec3_sub(Vec3 a, Vec3 b);
VEC_INLINE Vec3 vec3_subf(Vec3 a, float b);
VEC_INLINE Vec3 vec3_mul(Vec3 a, Vec3 b);
VEC_INLINE Vec3 vec3_mulf(Vec3 a, float b);
VEC_INLINE Vec3 vec3_div(Vec3 a, Vec3 b);
VEC_INLINE Vec3 vec3_divf(Vec3 a, float b);
VEC_INLINE Vec3 vec3_max(Vec3 a, Vec3 b);
VEC_INLINE Vec3 vec3_maxf(Vec3 a, float b);
VEC_INLINE Vec3 vec3_min(Vec3 a, Vec3 b);
VEC_INLINE Vec3 vec3_minf(Vec3 a, float b);
VEC_INLINE Vec3 vec3_invert(Vec3 a);
VEC_INLINE float vec3_dist_sq(Vec3 a, Vec3 b);
VEC_INLINE float vec3_len(Vec3 a);
VEC_INLINE Vec3 vec3_normalize(Vec3 a);
VEC_INLINE Vec3 vec3_dir(Vec3 a, Vec3 b);
VEC_INLINE float vec3_angle_y(Vec3 a);
VEC_INLINE bool vec3_eq(Vec3 a, Vec3 b, float delta);
VEC_INLINE bool vec3_is_zero(Vec3 a);

#ifdef __cplusplus

VEC_INLINE float Vec3::len() const {
	return vec3_len(*this);
}

VEC_INLINE Vec3 Vec3::normalize() const {
	return vec3_normalize(*this);
}

VEC_INLINE Vec3 Vec3::dir(const Vec3 b) const {
	return vec3_dir(*this, b);
}

VEC_INLINE float Vec3::angle_y() const {
	return vec3_angle_y(*this);
}

VEC_INLINE bool Vec3::eq(const Vec3 b, const float delta) const {
	return vec3_eq(*this, b, delta);
}

VEC_INLINE Vec3 Vec3::max(const float b) const {
	return vec3_maxf(*this, b);
}

VEC_INLINE Vec3 Vec3::max(const Vec3 b) const {
	return vec3_max(*this, b);
}

VEC_INLINE Vec3 Vec3::min(const float b) const {
	return vec3_minf(*this, b);
}

VEC_INLINE Vec3 Vec3::min(const Vec3 b) const {
	return vec3_min(*this, b);
}

VEC_INLINE Vec3 Vec3::invert() const {
	return vec3_invert(*this);
}

VEC_INLINE float Vec3::dist_sq(const Vec3 b) const {
	return vec3_dist_sq(*this, b);
}

VEC_INLINE bool Vec3::is_zero() const {
	return vec3_is_zero(*this);
}

VEC_INLINE Vec3 operator+(Vec3 a, Vec3 b);
VEC_INLINE Vec3 operator+(Vec3 a, float b);
VEC_INLINE Vec3 operator+(float a, Vec3 b);
VEC_INLINE Vec3 &operator+=(Vec3 &a, Vec3 b);
VEC_INLINE Vec3 &operator+=(Vec3 &a, float b);

VEC_INLINE Vec3 operator-(Vec3 a, Vec3 b);
VEC_INLINE Vec3 &operator-=(Vec3 &a, Vec3 b);

VEC_INLINE Vec3 operator *(Vec3 a, Vec3 b);
VEC_INLINE Vec3 operator *(Vec3 a, float b);
VEC_INLINE Vec3 operator *(float a, Vec3 b);
VEC_INLINE Vec3 &operator*=(Vec3 &a, Vec3 b);
VEC_INLINE Vec3 &operator*=(Vec3 &a, float b);

VEC_INLINE Vec3 operator/(Vec3 a, Vec3 b);
VEC_INLINE Vec3 operator/(Vec3 a, float b);
VEC_INLINE Vec3 operator/(float a, Vec3 b);
VEC_INLINE Vec3 &operator/=(Vec3 &a, Vec3 b);
VEC_INLINE Vec3 &operator/=(Vec3 &a, float b);
#endif

// ==================================
// Vec 2
// ==================================

VEC_INLINE Vec2 vec2(const float x, const float y) {
	return STRUCT_LIT(Vec2){.x = x, .y = y};
};

VEC_INLINE Vec2 vec2_add(Vec2 a, Vec2 b) {
	return vec2(a.x + b.x, a.y + b.y);
}

VEC_INLINE Vec2 vec2_addf(Vec2 a, float b) {
	return vec2(a.x + b, a.y + b);
}

VEC_INLINE Vec2 vec2_sub(Vec2 a, Vec2 b) {
	return vec2(a.x - b.x, a.y - b.y);
}

VEC_INLINE Vec2 vec2_subf(Vec2 a, float b) {
	return vec2(a.x - b, a.y - b);
}

VEC_INLINE Vec2 vec2_mul(Vec2 a, Vec2 b) {
	return vec2(a.x * b.x, a.y * b.y);
}

VEC_INLINE Vec2 vec2_mulf(Vec2 a, float b) {
	return vec2(a.x * b, a.y * b);
}

VEC_INLINE Vec2 vec2_div(Vec2 a, Vec2 b) {
	if (vec2_is_zero(b)) return vec2(0.0f, 0.0f);
	return vec2(a.x / b.x, a.y * b.y);
}

VEC_INLINE Vec2 vec2_divf(Vec2 a, float b) {
	if (b == 0.0f) return vec2(0.0f, 0.0f);
	return vec2(a.x * b, a.y * b);
}

VEC_INLINE float vec2_len(Vec2 v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

VEC_INLINE Vec2 vec2_normalize(Vec2 a) {
	const float len = vec2_len(a);

	if (len <= 0.00001f) {
		return vec2(0.0f, 0.0f);
	}

	return vec2(a.x / len, a.y / len);
}

VEC_INLINE Vec2 vec2_dir(Vec2 a, Vec2 b) {
	return vec2_normalize(vec2_sub(a, b));
}

VEC_INLINE float vec2_angle(Vec2 a) {
	return atan2f(a.y, a.x);
}

VEC_INLINE bool vec2_eq(Vec2 a, Vec2 b, float delta) {
	Vec2 sub = vec2_sub(a, b);
	return fabsf(sub.x) < delta && fabsf(sub.y) < delta;
}

VEC_INLINE Vec2 vec2_max(Vec2 a, Vec2 b) {
	return vec2(MAX(a.x, b.x), MAX(a.y, b.y));
}

VEC_INLINE Vec2 vec2_maxf(Vec2 a, float b) {
	return vec2(MAX(a.x, b), MAX(a.y, b));
}

VEC_INLINE Vec2 vec2_min(Vec2 a, Vec2 b) {
	return vec2(MIN(a.x, b.x), MIN(a.y, b.y));
}

VEC_INLINE Vec2 vec2_minf(Vec2 a, float b) {
	return vec2(MIN(a.x, b), MIN(a.y, b));
}

VEC_INLINE Vec2 vec2_invert(Vec2 a) {
	return vec2_mulf(a, -1.0f);
}

VEC_INLINE float vec2_dist_sq(const Vec2 a, const Vec2 b) {
	Vec2 diff = vec2_sub(a, b);
	return (diff.x * diff.x) + (diff.y * diff.y);
}

VEC_INLINE bool vec2_is_zero(Vec2 a) {
	return (a.x == 0.0f && a.y == 0.0f);
}

VEC_INLINE IVec2 vec2_to_ivec2(Vec2 a) {
	return ivec2((int) a.x, (int) a.y);
}

#ifdef __cplusplus
VEC_INLINE Vec2 operator+(Vec2 a, Vec2 b) {
	return vec2_add(a, b);
}

VEC_INLINE Vec2 operator+(Vec2 a, float b) {
	return vec2_addf(a, b);
}

VEC_INLINE Vec2 operator+(float a, Vec2 b) {
	return vec2_addf(b, a);
}

VEC_INLINE Vec2 &operator+=(Vec2 &a, Vec2 b) {
	a.x += b.x;
	a.y += b.y;
	return a;
}

VEC_INLINE Vec2 &operator+=(Vec2 &a, float b) {
	a.x += b;
	a.y += b;
	return a;
}

VEC_INLINE Vec2 operator-(Vec2 a, Vec2 b) {
	return vec2_sub(a, b);
}

VEC_INLINE Vec2 &operator-=(Vec2 &a, Vec2 b) {
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

VEC_INLINE Vec2 operator *(Vec2 a, Vec2 b) {
	return vec2_mul(a, b);
}

VEC_INLINE Vec2 operator *(Vec2 a, float b) {
	return vec2_mulf(a, b);
}

VEC_INLINE Vec2 operator *(float a, Vec2 b) {
	return vec2_mulf(b, a);
}

VEC_INLINE Vec2 &operator*=(Vec2 &a, Vec2 b) {
	a.x *= b.x;
	a.y *= b.y;
	return a;
}

VEC_INLINE Vec2 &operator*=(Vec2 &a, float b) {
	a.x *= b;
	a.y *= b;
	return a;
}

VEC_INLINE Vec2 operator/(Vec2 a, Vec2 b) {
	return vec2_div(a, b);
}

VEC_INLINE Vec2 operator/(Vec2 a, float b) {
	return vec2_divf(a, b);
}

VEC_INLINE Vec2 operator/(float a, Vec2 b) {
	return vec2_divf(b, a);
}

VEC_INLINE Vec2 &operator/=(Vec2 &a, Vec2 b) {
	if (vec2_is_zero(b)) {
		a.x = 0;
		a.y = 0;
	} else {
		a.x /= b.x;
		a.y /= b.y;
	}

	return a;
}

VEC_INLINE Vec2 &operator/=(Vec2 &a, float b) {
	if (b == 0.0f) {
		a.x = 0;
		a.y = 0;
	} else {
		a.x /= b;
		a.y /= b;
	}

	return a;
}
#endif

// ==================================
// IVec 2
// ==================================

VEC_INLINE IVec2 ivec2(const int x, const int y) {
	return STRUCT_LIT(IVec2){.x = x, .y = y};
}

VEC_INLINE Vec2 ivec2_to_vec2(IVec2 a) {
	return vec2((float) a.x, (float) a.y);
}

// ==================================
// Vec 3
// ==================================

VEC_INLINE Vec3 vec3(const float x, const float y, const float z) {
	return STRUCT_LIT(Vec3){.x = x, .y = y, .z = z};
};

VEC_INLINE Vec3 vec3_add(const Vec3 a, const Vec3 b) {
	return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

VEC_INLINE Vec3 vec3_addf(const Vec3 a, const float b) {
	return vec3(a.x + b, a.y + b, a.z + b);
}

VEC_INLINE Vec3 vec3_sub(const Vec3 a, const Vec3 b) {
	return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

VEC_INLINE Vec3 vec3_subf(const Vec3 a, const float b) {
	return vec3(a.x - b, a.y - b, a.z - b);
}

VEC_INLINE Vec3 vec3_mul(const Vec3 a, const Vec3 b) {
	return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

VEC_INLINE Vec3 vec3_mulf(const Vec3 a, const float b) {
	return vec3(a.x * b, a.y * b, a.z * b);
}

VEC_INLINE Vec3 vec3_div(const Vec3 a, const Vec3 b) {
	if (vec3_is_zero(b)) return vec3(0.0f, 0.0f, 0.0f);
	return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

VEC_INLINE Vec3 vec3_divf(const Vec3 a, const float b) {
	if (b == 0.0f) return vec3(0.0f, 0.0f, 0.0f);
	return vec3(a.x / b, a.y / b, a.z / b);
}

VEC_INLINE Vec3 vec3_max(const Vec3 a, const Vec3 b) {
	return vec3(MAX(a.x, b.x), MAX(a.y, b.y), MAX(a.z, b.z));
}

VEC_INLINE Vec3 vec3_maxf(const Vec3 a, const float b) {
	return vec3(MAX(a.x, b), MAX(a.y, b), MAX(a.z, b));
}

VEC_INLINE Vec3 vec4_min(const Vec3 a, const Vec3 b) {
	return vec3(MIN(a.x, b.x), MIN(a.y, b.y), MIN(a.z, b.z));
}

VEC_INLINE Vec3 vec3_minf(const Vec3 a, const float b) {
	return vec3(MIN(a.x, b), MIN(a.y, b), MIN(a.z, b));
}

VEC_INLINE float vec3_len(const Vec3 a) {
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

VEC_INLINE Vec3 vec3_normalize(Vec3 a) {
	const float len = vec3_len(a);

	if (len <= 0.00001f) {
		return vec3(0.0f, 0.0f, 0.0f);
	}

	return vec3(a.x / len, a.y / len, a.z / len);
}

VEC_INLINE Vec3 vec3_dir(const Vec3 a, Vec3 b) { return vec3_normalize(vec3_sub(a, b)); }

VEC_INLINE float vec3_angle_y(Vec3 a) { return atan2f(a.x, a.z); }

VEC_INLINE float vec3_dot(const Vec3 a, const Vec3 b) {
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

VEC_INLINE bool vec3_eq(Vec3 a, Vec3 b, float delta) {
	Vec3 sub = vec3_sub(a, b);
	return fabsf(sub.x) < delta && fabsf(sub.y) < delta && fabsf(sub.z) < delta;
}

VEC_INLINE bool vec3_is_zero(Vec3 a) {
	return (a.x == 0.0f && a.y == 0.0f && a.z == 0.0f);
}

VEC_INLINE Vec3 vec3_invert(Vec3 a) {
	return vec3(-a.x, -a.y, -a.z);
}

VEC_INLINE float vec3_dist_sq(Vec3 a, Vec3 b) {
	Vec3 diff = vec3_sub(a, b);
	return (diff.x * diff.x) + (diff.y * diff.y) + (diff.z * diff.z);
}

#ifdef __cplusplus
VEC_INLINE Vec3 operator+(Vec3 a, Vec3 b) {
	return vec3_add(a, b);
}

VEC_INLINE Vec3 operator+(Vec3 a, float b) {
	return vec3_addf(a, b);
}

VEC_INLINE Vec3 operator+(float a, Vec3 b) {
	return vec3_addf(b, a);
}

VEC_INLINE Vec3 &operator+=(Vec3 &a, Vec3 b) {
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}

VEC_INLINE Vec3 &operator+=(Vec3 &a, float b) {
	a.x += b;
	a.y += b;
	a.z += b;
	return a;
}

VEC_INLINE Vec3 operator-(Vec3 a, Vec3 b) {
	return vec3_sub(a, b);
}

VEC_INLINE Vec3 &operator-=(Vec3 &a, Vec3 b) {
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

VEC_INLINE Vec3 operator *(Vec3 a, Vec3 b) {
	return vec3_mul(a, b);
}

VEC_INLINE Vec3 operator *(Vec3 a, float b) {
	return vec3_mulf(a, b);
}

VEC_INLINE Vec3 operator *(float a, Vec3 b) {
	return vec3_mulf(b, a);
}

VEC_INLINE Vec3 &operator*=(Vec3 &a, Vec3 b) {
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}

VEC_INLINE Vec3 &operator*=(Vec3 &a, float b) {
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return a;
}

VEC_INLINE Vec3 operator/(Vec3 a, Vec3 b) {
	return vec3_div(a, b);
}

VEC_INLINE Vec3 operator/(Vec3 a, float b) {
	return vec3_divf(a, b);
}

VEC_INLINE Vec3 operator/(float a, Vec3 b) {
	return vec3_divf(b, a);
}

VEC_INLINE Vec3 &operator/=(Vec3 &a, Vec3 b) {
	if (vec3_is_zero(b)) {
		a.x = 0;
		a.y = 0;
		a.z = 0;
	} else {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
	}

	return a;
}

VEC_INLINE Vec3 &operator/=(Vec3 &a, float b) {
	if (b == 0.0f) {
		a.x = 0;
		a.y = 0;
		a.z = 0;
	} else {
		a.x /= b;
		a.y /= b;
		a.z /= b;
	}

	return a;
}
#endif
