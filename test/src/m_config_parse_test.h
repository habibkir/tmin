#include"minitest.hpp"

#include"../../src/m_config_parse.h"

std::list<m_config_info>::iterator find_from_name(std::list<m_config_info>& m_list, std::string tar_name){
  for(auto it = m_list.begin();it!=m_list.end();++it){
    if(it->name == tar_name)return it;
  }
  return m_list.end();
}

void test_m_parse(){
  test_suite(easy first){
    auto m_list = first_step("../files/easy.txt");
    //scrub test first
    for(auto element:m_list){
      std::cout<<element.name<<std::endl;
      std::cout<<element.id<<std::endl;
      std::cout<<element.rows_cnt<<std::endl<<std::endl;
    }

    //now for the actual tests
    test_case(init config){
      auto to_test = find_from_name(m_list,"init");
      exp_t(to_test!=m_list.end());
      exp_eq("init",to_test->name);
      exp_eq(0,to_test->id);
      exp_eq(2,to_test->rows_cnt);
    }end_case;

    test_case(other config){
      auto to_test = find_from_name(m_list,"q2");
      exp_t(to_test!=m_list.end());
      exp_eq("q2",to_test->name);
      exp_eq(1,to_test->id);
      exp_eq(2,to_test->rows_cnt);
    }end_case;

  }end_suite;
}
