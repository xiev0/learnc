cmake_minimum_required(VERSION 4.2)
project(learnC C)

set(CMAKE_C_STANDARD 11)

include_directories("level 4")

add_executable(learnC
        "level 3/main.c"
        "level 4/list.c"
        "level 4/list.h"
        "level 4/main.c"
        level2/main.c)
