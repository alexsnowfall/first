/*
Roy's Life Cycle
Max. Score 100
Roy is going through the dark times of his life. Recently his girl friend broke up with him and to overcome the pain of acute misery he decided to restrict himself to Eat-Sleep-Code life cycle. For N days he did nothing but eat, sleep and code.

A close friend of Roy kept an eye on him for last N days. For every single minute of the day, he kept track of Roy's actions and prepared a log file.

The log file contains exactly N lines, each line contains a string of length 1440 ( i.e. number of minutes in 24 hours of the day).
The string is made of characters E, S, and C only; representing Eat, Sleep and Code respectively. ith character of the string represents what Roy was doing during ith minute of the day.

Roy's friend is now interested in finding out the maximum of longest coding streak of the day - X.
He also wants to find the longest coding streak of N days - Y.
Coding streak means number of C's without any E or S in between.

See sample test case for clarification.

Input:
First line of each file contains N - number of days.
Following N lines contains a string of exactly 1440 length representing his activity on that day.

Output:
Print X and Y separated by a space in a single line.

Constraints:
1 ≤ N ≤ 365
String consists of characters E, S, and C only.
String length is exactly 1440.

Note: The sample test case does not follow the given constraints on string length to avoid large data. It is meant only for explanation. We assure you that the hidden test files strictly follow the constraints.

Sample Input (Plaintext Link)
4
SSSSEEEECCCCEECCCC
CCCCCSSSSEEECCCCSS
SSSSSEEESSCCCCCCCS
EESSSSCCCCCCSSEEEE

Sample Output (Plaintext Link)
7 9

Explanation
Longest coding streak for each day is as follows: 
Day 1: 4 
Day 2: 5 
Day 3: 7 
Day 4: 6 
Maximum of these is 7, hence X is 7. 

Now in order to find longest coding streak of the all days, we should also check if Roy continued his coding from previous days. 
As in the sample test case, Roy was coding for 4 minutes at the end of Day 1 and he continued to code till 5 more minutes on Day 2. Hence the longest coding streak is 4+5 equals 9. There is no any other coding streak larger than this. So the longest coding streak of all days is 9.
*/

#include <stdio.h>
#define MAX 1440
main()
{
int n;
scanf("%d",&n);
int i=1;
int *last=malloc(sizeof(int)*n+1);
int *first=malloc(sizeof(int)*n+1); 
int max1=0;
for(i=0;i<n;i++){
    char *s;
    s=malloc(sizeof(char)*1441);
    scanf("%s",s);
    int j;
    int max=0;int count=0;
    for(j=0;j<MAX;j++){
        
        int flag=0;
        if(s[j]!='C'){continue;}
        if(j==0){flag=1;}
        count=1;j++;
        while(s[j]=='C' && j<MAX){
            count++;
            j++;    
        }
        if(flag){first[i]=count;}
        if(j==MAX && s[j-1]=='C'){last[i]=count;}
        if(count>max){max=count;}
    }
    //printf("%d\n",max);
    if(max>max1){max1=max;}
}
printf("%d ",max1);
int le1=0;int le=0;
first[n+1]=0;
/*for(i=0;i<n;i++){
    printf ("%d %d\n",first[i],last[i]); 
}*/
for(i=0;i<n;i++){
    le+=last[i];
    if(first[i+1]==MAX){continue;}
    le+=first[i+1];
    if(le>le1){le1=le;}
    le=0;
}
if(le>le1){le1=le;}
if(max1>le1){le1=max1;}
printf("%d",le1);
}
