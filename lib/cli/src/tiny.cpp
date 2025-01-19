#include "tiny.hpp"
#include "os.hpp"

tiny::tiny(char *s) {
    size_t len = strlen(s);
    assert(len < tiny::max);  // uint8_t limit
    length = len;
    assert(value = (char *)malloc(length + 1));
    strncpy(value, s, length);
}

tiny::~tiny() {
    assert(value);
    free(value);
}
