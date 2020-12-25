//
// Created by gofor on 22.12.2020.
//

#ifndef GOXX_STD_FMT_H
#define GOXX_STD_FMT_H

#include <string>
#include <cstdarg>

namespace goxx_std {
    namespace fmt {

        inline
        std::string sprintf(const char *format...) {
            std::string result = format;

            va_list vargs;
            va_start(vargs, format);

            size_t startPos = 0;
            while (startPos < result.length()) {
                size_t percentPos = result.find('%', startPos);
                if (percentPos == std::string::npos) break;

                char marker = result.at(percentPos + 1);
                std::string insertion;
                if (marker == 'd') {
                    long i = va_arg(vargs, long);
                    insertion = std::to_string(i);
                } else if (marker == 'f') {
                    double d = va_arg(vargs, double);
                    insertion = std::to_string(d);
                } else if (marker == 's') {
                    const char *str = va_arg(vargs, const char *);
                    insertion = str;
                }

                result = result.replace(percentPos, 2, insertion);
            }

            va_end(vargs);

            return result;
        }

    }
}

#endif //GOXX_STD_FMT_H
