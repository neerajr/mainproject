/******************Function for editing a RSL file *******************/
#include<stdio.h>
main(){
	char path[100]="/home/globus/mainproject/";
	char s[25],c;
//	path[0]='\0';
	s[0]='\0';
	//strcat()
	strcat(s,"a.out");
	strcat(path,s);
	printf("path is %s\n",path);
	FILE *f1=NULL,*f2;
	f1=fopen("test.rsl","r");
	f2=fopen("tmp.txt","w");
	do{
		c=fgetc(f1);
		fprintf(f2,"%c",c);
			
	}while(c!='\n');

	do{
		c=fgetc(f1);
		fprintf(f2,"%c",c);
		
	}while(c!='>');
	fprintf(f2,"%s",path);	
	while(c=fgetc(f1)){
		if(c=='<'){
			fprintf(f2,"%c",c);
			break;
		}
	}
	do{
		c=fgetc(f1);
		fprintf(f2,"%c",c);
	}while(c!=EOF);
	fclose(f1);
	fclose(f2);
		
}
	
