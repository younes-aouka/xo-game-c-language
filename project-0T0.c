#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<math.h>



void cls() // used to clear screen fast
{
    system("cls") ;
}



void gotoxy(int x, int y) // to move between rows and colums (no need to understand it so basicaly x for rows and y for colums)
{
    COORD position ;
    position.X=x ;
    position.Y=y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position) ;
}



void table(char tab[9]) // fucntion for printing the xo table
{
    printf("\n\n\n");
    printf(" %c | %c | %c ",tab[0],tab[1],tab[2]) ;
    printf("\n");
    printf("----------- ");

    printf("\n");
    printf(" %c | %c | %c ",tab[3],tab[4],tab[5]);
    printf("\n");
    printf("----------- ");

    printf("\n");
    printf(" %c | %c | %c ",tab[6],tab[7],tab[8]);
    printf("\n\n");
}






char winner=' ' ; // global variable used hir to prevent using pointerin
int up=30,down=31,right=16 ; // i use this value to print some chars from ascii-table so you can consider them as special-char
                            // got to menu function and you will understand how i use them
void checkwinner(char t[9]) // this function only check winner in solo-mode
{

    if(( (t[0]=='X') && (t[1]=='X') && (t[2]=='X') ) || //case 1
       ( (t[2]=='X') && (t[5]=='X') && (t[8]=='X') ) || //case 2
       ( (t[8]=='X') && (t[7]=='X') && (t[6]=='X') ) || //case 3
       ( (t[6]=='X') && (t[3]=='X') && (t[0]=='X') ) || //case 4
       ( (t[1]=='X') && (t[4]=='X') && (t[7]=='X') ) || //case 5
       ( (t[5]=='X') && (t[4]=='X') && (t[3]=='X') ) || //case 6
       ( (t[0]=='X') && (t[4]=='X') && (t[8]=='X') ) || //case 7
       ( (t[2]=='X') && (t[4]=='X') && (t[6]=='X') ))   //case 8
    {
        winner='p' ; // p => player

    }
    else if(( (t[0]=='O') && (t[1]=='O') && (t[2]=='O') ) ||
            ( (t[2]=='O') && (t[5]=='O') && (t[8]=='O') ) ||
            ( (t[8]=='O') && (t[7]=='O') && (t[6]=='O') ) ||
            ( (t[6]=='O') && (t[3]=='O') && (t[0]=='O') ) ||
            ( (t[1]=='O') && (t[4]=='O') && (t[7]=='O') ) ||
            ( (t[5]=='O') && (t[4]=='O') && (t[3]=='O') ) ||
            ( (t[0]=='O') && (t[4]=='O') && (t[8]=='O') ) ||
            ( (t[2]=='O') && (t[4]=='O') && (t[6]=='O') ))
    {
        winner='c' ; //c => computer

    }
    else if(t[0]!='1'&&t[1]!='2'&&t[2]!='3'&&t[3]!='4'&&t[4]!='5'&&t[5]!='6'&&t[6]!='7'&&t[7]!='8'&&t[8]!='9')
    {
        winner='e' ; // e => equal
    }

}





void checkwinner2(char t[9]) // this function only check winner in multiplayer-mode mode
{

    if(  ((t[0]=='X') && (t[1]=='X') && (t[2]=='X')) ||
        ((t[2]=='X') && (t[5]=='X') && (t[8]=='X')) ||
        ((t[8]=='X') && (t[7]=='X') && (t[6]=='X')) ||
        ((t[6]=='X') && (t[3]=='X') && (t[0]=='X')) ||
        ((t[1]=='X') && (t[4]=='X') && (t[7]=='X')) ||
        ((t[5]=='X') && (t[4]=='X') && (t[3]=='X')) ||
        ((t[0]=='X') && (t[4]=='X') && (t[8]=='X')) ||
        ((t[2]=='X') && (t[4]=='X') && (t[6]=='X')) )
    {
        winner='1' ; // player


    }
    else if(  ((t[0]=='O') && (t[1]=='O') && (t[2]=='O')) ||
             ((t[2]=='O') && (t[5]=='O') && (t[8]=='O')) ||
             ((t[8]=='O') && (t[7]=='O') && (t[6]=='O')) ||
             ((t[6]=='O') && (t[3]=='O') && (t[0]=='O')) ||
             ((t[1]=='O') && (t[4]=='O') && (t[7]=='O')) ||
             ((t[5]=='O') && (t[4]=='O') && (t[3]=='O')) ||
             ((t[0]=='O') && (t[4]=='O') && (t[8]=='O')) ||
             ((t[2]=='O') && (t[4]=='O') && (t[6]=='O')) )
    {
        winner='2' ;

    }
    else if(t[0]!='1'&&t[1]!='2'&&t[2]!='3'&&t[3]!='4'&&t[4]!='5'&&t[5]!='6'&&t[6]!='7'&&t[7]!='8'&&t[8]!='9')
    {
        winner='e' ;
    }


}









void solo_player()
{

    int pm,cm ;// player move and computer move
    char t[9]= {'1','2','3','4','5','6','7','8','9'} ;
    srand(time(NULL)) ;

    char firstmove ;
    do{
        printf("\n player begin (1) | computer begin (2)\n ") ;
        firstmove=getch() ;
        cls() ;
    }while(firstmove!='1'&&firstmove!='2') ;

    if(firstmove=='1')
    {
        while(winner==' ')
        {
            do {
            cls();
            table(t) ;
            printf("Enter your position: ") ;
            scanf("%d",&pm) ;
            }while(t[pm-1]=='X'||t[pm-1]=='O'||pm>9||pm<1) ;

            t[pm-1]='X' ;
            cls() ;
            table(t) ;
            checkwinner(t) ;

            if(winner==' ')
            {

                do
                {

                    cm=rand()%10 ;


                }while(t[cm-1]=='O'||t[cm-1]=='X'||cm<=0) ;

                t[cm-1]='O' ;
                cls() ;
                table(t) ;
                checkwinner(t) ;

            }

        }
    }
//end of round (player first move)

    else if(firstmove=='2')
    {

        while(winner==' ')
        {

            do
            {

                cm=rand()%10 ;


            }
            while(t[cm-1]=='O'||t[cm-1]=='X'||cm<=0) ;

            t[cm-1]='O' ;
            cls() ;
            table(t) ;
            checkwinner(t) ;

            if(winner==' ')
            {

            do {
            cls();
            table(t) ;
            printf("Enter your position: ") ;
            scanf("%d",&pm) ;
            }while(t[pm-1]=='X'||t[pm-1]=='O'||pm>9||pm<1) ;

            t[pm-1]='X' ;
            cls() ;
            table(t) ;
            checkwinner(t) ;

            }
        }
    }
    //end of round(computer first move)

    if(winner=='p')
    {
        printf("\n You win!\n") ;
    }
    else if(winner=='e')
    {
        printf("\n  Eqaul!\n") ;
    }
    else
    {
        printf("\n  Computer Win!\n") ;
    }

    winner=' ' ;
    Sleep(2000) ;
    cls();
    menu();

}



void Multiplayer()
{
    char t[9]= {'1','2','3','4','5','6','7','8','9'} ;
    int player1,player2 ;

    while(winner==' ')
    {
        do {
        cls();
        table(t) ;
        printf(" Player 1 inter your position: ");
        scanf("%d",&player1) ;
        }while(t[player1-1]=='X'||t[player1-1]=='O'||player1>9||player1<1) ;

        t[player1-1]='X' ;
        cls() ;
        table(t) ;
        checkwinner2(t) ;

        if(winner==' ')
        {

        do {
        cls();
        table(t) ;
        printf(" Player 2 inter your position: ");
        scanf("%d",&player2) ;
        }while(t[player2-1]=='X'||t[player2-1]=='O'||player2>9||player2<1) ;

            t[player2-1]='O' ;
            cls() ;
            table(t) ;
            checkwinner2(t) ;

        }

    }

    if(winner=='1')
    {
        printf("\n player 1 win \n") ;
    }
    else if(winner=='2')
    {
        printf("\n player  win \n") ;
    }
    else if(winner=='e')
    {
        printf("\n Equal \n") ;
    }

    winner=' ' ;
    Sleep(2000) ;
    cls() ;
    menu() ;
}      //end of multiplayer round




void menu()
{
    gotoxy(4,1);
    printf("%c",up) ;
    gotoxy(6,2);
    printf("MENU") ;
    gotoxy(4,2) ;
    printf("%c",down) ;
    char u ;
    int i,j ;
    i=7 ;
    j=5 ;
    gotoxy(10,5) ;
    printf("Multiplayer mode") ;
    gotoxy(i,j) ;
    printf("%c",right) ;
    gotoxy(10,7) ;
    printf("Solo mode") ;
    gotoxy(10,9) ;
    printf("Exit") ;
    while(u!=' ')
    {

        u=getch() ;
        if((u=='s')&&(i==7)&&(j==5))
        {
            gotoxy(i,j) ;
            printf(" ") ;
            gotoxy(i,j+2) ;
            printf("%c",right) ;
            j=j+2 ;

        }
        else if((u=='s')&&(i==7)&&(j==7))
        {
            gotoxy(i,j) ;
            printf(" ") ;
            gotoxy(i,j+2) ;
            printf("%c",right) ;
            j=j+2 ;
        }

        else if((u=='z')&&(i==7)&&(j==9))
        {
            gotoxy(i,j) ;
            printf(" ") ;
            gotoxy(i,j-2) ;
            printf("%c",right) ;
            j=j-2 ;

        }

        else if((u=='z')&&(i==7)&&(j==7))
        {
            gotoxy(i,j) ;
            printf(" ") ;
            gotoxy(i,j-2) ;
            printf("%c",right) ;
            j=j-2 ;
        }

        if(u==' ')
        {
            cls() ; //close Menu
        }

    }



    if(j==5)
    {

        Multiplayer() ;     //multiplayer mode

    }


    else if(j==7)
    {
        solo_player() ;         //solo mode
    }



    else if(j==9) //exit
    {
        char f ;
        int n=8 ;
        int b=5 ;

        gotoxy(10,5) ;
        printf("YES") ;
        gotoxy(8,5) ;
        printf("%c",right) ;
        gotoxy(10,7) ;
        printf("NO") ;

        while(f!=' ')
        {

            f=getch() ;
            if((f=='s')&&(n==8)&&(b==5))
            {
                gotoxy(n,b) ;
                printf(" ") ;
                gotoxy(n,b+2) ;
                printf("%c",right) ;
                b=b+2 ;
            }

            else if((f=='z')&&(n==8)&&(b==7))
            {
                gotoxy(n,b) ;
                printf(" ") ;
                gotoxy(n,b-2) ;
                printf("%c",right) ;
                b=b-2 ;
            }
            else if(f==' ')
            {
                cls() ;
            }
        }

        if(b==7)
        {
            menu() ; //Menu comme back
        }
        else
        {
            cls() ;

        }

    }

}






int main()
{

    menu() ;

    return 0;
}
