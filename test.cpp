#include <stdio.h>
#include <math.h>
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    if(m>n){
        int temp=m;
        m=n;
        n=temp;
    }
    int f=1;
    for(int i=m;i<=n;i++){
        if(i<2){
            continue;
        }
        int is_prime=1;
        int limit = (int)sqrt(i);

        for(int j=2;j<=limit;j++){
            if(i%j==0){
                is_prime=0;
                break;
            }
        }
        if(is_prime){
            if(!f){
                printf(" ");
            }
            printf("%d",i);
            f=0;
        }
    }

    return 0;
}