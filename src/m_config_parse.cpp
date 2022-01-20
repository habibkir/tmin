#include<iostream>
#include<string>
#include<fstream>
#include<list>

#include"machine_components.h"

#ifndef TMIN_M_CONFIG_PARSE
#define TMIN_M_CONFIG_PARSE

struct m_config_info{
    int id;
    std::string name;
    int rows_count;
};

std::list<m_config_info> first_step(const char* filepath){
    std::list<m_config_info>ret;
    std::ifstream ifs(filepath);
    std::string line;

    if(!ifs){
        std::cout<<"oopsie woopsie, I want to strangle a giraffe\n";
    }

    while(std::getline(ifs,line)){
        //std::cout<<"I am doing something to this line of text\n";
        std::cout<<line;
        std::cout<<'\n';
    }
    return ret;
}

#endif