//
// Created by gofor on 22.12.2020.
//

#ifndef GOXX_STD_GOXX_STD_FMT_H
#define GOXX_STD_GOXX_STD_FMT_H

#include <string>
#include <cstdarg>

namespace goxx_std {
    namespace fmt {

        inline
        std::string sprintf(const std::string &format, const char *args) {
            va_list vargs;
            va_start(vargs, args);

            while (*args != '\0') {
                if (*args == 'd') {
                    int i = va_arg(vargs, int);
                } else if (*args == 'c') {
                    // note automatic conversion to integral type
                    char c =  static_cast<char>(va_arg(vargs, int));
                } else if (*args == 'f') {
                    double d = va_arg(vargs, double);
                }
                ++args;
            }

            va_end(args);
        }

    }
}

#endif //GOXX_STD_GOXX_STD_FMT_H
