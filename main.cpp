#define STRINGS_IMPLEMENTATION
#include "strings.h"

#include <cstdio>

#include "vec.h"

int main() {
	Str s = str_from_cstr("hallo  , slkfsf  ");
	s.trim_left();

	Vec3 a = vec3(2.0f, 1.0f, 3.0f);
	Vec3 b = a * 2.0f;

	printf(VEC3_FMT"\n", VEC3_SPREAD(b));

	return 0;
}
