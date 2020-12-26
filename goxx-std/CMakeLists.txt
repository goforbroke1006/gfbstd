cmake_minimum_required(VERSION 3.12)
project(goxx-std)

add_library(${PROJECT_NAME}
        include/net/http.h
        include/fmt.h
        include/strings.h
        include/unicode.h
        main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

find_package(CURL)
if (CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})
else (CURL_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the CURL library and development files.")
endif (CURL_FOUND)


if (LINUX)
    set(CMAKE_INSTALL_PREFIX /usr/local/)
endif ()

# installation steps
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY "include/"
        DESTINATION "include/goxx-std"
        FILES_MATCHING
        PATTERN "*.h"
        )
