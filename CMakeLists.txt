cmake_minimum_required(VERSION 3.12)
project(goxx-std)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Werror")

add_library(${PROJECT_NAME}
        src/fmt.h
        src/strings.h
        )
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
add_subdirectory(tests)

if (LINUX)
    set(CMAKE_INSTALL_PREFIX /usr/local/)
endif ()

# installation steps
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
set(HEADER_FILES
        src/fmt.h
        src/strings.h
        )
install(FILES ${HEADER_FILES} DESTINATION include/${PROJECT_NAME})
