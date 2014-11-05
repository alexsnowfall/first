//finding the maximum weighted path through the tree.

#include<stdio.h>
#include<malloc.h>


//Sample code to read in test cases:
int main(int argc,char *argv[])
{

int i,j,len,row;row=-1;
long long int temp[101][101];
char *line;line=(char*)malloc(sizeof(char)*1024);
FILE *f;
f = fopen(argv[1], "r");
while (fgets(line, 1024, f)) {

        // Skip empty lines
        if (line[0] == '\n') {
            continue;
        }
        row++;
        // Do something with the line
        for(i=0;i<=row;i++){
             sscanf(line,"ll%d%n",&temp[row][i],&len);
             line+=len;
         }
    }
    for(i=0;i<row;i++){for(j=0;j<row;j++){temp[i][j]=0;}}
       for(i=row-1;i>=0;i--){
       for(j=0;j<=i;j++){
           temp[i][j]+=(temp[i+1][j]>temp[i+1][j+1])?temp[i+1][j]:temp[i+1][j+1];
       }
   }
   printf("%lld",temp[0][0]);

    return 0;
}
