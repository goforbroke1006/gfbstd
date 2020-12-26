//
// Created by goforbroke on 26.12.2020.
//

#ifndef GOXX_STD_UNICODE_H
#define GOXX_STD_UNICODE_H


namespace goxx_std {
    namespace unicode {

        inline
        bool
        IsSpace(char c) {
            return c == ' ' || c == '\n' || c == '\t';
        }

    }
}

#endif //GOXX_STD_UNICODE_H
