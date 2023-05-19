/***********************Function for parsing a RSL file ******************/
#include<stdio.h>
#include<string.h>
main(){
	char pattern[50],c,rsl[1000];
	pattern[0]='\0';
	strcat(pattern,"fileStageIn");
//	puts(pattern);
	FILE *fp;
	int i=0,suc,j;
	fp=fopen("test.rsl","r");
	while((c=fgetc(fp))!=EOF){
		if(c!='\n')
			rsl[i++]=c;
		else{
			//rsl[i]='\n';
			rsl[i]='\0';
		//	puts(rsl);
			suc=check(pattern,rsl);
			if(suc==0){
				printf("file stagein present");
			}
			break;
		}
	
	}
	
	//	printf("%c",rsl[j]);
	//	suc=check(pattern,rsl);
	
}
int check(char pat[],char rsl[]){
	int i=1,succ;
	char cat[500];
	cat[0]='<';
	cat[1]='\0';
	strcat(cat,pat);
	strcat(cat,">");
	printf("In function %s",cat);
	succ=strcmp(cat,rsl);
	printf("succ is %d",succ);
	return(succ);
}
			
	
	
	


