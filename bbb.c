//
// Created by ASUS on 2024/11/1.
//
#include<stdio.h>
    int main(void)
    {
        /*********Begin*********/
        int n;
        double sum=0;
        scanf("%d",&n);

        printf("the number of students:");
        printf("the scores:");
        if(n<=0)
            printf("average=0.00");return 0;

        for(int i = 0;i<n;i++){
            double score;
            scanf("%f",&score);
            sum += score;
        }
        printf("\n");
        printf("average=%.2f",sum/n);


        /*********End**********/
         return 0;
    }