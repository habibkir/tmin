cmake_minimum_required(VERSION 3.10)

project(tmin)

add_executable(tmin main.cpp machine_components.h machine_components.cpp m_config_parse.h m_config_parse.cpp line_parse.h line_parse.cpp)