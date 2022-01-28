#ifndef MINITEST_THIS_FUCKING_HEADER
#define MINITEST_THIS_FUCKING_HEADER

//TODO make asserts and expects print the case and suite they failed in instead

#include<iostream>

std::string suite_name;
std::string test_name;
bool test_failed = 0;//did a test fail in the current suite?
bool assert_failed = 0;//did an assert fail?

//all test macros are big ass loops because breaking out of loops is the best flow control I could think of
//given how do{}while(false) gets executed only once and has all the good break shit I used that

//sythax with and without curly braces is supported, mostly by accident, this thing was magnificiently designed

//test cases
#define test_case(name)test_name = #name;\
	              do{

#define end_case }while(false);\
	     if(assert_failed){break;}


//suites
#define test_suite(name) suite_name = #name;\
		    test_failed = 0;\
		    /*no tests have failed in this suite yet*/\
	  	    do{

#define end_suite }while(false);\
	      if(assert_failed) exit(1);


//the following have been put in a useless loop to limit name scope and avoid name clashes
//(20 different exp_val and the compiler starts acting up) 
//an if(true) would have done just as well, I just used the do while(false) for consisency

//expect
#define exp_eq(exp, act)do{\
			auto exp_val = (exp);\
			auto act_val = (act);\
		        if(exp_val != act_val){\
				std::cout<<#act<<" is not equal to "<<#exp<<'\n';\
				std::cout<<#exp<<" is "<<exp_val<<'\n';\
				std::cout<<#act<<" is "<<act_val<<'\n';\
		        	test_failed = 1;\
				std::cout<<"in test "<<test_name<<'\n';\
				std::cout<<"in suite "<<suite_name<<std::endl;\
			}\
			}while(false);

//assert
#define ass_eq(exp, act)do{\
			auto exp_val = (exp);\
			auto act_val = (act);\
		        if(exp_val != act_val){\
				std::cout<<#act<<" is not equal to "<<#exp<<'\n';\
				std::cout<<#exp<<" is "<<exp_val<<'\n';\
				std::cout<<#act<<" is "<<act_val<<'\n';\
		        	test_failed = 1;\
				assert_failed = 1;\
				std::cout<<"in test "<<test_name<<'\n';\
				std::cout<<"in suite "<<suite_name<<std::endl;\
			}\
			}while(false);


#define exp_t(condition) if(!(condition)){\
					  std::cout<<#condition<<" was supposed to be true but is false\n";\
					  test_failed=1;\
					  std::cout<<"in test "<<test_name<<'\n';\
					  std::cout<<"in suite "<<suite_name<<std::endl;\
					 }

#define ass_t(condition) if(!(condition)){\
					  std::cout<<#condition<<" was supposed to be true but is false\n";\
					  test_failed=1;\
					  assert_failed=1;\
					  std::cout<<"in test "<<test_name<<'\n';\
					  std::cout<<"in suite "<<suite_name<<std::endl;\
					 }
#endif //MINITEST_THIS_FUCKING_HEADER
