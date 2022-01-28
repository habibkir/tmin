#ifndef TMIN_M_CONFIG_PARSE
#define TMIN_M_CONFIG_PARSE

#include<iostream>
#include<string>
#include<fstream>
#include<list>

#include"machine_components.h"

struct m_config_info{
  int id;
  std::string name;
  int rows_cnt;
};

m_config_info create_m_config_info(int id, std::string name, int rows_cnt){
  m_config_info mci;
  mci.id = id;
  mci.name = name;
  mci.rows_cnt = rows_cnt;
  return mci;//how did I fucking forget this one?
}

std::list<m_config_info>first_step(char const*);//gathers info about m_configs to ease later parsing

//used in first_step
void skip_empty_lines(std::ifstream&, std::string&);//used in first_step's file exploring
std::string get_m_config_name(std::string&);//used in first_step's info gathering
int get_rows_count(std::ifstream&);//used in first_step's info gathering

//used in functions called by first_step
int m_config_name_length(int,std::string&);//used in get_m_config_name
void ignore_whitespace(int&, std::string&);//used in get_m_config_name

//even futher below
bool is_whitespace(char);//used in ignore_whitespace



std::list<m_config_info> first_step(char const* filepath){
  //used to get info about the size and names of m-configs
  //should make building a model of the machine for the later steps easier

  //m-config info needed is a universally unique id, name, and amount of rows
  //ids go from 1 to whatever, with 0 being assigned to the init m-configs
  int curr_id = 1;

  std::list<m_config_info>gathered_info;
  std::ifstream ifs(filepath, std::ifstream::in);
  std::string line;
  if(!ifs){
      std::cout<<"could not open the fucking file\n";
  }

  //create the m-config-info structure, this thing might need a separate function
  while(std::getline(ifs,line)){
    skip_empty_lines(ifs,line);//needed to cope with empty lines between m-configs
    //TODO check for end of file, in case there just were some empty lines and then nothing

    //TODO once this shit is tested, have a more general way to determine init config
    std::string mci_name = get_m_config_name(line);
    int mci_id = ((mci_name=="init")?0:(curr_id++));
    int mci_rows_cnt = get_rows_count(ifs);
    //put it all together
    gathered_info.push_back(create_m_config_info(mci_id,mci_name,mci_rows_cnt));
  }
  return gathered_info;
}

void skip_empty_lines(std::ifstream& ifs, std::string& s){
  int index = 0;
  do{
    ignore_whitespace(index,s);
    if(index!=s.size())return;//we have reached a line with something other than whitespace
  }while(std::getline(ifs,s));
}

std::string get_m_config_name(std::string& line){
    int index = 0;
    ignore_whitespace(index,line);
    return line.substr(index,m_config_name_length(index,line));
}

int get_rows_count(std::ifstream& ifs){
    int rows = 0;
    std::string line;
    while(std::getline(ifs,line)){
      if(line.find('}')!=std::string::npos)break;
      rows++;
    }
    //TODO check whether the line was made by some psycho who puts
    //the closing brack after a statement with no newline
    //and increment rows if so
    return rows;
}


int m_config_name_length(int i, std::string& s){//used in first_step
  int res = 0;//first char is already considered in the loop
  while(!is_whitespace(s[i])&&s[i]!='{'){
    ++res;
    ++i;
  }
  return res;
}

void ignore_whitespace(int& i, std::string& s){
  while(is_whitespace(s[i])){++i;}
}

bool is_whitespace(char c){
  return c==' '||c=='\t';
}

#endif
