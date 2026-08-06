#define CSTD_IMPLEMENTATION
#include "cstd.h"

#include <cstdio>


int main() {
	Str s = Str::from("hallo  , slkfsf  ");
	printf("original: |" STR_FMT "|\n", STR_ARG(s));
	Str trimmed = s.trim();
	printf("trimmed:  |" STR_FMT "|\n", STR_ARG(trimmed));

	Vec3 a = vec3(2.0f, 1.0f, 3.0f);
	Vec3 b = a * 2.0f;

	printf(VEC3_FMT"\n", VEC3_SPREAD(b));

	return 0;
}
