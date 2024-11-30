#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
char* interleaveString(char* s1, char* s2);
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        char s1[3000] = {0};
        char s2[3000] = {0};
        // char *s1 = calloc(3000,sizeof(char));
        // char *s2 = calloc(3000,sizeof(char));
        // if(s1 == NULL||s2 == NULL) {
        //     return 1;
        // }
        char d = getchar();
        int len1 = 0;
        do {
            char c = getchar();
            s1[len1] = c;
            //*(s1+len1) = c;
            len1++;
        }while(s1[len1 - 1] != ';');//(*(s1+len1-1)!=';');
        len1--;
        s1[len1] = '\0';//*(s1+len1) = '\0';
        int len2 = 0;
        do {
            char c = getchar();
            s2[len2] = c;//*(s2+len2) = c;
            len2++;
        }while(s2[len2 - 1] != ';');//(*(s2+len2-1)!=';');
        len2--;
        s2[len2] = '\0';//*(s2+len2) = '\0';
        int grab1,grab2,size;
        scanf("%d",&grab1);
        char a = getchar();
        scanf("%d",&grab2);
        char b = getchar();
        scanf("%d",&size);
        char ans[3000] = {0};
        //char *ans = calloc(3000,sizeof(char));
        int count1 = 1,count2 = 1;
        bool flag1 = true;
        bool flag2 = true;//分别用于记录s1或s2是否已经用完了、不能再取了
        while((count1-1)*grab1+(count2-1)*grab2<size && (flag1||flag2)){
            if(count1<=count2 && flag1) {
//count1和count2用于控制对哪个字符串进行操作  同时记录已操作的长度
                char new_s1[3000] = {0};
                //char *new_s1 = calloc(3000,sizeof(char));
                if(count1*grab1<=len1) {
//count1*grab1就是目前取用过的总长度  与s1的长度比较  小于等于len1表示可以取到一整个grab1的长度去  当然这里还没有考虑size是否容纳的下的问题
                    for(int j = 0;j<grab1&&strlen(ans)+j+1<size;j++) {
                        new_s1[j] = s1[j + (count1 - 1) * grab1];
                        //*(new_s1+j) = *(s1+j+(count1-1)*grab1);
                    }
                    interleaveString(ans,new_s1);
                    //ans = interleaveString(ans,new_s1);
                    if(count1*grab1==len1&&strlen(new_s1) == grab1)
//恰好用完了整个s1  并且我取下来新的要插入ans的s1的部分长度是grab  那s1已经用完了  flag1改变  不要再拿s1了
                        flag1 = false;
                    count1++;
                }
                else if(count1*grab1>len1) {
//大于len1说明不能取到一整个grab1的部分
                    for(int j = (count1-1)*grab1;j<len1;j++) {
                        new_s1[j - (count1 - 1) * grab1] = s1[j];
                        // *(new_s1+j-(count1-1)*grab1) = *(s1+j);
                    }
                    interleaveString(ans,new_s1);
                    // ans = interleaveString(ans,new_s1);
                    flag1 = false;
                    count1++;
                }
            }
            else if(count1<=count2&&!flag1){
                break;
            }
            else if(count1>count2 && flag2) {
                char new_s2[3000] = {0};
                // char *new_s2 = calloc(3000,sizeof(char));
                if(count2*grab2<=len2) {
                    for(int j = 0;j<grab2&&strlen(ans)+j+1<size;j++) {
                        new_s2[j] = s2[j + (count2 - 1) * grab2];
                        // *(new_s2+j) = *(s2+j+(count2-1)*grab2);
                    }
                    interleaveString(ans,new_s2);
                    // ans = interleaveString(ans,new_s2);
                    if(count2*grab2==len2&&strlen(new_s2) == grab2)
                        flag2 = false;
                    count2++;
                }
                else if(count2*grab2>len2) {
                    for(int j = (count2-1)*grab2;j<len2;j++) {
                        new_s2[j - (count2 - 1)*grab2] = s2[j];
                        // *(new_s2+j-(count2-1)*grab2) = *(s2+j);
                    }
                    interleaveString(ans,new_s2);
                    // ans = interleaveString(ans,new_s2);
                    flag2 = false;
                    count2++;
                    
                }
            }
            else if(count1>count2&&!flag2){
                break;
            }
        }
        if((count1-1)*grab1<len1) {
//对于s1,s2 剩余的部分（如果有）要整个放进ans里  以下就是判断怎么放
            char new_s1[3000] = {0};
            //char *new_s1 = calloc(3000,sizeof(char));
            for(int j = (count1-1)*grab1;j<len1&&strlen(ans)+j-(count1-1)*grab1+1<size;j++) {
                new_s1[j - (count1 - 1) * grab1] = s1[j];
                // *(new_s1+j-(count1-1)*grab1) = *(s1+j);
            }
            interleaveString(ans,new_s1);
        }
        if((count2-1)*grab2<len2) {
            char new_s2[3000] = {0};
            // char *new_s2 = calloc(3000,sizeof(char));
            for(int j = (count2-1)*grab2;j<len2&&strlen(ans)+j-(count2-1)*grab2+1<size;j++) {
                new_s2[j - (count2 - 1)*grab2] = s2[j];
                // *(new_s2+j-(count2-1)*grab2) = *(s2+j);
            }
            interleaveString(ans,new_s2);
        }
        printf("%s\n",ans);
    }
    return 0;
}
char* interleaveString(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i = 0;i<len2;i++) {
        *(s1+len1+i) = *(s2+i);
    }
    return s1;
}