file(GLOB sources *.cpp)

set(name server)
add_executable(${name} ${sources})

target_compile_options(${name}
  PUBLIC
    -Wall
    $<$<CONFIG:Debug>:-O0 -g3>           # -D CMAKE_BUILD_TYPE=Debug
    $<$<CONFIG:Release>:-O3>             # -D CMAKE_BUILD_TYPE=Release
    $<$<CONFIG:MinSizeRel>:-Os>          # -D CMAKE_BUILD_TYPE=MinSizeRel
    $<$<CONFIG:RelWithDebInfo>:-O3 -g3>  # -D CMAKE_BUILD_TYPE=RelWithDebInfo
)
target_link_options(${name} PUBLIC -Wall)
target_link_libraries(${name} ppcnn_server ${COMMON_LIBS})
