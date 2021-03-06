//
// Created by GOFORBROKE on 18.10.2020.
//

#ifndef GOXX_STD_STRINGS_H
#define GOXX_STD_STRINGS_H

#include <vector>
#include <string>
#include <sstream>

#include "unicode.h"

namespace goxx_std {
    namespace strings {

        inline
        std::vector<std::string>
        Split(const std::string &s, const std::string &sep) {
            std::vector<std::string> result;

            if (s.empty()) {
                return result;
            }

            if (sep.empty()) {
                for (char c : s) {
                    result.push_back(std::string(1, c));
                }
                return result;
            }

            size_t last = 0;
            size_t position = s.find(sep, last);

            while (position != std::string::npos) {
                std::string item = s.substr(last, position - last);
                result.push_back(item);

                last = position + sep.size();
                position = s.find(sep, last);
            }

            std::string item = s.substr(last, position - last);
            result.push_back(item);

            return result;
        }

        inline
        std::string
        TrimSpace(const std::string &s) {
            std::string result = s;

            if (result.empty())
                return result;


            while (unicode::IsSpace(result[0])) {
                result = result.substr(1);
            }
            while (unicode::IsSpace(result[result.size() - 1])) {
                result = result.substr(0, result.size() - 1);
            }
            return result;
        }

        inline
        std::string
        Replace(const std::string &s, const std::string &_old, const std::string &_new) {
            std::string result = s;

            size_t last = 0;
            size_t position = result.find(_old, last);

            while (position != std::string::npos) {
                result = result.replace(position, _old.length(), _new, 0, _new.length());

                last = position + _new.length();
                position = result.find(_old, last);
            }

            return result;
        }

        inline
        std::string
        Join(const std::vector<std::string> &elems, const std::string &sep) {
            std::string result;
            for (auto it = elems.begin(); it != elems.end(); it++) {
                result += (*it);
                if (std::next(it) != elems.end())
                    result += sep;
            }
            return result;
        }

        inline bool
        HasPrefix(const std::string &s, const std::string &p) {
            if (p.empty()) return true;
            if (s.empty()) return false;

            size_t minLen = p.length() < s.length()
                            ? p.length()
                            : s.length();

            for (size_t li = 0; li < minLen; ++li) {
                if (p[li] != s[li])
                    return false;
            }

            return true;
        }
    }
}

#endif //GOXX_STD_STRINGS_H
