#pragma once

#ifdef __cplusplus
#include <cassert>
#include <cstring>
#else
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#endif

#ifdef __cplusplus
#define STRINGS_API
#else
#define STRINGS_API static inline
#endif

struct Str;
struct String;

typedef struct String {
	size_t len;
	const char *data;

#ifdef __cplusplus
	size_t length();
	bool startswith(Str slice);
	Str to_str();
	void free();
	static String from(const char *cstr);
	static String from(char *cstr);
#endif
} String;

typedef struct Str {
	size_t len;
	const char *data;

#ifdef __cplusplus
	[[nodiscard]] Str trim_left() const;
	[[nodiscard]] Str trim_right() const;
	[[nodiscard]] Str trim() const;
	[[nodiscard]] size_t length() const;
	int split(char delim, Str *out, int out_size) const;
	int split_str(Str delim, Str *out, int out_size) const;
	[[nodiscard]] bool eq(Str b) const;
	[[nodiscard]] bool startswith_str(Str b) const;
	bool startswith_cstr(const char *cstr) const;
	[[nodiscard]] String to_string() const;
	void to_cstr(char *buf) const;
	[[nodiscard]] char *to_cstr() const;
	static Str from(const char *cstr);
	static Str from(char *cstr);
#endif
} Str;

#ifdef __cplusplus
extern "C" {
#endif

// ========
// Utils
// ========

#define STR(s)                                                                 \
  (Str) { .len = sizeof(s) - 1, .data = s }
#define STRING(s)                                                              \
  (String) { .len = sizeof(s) - 1, .data = s }

#define STR_FMT "%.*s"
#define STR_ARG(s) (int)s.len, s.data

#define STR_FOR(s, i) for (size_t i = 0; i < s.len; i++)

const char WHITESPACE[] = " \r\t\n\0";
STRINGS_API bool is_whitespace(char c);

// ========
// String
// ========

STRINGS_API String string_from_cstr(const char *cstr);
STRINGS_API size_t string_len(String s);
STRINGS_API bool string_startswith_str(String s, Str slice);
STRINGS_API Str string_to_str(String s);
STRINGS_API void string_free(String s);

// ========
// Str
// ========

STRINGS_API Str str_from_cstr(const char *cstr);
STRINGS_API Str str_trim_left(Str s);
STRINGS_API Str str_trim_right(Str s);
STRINGS_API Str str_trim(Str s);
STRINGS_API size_t str_len(Str s);
STRINGS_API int str_split(Str s, char delim, Str *out, int out_size);
STRINGS_API int str_split_str(Str s, Str delim, Str *out, int out_size);
STRINGS_API bool str_eq(Str a, Str b);
STRINGS_API bool str_startswith_str(Str a, Str b);
STRINGS_API bool str_startswith_cstr(Str a, const char *cstr);
STRINGS_API String str_to_string(Str s);
STRINGS_API void str_to_cstr(Str s, char *buf);
STRINGS_API char *str_to_cstr_m(Str s);

#ifdef __cplusplus
}
#endif

#ifdef STRINGS_IMPLEMENTATION

// ========
// IMPL
// ========

#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

// ========
// Utils
// ========

STRINGS_API bool is_whitespace(const char c) {
	for (size_t i = 0; i < sizeof(WHITESPACE); i++) {
		if (c == WHITESPACE[i])
			return true;
	}

	return false;
}

// ========
// String
// ========

STRINGS_API String string_from_cstr(const char *cstr) {
	size_t len = strlen(cstr);
	char *new_data = (char *) malloc(len);
	memcpy(new_data, cstr, len);
	return (String){.len = len, .data = new_data};
}

STRINGS_API size_t string_len(const String s) { return s.len; }

STRINGS_API bool string_startswith_str(const String s, const Str slice) {
	if (s.len < slice.len)
		return false;
	return memcmp(s.data, slice.data, slice.len) == 0;
}

STRINGS_API Str string_to_str(const String s) {
	return (Str){.len = s.len, .data = s.data};
}

inline void string_free(String s) { free((void *) s.data); }

// ========
// Str
// ========

STRINGS_API Str str_trim_left(Str s) {
	for (size_t i = 0; i < s.len; i++) {
		if (!is_whitespace(s.data[i]))
			break;
		s.data++;
		s.len--;
	}

	return s;
}

STRINGS_API Str str_trim_right(Str s) {
	for (size_t i = s.len - 1; i > 0; i--) {
		if (!is_whitespace(s.data[i]))
			break;
		s.len--;
	}

	return s;
}

STRINGS_API Str str_trim(const Str s) {
	return str_trim_right(str_trim_left(s));
}

STRINGS_API size_t str_len(const Str s) { return s.len; }

STRINGS_API Str str_copy(const Str s) { return s; }

STRINGS_API bool str_eq(const Str a, const Str b) {
	if (a.len != b.len)
		return false;
	return memcmp(a.data, b.data, a.len) == 0;
}

STRINGS_API int str_split(const Str s, const char delim, Str *out,
                          int out_size) {
	int found = 0;
	size_t start = 0;

	STR_FOR(s, i) {
		if (s.data[i] == delim) {
			if (i > start) {
				if (found >= out_size)
					return found;
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

STRINGS_API int str_split_str(Str s, Str delim, Str *out, int out_size) {
	assert(0 && "str_split_str not yet implemented");
}

STRINGS_API Str str_from_cstr(const char *cstr) {
	return (Str){.len = strlen(cstr), .data = cstr};
}

STRINGS_API bool str_startswith_str(const Str a, const Str b) {
	if (a.len < b.len)
		return false;
	return memcmp(a.data, b.data, b.len) == 0;
}

STRINGS_API bool str_startswith_cstr(Str a, const char *cstr) {
	size_t len = strlen(cstr);
	if (a.len < len)
		return false;
	return memcmp(a.data, cstr, len) == 0;
}

STRINGS_API String str_to_string(Str s) {
	char *new_data = (char *) malloc(s.len);
	memcpy(new_data, s.data, s.len);
	return (String){.len = s.len, .data = new_data};
}

STRINGS_API char *str_to_cstr_m(Str s) {
	char *new_data = (char *) malloc(s.len + 1);
	memcpy(new_data, s.data, s.len);
	new_data[s.len] = '\0';
	return new_data;
}

STRINGS_API void str_to_cstr(Str s, char *buf) {
	memcpy(buf, s.data, s.len);
	buf[s.len] = '\0';
}

#ifdef __cplusplus

STRINGS_API size_t String::length() { return len; }
STRINGS_API bool String::startswith(Str slice) {
	return string_startswith_str(*this, slice);
}

STRINGS_API Str String::to_str() { return string_to_str(*this); }

STRINGS_API void String::free() { return string_free(*this); }

STRINGS_API String String::from(const char *cstr) {
	return string_from_cstr(cstr);
}

STRINGS_API String String::from(char *cstr) { return string_from_cstr(cstr); }

STRINGS_API Str Str::trim_left() const { return str_trim_left(*this); }

STRINGS_API Str Str::trim_right() const { return str_trim_right(*this); }

STRINGS_API Str Str::trim() const { return str_trim(*this); }

STRINGS_API size_t Str::length() const { return str_len(*this); }

STRINGS_API int Str::split(char delim, Str *out, int out_size) const {
	return str_split(*this, delim, out, out_size);
}

STRINGS_API int Str::split_str(Str delim, Str *out, int out_size) const {
	return str_split_str(*this, delim, out, out_size);
}

STRINGS_API bool Str::eq(Str b) const { return str_eq(*this, b); }

STRINGS_API bool Str::startswith_str(Str b) const {
	return str_startswith_str(*this, b);
}

STRINGS_API bool Str::startswith_cstr(const char *cstr) const {
	return str_startswith_cstr(*this, cstr);
}

STRINGS_API String Str::to_string() const { return str_to_string(*this); }

STRINGS_API void Str::to_cstr(char *buf) const { str_to_cstr(*this, buf); }

STRINGS_API char *Str::to_cstr() const { return str_to_cstr_m(*this); }

STRINGS_API inline Str Str::from(char *cstr) {
	return str_from_cstr(cstr);
}

STRINGS_API inline Str Str::from(const char *cstr) {
	return str_from_cstr(cstr);
}

#endif

#endif
