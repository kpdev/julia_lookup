cmake_minimum_required(VERSION 3.10)

project(LookupGenericLibrary VERSION 1.0 LANGUAGES C)

set(JULIA_INCLUDE_DIR "../julia/usr/include/julia" CACHE PATH "Path to Julia include directory")
if(NOT EXISTS "${JULIA_INCLUDE_DIR}/julia.h")
    message(FATAL_ERROR "Julia headers not found in ${JULIA_INCLUDE_DIR}")
endif()

set(SOURCES lookup_generic.c)

add_library(lookup_generic SHARED ${SOURCES})

target_include_directories(lookup_generic PUBLIC ${JULIA_INCLUDE_DIR})

set_target_properties(lookup_generic PROPERTIES
    OUTPUT_NAME "lookup_generic"
    PREFIX ""
)

if(BUILD_TESTING)
    add_executable(test_lookup_generic test_lookup_generic.c)
    target_link_libraries(test_lookup_generic PRIVATE lookup_generic)
    target_include_directories(test_lookup_generic PRIVATE ${JULIA_INCLUDE_DIR})

    add_executable(test_lookup_generic_shared example_usage.c)
    # target_link_libraries(test_lookup_generic PRIVATE lookup_generic)
    target_include_directories(test_lookup_generic_shared PRIVATE ${JULIA_INCLUDE_DIR})
endif()
