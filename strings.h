#pragma once


#include <string.h>

typedef struct {
	size_t len;
	const char *data;
} String;

typedef struct {
	size_t len;
	const char *data;
} Str;

// ========
// Utils
// ========
#define STR(s) (Str){.len = sizeof(s)-1, .data = s}
#define STRING(s) (String){.len = sizeof(s)-1, .data = s}

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

static void string_free(String s);


// ========
// Str
// ========
static Str str_from_cstr(const char *cstr);

static Str str_trim_left(Str s);

static Str str_trim_right(Str s);

static Str str_trim(Str s);

static size_t str_len(Str s);

static int str_split(Str s, char delim, Str *out, int out_size);

static int str_split_str(Str s, Str delim, Str *out, int out_size);

static bool str_eq(Str a, Str b);

static bool str_startswith_str(Str a, Str b);

static bool str_startswith_cstr(Str a, const char *cstr);

static String str_to_string(Str s);

static void str_to_cstr(Str s, char *buf);

static char *str_to_cstr_m(Str s);

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
	size_t len = strlen(cstr);
	char *new_data = (char *) malloc(len);
	memcpy(new_data, cstr, len);
	return (String){.len = len, .data = new_data};
}

static size_t string_len(const String s) {
	return s.len;
}

static bool string_startswith_str(const String s, const Str slice) {
	if (s.len < slice.len) return false;
	return memcmp(s.data, slice.data, slice.len) == 0;
}

static Str string_to_str(const String s) {
	return (Str)
	{
		.len = s.len, .data = s.data
	};
}

inline void string_free(String s) {
	free((void *) s.data);
}

// ========
// Str
// ========
static Str str_trim_left(Str s) {
	for (size_t i = 0; i < s.len; i++) {
		if (!is_whitespace(s.data[i])) break;
		s.data++;
		s.len--;
	}

	return s;
}

static Str str_trim_right(Str s) {
	for (size_t i = s.len - 1; i > 0; i--) {
		if (!is_whitespace(s.data[i])) break;
		s.len--;
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
	size_t start = 0;

	STR_FOR(s, i) {
		if (s.data[i] == delim) {
			if (i > start) {
				if (found >= out_size) return found;
				out[found++] = (Str){.len = i - start, .data = s.data + start};
			}
			start = i + 1;
		}
	}

	if (s.len > start && found < out_size) {
		out[found++] = (Str){.len = s.len - start, .data = s.data + start};
	}

	return found;
}

static Str str_from_cstr(const char *cstr) {
	return (Str)
	{
		.len = strlen(cstr), .data = cstr
	};
}

static bool str_startswith_str(const Str a, const Str b) {
	if (a.len < b.len) return false;
	return memcmp(a.data, b.data, b.len) == 0;
}

static bool str_startswith_cstr(Str a, const char *cstr) {
	size_t len = strlen(cstr);
	if (a.len < len) return false;
	return memcmp(a.data, cstr, len) == 0;
}

static String str_to_string(Str s) {
	char *new_data = (char *) malloc(s.len);
	memcpy(new_data, s.data, s.len);
	return (String){.len = s.len, .data = new_data};
}

static char *str_to_cstr_m(Str s) {
	char *new_data = (char *) malloc(s.len + 1);
	memcpy(new_data, s.data, s.len);
	new_data[s.len] = '\0';
	return new_data;
}

static void str_to_cstr(Str s, char *buf) {
	memcpy(buf, s.data, s.len);
	buf[s.len] = '\0';
}
