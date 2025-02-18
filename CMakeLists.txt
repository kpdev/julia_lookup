cmake_minimum_required(VERSION 3.10)

project(LookupGenericLibrary VERSION 1.0 LANGUAGES C)

set(JULIA_INCLUDE_DIR "../julia/usr/include/julia" CACHE PATH "Path to Julia include directory")
if(NOT EXISTS "${JULIA_INCLUDE_DIR}/julia.h")
    message(FATAL_ERROR "Julia headers not found in ${JULIA_INCLUDE_DIR}")
endif()

set(SOURCES lookup_generic.c)

add_library(lookup_generic SHARED ${SOURCES})

target_include_directories(lookup_generic PUBLIC ${JULIA_INCLUDE_DIR})
target_include_directories(lookup_generic PRIVATE "../julia/src")
target_include_directories(lookup_generic PRIVATE "../julia/usr/include")

find_library(JULIA_LIBRARY julia-debug PATHS "../julia/usr/lib/" NO_DEFAULT_PATH)
find_library(JULIA_INTERNAL_LIBRARY julia-internal-debug PATHS "../julia/usr/lib/" NO_DEFAULT_PATH)
if(JULIA_LIBRARY AND JULIA_INTERNAL_LIBRARY)
    target_link_libraries(lookup_generic PRIVATE ${JULIA_LIBRARY} ${JULIA_INTERNAL_LIBRARY})
else()
    message(FATAL_ERROR "Julia library not found")
endif()

set_target_properties(lookup_generic PROPERTIES
    OUTPUT_NAME "lookup_generic"
    PREFIX ""
)

if(BUILD_TESTING)
    add_executable(test_lookup_generic test_lookup_generic.c)
    target_include_directories(test_lookup_generic PRIVATE "../../julia/src")
    target_include_directories(test_lookup_generic PRIVATE "../../julia/usr/include")
    target_link_libraries(test_lookup_generic PRIVATE lookup_generic ${JULIA_LIBRARY} ${JULIA_INTERNAL_LIBRARY})
    target_include_directories(test_lookup_generic PRIVATE ${JULIA_INCLUDE_DIR})

    add_executable(test_lookup_generic_shared example_usage.c)
    # target_link_libraries(test_lookup_generic PRIVATE lookup_generic)
    target_include_directories(test_lookup_generic_shared PRIVATE ${JULIA_INCLUDE_DIR})
endif()
