#include<iostream>
#include"m_config_parse_test.h"

int main(){
  //this is the driver for all these tests
  test_m_parse();
  //we get here it means nothing aborted
  if(!test_failed)std::cout<<"ALL TESTS PASS!"<<std::endl;
  return 0;
}
