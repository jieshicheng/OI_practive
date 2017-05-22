#include <stdio.h>  
#include <string.h>  
      
void move(char* data, int from, int to)  
{  
    data[to] = data[from];  
    data[from] = '.';  
}  
      
int valid(char* data, int k)  
{  
    if(k<0 || k>=strlen(data)) return 0;  
    return 1;  
}  
      
void f(char* data)  
{  
    int i;  
    int tag;  
    int dd = 0;
      
    while(1) 
    {  
        tag = 0;  
        for(i=0; i<strlen(data); i++) 
        {  
            if(data[i]=='.') continue;  
            if(data[i]=='A') dd = 1;  
            if(data[i]=='B') dd = -1;  
      
            if(valid(data, i+dd) && valid(data,i+dd+dd) && data[i+dd]!=data[i] && data[i+dd+dd]=='.') 
            {   
                move(data, i, i+dd+dd);  
                printf("%s\n", data);  
                tag = 1;  
                break;  
            }  
        }  
      
        if(tag) continue;  
      
        for(i=0; i<strlen(data); i++) {  
            if(data[i]=='.') continue;  
            if(data[i]=='A') dd = 1;  
            if(data[i]=='B') dd = -1;             
      
            if(valid(data, i+dd) && data[i+dd]=='.') 
            {   
                // if(_________) 待填空的地方
                if( valid(data, i + dd + dd) && valid(data, i - dd) && data[i + dd + dd] == data[i - dd]) 
                    continue;
                move(data, i, i+dd);  
                printf("%s\n", data);  
                tag = 1;  
                break;  
            }  
        }  
        if(tag==0) break;                     
    }  
}  
      
int main()  
{  
    char data[] = "AAA.BBB";      
    f(data);  
    return 0;  
}  
