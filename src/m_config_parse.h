#include<iostream>
#include<string>
#include<fstream>
#include<list>

#include"machine_components.h"

#ifndef TMIN_M_CONFIG_PARSE
#define TMIN_M_CONFIG_PARSE

struct m_config_info;

std::list<m_config_info> first_step(const char* filepath);

#endif