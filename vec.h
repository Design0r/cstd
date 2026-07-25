#pragma once

#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#include <stdbool.h>
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
	float len() const;
	Vec2 normalize() const;
	Vec2 dir(Vec2 b) const;
	float angle() const;
	bool eq(Vec2 b, float delta) const;
	Vec2 maxf(float b) const;
	Vec2 invert() const;
	float dist_sq(Vec2) const;
	bool is_zero() const;
#endif
} Vec2;

typedef struct IVec2 {
	int x, y;
} IVec2;

typedef struct Vec3 {
	float x, y, z;

#ifdef __cplusplus
	float len() const;
	Vec3 normalize() const;
	Vec3 dir(Vec3 b) const;
	float angle_y() const;
	bool eq(Vec3 b, float delta) const;
	Vec3 maxf(float b) const;
	Vec3 invert() const;
	float dist_sq(Vec3) const;
	bool is_zero() const;
#endif
} Vec3;

// ==================================
// Vec 2
// ==================================

static inline Vec2 vec2(float x, float y);
static inline Vec2 vec2_add(Vec2 a, Vec2 b);
static inline Vec2 vec2_addf(Vec2 a, float b);
static inline Vec2 vec2_sub(Vec2 a, Vec2 b);
static inline Vec2 vec2_subf(Vec2 a, float b);
static inline Vec2 vec2_mul(Vec2 a, Vec2 b);
static inline Vec2 vec2_mulf(Vec2 a, float b);
static inline Vec2 vec2_div(Vec2 a, Vec2 b);
static inline Vec2 vec2_divf(Vec2 a, float b);
static inline float vec2_len(Vec2 v);
static inline Vec2 vec2_normalize(Vec2 a);
static inline Vec2 vec2_dir(Vec2 a, Vec2 b);
static inline float vec2_angle(Vec2 a);
static inline bool vec2_eq(Vec2 a, Vec2 b, float delta);
static inline Vec2 vec2_max(Vec2 a, Vec2 b);
static inline Vec2 vec2_maxf(Vec2 a, float b);
static inline Vec2 vec2_invert(Vec2 a);
static inline float vec2_dist_sq(Vec2 a, Vec2);
static inline bool vec2_is_zero(Vec2 a);

#ifdef __cplusplus

inline float Vec2::len() const {
	return vec2_len(*this);
}

inline Vec2 Vec2::normalize() const {
	return vec2_normalize(*this);
}

inline Vec2 Vec2::dir(const Vec2 b) const {
	return vec2_dir(*this, b);
}

inline float Vec2::angle() const {
	return vec2_angle(*this);
}

inline bool Vec2::eq(const Vec2 b, const float delta) const {
	return vec2_eq(*this, b, delta);
}

inline Vec2 Vec2::maxf(const float b) const {
	return vec2_maxf(*this, b);
}

inline Vec2 Vec2::invert() const {
	return vec2_invert(*this);
}

inline float Vec2::dist_sq(const Vec2 b) const {
	return vec2_dist_sq(*this, b);
}

inline bool Vec2::is_zero() const {
	return vec2_is_zero(*this);
}

static inline Vec2 operator+(Vec2 a, Vec2 b);
static inline Vec2 operator+(Vec2 a, float b);
static inline Vec2 operator+(float a, Vec2 b);
static inline Vec2&operator+=(Vec2&a, Vec2 b);
static inline Vec2&operator+=(Vec2&a, float b);

static inline Vec2 operator-(Vec2 a, Vec2 b);
static inline Vec2&operator-=(Vec2&a, Vec2 b);

static inline Vec2 operator *(Vec2 a, Vec2 b);
static inline Vec2 operator *(Vec2 a, float b);
static inline Vec2 operator *(float a, Vec2 b);
static inline Vec2&operator*=(Vec2&a, Vec2 b);
static inline Vec2&operator*=(Vec2&a, float b);

static inline Vec2 operator/(Vec2 a, Vec2 b);
static inline Vec2 operator/(Vec2 a, float b);
static inline Vec2 operator/(float a, Vec2 b);
static inline Vec2&operator/=(Vec2&a, Vec2 b);
static inline Vec2&operator/=(Vec2&a, float b);
#endif

// ==================================
// IVec 2
// ==================================

static inline IVec2 ivec2(int x, int y);
static inline IVec2 vec2_to_ivec2(Vec2 a);
static inline Vec2 ivec2_to_vec2(IVec2 a);

// ==================================
// Vec 3
// ==================================

static inline Vec3 vec3(float x, float y, float z);
static inline Vec3 vec3_add(Vec3 a, Vec3 b);
static inline Vec3 vec3_addf(Vec3 a, float b);
static inline Vec3 vec3_sub(Vec3 a, Vec3 b);
static inline Vec3 vec3_subf(Vec3 a, float b);
static inline Vec3 vec3_mul(Vec3 a, Vec3 b);
static inline Vec3 vec3_mulf(Vec3 a, float b);
static inline Vec3 vec3_div(Vec3 a, Vec3 b);
static inline Vec3 vec3_divf(Vec3 a, float b);
static inline Vec3 vec3_max(Vec3 a, float b);
static inline Vec3 vec3_maxf(Vec3 a, float b);
static inline Vec3 vec3_invert(Vec3 a);
static inline float vec3_dist_sq(Vec3 a, Vec3 b);
static inline float vec3_len(Vec3 a);
static inline Vec3 vec3_normalize(Vec3 a);
static inline Vec3 vec3_dir(Vec3 a, Vec3 b);
static inline float vec3_angle_y(Vec3 a);
static inline bool vec3_eq(Vec3 a, Vec3 b, float delta);
static inline bool vec3_is_zero(Vec3 a);

#ifdef __cplusplus

inline float Vec3::len() const {
	return vec3_len(*this);
}

inline Vec3 Vec3::normalize() const {
	return vec3_normalize(*this);
}

inline Vec3 Vec3::dir(const Vec3 b) const {
	return vec3_dir(*this, b);
}

inline float Vec3::angle_y() const {
	return vec3_angle_y(*this);
}

inline bool Vec3::eq(const Vec3 b, const float delta) const {
	return vec3_eq(*this, b, delta);
}

inline Vec3 Vec3::maxf(const float b) const {
	return vec3_maxf(*this, b);
}

inline Vec3 Vec3::invert() const {
	return vec3_invert(*this);
}

inline float Vec3::dist_sq(const Vec3 b) const {
	return vec3_dist_sq(*this, b);
}

inline bool Vec3::is_zero() const {
	return vec3_is_zero(*this);
}

static inline Vec3 operator+(Vec3 a, Vec3 b);
static inline Vec3 operator+(Vec3 a, float b);
static inline Vec3 operator+(float a, Vec3 b);
static inline Vec3&operator+=(Vec3&a, Vec3 b);
static inline Vec3&operator+=(Vec3&a, float b);

static inline Vec3 operator-(Vec3 a, Vec3 b);
static inline Vec3&operator-=(Vec3&a, Vec3 b);

static inline Vec3 operator *(Vec3 a, Vec3 b);
static inline Vec3 operator *(Vec3 a, float b);
static inline Vec3 operator *(float a, Vec3 b);
static inline Vec3&operator*=(Vec3&a, Vec3 b);
static inline Vec3&operator*=(Vec3&a, float b);

static inline Vec3 operator/(Vec3 a, Vec3 b);
static inline Vec3 operator/(Vec3 a, float b);
static inline Vec3 operator/(float a, Vec3 b);
static inline Vec3&operator/=(Vec3&a, Vec3 b);
static inline Vec3&operator/=(Vec3&a, float b);
#endif

// ==================================
// Vec 2
// ==================================

static inline Vec2 vec2(const float x, const float y) { return (Vec2){.x = x, .y = y}; };
static inline Vec2 vec2_add(Vec2 a, Vec2 b) { return vec2(a.x + b.x, a.y + b.y); }
static inline Vec2 vec2_addf(Vec2 a, float b) { return vec2(a.x + b, a.y + b); }
static inline Vec2 vec2_sub(Vec2 a, Vec2 b) { return vec2(a.x - b.x, a.y - b.y); }
static inline Vec2 vec2_subf(Vec2 a, float b) { return vec2(a.x - b, a.y - b); }

static inline Vec2 vec2_mul(Vec2 a, Vec2 b) {
	return vec2(a.x * b.x, a.y * b.y);
}

static inline Vec2 vec2_mulf(Vec2 a, float b) {
	return vec2(a.x * b, a.y * b);
}

static inline Vec2 vec2_div(Vec2 a, Vec2 b) {
	if (vec2_is_zero(b)) return vec2(0.0f, 0.0f);
	return vec2(a.x / b.x, a.y * b.y);
}

static inline Vec2 vec2_divf(Vec2 a, float b) {
	if (b == 0.0f) return vec2(0.0f, 0.0f);
	return vec2(a.x * b, a.y * b);
}

static inline float vec2_len(Vec2 v) { return sqrtf(v.x * v.x + v.y * v.y); }

static inline float vec2_dist_sq(const Vec2 a, const Vec2 b) {
	Vec2 diff = vec2_sub(a, b);
	return (diff.x * diff.x) + (diff.y * diff.y);
}

static inline Vec2 vec2_normalize(Vec2 a) {
	const float len = vec2_len(a);

	if (len <= 0.00001f) {
		return vec2(0.0f, 0.0f);
	}

	return vec2(a.x / len, a.y / len);
}

static inline Vec2 vec2_dir(Vec2 a, Vec2 b) { return vec2_normalize(vec2_sub(a, b)); }

static inline float vec2_angle(Vec2 a) { return atan2f(a.y, a.x); }

static inline bool vec2_eq(Vec2 a, Vec2 b, float delta) {
	Vec2 sub = vec2_sub(a, b);
	return fabsf(sub.x) < delta && fabsf(sub.y) < delta;
}

static inline Vec2 vec2_invert(Vec2 a) {
	return vec2_mulf(a, -1.0f);
}

static inline Vec2 vec2_max(Vec2 a, Vec2 b) {
	return vec2(MAX(a.x, b.x), MAX(a.y, b.y));
}

static inline Vec2 vec2_maxf(Vec2 a, float b) {
	return vec2(a.x > b ? a.x : b, a.y > b ? a.y : b);
}

static inline IVec2 vec2_to_ivec2(Vec2 a) {
	return ivec2((int) a.x, (int) a.y);
}

static inline bool vec2_is_zero(Vec2 a) {
	return (a.x == 0.0f && a.y == 0.0f);
}

#ifdef __cplusplus
static inline Vec2 operator+(Vec2 a, Vec2 b) {
	return vec2_add(a, b);
}

static inline Vec2 operator+(Vec2 a, float b) {
	return vec2_addf(a, b);
}

static inline Vec2 operator+(float a, Vec2 b) {
	return vec2_addf(b, a);
}

static inline Vec2&operator+=(Vec2&a, Vec2 b) {
	a.x += b.x;
	a.y += b.y;
	return a;
}

static inline Vec2&operator+=(Vec2&a, float b) {
	a.x += b;
	a.y += b;
	return a;
}

static inline Vec2 operator-(Vec2 a, Vec2 b) {
	return vec2_sub(a, b);
}

static inline Vec2&operator-=(Vec2&a, Vec2 b) {
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

static inline Vec2 operator *(Vec2 a, Vec2 b) {
	return vec2_mul(a, b);
}

static inline Vec2 operator *(Vec2 a, float b) {
	return vec2_mulf(a, b);
}

static inline Vec2 operator *(float a, Vec2 b) {
	return vec2_mulf(b, a);
}

static inline Vec2&operator*=(Vec2&a, Vec2 b) {
	a.x *= b.x;
	a.y *= b.y;
	return a;
}

static inline Vec2&operator*=(Vec2&a, float b) {
	a.x *= b;
	a.y *= b;
	return a;
}

static inline Vec2 operator/(Vec2 a, Vec2 b) {
	return vec2_div(a, b);
}

static inline Vec2 operator/(Vec2 a, float b) {
	return vec2_divf(a, b);
}

static inline Vec2 operator/(float a, Vec2 b) {
	return vec2_divf(b, a);
}

static inline Vec2&operator/=(Vec2&a, Vec2 b) {
	if (vec2_is_zero(b)) {
		a.x = 0;
		a.y = 0;
	} else {
		a.x /= b.x;
		a.y /= b.y;
	}

	return a;
}

static inline Vec2&operator/=(Vec2&a, float b) {
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

static inline IVec2 ivec2(const int x, const int y) { return (IVec2){.x = x, .y = y}; };

static inline Vec2 ivec2_to_vec2(IVec2 a) {
	return vec2((float) a.x, (float) a.y);
}

// ==================================
// Vec 3
// ==================================

static inline Vec3 vec3(const float x, const float y, const float z) {
	return (Vec3){.x = x, .y = y, .z = z};
};

static inline Vec3 vec3_add(const Vec3 a, const Vec3 b) {
	return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

static inline Vec3 vec3_addf(const Vec3 a, const float b) {
	return vec3(a.x + b, a.y + b, a.z + b);
}

static inline Vec3 vec3_sub(const Vec3 a, const Vec3 b) {
	return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

static inline Vec3 vec3_subf(const Vec3 a, const float b) {
	return vec3(a.x - b, a.y - b, a.z - b);
}

static inline Vec3 vec3_mul(const Vec3 a, const Vec3 b) {
	return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

static inline Vec3 vec3_mulf(const Vec3 a, const float b) {
	return vec3(a.x * b, a.y * b, a.z * b);
}

static inline Vec3 vec3_div(const Vec3 a, const Vec3 b) {
	if (vec3_is_zero(b)) return vec3(0.0f, 0.0f, 0.0f);
	return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

static inline Vec3 vec3_divf(const Vec3 a, const float b) {
	if (b == 0.0f) return vec3(0.0f, 0.0f, 0.0f);
	return vec3(a.x / b, a.y / b, a.z / b);
}

static inline Vec3 vec3_max(const Vec3 a, const float b) {
	return vec3(a.x > b ? a.x : b, a.y > b ? a.y : b, a.z > b ? a.z : b);
}

static inline float vec3_len(const Vec3 a) {
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

static inline Vec3 vec3_normalize(Vec3 a) {
	const float len = vec3_len(a);

	if (len <= 0.00001f) {
		return vec3(0.0f, 0.0f, 0.0f);
	}

	return vec3(a.x / len, a.y / len, a.z / len);
}

static inline Vec3 vec3_dir(const Vec3 a, Vec3 b) { return vec3_normalize(vec3_sub(a, b)); }

static inline float vec3_angle_y(Vec3 a) { return atan2f(a.x, a.z); }

static inline float vec3_dot(const Vec3 a, const Vec3 b) {
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static inline bool vec3_eq(Vec3 a, Vec3 b, float delta) {
	Vec3 sub = vec3_sub(a, b);
	return fabsf(sub.x) < delta && fabsf(sub.y) < delta && fabs(sub.z) < delta;
}

static inline bool vec3_is_zero(Vec3 a) {
	return (a.x == 0.0f && a.y == 0.0f && a.z == 0.0f);
}

static inline Vec3 vec3_maxf(Vec3 a, float b) {
	return vec3(MAX(a.x, b), MAX(a.y, b), MAX(a.z, b));
}

static inline Vec3 vec3_invert(Vec3 a) {
	return vec3(-a.x, -a.y, -a.z);
}

static inline float vec3_dist_sq(Vec3 a, Vec3 b) {
	Vec3 diff = vec3_sub(a, b);
	return (diff.x * diff.x) + (diff.y * diff.y) + (diff.z * diff.z);
}

#ifdef __cplusplus
static inline Vec3 operator+(Vec3 a, Vec3 b) {
	return vec3_add(a, b);
}

static inline Vec3 operator+(Vec3 a, float b) {
	return vec3_addf(a, b);
}

static inline Vec3 operator+(float a, Vec3 b) {
	return vec3_addf(b, a);
}

static inline Vec3&operator+=(Vec3&a, Vec3 b) {
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}

static inline Vec3&operator+=(Vec3&a, float b) {
	a.x += b;
	a.y += b;
	a.z += b;
	return a;
}

static inline Vec3 operator-(Vec3 a, Vec3 b) {
	return vec3_sub(a, b);
}

static inline Vec3&operator-=(Vec3&a, Vec3 b) {
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

static inline Vec3 operator *(Vec3 a, Vec3 b) {
	return vec3_mul(a, b);
}

static inline Vec3 operator *(Vec3 a, float b) {
	return vec3_mulf(a, b);
}

static inline Vec3 operator *(float a, Vec3 b) {
	return vec3_mulf(b, a);
}

static inline Vec3&operator*=(Vec3&a, Vec3 b) {
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}

static inline Vec3&operator*=(Vec3&a, float b) {
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return a;
}

static inline Vec3 operator/(Vec3 a, Vec3 b) {
	return vec3_div(a, b);
}

static inline Vec3 operator/(Vec3 a, float b) {
	return vec3_divf(a, b);
}

static inline Vec3 operator/(float a, Vec3 b) {
	return vec3_divf(b, a);
}

static inline Vec3&operator/=(Vec3&a, Vec3 b) {
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

static inline Vec3&operator/=(Vec3&a, float b) {
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
