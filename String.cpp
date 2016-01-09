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