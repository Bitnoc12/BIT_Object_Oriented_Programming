#ifndef REQUIRE_H
#define REQUIRE_H

#include <cstdio>
#include <cstdlib>

inline void require(bool requirement, const char* error_message = "Requirement failed") {
    if (!requirement) {
        std::fprintf(stderr, "%s\n", error_message);
        std::exit(EXIT_FAILURE);
    }
}

#endif // REQUIRE_H
