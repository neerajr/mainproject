/************************Program for redirecting a file into a specific node **************/
#include<stdio.h>
#include<string.h>

main()
{
	char c,filename[30],node[10],arr[10],cmd[200];
	int i=0;
	FILE *fp=NULL;
	while(1)
	{
		filename[0]='\0';
		node[0]='\0';
		arr[0]='\0';
		cmd[0]='\0';
	
		system("ls -tr *.out > filelist2");  //create the filelist
		fp=fopen("filelist2", "r");
		if(fp==NULL)
		{
			printf("NO FILE EXIT\n");
		}
		else
		{
			while((c=fgetc(fp))!='\n')  //store the first line of the file in a character array
			{
				filename[i]=c;
				i++;
			}
			filename[i]='\0';
			rewind(fp);
			i=0;
			while((c=fgetc(fp))!='_')  // store the node name in a character array
			{
				node[i]=c;
				i++;
			}
			node[i]='\0';
				
//			printf("Hello");					// send the file to the corresponding node
			if((i=strcmp(node,"node1"))==0)
			{
				strcat(cmd,"globus-url-copy gsiftp://globus14.local/home/globus/mainproject/outputfiles/ file:/dayanand.globus/home/globus/mainproject/output/");
				strcat(cmd,filename);
				system(cmd);
			}		
			else if((i=strcmp(node,"node2"))==0)
			{
                        	strcat(cmd,"globus-url-copy gsiftp://globus15.local/home/globus/mainproject/outputfiles/ file:/dayanand.globus/home/globus/mainproject/output/");
                        	strcat(cmd,filename);
                        	system(cmd);
                	}	 
			else if((i=strcmp(node,"node3"))==0)
                	{
                        	strcat(cmd,"globus-url-copy gsiftp://globus16.local/home/globus/mainproject/outputfiles/ file:/dayanand.globus/home/globus/mainproject/output/");
                        	strcat(cmd,filename);
                        	system(cmd);
                	} 
          		else if((i=strcmp(node,"node4"))==0)
			{
                        	strcat(cmd,"globus-url-copy gsiftp://globus18.local/home/globus/mainproject/outputfiles/ file:/dayanand.globus/home/globus/mainproject/output/");
                        	strcat(cmd,filename);
                        	system(cmd);
                	}                 	
                	else if((i=strcmp(node,"node5"))==0)
                	{
                        	strcat(cmd,"globus-url-copy gsiftp://vishnu.local/home/globus/mainproject/outputfiles/ file:/dayanand.globus/home/globus/mainproject/output/");
                        	strcat(cmd,filename);
                        	system(cmd);
                	} 
		        
			else
				printf("Error while redirecting\n");
			strcat(arr,"rm ");
			strcat(arr,node);
			system(arr);
		}
}
		
			
