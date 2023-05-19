/****************************************************** GRID SCHEDULER ****************************************/
#include<stdio.h>
#include<string.h>
#define MAX 2000000
void command(char[]);
int num,cost;
int nod[4],value=0;
char file[15],rfile[50],temp2[25],file2[100],zip3[25];
void uzip(void);
void rsl(char[]);
char *strrev(char[]);
int top();
main()
{
	while(1)
      {
      
		int i=0,max=20;
		char arg[100],c,cmd[50],tem[25],cos1[20];
		for(i=0;i<5;i++)
			nod[i]=0;
		file[0]='\0';
		system("ls -tr ./output/*.zip > zipfile");
		i=0;
		num=i;
		char top[150];
		top[0]='\0';	
		FILE *top1,*top2,*top3,*top4;
		top1=fopen("vishnu.out","r");
		top2=fopen("globus14.out","r");
		top3=fopen("globus16.out","r");
		top4=fopen("globus18.out","r");	
		i=0;
		while((c=fgetc(top1))!='\n')
		{
			cos1[i]=c;//cost of process
			i++;
		}
		cos1[i]='\0';
		nod[0]=atoi(cos1);
		printf("nod0 value is %d\n",nod[0]);
		i=0;
		while((c=fgetc(top2))!='\n')
		{
			cos1[i]=c;//cost of process
			i++;
		}
		cos1[i]='\0';
		nod[1]=atoi(cos1);
		 printf("nod1 value is %d\n",nod[1]);

		i=0;
        	while((c=fgetc(top3))!='\n')
        	{
                	cos1[i]=c;//cost of process
                	i++;
        	}
        	cos1[i]='\0';
        	nod[2]=atoi(cos1);
		 printf("nod2 value is %d\n",nod[2]);

		i=0;
        	while((c=fgetc(top4))!='\n')
        	{
                	cos1[i]=c;//cost of process
                	i++;
        	}
        	cos1[i]='\0';
        	nod[3]=atoi(cos1);
		 printf("nod3 value is %d\n",nod[3]);

		i=0;
		value=nod[i];	
		for(i=0;i<4;i++)
	 	{
	 		if(value>nod[i])
			{	
		//		printf("nod %d value %f\n",i,nod[i]);
				value=nod[i];	// value of lowest loaded node...................
				num=i;
			}
	 	}
	
	//printf("In main num=%d\n",num);
		i=0;
		uzip();
		printf("value is %d cost is %d\n",value,cost);
		if((value+cost)<MAX)
		{
			strcat(arg,rfile);
			command(arg);
		}
		else
		{
			printf("\nJOB CANNOT BE SCHEDULED !!!!\n");
		}
		system("rm file");
		system("rm zipfile");
		
	//	system("rm vishnu.out");
	//	system("rm globus14.out");
	//	system("rm globus16.out");
	//	system("rm globus18.out");	
	}
}

/****************************************Function for Globus command execution************************************/

void command(char arr[]) 
{
	char cmd[200];
	int i,l=0;
	char arr2[20],arr3[20],name[20];
	arr2[0]='\0';
	arr3[0]='\0';
	name[0]='\0';
	strcat(arr2,arr);
	l=strlen(arr2);
	printf("arr2=%s\n",arr2);
	i=0;
	strcat(arr3,temp2);
	strcat(arr3,".out");
	printf("arr3=%s\n",arr3);
	cmd[0]='\0';
	if(num+1==1)
	{	
		nod[num]=nod[num]+cost;
		strcat(name,"vishnu.local");
		printf("name of node is %s\n",name);
		strcat(cmd,"globusrun-ws -submit -streaming -F https://");
		strcat(cmd,name);
		strcat(cmd,":8443/wsrf/services/ManagedJobFactoryService -so /home/globus/mainproject/output/");
		strcat(cmd,arr3);
		strcat(cmd," -f ");
		strcat(cmd,arr2);
      		printf("globus cmd is :%s\n",cmd);
		system(cmd);   //!!!!!!!!!!!!Remove comment!!!!!!!!!!!!!!!!!!!!!!!!
	}
	if(num+1==2)
	{
		nod[num]=nod[num]+cost;
		strcat(name,"globus14.local");
                printf("name of node is %s\n",name);
                strcat(cmd,"globusrun-ws -submit -streaming -F https://");
                strcat(cmd,name);
                strcat(cmd,":8443/wsrf/services/ManagedJobFactoryService -so /home/globus/mainproject/output/");
                strcat(cmd,arr3);
                strcat(cmd," -f ");
                strcat(cmd,arr2);
                printf("globus cmd is :%s\n",cmd);
                system(cmd);   //!!!!!!!!!!!!Remove comment!!!!!!!!!!!!!!!!!!!!!!!!

		
	}
	if(num+1==3)
	{
		nod[num]=nod[num]+cost;
		strcat(name,"globus16.local");
                printf("name of node is %s\n",name);
                strcat(cmd,"globusrun-ws -submit -streaming -F https://");
                strcat(cmd,name);
                strcat(cmd,":8443/wsrf/services/ManagedJobFactoryService -so /home/globus/mainproject/output/");
                strcat(cmd,arr3);
                strcat(cmd," -f ");
                strcat(cmd,arr2);
                printf("globus cmd is :%s\n",cmd);
                system(cmd);   //!!!!!!!!!!!!Remove comment!!!!!!!!!!!!!!!!!!!!!!!!

	}
	if(num+1==4)
	{
		nod[num]=nod[num]+cost;
		strcat(name,"globus18.local");
                printf("name of node is %s\n",name);
                strcat(cmd,"globusrun-ws -submit -streaming -F https://");
                strcat(cmd,name);
                strcat(cmd,":8443/wsrf/services/ManagedJobFactoryService -so /home/globus/mainproject/output/");
                strcat(cmd,arr3);
                strcat(cmd," -f ");
                strcat(cmd,arr2);
                printf("globus cmd is :%s\n",cmd);
                system(cmd);   //!!!!!!!!!!!!Remove comment!!!!!!!!!!!!!!!!!!!!!!!!
	}
	if(num+1==5)
	{
		nod[num]=nod[num]+cost;
		strcat(name,"vishnu.local");
                printf("name of node is %s\n",name);
                strcat(cmd,"globusrun-ws -submit -streaming -F https://");
                strcat(cmd,name);
                strcat(cmd,":8443/wsrf/services/ManagedJobFactoryService -so /home/globus/mainproject/output/");
                strcat(cmd,arr3);
                strcat(cmd," -f ");
                strcat(cmd,arr2);
                printf("globus cmd is :%s\n",cmd);
                system(cmd);   //!!!!!!!!!!!!Remove comment!!!!!!!!!!!!!!!!!!!!!!!!

	}

}
/**************************************Function for ZIP DATA*********************************************/
void uzip()
{
	char c,*t1,*t2,zip[30],cos[5],temp[25],zip1[50],zip2[50],zip4[25],zip5[25],perl[30],cfile[25],comp[30],fname[25];
	char temp3[25],temp4[25],temp5[25];
	int i=0,l=0,j=0;
	FILE *fp1=NULL,*fp2=NULL,*fp3=NULL,*fp4=NULL;
	zip[0]='\0';
	zip1[0]='\0';
	zip2[0]='\0';
	zip3[0]='\0';
	zip4[0]='\0';
	cfile[0]='\0';
	zip5[0]='\0';
	perl[0]='\0';
	cos[0]='\0';
	rfile[0]='\0';
	fname[0]='\0';
	comp[0]='\0';
	fp1=fopen("zipfile","r");//contain zip file names..............
	if(fp1==NULL)
		printf("NO FILE EXIST!!\n");
	else
	{
		while((c=fgetc(fp1))!='\n')
		{
			file[i]=c;//select each .zip file
			i++;
		}
		file[i]='\0';
	      	//printf("file is :%s\n",file);
		printf("zip file is %s\n",file);
/*		i=9;
		int j=0;
		l=strlen(file);
		printf("l=%d\n",l);
		while(i<l)
		{
			fname[j]=file[i];
			j++;
			i++;
		}
		fname[j]='\0';
		printf("fname is %s\n",fname);
		i=0;
		l=strlen(fname);
		while(fname[i]!='.')
		{
			
			zip1[i]=fname[i];
			i++;
		}
		zip1[i]='\0';
		printf("zip1 is %s\n",zip1);	*/
			
		for(i=strlen(file)-1,j=0;file[i]!='/';i--)
         	{
               		fname[j]=file[i];
               		j++;
         	}
         	fname[j]='\0';
		printf("fname is %s\n",fname);
		//while(fname[i]!='.')
                //{
                        
                  //      zip1[i]=fname[i];
                    //    i++;
               // }
                //zip1[i]='\0';

	//	printf("zip1 is %s\n",zip1);
		t1=strrev(fname);
		printf("original zip1 name is %s\n",t1);
		zip[0]='\0';
		strcat(zip,"unzip ");
		strcat(zip,file);
		printf("zip is %s\n",zip);
		//system(zip);// unzip the zip file
		
		//system("rm filelist");
		i=0;
		temp[0]='\0';
		temp2[0]='\0';
		strcat(temp,t1);
		while(temp[i]!='.')
		{
			temp2[i]=temp[i];
			i++;
		}
		temp2[i]='\0';
		printf("temp is %s\n",temp2);
		zip2[0]='\0';
		strcat(zip2,"ls ");
                strcat(zip2,"./");
                strcat(zip2,temp2);
                strcat(zip2,"/");
                strcat(zip2,"*.c > cpfile");
                printf("zip2 is %s\n",zip2); 
                system(zip2);// Add all .c file names into filelist2

	        zip2[0]='\0';
		strcat(zip2,"ls ");
		strcat(zip2,"./");
		strcat(zip2,temp2);
		strcat(zip2,"/");
		strcat(zip2,"*.rsl > rslfile");
		system(zip2);
	      	fp2=fopen("cpfile","r");
		if(fp2==NULL)
			printf("NO FILE EXIST IN FILELIST 2 !!\n");
		else
		{	i=0;
			 while((c=fgetc(fp2))!='\n')// THERE IS ONLY ONE C FILE ALLOWED ,NO OTHER C FILE DEPENDENCY 
			 {
				 cfile[i]=c;
				 i++;
			 }
			 cfile[i]='\0';
			 printf("cfile is %s\n",cfile);
		/*	 i=13;
                	  j=0;
                	 l=strlen(cfile);
                	 printf("l=%d\n",l);
			fname[0]='\0';
                         while(i<l)
                         {
                               fname[j]=cfile[i];
                               j++;
                               i++;
                	  }
                	fname[j]='\0';
                	printf("fname is %s\n",fname);
*/
			for(i=strlen(cfile)-1,j=0;cfile[i]!='/';i--)
         		{
               			fname[j]=cfile[i];
               			j++;
         		}
         		fname[j]='\0';
			printf("fname is %s\n",fname);
			t2=strrev(fname);
			printf("original fname is %s\n",t2);
			i=0;
			temp3[0]='\0';
			strcat(temp3,t2);
			while(temp3[i]!='.')
			{
				 
				zip3[i]=temp3[i];//convert example.c-->example(executable)
				 i++;
 			}
			zip3[i]='\0';
			printf("zip3 is %s\n",zip3);
			zip4[0]='\0';
			 strcat(zip4,"gcc -S ");
			 //strcat(zip4,zip3);
			 //strcat(zip4," ");
			 strcat(zip4,cfile);
			 printf("zip4 is %s\n",zip4);
			system(zip4);
			comp[0]='\0';
			strcat(comp,"gcc ");
			strcat(comp,cfile);
			strcat(comp," -o ");
			strcat(comp,zip3);
			system(comp);
			printf("compilation is %s\n",comp);
			// system(zip4);// gcc -S example.c (generate assembly file ie., example.s)
			 zip5[0]='\0';
			 strcat(zip5,zip3);
			 strcat(zip5,".s");
			 perl[0]='\0';
			 strcat(perl,"perl cost.pl ");
			 strcat(perl,zip5);
			printf("perl is %s\n",perl);
			 system(perl);// perl cost.pl example.s(To find cost)cost file generated
			fp3=fopen("cost","r");
			if(fp3==NULL)
				printf("NO COST FILE\n");
			else
			{	
				i=0;
				cos[0]='\0';
				while((c=fgetc(fp3))!='\n')
				{
					cos[i]=c;//cost of process
					i++;
				}
				cos[i]='\0';
				cost=atoi(cos);
				printf("cost=%d\n",cost);
								
			}	
			fp4=fopen("rslfile","r");
			if(fp4==NULL)
				printf("NO RSL FILE\n");
			else
			{
				i=0;
				rfile[0]='\0';
				while((c=fgetc(fp4))!='\n')
				{
					rfile[i]=c;
					i++;
				}
				rfile[i]='\0';
				printf("rfile is %s\n",rfile);
				rsl(rfile);
				temp4[0]='\0';
				strcat(temp4,"rm ");
				strcat(temp4,rfile);
				system(temp4);
				printf("temp4 is %s\n",temp4);
				temp5[0]='\0';		
				strcat(temp5,"mv ");
				strcat(temp5,temp2);
				strcat(temp5,".rsl ./");
				strcat(temp5,temp2);
				strcat(temp5,"/");
				system(temp5);
				printf("copy is %s\n",temp5);
			}


		
			 //system("rm filelist2");
			 
			
			 //system("perl cost.pl ");
		}



	}
}
void rsl(char *arr5)
{
	FILE *f1=NULL,*f2;
	char filename[30],filename1[30],c,*t,source[50]="gsiftp://dayanand.globus/home/globus/mainproject/";
	int i=0,j=0,d=0;
	printf("arr5 is %s\n",arr5);
	char path[100]="/home/globus/mainproject/";
	strcat(path,zip3);
	strcat(source,arr5);
	f1=fopen(arr5,"r");
	for(i=strlen(arr5)-1,j=0;arr5[i]!='/';i--)
         {
               filename[j]=arr5[i];
               j++;
         }
         filename[j]='\0';
	printf("filename is %s\n",filename);
	t=strrev(filename);
	printf("original name is %s\n",t);
	f2=fopen(t,"w");
	if(f1==NULL)
		printf("NO FILE OPERATION\n");
	else
	{
		do
		{
			c=fgetc(f1);
			fprintf(f2,"%c",c);
		}while(c!='\n');
		do
		{
			c=fgetc(f1);
			fprintf(f2,"%c",c);
		}while(c!='>');
		fprintf(f2,"%s",path);
		while(c=fgetc(f1))
		{
			if(c=='<')
			{
				fprintf(f2,"%c",c);
				break;
			}
		}
		do
		{
			c=fgetc(f1);
			fprintf(f2,"%c",c);
		}while(c!='>');
		char p; 
                       /*  zip5[0]='\0';
                         strcat(zip5,zip3);
                         strcat(zip5,".s");
                         perl[0]='\0';
                         strcat(perl,"perl cost.pl ");
                         strcat(perl,zip5);
                   */


//..................................................................................

		 p=fgetc(f1);
			printf("charcter=%c",p);

		fprintf(f2,"%c",p);
		while(p!=EOF){
		   c=fgetc(f1);
//		  printf("%c",c);
		   if(p=='<'){
			if(c=='s'){
				fprintf(f2,"%c",c);
				while(c=fgetc(f1)){
					fprintf(f2,"%c",c);
					if(c=='>'){
						break;
					}
				}

				char c1[50];
				c1[0]='\0';
				strcat(c1,source);
				int i=0;
				while(c1[i]!='\0'){
					fprintf(f2,"%c",c1[i]);
					i++;
				}
				while(c=fgetc(f1)){
				//	printf("c is %c\n",c); 
				 	if(c=='<'){
						fprintf(f2,"%c",c);
						break;
					}
					else{}
				}
				
				break;
			}
		   }
		   fprintf(f2,"%c",c);
		  p=c;
	       
		
			
		
		}


                fprintf(f2,"%c",p);
                while(p!=EOF){
                   c=fgetc(f1);
                   if(p=='<'){
                        if(c=='d'){
                                fprintf(f2,"%c",c);
                                while(c=fgetc(f1)){
                                        fprintf(f2,"%c",c);
                                        if(c=='>'){
                                                break;
                                        }
                                }

                                //char c1[]="neeraj";
				char c1[50];
				if(num+1==1)
				{
					strcat(c1,"gsiftp://globus14.local/home/guser02/mainproject/Client__code/");
				}
				if(num+1==2)
				{
					strcat(c1,"gsiftp://globus15.local/home/guser03/mainproject/Client__code/");
				}
				if(num+1==3)
				{
					strcat(c1,"gsiftp://globus16.local/home/guser04/mainproject/Client__code/");
				}
				 if(num+1==4)
				{
					strcat(c1,"gsiftp://globus18.local/home/guser05/mainproject/Client__code/");
				}
				if(num+1==5)
				{
					strcat(c1,"gsiftp:/vishnu.local/home/guser01/mainproject/Client__code/");
				}
				c1[0]='\0';
				
                                int i=0;
                                while(c1[i]!='\0'){
                                        fprintf(f2,"%c",c1[i]);
                                        i++;
                                }
				while(c=fgetc(f1)){
					if(c=='<'){
						fprintf(f2,"%c",c);
						break;
					}
				}
                                break;
                        }
                   }
                   fprintf(f2,"%c",c);
                  p=c;
                 



                }
		p=fgetc(f1);
		fprintf(f2,"%c",p);
		while(c=fgetc(f1)){
			if(p=='r'){
				if(c=='>'){
					//printf("fsdfsdfsdfsdf");
					fprintf(f2,"%c",c);
					break;
				}
			}
			fprintf(f2,"%c",c);
			p=c;
				
		}
			while((c=fgetc(f1))!=EOF)
			{
				fprintf(f2,"%c",c);
			}


//.................................................................................................
		


	/*	c=fgetc(f1);
		fprintf(f2,"%c",c);
		i=0;
		while((c=fgetc(f1))!=EOF)
		{
			while(c!='\n')
			{
				filename1[i]=c;
				i++;
				c=fgetc(f1);
			}
		
		if((d=strcmp(filename1,"<transfer>"))!=0)
			fprintf(f2,"%s",filename1);
		else
			fprintf(f2,"%s",filename1);

		} */

		fclose(f1);
		fclose(f2);

	}
}
/***************************************Function for RSL ***********************************************/
/*void rsl(char *arr5)
{	
	int a,i,j,d=0;
	char c,ch,file1[200],arr7[200],nodename[20],filename[30];
	FILE *f1=NULL,*f2;
	file1[0]='\0';
	a=strlen(arr5);
	printf("arr5 is %s\n",arr5);
	char path[100]="/home/globus/mainproject/";
	strcat(path,zip3);
	f1=fopen(arr5,"r");
	f2=fopen("tmp.txt","w");
	if(f1==NULL)
		printf("NO FILE EXIST!!\n");
	else
	{
	//	printf("11111111111111\n");
		while((c=fgetc(f1))!=EOF)
		{
			i=0;
			j=0;
			file1[0]='\0';
			file2[0]='\0';
			nodename[0]='\0';
			filename[0]='\0';
			arr7[0]='\0';
			while(c!='\n')
			{
				file1[i]=c;
				i++;
				c=fgetc(f1);
				fprintf(f2,"%c",c);
			}
			fprintf(f2,"\n");
			file1[i]='\0';	
			//printf("file1's content is %s\n",file1);
			if((d=strcmp(file1,"<job>"))==0)
			{	i=0;
				while(c=fgetc(f1))
				{
					fprintf(f2,"%c",c);
					if(c=='>')
						break;
				}
				fprintf(f2,"%s",path);
//				while((c=fgetc(fp1))!='<')
//				{
//					file2[i]=c;
//					i++;
//				}
//				file2[i]='\0';
				//printf("file2's content is %s\n",file2);
				for(i=0;i<16;i++)
        			{			
                			if(i>7)
                			{
                        			nodename[j]=file2[i];
                        			j++;
                			}
                			else
                        			i++;
        			}
        			nodename[j]='\0';
        			//printf("Nodename=%s\n",nodename);
        			for(i=strlen(file2)-1,j=0;file2[i]!='/';i--)
        			{
                			filename[j]=file2[i];
			                j++;
        			}
        			filename[j]='\0';
			        //printf("Reversed filename is %s\n",filename);
        			char *t;
        		//	t=strrev(filename);// Function for string reversal...............
				// printf("Original filename is %s\n",t);
			        strcat(arr7,"globus-url-copy ");
		                strcat(arr7,file2);
	                        strcat(arr7," gsiftp:///dayanand.globus/home/globus/mainproject/input_files/");//NEED TO CORRECT THE FOLDER
                                strcat(arr7,nodename);  //specify where to copy the file ??????????????
                                strcat(arr7,"/");
				strcat(arr7,t);
				//printf("arr7[]=%s\n",arr7);
                         //       system(arr7);
			}
		}
	}
}*/
	
/***************************************Function for reversing the string**********************************************/
char *strrev(char rev[])
{
        int i,j;
        char temp[15],a;
        temp[0]='\0';
        j=strlen(rev)-1;
        //or(i=0,j=strlen(rev)-1;j>=0;i++,j--)
        for(i=0;j>=0;i++,j--)
        {
                a=rev[j];
                temp[i]=a;
        }
        j=strlen(rev)-1;
        for(i=0;i<=j;i++)
        {
                rev[i]=temp[i];
        }
        rev[i]='\0';
        return(rev);
}


/***************************Function for redirecting output file into nodes********************************/
/*void redirect()
{
        char ch,filename[10],node[10],arr[10];
        int i=0;
        FILE *fp;
        //while(1)
        //{
	       for(i=0;i<10;i++)
                {
                        filename[i]='\0';
                        node[i]='\0';
                        arr[i]='\0';
                }
                system("ls -tr *.out > filelist2");  //create the filelist
                fp=fopen("filelist2", "r");
                while((ch=fgetc(fp))!='\n')  //store the first line of the file in a character array
                {
                        filename[i]=ch;
                        i++;
                }
                filename[i]='\0';
                rewind(fp); 
                i=0;
                while((ch=fgetc(fp))!='_')  // store the node name in a character array
                {
                        node[i]=ch;
                        i++;
                }
                node[i]='\0';

//              printf("Hello");                                        // send the file to the corresponding node
                if((i=strcmp(node,"node1"))==0)
                        system("globus-url-copy file://serverhostname gsiftp:// clientpath");
                        i++;    
                else if((i=strcmp(node,"node2"))==0)
//                      system("globus-url-copy file://serverhostname gsiftp:// clientpath");
    
                        i++;
                else if((i=strcmp(node,"node3"))==0)
//                   system("globus-url-copy file://serverhostname gsiftp:// clientpath");

                        i++;
		               else if((i=strcmp(node,"node4"))==0)
//                      system("globus-url-copy file://serverhostname gsiftp:// clientpath");
//
                        i++;
                else if((i=strcmp(node,"node5"))==0)
                //              system("globus-url-copy file://serverhostname gsiftp:// clientpath");
                //
                        i++;
                else
                        printf("Error while redirecting\n");
        //}
        strcat(arr,"rm ");
        strcat(arr,node);
        system(arr);
}*/


