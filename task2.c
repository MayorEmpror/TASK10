#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Perc(int num,int perc,float val){
    perc+= 1;
    val =( num /100 )* perc;
   if(perc <=20){
     printf("%d percent of %d is %f\n",perc,num,val);
    Perc(num,perc,val);
   }
   
}


int main(){
    int num = 1100;
    int perc = 0;
    float val = 0;
    printf("Enter number: ");
    scanf("%d",&num);
    Perc(num,perc,val);
    return 0;

}