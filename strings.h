#pragma once

#include <stdbool.h>
#include <string.h>

typedef struct {
	size_t len;
	const char *data;
} String;

typedef String Str;

// ========
// Utils
// ========
#define STR(s) (Str){.len = strlen(s), .data = s}
#define STRING(s) (String){.len = strlen(s), .data = s}

#define STR_FMT "%.*s"
#define STR_ARG(s) s.len, s.data

#define STR_FOR(s, i) for (size_t i = 0; i<s.len; i++)

static const char WHITESPACE[] = " \r\t\n\0";

static bool is_whitespace(char c);

// ========
// String
// ========
static String string_from_cstr(const char *cstr);

static size_t string_len(String s);

static bool string_startswith_str(String s, Str slice);

static Str string_to_str(String s);

// ========
// Str
// ========
static Str str_trim_left(Str s);

static Str str_trim_right(Str s);

static Str str_trim(Str s);

static size_t str_len(Str s);

static int str_split(Str s, char delim, Str *out, int out_size);

static int str_split_str(Str s, Str delim, Str *out, int out_size);

static bool str_eq(Str a, Str b);

// ========
// Utils
// ========
static bool is_whitespace(const char c) {
	for (size_t i = 0; i < sizeof(WHITESPACE); i++) {
		if (c == WHITESPACE[i]) return true;
	}

	return false;
}

// ========
// String
// ========
static String string_from_cstr(const char *cstr) {
	return (String){.len = strlen(cstr), .data = cstr};
}

static size_t string_len(const String s) {
	return s.len;
}

static bool string_startswith_str(const String s, const Str slice) {
	if (s.len < slice.len) return false;
	return memcmp(s.data, &slice.data, slice.len) == 0;
}

static Str string_to_str(const String s) {
	return (Str){.len = s.len, .data = s.data};
}

// ========
// Str
// ========
static Str str_trim_left(Str s) {
	for (size_t i = 0; i < s.len; i++) {
		if (is_whitespace(s.data[i])) {
			s.data++;
			s.len--;
		}
	}

	return s;
}

static Str str_trim_right(Str s) {
	for (size_t i = s.len - 1; i > 0; i--) {
		if (is_whitespace(s.data[i])) {
			s.len--;
		}
	}

	return s;
}

static Str str_trim(const Str s) {
	return str_trim_right(str_trim_left(s));
}

static size_t str_len(const Str s) {
	return s.len;
}

static Str str_copy(const Str s) {
	return s;
}

static bool str_eq(const Str a, const Str b) {
	if (a.len != b.len) return false;
	return memcmp(a.data, b.data, a.len) == 0;
}


static int str_split(const Str s, const char delim, Str *out, int out_size) {
	int found = 0;
	size_t last_split = 0;
	size_t len = 0;
	STR_FOR(s, i) {
		char curr = s.data[i];
		if (curr == delim || i == (s.len - 1)) {
			out[found] = (Str){.len = len, .data = s.data + last_split + (found > 0 ? 1 : 0)};
			found++;
			last_split = i;
			len = 0;
		}
		len++;
	}

	return found;
}
