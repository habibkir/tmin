#ifndef TMIN_MACHINE_COMPONENTS
#define TMIN_MACHINE_COMPONENTS

struct m_config;

struct row{
	char key;
	char* operations;
	m_config* final_m_config;
};

struct m_config{
	row* rows;
	int rows_cnt;
};

#endif
