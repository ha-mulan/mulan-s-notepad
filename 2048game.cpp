#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define LEFT 52
#define RIGHT 54
#define UP 56
#define DOWN 50
int score=0;
int gover_deter(int (*arr)[4]);
int inputer(int n,int (*arr)[4])
void left(int (*arr)[4]);
void showArr(int (*arr) [4]);
void real_left(int (*arr)[4]);
void real_up(int (*arr)[4]);
void up(int (*arr)[4]);
void real_right(int (*arr)[4]);
void right(int (*arr)[4]);
void copyer(int (*arr)[4],int (*brr)[4]);
int main(void){
    int key=0,n=1000,per=0,gover=0;
    int arr[4][4]={{2,0,0,0}};
    int brr[4][4]={0};
    puts("");
    puts("");
    puts("");
    puts("                           PRESS ANY BUTTON TO START!                       ");
    puts("");
    puts("");
    puts("");
    //showArr(arr);
    while(1){
    copyer(arr,brr);
    //showArr(arr);
    key=getch();
    switch(key){
        case LEFT:
        real_left(arr);
        break;
        case RIGHT:
        real_right(arr);
        break;
        case UP:
        real_up(arr);
        break;
        case DOWN:
        real_down(arr);
        break;
    }
if(cdeter(arr,brr)){
    //arr 안에 2나 4 생성
    srand((int)time(NULL));
    per=rand()%100+1;
    if(per<=80)
      gover=inputer(2,arr);
    else
      gover=inputer(4,arr);
    
}
clrscr();
showArr(arr);
//clrscr();
if(gover_deter(arr)==0)
    break;
 
}
//showArr(arr);
    return 0;
}
int gover_deter(int (*arr)[4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==0)
                return 1;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==arr[i][j+1])
                return 1;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(arr[j+1][i]==arr[j][i])
                return 1;
        }
    }
    return 0;
}
int inputer(int n,int (*arr)[4]){
    int low=0,cols=0,c=0,returner=0;
    srand((int)time(NULL));
    while(1){
        for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==0){
                c=1;
                i=4;
            }
        }
    }
    if(c==0)
        return returner;
         //srand((int)time(NULL));
         low=rand()%4;
         cols=rand()%4;
         if(arr[low][cols]==0){
             arr[low][cols]=n;
             returner=1;
             break;
         }
        
    }
    return returner;
}
void copyer(int (*arr)[4],int (*brr)[4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            brr[i][j]=arr[i][j];
        }
    }
}
int cdeter(int (*arr)[4],int (*brr)[4])//변한게 잇으면 1 리턴 아니면 0
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]!=brr[i][j])
                return 1;
        }
    }
    return 0;
}
void real_right(int (*arr)[4]){
    right(arr);
    for(int i=0;i<4;i++){
       for(int j=2;j>=0;j--){
           if(arr[i][j]==arr[i][j+1]){
           score+=arr[i][j];
           arr[i][j+1]=2*arr[i][j];
           arr[i][j]=0;
           right(arr);
           break;
           }
       } 
   }
}
void right(int (*arr)[4]){
    int memo,brr[4][4]={0};
   for(int i=3;i>=0;i--){
       for(int j=3,c=3;j>=0;j--){
          if(arr[i][j]!=0){
            brr[i][c]=arr[i][j];
              c--;
          }
       }
   }
   for(int i=0;i<4;i++){
       for(int j=0,c=0;j<4;j++){
            arr[i][j]=brr[i][j];    
       }
   }
}
void real_down(int (*arr)[4]){
    down(arr);
    for(int j=0;j<4;j++){
       for(int i=2;i>=0;i--){
           if(arr[i][j]==arr[i+1][j]){
           score+=arr[i][j];
           arr[i+1][j]=2*arr[i+1][j];
           arr[i][j]=0;
           down(arr);
           break;
           }
       }  
   }
}
void down(int (*arr)[4]){
    int memo,brr[4][4]={0};
   for(int i=0;i<4;i++){
       for(int j=3,c=3;j>=0;j--){
          if(arr[j][i]!=0){
            brr[c][i]=arr[j][i];
              c--;
          }
       }
   }
   for(int i=0;i<4;i++){
       for(int j=0,c=0;j<4;j++){
            arr[i][j]=brr[i][j];    
       }       
   }
}
void real_left(int (*arr)[4]){
    left(arr);
    for(int i=0;i<4;i++){
       for(int j=0;j<3;j++){
           if(arr[i][j]==arr[i][j+1]){
           score+=arr[i][j];
           arr[i][j]=2*arr[i][j];
           arr[i][j+1]=0;
           left(arr);
           break;
           }
       }       
   }
}
void left(int (*arr)[4]){
    int memo,brr[4][4]={0};
   for(int i=0;i<4;i++){
       for(int j=0,c=0;j<4;j++){
          if(arr[i][j]!=0){
            brr[i][c]=arr[i][j];
              c++;
          }
       }
   }
   for(int i=0;i<4;i++){
       for(int j=0,c=0;j<4;j++){
            arr[i][j]=brr[i][j];    
       }
   }
}
void real_up(int (*arr)[4]){
    up(arr);
    for(int i=0;i<4;i++){
       for(int j=0;j<3;j++){
           if(arr[j][i]==arr[j+1][i]){
            score+=arr[i][j];
           arr[j][i]=2*arr[j][i];
           arr[j+1][i]=0;
           up(arr);
           break;
           }
       }       
   }
}
void up(int (*arr)[4]){
    int memo,brr[4][4]={0};
   for(int i=0;i<4;i++){
       for(int j=0,c=0;j<4;j++){
          if(arr[j][i]!=0){
            brr[c][i]=arr[j][i];
              c++;
          }
       }
   }
   for(int i=0;i<4;i++){
       for(int j=0,c=0;j<4;j++){
            arr[i][j]=brr[i][j];    
       }
   }
}
void showArr(int (*arr) [4]){
    printf("\n");
    printf("\n");
    printf("\n");
    puts("made by ham~");
    printf("\n");
    printf("\n");
    printf("\n");
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        printf("%20d",arr[i][j]);
    }
    for(int k=0;k<2;k++)
            printf(" \n");
}
    printf("score: %30d \n",score);
}
