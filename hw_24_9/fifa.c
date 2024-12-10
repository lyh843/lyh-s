#include<stdio.h>
#include<stdlib.h>
#define N 21//名字长度
#define M 1001//球队数量
int num_team = 0;
typedef struct
{
    char name_players[N];
    int attack;
    int defend;
    int organize;
}player;
typedef struct 
{
    player players[11];
    char name_team[N];
    int sum_attack;
    int sum_defend;
    int sum_organize;
}team;
team teams[M];
int f_cmp_attack(const void *a, const void *b)
{
    team *team1 = (team *)a;
    team *team2 = (team *)b;
    team1 -> sum_attack = 0;
    team2 -> sum_attack = 0;
    for(int i = 0; i < 11; i++)
    {
        team1 -> sum_attack += team1 -> players[i].attack;
        team2 -> sum_attack += team2 -> players[i].attack;
    }
    return ((team2 -> sum_attack) - (team1 -> sum_attack));
}
int f_cmp_defend(const void *a, const void *b)
{
    team *team1 = (team *)a;
    team *team2 = (team *)b;
    team1 -> sum_defend = 0;
    team2 -> sum_defend = 0;
    for(int i = 0; i < 11; i++)
    {
        team1 -> sum_defend += team1 -> players[i].defend;
        team2 -> sum_defend += team2 -> players[i].defend;
    }
    return ((team2 -> sum_defend) - (team1 -> sum_defend));
}
int f_cmp_organize(const void *a, const void *b)
{
    team *team1 = (team *)a;
    team *team2 = (team *)b;
    team1 -> sum_organize = 0;
    team2 -> sum_organize = 0;
    for(int i = 0; i < 11; i++)
    {
        team1 -> sum_organize += team1 -> players[i].organize;
        team2 -> sum_organize += team2 -> players[i].organize;
    }
    return ((team2 -> sum_organize) - (team1 -> sum_organize));
}
void f_input()
{
    scanf("%d", &num_team);
    for(int i = 0; i < num_team; i++)
    {
        scanf("%s", teams[i].name_team);
        for(int j = 0; j < 11; j++)
        {
            scanf("%s", teams[i].players[j].name_players);
            scanf("%d", &teams[i].players[j].attack);
            scanf("%d", &teams[i].players[j].defend);
            scanf("%d", &teams[i].players[j].organize);
        }
    }
}
void f_rank_attack()
{
    qsort(teams, M, sizeof(team), f_cmp_attack);
    for(int i = 0; i < num_team; i++)
    {
        printf("%s ", teams[i].name_team);
    }
    printf("\n");
}
void f_rank_defend()
{
    qsort(teams, M, sizeof(team), f_cmp_defend);
    for(int i = 0; i < num_team; i++)
    {
        printf("%s ", teams[i].name_team);
    }
    printf("\n");
}
void f_rank_organize()
{
    qsort(teams, M, sizeof(team), f_cmp_organize);
    for(int i = 0; i < num_team; i++)
    {
        printf("%s ", teams[i].name_team);
    }
    printf("\n");
}
int main(void)
{
    f_input();
    f_rank_attack();
    f_rank_defend();
    f_rank_organize();
    return 0;
}