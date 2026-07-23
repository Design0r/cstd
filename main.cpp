#define STRINGS_IMPLEMENTATION
#include "strings.h"


int main() {
	Str s = str_from_cstr("hallo  , slkfsf  ");
	s.trim_left();

	return 0;
}
