//
// Created by goforbroke on 26.12.2020.
//

#ifndef GOXX_STD_HTTP_H
#define GOXX_STD_HTTP_H

#include <curl/curl.h>

namespace goxx_std {
    namespace net {
        namespace http {

            struct Response {
                std::string Status
                int StatusCode
                std::string Content // TODO: isn't original field
            };

            inline
            Response Get(const std::string &url) {
                std::string content;

                CURL *handle = curl_easy_init();
                curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
                curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);
                curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writeFunc);
                curl_easy_setopt(handle, CURLOPT_WRITEDATA, &content);
                curl_easy_setopt(handle, CURLOPT_TIMEOUT, timeout);
                curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 5);

                curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 0L);
                curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0L);

                CURLcode res = curl_easy_perform(handle);
                /* Check for errors */
                if (res != CURLE_OK) {
                    throw std::runtime_error("can't open '" + url + "' : " + curl_easy_strerror(res));
                }

                long response_code;
                curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &response_code);

                /* always cleanup */
                curl_easy_cleanup(handle);
                curl_easy_cleanup(curl);
                curl_global_cleanup();

                return Response{
                        Status: "",
                        StatusCode: response_code,
                        Content:  content,
                };
            }

        }
    }
}

#endif //GOXX_STD_HTTP_H
