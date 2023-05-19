/***********************Function for RSL generator ************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	FILE *fp;
	char hostname[50]="node1";
	char opfile[30],ccount[5],executable[15],arguments[50],filename[50],cmd[200];
	opfile[0]=0;
	ccount[0]=0;
	cmd[0]=0;
	executable[0]=0;
	int count=0,c,k=0,j=0,i=0;
	int p;
	int extract(char[]);
	
	strcat(opfile,hostname);
	strcat(opfile,"_");
	strcat(opfile,"job");
	sprintf(ccount,"%d",count);
	strcat(opfile,ccount);
	strcat(opfile,".rsl");
	printf("Enter the complete path to the c file: ");
        do{
		executable[k]=fgetc(stdin);
	}while(executable[k++]!='\n');
	executable[--k]='\0';
	k=0;
	fflush(stdin);
	printf("Enter the arguments (seperated by space): Press enter if NO arguments: ");
	fflush(stdin);
	do{
		arguments[k]=fgetc(stdin);
	}while(arguments[k++]!='\n');
	arguments[--k]='\0';
	k=strlen(arguments);
//	printf("length is %d",k);
	fp=fopen(opfile,"w");
	fprintf(fp,"<job>\n");
//	printf("Enter the complete path to the executable: ");
	fprintf(fp,"<executable>%s</executable>\n",executable);
	fprintf(fp,"<directory>${GLOBUS_USER_HOME}/</directory>\n");
	i=0;
	if(k!=0){
		while(i<=k){
//			printf("Hello\n");
		        fprintf(fp,"<argument>");
				while(arguments[i]!=' '&& arguments[i]!='\0'){		
					fprintf(fp,"%c",arguments[i++]);
				}
				i++;
		       	fprintf(fp,"</argument>\n");			
		}	
	}
	printf("\nDoes your job involve file transfer?(Enter 0 if none or enter the number of file transfers): ");
	scanf("%d",&c);
	j=0;
	if(c!=0){
		 fprintf(fp,"<fileStageIn>\n");
	}
	while(j<c){
//		fprintf(fp,"<fileStageIn>\n");
		fprintf(fp,"<transfer>\n");
		printf("Enter the path of the filename\n");
		i=0;
		fflush(stdin);
		scanf("%s",filename);
		filename[--i]='\0';
		fprintf(fp,"<sourceUrl>:%s\n",filename);
		fprintf(fp,"<destinationUrl>:       \n");
		fprintf(fp,"</transfer>\n");
//		fprintf(fp,"</fileStageIn>\n");
		filename[0]='\0';
		j++;
	}
	if(c!=0){
		fprintf(fp,"</fileStageIn>\n");
		fprintf(fp,"<fileCleanUp>\n");	
	}
	j=0;
	while(j<c){
//		fprintf(fp,"<fileCleanUp>\n");
		fprintf(fp,"<deletion>\n");
		fprintf(fp,"<file>file:///\n");
		fprintf(fp,"</deletion>\n");
//		fprintf(fp,"</fileCleanUp>\n");
		j++;
	}
	if(c!=0)
	 	fprintf(fp,"</fileCleanUp>\n");

//	while(i!=0&&i!=c)
//	{
//		//Function call................			
//	}
	fprintf(fp,"</job>\n");
	
//............................................................................................................
	fclose(fp);
	strcat(cmd,"globus-url-copy file:/");
	strcat(cmd,opfile);
	strcat(cmd," gsiftp:///dayanand.globus/home/globus/mainproject/");
	printf("cmd is:%s\n",cmd);
	system(cmd);
//............................................................................................................
	
}

