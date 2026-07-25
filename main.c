#include <assert.h>
#define DA_INIT_CAP 2
#include <stdio.h>
#include "array.h"

#define STRINGS_IMPLEMENTATION
#include "vec.h"
#include "strings.h"

typedef struct {
	int *items;
	size_t length;
	size_t capacity;
} IntArray;

int main() {
	IntArray a = {0};

	for (size_t i = 0; i < 10; i++) {
		da_append(&a, i);
	}

	assert(a.length == 10);
	int val = da_pop(&a);
	assert(a.length == 9);
	printf("%d\n", val);

	da_free(a);

	printf("len: %zu, cap: %zu\n", a.length, a.capacity);

	String s = string_from_cstr("hallo was geht");
	Str test = STR("das ist ein test");
	Str out[10];
	int found = str_split(test, ' ', out, 10);

	for (int i = 0; i < found; i++) {
		printf("len: %zu:"STR_FMT"\n", out[i].len,STR_ARG(out[i]));
	}

	Vec3 v = vec3(2.0f, 1.0f, 3.0f);
	Vec3 b = vec3_mulf(v, 2.0f);

	printf(VEC3_FMT"\n", VEC3_SPREAD(b));

	return 0;
}
