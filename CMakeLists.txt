cmake_minimum_required(VERSION 3.10)

project(LookupGenericLibrary VERSION 1.0)

# Default vals
set(ROOT_DIR "${CMAKE_SOURCE_DIR}/..")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(BUILD_TESTING ON)
set(CMAKE_C_COMPILER "ppclang")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

# message(FATAL_ERROR ${CMAKE_SOURCE_DIR})

if (BUILD_JULIA)

    set(JULIA_INCLUDE_DIR "${ROOT_DIR}/julia/usr/include/julia" CACHE PATH "Path to Julia include directory")
    if(NOT EXISTS "${JULIA_INCLUDE_DIR}/julia.h")
        message(FATAL_ERROR "Julia headers not found in ${JULIA_INCLUDE_DIR}")
    endif()

    set(SOURCES lookup_generic.c)

    add_library(lookup_generic SHARED ${SOURCES})

    target_include_directories(lookup_generic PUBLIC ${JULIA_INCLUDE_DIR})
    target_include_directories(lookup_generic PRIVATE "${ROOT_DIR}/julia/src")
    target_include_directories(lookup_generic PRIVATE "${ROOT_DIR}/julia/usr/include")

    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        find_library(JULIA_LIBRARY julia-debug PATHS "${ROOT_DIR}/julia/usr/lib/" NO_DEFAULT_PATH)
        find_library(JULIA_INTERNAL_LIBRARY julia-internal-debug PATHS "${ROOT_DIR}/julia/usr/lib/" NO_DEFAULT_PATH)
        if(JULIA_LIBRARY AND JULIA_INTERNAL_LIBRARY)
            target_link_libraries(lookup_generic PRIVATE ${JULIA_LIBRARY} ${JULIA_INTERNAL_LIBRARY})
        else()
            message(FATAL_ERROR "Julia library not found")
        endif()
    else()
        find_library(JULIA_LIBRARY julia PATHS "${ROOT_DIR}/julia/usr/lib/" NO_DEFAULT_PATH)
        find_library(JULIA_INTERNAL_LIBRARY julia-internal PATHS "${ROOT_DIR}/julia/usr/lib/" NO_DEFAULT_PATH)
        if(JULIA_LIBRARY AND JULIA_INTERNAL_LIBRARY)
            target_link_libraries(lookup_generic PRIVATE ${JULIA_LIBRARY} ${JULIA_INTERNAL_LIBRARY})
        else()
            message(FATAL_ERROR "Julia library not found")
        endif()
    endif()

    # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} BUILD_JULIA")

    add_compile_options("-DBUILD_JULIA")

    set_target_properties(lookup_generic PROPERTIES
        OUTPUT_NAME "lookup_generic"
        PREFIX ""
    )

endif()


if(BUILD_TESTING)
    add_executable(test_lookup_generic
        util.h
        test_lookup_generic.c
        test_lookup_generic.h
        test_lookup_generic_impl.c
        ppp-mm-tag-disp/multimethod-empty.c
        ppp-mm-tag-disp/multimethod-empty.h
        procedural-vt/proced.h
        procedural-vt/proced.c
        procedural-switch/proced-switch.h
        procedural-switch/proced-switch.c
        procedural-switch/proced-switch-3d.c
        procedural-switch/proced-switch-2dx10.c
        )

if (BUILD_JULIA)
    target_include_directories(test_lookup_generic PRIVATE "${ROOT_DIR}/julia/src")
    target_include_directories(test_lookup_generic PRIVATE "${ROOT_DIR}/julia/usr/include")
    target_link_libraries(test_lookup_generic PRIVATE lookup_generic ${JULIA_LIBRARY} ${JULIA_INTERNAL_LIBRARY})
    target_include_directories(test_lookup_generic PRIVATE ${JULIA_INCLUDE_DIR})
endif()

    add_executable(test_visitor
        util.h
        oop/visitor.cpp
        oop/visitor3d.cpp
        oop/measure.cpp
        oop/visitor.h
        )

    # add_executable(test_lookup_generic_shared example_usage.c)
    # target_link_libraries(test_lookup_generic PRIVATE lookup_generic)
    # target_include_directories(test_lookup_generic_shared PRIVATE ${JULIA_INCLUDE_DIR})
endif()
