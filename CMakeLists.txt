cmake_minimum_required(VERSION 3.9)
project(hashcode C)

set(CMAKE_C_STANDARD 99)

add_executable(hashcode
        veh.h
        veh_structs.h
        main.c
        check_ride.c
        marshroot.c rides_iter.c)