/************************************************************************
*
*   Description: string ,use squence structure and string's length putted in s[0]
*
*   Author & Data: JY Liu, 2016/01/08
*
************************************************************************/

#include "Main.h"

int BFMatching(char * s,char * t) //Brute-Force algorithm
{
	int i=1,j=1;
	while(i<=s[0] && j<=t[0]){
		if(s[i]==t[j]){
			i++;
			j++;
		}else{
			i=i-j+2;
			j=1;
		}
	}
	if(j>t[0])
		return i-j+1;
	else
		return 0;
}

void GetNext(char t[],int next[])
{
	next[1]=0;
	int j=1,k=0;
	while(j<t[0]){
		if(k==0 || t[j]==t[k]){
			j++; k++;
			next[j]=k;
		}else
			k=next[k];
	}
}

int KMPMatching(char s[],char t[])
{
	int * next=new int[t[0]+1];
	GetNext(t,next);

	int i=1,j=1;
	while(i<=s[0] && j<=t[0]){
		if(j==0 || s[i]==t[j]){
			i++; j++;
		}else{
			j=next[j];
		}
	}
	if(j==t[0]+1)
		return i-j+1;
	else
		return 0;
}