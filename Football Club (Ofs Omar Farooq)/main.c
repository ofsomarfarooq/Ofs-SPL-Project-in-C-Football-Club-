#include<stdio.h>

struct player{
        char name[50];
        int age;
        int rating;
        float value;
};typedef struct player Player;

struct club{
        char name[50];
        float budget;
        Player player[11];
};typedef struct club Club;

void new_club()
{
    Club club;
    float sum=0,Extra;
    printf("Write your club name:");
    fflush(stdin);
    gets(club.name);
    printf("Write your club budget:");
    scanf("%f",&club.budget);

    FILE *All_Clubs;
    All_Clubs = fopen("All Clubs","a");
    fprintf(All_Clubs,"\t\t\t\t\t%s\n",club.name);
    fclose(All_Clubs);

    FILE *Clubs;
    Clubs = fopen(club.name,"a");
    fprintf(Clubs,"Name     : %s\nBudget  : %.4f",club.name,club.budget);
    fprintf(Clubs,"\nAll Players Information:\n");
    Player player[11];
    fprintf(Clubs,"\nName\t\tAge\t\tRating\t\tValue");
    fprintf(Clubs,"\n------\t\t------\t\t------\t\t------\n");
    int n;
    printf("\t\t\tHow many players you want to add : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nPlayer %d:\n",i+1);
        printf("Name:");
        fflush(stdin);
        gets(player[i].name);
        printf("Age: ");
        scanf("%d",&player[i].age);
        printf("Rating(out of 100):");
        scanf("%d",&player[i].rating);
        printf("Value: ");
        scanf("%f",&player[i].value);

        FILE *Players;
        Players = fopen("players","a");
        fprintf(Players,"\n%s\t\t%d\t\t%d\t\t%.4f $US\t\t%s",player[i].name,player[i].age,player[i].rating,player[i].value,club.name);
        fprintf(Clubs,"\n%s\t\t%d\t\t%d\t\t%.4f $US",player[i].name,player[i].age,player[i].rating,player[i].value);
        sum += player[i].value;
        fclose(Players);
    }

    fprintf(Clubs,"\n----------------------------------------------------------------");
    Extra = club.budget-sum;
    if(Extra <0)
    {

        printf("\a\t\t\t[%s Has Crossed The Budget Limit In This Season]\n\t\t\t\t[%.4f $US Due in Bank]\n",club.name,fabs(Extra));
        fprintf(Clubs,"\nRemaining budget:\t\t\t\t%.4f $US(Due)",fabs(Extra));
    }
    else if(Extra > 0)
    {
        printf("\t\t\t[%s Has Made A Good Budget]\n\t\t\t[%.4f $US are remaining]",club.name,Extra);
        fprintf(Clubs,"\nRemaining budget:\t\t\t\t%.4f $US",Extra);

    }
    else if (Extra == 0.0000)
    {
        printf("\t\t\t[%s Has Made A Perfect Budget]\n\t\t\t[Nothing is Remaining or Due]",club.name);
        fprintf(Clubs,"\nRemaining budget:\t\t\t\t%.4f",Extra);
    }

    fclose(Clubs);
}
void see_club()
{
    char ch;
    Club club;
    printf("\t\t\tWrite any Club From This Season:\n");

    FILE *All_Clubs;
    All_Clubs = fopen("All Clubs","r");
    while(!feof(All_Clubs))
    {
        ch = fgetc(All_Clubs);
        printf("%c",ch);
    }
    fclose(All_Clubs);
    printf("Enter Any Club name from Above:");
    fflush(stdin);
    gets(club.name);
    printf("\n\n");
    FILE *Clubs;
    Clubs = fopen(club.name,"r");
    while(!feof(Clubs))
    {
        ch = fgetc(Clubs);
        printf("%c",ch);
    }
    fclose(Clubs);
    printf("\n\n");

}

void see_all_players()
{
    char ch;
    FILE *Players;
    Players = fopen("players","r");
    while(!feof(Players))
    {
        ch = fgetc(Players);
        printf("%c",ch);
    }
}
int main()
{
    int choice;
    char x;
    printf("\n\n\t\t\t--------------------------------\n");
    printf("\t\t\t|  TOM Raiders Football League |\n");
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t 1. Add New Club.\n");
    printf("\t\t\t 2. See Club Information.\n");
    printf("\t\t\t 3. See All Players Information in this Season.\n");
    printf("\t\t\t 4. Transfer Player.\n");
    printf("\t\t\t 5. EXIT.\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:

            do
            {
                new_club();
                printf("\n\t\t\t Do You Want To Add Another Club? (y/n):");
                scanf(" %c",&x);
            }while(x == 'y' || x == 'Y');
            break;
    case 2:

            do
            {
                see_club();
                printf("\n\t\t\t Do You Want To See Another Club? (y/n):");
                scanf(" %c",&x);
            }while(x=='y' || x=='Y');
            break;
    case 3:
            see_all_players();
            break;
    case 4:
            printf("\n\n\t\t\t\a***Club to Club Transfer Market Has Not Opened Yet***\n\n");
            break;
    case 5:
            printf("\n\n\t\t\t*****Thank You*****\n\t\t\t\t***See You***\n\n\n\t\t\t\t\t\t\t -Created by Ofs");
            return 0;
            break;
    default:
            printf("Wrong press");
    }
    return main();
}
