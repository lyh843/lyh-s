#include<stdio.h>
#include<math.h>
//个人系统
int main(void)
{
    char name[13] = "Xiaojing Nan";
    name[13] = "A";
    char gender = 'F';

    int birth_month = 5;
    int birth_day = 20;
    int birth_year = 1902;

    char weekday[] = "Tuesday";

    double score_c = 100;
    double score_music = 90;
    double score_medicine = 80;

    double mean = (score_c + score_music + score_medicine) / 3 ;
    double sum_square = pow(score_c - mean, 2) + pow(score_music, 2) + pow(score_medicine, 2);
    double sd = sqrt(sum_square);

    int rank =5;
    printf("%s\t%c\n",name, gender);
    printf("%.2d-%.2d-%.4d\t%.3s.\n", birth_month, birth_day, birth_year, weekday);
    printf("%.f\t%d%%", mean, rank);
    printf("%d\n%s\nelement of 12: %c\nelement of 13: %c\n", sizeof(name), name, name[11], name[12]);



}