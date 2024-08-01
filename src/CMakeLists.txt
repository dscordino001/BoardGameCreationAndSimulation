file(GLOB SOURCES "*.cpp")
list(REMOVE_ITEM SOURCES "main.cpp")

add_library(ccbb ${SOURCES} "autoSim.cpp")
add_executable(
    play main.cpp
)

target_link_libraries(
  play
  ccbb
)
