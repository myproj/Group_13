#include<stdio.h>
#include<string.h>
int total_lines=0;
int numpresent(int array[], int num)
{
	int flagnum=0;
	for(int i=0;i<50000;i++)
	{
		if(array[i]==num)
		{
			flagnum=1;
			break;
		}
	}
	return flagnum;
}

	 

int matchpattern(char text[], char pattern[]) {
  int a, b, c, position = -1; 
  if ((unsigned)strlen(pattern) > (unsigned)strlen(text)) {
    return -1;
  }
 
  for (a = 0; a <= (unsigned)strlen(text) - (unsigned)strlen(pattern); a++) {
    position = c = a;
 
    for (b = 0; b < (unsigned)strlen(pattern); b++) {
      if (pattern[b]=='?'){
      	if( (text[c]>=48 && text[c]<=57) || (text[c]>=97 && text[c]<=122) )
	  c++;
      }
      else if (pattern[b] == text[c]) {
        c++;
      }
      else {
        break;
      }
    }
    if (b == (unsigned)strlen(pattern)) {
      return position;
    }
  }
 
  return -1;
}

int readfromfile(char pattern[], char filename[], int linenum[])
{
	FILE *fptr;
	fptr=fopen(filename,"r");
	char input[50000];
	char *in=input;
	size_t inputsize=50000;
	size_t ch;
	int count=0;int flag=0;

		for(int j=0;j<50000;j++)
		{
			if(ch=getline(&in, &inputsize, fptr))count++;
				//printf("%zu \t %s \n",ch,input);
			if(matchpattern(input,pattern)!=-1)
			{
				if(numpresent(linenum,count)==0){total_lines++;			
 					printf("%d\t%d\t%s\n",total_lines,count,input);}
				flag=1; 
			}
						
			if(ch==EOF)
				break;	
		}
		
		//if(flag!=1){ printf("No Match Found!"); }
	
	fclose(fptr);
	return flag;	

}

void readfromterminal(char pattern1[], char pattern2[], char instring[])
{
	int flag1=0;int flag2=0;
  	if(matchpattern(instring,pattern1)!=-1){
		flag1=1;}
	if(matchpattern(instring,pattern2)!=-1){
		flag2=1;}
	//printf("%d %d\n",flag1,flag2);
	if(flag1 || flag2)
		printf("%s\n",instring);
	else{
		printf("NoT found\n");}
}

int main(int argc,char *argv[])
{
	//printf("h!");
	//printf("%d \t %s \t %s \t %s \t %zu\n",argc,argv[0],argv[1],argv[2],strlen(argv[1]));
	int x=(unsigned)strlen(argv[1]);
	int linenum[50000];
	for(int p=0;p<50000;p++)
		linenum[p]=-1;
	//printf("%d\n",x);
	char ignoreques[x];
	for(int s=0;s<(unsigned)strlen(argv[1]);s++)
		{
			int flag=0;
			if(argv[1][s]=='?')
			{
				for(int h=s;h<(unsigned)strlen(argv[1])-1;h++)
					ignoreques[h]=argv[1][h+1];
				flag=1;
			}
			else{
			ignoreques[s]=argv[1][s]; }
			if(flag==1)
				break;
		}
	//printf("%s\n",ignoreques);
	

	if(argc==2)
	{
		//printf("Reading From The Terminal\n");
		char instring[50];
		printf("Enter the string\n");
		while(1)
		{
			gets(instring);
			readfromterminal(argv[1],ignoreques,instring);
		}
	}
	if(argc==3)
	{
		//printf("hello!");
		int x,y;
		printf("Total number of lines=%d\n",total_lines);
		x=readfromfile(ignoreques,argv[2],linenum);
		printf("Total number of lines=%d\n",total_lines);
		y=readfromfile(argv[1],argv[2],linenum);
		if(!(x || y)){
			printf("NoT found\n");}
		printf("Total number of lines=%d\n",total_lines);
		//printf("hello!");
	}

	return 0;
}