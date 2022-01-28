cmake_minimum_required(VERSION 3.10)

project(tests)

set(to_test ../../src)
include_directories(${to_test} . )

set(m_conf_files ${to_test}/m_config_parse.h ../src/m_config_parse_test.h)

add_executable(testexe test_main.cpp minitest.hpp  ${m_conf_files})

#target_include_directories(testexe PUBLIC ../../src) #public keyword worked last time, boh
#vediamo se include_directories normale funziona meglio, che questo mi si bugga
