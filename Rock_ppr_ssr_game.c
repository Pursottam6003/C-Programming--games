#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<unistd.h>

int generaterandomnumber(int n);
int greater(char* ch1,char* ch2);

int main()
{
    printf("Please wait, loading into the RAM.");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n\n");
    char str1[30];
    char str2[]="Computer";
    printf("<<<<<<<<<<<<<<      Welcome to Rock Paper Scissor Game      >>>>>>>>>>>>>>\n\n");
    printf("Enter your name: ");
    scanf("%s",str1);

    int str1_len = strlen(str1);

    printf("Hello %s you have '3' chances \n\n",str1);

    printf("\t%s Vs %s",str1,str2);

    printf("\n\n    <------------------------ Match Started ------------------------->    \n\n");

    //char outcomes[]={'r','p','s'}; // created an outcome for our results
    char *outcomes[] ={"Rock","Paper","Scissor"};

    int points_computer=0,points_usr=0,temp;
    char  *playerChar=0;
    char *computerchar=0;
   
    for(int i=0;i<3;i++)
    {   
        //user turn 
        printf("\t%s 's Turns\n",str1);
        printf("\tChoose : 1--> Rock ,2---> paper,3 ----> sicssor :: ");
        scanf("%d",&temp);
        getchar();
        playerChar=outcomes[temp-1];

        printf("\tYou Enterd :%d ----->' %s ' \n",temp,playerChar);

        //comuters turn 
        printf("\t%s's Trurns\n",str2);
        temp=generaterandomnumber(3)+1;
        computerchar=outcomes[temp-1];

        printf("\tCompter Enterd : %d----> '%s' \n",temp,computerchar);

        if (greater(computerchar,playerChar)==1) //calling the function
        {
            points_computer+=1;
            printf("**********   Computer got it !!  **********\n");
        }

        else if(greater(computerchar,playerChar)== -1)
        {
            points_computer+=1;
            points_usr+=1;
            printf("************    Its a tie   ***************\n");
        }

        else
        {
            points_usr+=1;
            printf("***************** You got it **************\n");
        }

        printf("\t%s your score : %d\n",str1,points_usr);
        printf("\tcompter score :%d \n",points_computer);

        
    }

    if(points_computer >points_usr)
    {           
        printf("Fetching results.");
        for (int i = 0; i < 8; i++)
        {
            printf(".");
            fflush(stdout);
            sleep(1); // calling the sleep function 
        }
        printf("\n\n");
        printf("<<<<<<<<<<<<<<             OMG ! Computer wins!!            >>>>>>>>>>>>>>\n");
        printf("\n");

    }

    else if(points_computer <points_usr)
    {   
        // design XD
        int evn = (str1_len % 2) ? str1_len - 1 : str1_len;
        int des_len = (28 - evn) / 2;
        char angl[des_len], angr[des_len];
        for (int i = 0; i < des_len; i++)
        {
            angl[i] = '<';
            angr[i] = '>';
        }

        angl[des_len - 1] = '\0';
        angr[des_len - 1] = '\0';
        printf("Fetching results.");
        for (int i = 0; i < 8; i++)
        {
            printf(".");
            fflush(stdout);
            sleep(1); // calling the sleep function 
        }
        printf("\n\n");
        if (str1_len % 2 == 0)
            printf("<<<<%s Congratutlations %s You  wins the game %s>>>>\n",angl,str1,angr); // 28 ang brackets to add if name=0
        else
            printf("<<<<%s Congratutlations %s  You  wins the game %s>>>>\n",angl,str1,angr); // 28 ang brackets to add if name=0

    }

    else
    {   
        printf("Fetching results.");
        for (int i = 0; i < 8; i++)
        {
            printf(".");
            fflush(stdout);
            sleep(1); // calling the sleep function 
        }
        printf("\n\n");
        printf("<<<<<<<<<<<<<<           Unbelieveble ! its a Tie           >>>>>>>>>>>>>>\n");
    }

}

int generaterandomnumber(int n)
{
    srand(time(NULL));

    return rand()%n;
}

int greater(char* ch1,char* ch2)
{
    if(strcmp(ch1,ch2)==0)
    {
        return -1;
    }

    //for Rock Paper Scissors---> return 1 if c1>c2 returns 0 if c1<c2 return -1 if c1==c2 
    

    // 1st combination
    if (strcmp(ch1,"Rock") == 0 && strcmp(ch2,"Scissor") == 0)
    {
        return 1;
    }
    //else if ((ch1=='s') && (ch2=='r'))
    else if (strcmp(ch1,"Scissor") == 0 && strcmp(ch2,"Rock") == 0)
    {
        return 0;
    }

    //2nd combination
    if (strcmp(ch1,"Scissor") == 0 && strcmp(ch2,"Paper") == 0)
    {
        return 1;
    }
    else if (strcmp(ch1,"Paper") == 0 && strcmp(ch2,"Scissor") == 0)
    {
        return 0;
    }
    
    
    //3rd combination
    if (strcmp(ch1,"Rock") == 0 && strcmp(ch2,"Paper") == 0)
    {
        return 0;
    }
    else if (strcmp(ch1,"Paper") == 0 && strcmp(ch2,"Rock") == 0)
    {
        return 1;
    }
}