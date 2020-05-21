#include<stdio.h>/*standard input output*/
#include<string.h>/*string related operation functions*/
#include<stdlib.h>/*standard library*/
#include<io.h>/*buffer related read and write functions*/
int word=0;
int cha=0;
int num=0;
int  countWords(char *file)
{
       FILE *f;/*declare a pointer to a file type*/
       char ch;
       f=fopen(file,"r");
       if(NULL==(f=fopen(file,"r")))
       {
             /*to determine whether the file is empty*/
             printf("FILE IS NULL");
        }
        else
         
              while(!feof(f))
              {
               /*if pointer does not reach to the end of the file,loop*/
                  ch=fgetc(f);/*assign a character in the file to ch*/
                   if((ch >= 'a'&&ch <= 'z')||(ch>='A'&&ch<='Z')||ch=='_')
					{
                  word=1;
					}
				 
			       else if(word) 
				   {
                  word=0;   
                  num++;   
               
				   }
		 
			  }
		  fclose(f);
          printf("单词个数：%d",num);
          return 0;
}
int countChar(char *file)
{
           FILE *f;
           char a;
           f=fopen(file,"r");
           if(NULL==(f=fopen(file,"r")))
          {
           printf("file is NULL");
           }
           else
		   {
              while(!feof(f))
               {
                a=fgetc(f);
                if((a >= 'a'&&a <= 'z')||(a>='A'&&a<='Z')||(a==' ')||(a=='\n')||(a=='\t'))
                {
                 cha++;
                } 
			  }
		   }
		  fclose(f);
          printf("字符个数:%d",cha);
          return 0;     
}

int searchfile(void)//find .txt  file
{
    struct _finddata_t filefind;
    long handle;
    int t=0;
       if( (handle=_findfirst( "E:\\wordcount\\test\\*txt", &filefind)) == -1L ) 
        {
        printf( ".TXT file not found\n");
        }
    else
	do{
		t++;
        printf("find txt file:%s\n", filefind.name); 
    }while (_findnext(handle,&filefind)==0);
	_findclose(handle);
	printf("number of txt file：%d\n",t);
	 return 0;
}

int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("File is Null\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-w")) 
		countWords(argv[2]);                
        else if(!strcmp(argv[1],"-c"))  
		countChar(argv[2]);                
		else
        printf("NULL\n");
	    printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	return 0;
}