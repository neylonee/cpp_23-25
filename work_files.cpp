#include"work_files.h"

void WriteRes(const char* fl_name, int num_1,float num_2,bool update = 1){
	FILE* f;
	if(update){
		 f = fopen(fl_name,"a");
	}
	else{	
		 f = fopen(fl_name,"w");
	}
	fprintf(f,"%d\t%f\n",num_1,num_2);
	fclose(f);
}
