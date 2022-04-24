cmake_minimum_required(VERSION 3.16)
project(Scheduler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Scheduler main.cpp Time.h Task.h OptimalScheduler.h)
