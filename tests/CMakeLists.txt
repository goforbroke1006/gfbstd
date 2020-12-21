project(goxx-std-tests)

if (CYGWIN)
    include(ExternalProject)
    find_package(Threads REQUIRED)

    set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

    ExternalProject_Add(googletest
            GIT_REPOSITORY https://github.com/google/googletest
            CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
            )
    include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
    link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)
endif ()


add_executable(${PROJECT_NAME}
        main.cpp

        goxx-std-strings.cpp
        goxx-std-fmt.cpp
        )
if (CYGWIN)
    add_dependencies(${PROJECT_NAME} googletest)
endif ()
target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
add_test(runUnitTests ${PROJECT_NAME})