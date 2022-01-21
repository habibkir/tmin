class m_config_info{
    int id;
    std::string name;
    int rows_count;
};

std::vector<m_config_info> first_step(const char* filepath){
    std::vector<m_config_info>ret;
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

