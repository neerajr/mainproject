/************************Function for job submit *********************/
#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
main()
{
	int count=1;
	while(1)
	{
//		system("clear");
		char command[50],parameters[200];
		char ccount[5],*s;
		char hostname[50]="node1";
		char opfile[30];
		int i;
		opfile[0]=0;
		i=0;
		printf("Enter the command: ");
		do{
			command[i]=fgetc(stdin);
		}while(command[i++]!='\n');
//		printf("i is %d",i);
		command[--i]='\0';
//		printf("Command is --->%s\n",command);
		printf("Enter the parameters: ");
		i=0;
		do{
//			printf("Check\n");
			parameters[i]=fgetc(stdin);
//			if(parameters[i]=='\n'){
//				break;
//			}
//			puts("Check2");
		}while(i<200 && parameters[i++]!='\n');
		parameters[--i]='\0';
                printf("------------------------------------------------------------------\n");
		printf("Command is --->%s\n",command);
		printf("------------------------------------------------------------------\n");
		printf("Parameters are -->");
		puts(parameters);
//		scanf("%s",parameters); // Can read only one parameter
//		Submitting a job to the server from a client 
		char globus[500]="globusrun-ws -submit -streaming -F https://dayanand.globus:8443/wsrf/services/ManagedJobFactoryService -c -so ";
		strcat(opfile,hostname);
		strcat(opfile,"_");
		strcat(opfile,"count");
		sprintf(ccount,"%d",count);
		strcat(opfile,ccount);
		strcat(opfile,".txt");
		printf("------------------------------------------------------------------\n");
		printf("The o/p file --->");
		puts(opfile);
		strcat(globus,opfile);	
		strcat(globus," -c ");
		strcat(globus,command);
		strcat(globus," ");
		strcat(globus,parameters);
                printf("------------------------------------------------------------------\n");
		printf("The whole command is -->");
		i=0;
		while(globus[i]!='\0'){
			printf("%c",globus[i++]);
		}
	//	printf("i is %d",i);
		count++;
		system(globus);
	}
	
}
