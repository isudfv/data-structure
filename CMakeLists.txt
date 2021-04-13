# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
project (data_structrue VERSION 1.0)

file(GLOB SOURCES
    src/*.cpp
)

add_library(data STATIC ${SOURCES})
add_executable(data_bin ${SOURCES})


target_include_directories(data
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include/data
)

target_include_directories(data_bin
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include/data
)

target_link_libraries(data_bin data)


# find_package(FMT REQUIRED)
target_link_libraries(data )

install(TARGETS data
    LIBRARY DESTINATION lib)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)

# install(TARGETS data
#     EXPORT MyMathTargets
#     LIBRARY DESTINATION lib 
#     ARCHIVE DESTINATION lib
#     RUNTIME DESTINATION bin
#     PUBLIC_HEADER DESTINATION include
# )