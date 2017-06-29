#include <iostream>
#include <random>
#include <ctime>
#include <conio.h>
using namespace std;
unsigned lenght (unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}
int spawn (int a[4][4])
{
    int b[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int free=0,br=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            free++;
            if(a[i][j]==0)
            {
                b[br]=free;
                br++;
            }
        }
    }
    if(br==0)return 0;
    srand(time(0));
    int x= (rand() % br ) +1;
    //cout<<x<<endl;
    int tf[6]={2,2,4,2,2,2};
    a[(b[x-1]-1)/4][(b[x-1]-1)%4]=tf[(rand() % 6 )] ;
}
void show(int a[4][4])
{
    cout<<"r for restart\n\n\n";
        //system("CLS");
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            switch(lenght(a[i][j]))
            {
            case 1:
                cout<<a[i][j]<<"    ";
                break;
            case 2:
                cout<<a[i][j]<<"   ";
                break;
            case 3:
                cout<<a[i][j]<<"  ";
                break;
            case 4:
                cout<<a[i][j]<<" ";
                break;
            }

        }
        cout<<endl<<endl;
    }

}
void up(int a[4][4])
{
    bool movement=false;
    //merge below
    for(int j=0; j<4; j++)
    {
        for(int i=1; i<4; i++)
        {
            if(i==3 && a[i][j]!=0 && a[i-1][j]==0 && a[i-2][j]==0 && a[i-3][j]==a[i][j])
            {
                a[i][j]=0;
                a[i-3][j]*=2;
                movement=true;
            }
            else if(i==3 && a[i][j]!=0 && a[i-1][j]==0 && a[i-2][j]==a[i][j] )
            {
                a[i][j]=0;
                a[i-2][j]*=2;
                movement=true;
            }
            else if(i==2 && a[i][j]!=0 && a[i-1][j]==0 && a[i-2][j]==a[i][j])
            {
                a[i][j]=0;
                a[i-2][j]*=2;
                movement=true;
            }
            else if( a[i][j]!=0 && a[i-1][j]==a[i][j] )
            {
                a[i][j]=0;
                a[i-1][j]*=2;
                movement=true;
            }
        }
    }
    //movement below
    for(int j=0; j<4; j++)
    {
        for(int i=1; i<4; i++)
        {
            if(i==3 && a[i][j]!=0 && a[i-1][j]==0 && a[i-2][j]==0 && a[i-3][j]==0)
            {
                swap(a[i][j],a[i-3][j]);
                movement=true;
            }
            else if(i==3 && a[i][j]!=0 && a[i-1][j]==0 && a[i-2][j]==0 )
            {
                swap(a[i][j],a[i-2][j]);
                movement=true;
            }
            else if(i==2 && a[i][j]!=0 && a[i-1][j]==0 && a[i-2][j]==0)
            {
                swap(a[i][j],a[i-2][j]);
                movement=true;
            }
            else if( a[i][j]!=0 && a[i-1][j]==0 )
            {
                swap(a[i][j],a[i-1][j]);
                movement=true;
            }
        }
    }
    if(movement)
        spawn(a);
}
void down(int a[4][4])
{
    bool movement=false;
    //merge below
    for(int j=0; j<4; j++)
    {
        for(int i=2; i>-1; i--)
        {
            if(i==0 && a[i][j]!=0 && a[i+1][j]==0 && a[i+2][j]==0 && a[i+3][j]==a[i][j])
            {
                a[i][j]=0;
                a[i+3][j]*=2;
                movement=true;
            }
            else if(i==0 && a[i][j]!=0 && a[i+1][j]==0 && a[i+2][j]==a[i][j] )
            {
                a[i][j]=0;
                a[i+2][j]*=2;
                movement=true;
            }
            else if(i==1 && a[i][j]!=0 && a[i+1][j]==0 && a[i+2][j]==a[i][j])
            {
                a[i][j]=0;
                a[i+2][j]*=2;
                movement=true;
            }
            else if( a[i][j]!=0 && a[i+1][j]==a[i][j] )
            {
                a[i][j]=0;
                a[i+1][j]*=2;
                movement=true;
            }
        }
    }
    //movement below
    for(int j=0; j<4; j++)
    {
        for(int i=2; i>-1; i--)
        {
            if(i==0 && a[i][j]!=0 && a[i+1][j]==0 && a[i+2][j]==0 && a[i+3][j]==0)
            {
                swap(a[i][j],a[i+3][j]);
                movement=true;
            }
            else if(i==0 && a[i][j]!=0 && a[i+1][j]==0 && a[i+2][j]==0 )
            {
                swap(a[i][j],a[i+2][j]);
                movement=true;
            }
            else if(i==1 && a[i][j]!=0 && a[i+1][j]==0 && a[i+2][j]==0)
            {
                swap(a[i][j],a[i+2][j]);
                movement=true;
            }
            else if( a[i][j]!=0 && a[i+1][j]==0 )
            {
                swap(a[i][j],a[i+1][j]);
                movement=true;
            }
        }
    }
    if(movement)
        spawn(a);
}
void left(int a[4][4])
{
    bool movement=false;
    //merge below
    for(int i=0; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            if(j==3 && a[i][j]!=0 && a[i][j-1]==0 && a[i][j-2]==0 && a[i][j-3]==a[i][j])
            {
                a[i][j]=0;
                a[i][j-3]*=2;
                movement=true;
            }
            else if(j==3 && a[i][j]!=0 && a[i][j-1]==0 && a[i][j-2]==a[i][j] )
            {
                a[i][j]=0;
                a[i][j-2]*=2;
                movement=true;
            }
            else if(j==2 && a[i][j]!=0 && a[i][j-1]==0 && a[i][j-2]==a[i][j])
            {
                a[i][j]=0;
                a[i][j-2]*=2;
                movement=true;
            }
            else if( a[i][j]!=0 && a[i][j-1]==a[i][j] )
            {
                a[i][j]=0;
                a[i][j-1]*=2;
                movement=true;
            }
        }
    }
    //movement below
    for(int i=0; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            if(j==3 && a[i][j]!=0 && a[i][j-1]==0 && a[i][j-2]==0 && a[i][j-3]==0)
            {
                swap(a[i][j],a[i][j-3]);
                movement=true;
            }
            else if(j==3 && a[i][j]!=0 && a[i][j-1]==0 && a[i][j-2]==0 )
            {
                swap(a[i][j],a[i][j-2]);
                movement=true;
            }
            else if(j==2 && a[i][j]!=0 && a[i][j-1]==0 && a[i][j-2]==0)
            {
                swap(a[i][j],a[i][j-2]);
                movement=true;
            }
            else if( a[i][j]!=0 && a[i][j-1]==0 )
            {
                swap(a[i][j],a[i][j-1]);
                movement=true;
            }
        }
    }
    if(movement)
        spawn(a);
}
void right(int a[4][4])
{
    bool movement=false;
    //merge below
    for(int i=0; i<4; i++)
    {
        for(int j=2; j>-1; j--)
        {
            if(j==0 && a[i][j]!=0 && a[i][j+1]==0 && a[i][j+2]==0 && a[i][j+3]==a[i][j])
            {
                a[i][j]=0;
                a[i][j+3]*=2;
                movement=true;
            }
            else if(j==0 && a[i][j]!=0 && a[i][j+1]==0 && a[i][j+2]==a[i][j] )
            {
                a[i][j]=0;
                a[i][j+2]*=2;
                movement=true;
            }
            else if(j==1 && a[i][j]!=0 && a[i][j+1]==0 && a[i][j+2]==a[i][j])
            {
                a[i][j]=0;
                a[i][j+2]*=2;
                movement=true;
            }
            else if( a[i][j]!=0 && a[i][j+1]==a[i][j] )
            {
                a[i][j]=0;
                a[i][j+1]*=2;
                movement=true;
            }
        }
    }
    //movement below
    for(int i=0; i<4; i++)
    {
        for(int j=2; j>-1; j--)
        {
            if(j==0 && a[i][j]!=0 && a[i][j+1]==0 && a[i][j+2]==0 && a[i][j+3]==0)
            {
                swap(a[i][j],a[i][j+3]);
                movement=true;
            }
            else if(j==0 && a[i][j]!=0 && a[i][j+1]==0 && a[i][j+2]==0 )
            {
                swap(a[i][j],a[i][j+2]);
                movement=true;
            }
            else if(j==1 && a[i][j]!=0 && a[i][j+1]==0 && a[i][j+2]==0)
            {
                swap(a[i][j],a[i][j+2]);
                movement=true;
            }
            else if( a[i][j]!=0 && a[i][j+1]==0 )
            {
                swap(a[i][j],a[i][j+1]);
                movement=true;
            }
        }
    }
    if(movement)
        spawn(a);
}
bool lose(int a[4][4])
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            if(a[i][j]==0)
                return false;
        }
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            if(i==3)
            {
                if(j==3)
                    break;
                if(a[i][j]==a[i][j+1])
                return false;
            }
            else if(j==3)
            {
                if(i==3)
                    break;
                if(a[i][j]==a[i+1][j] )
                return false;
            }
            else if(a[i][j]==a[i][j+1] || a[i][j]==a[i+1][j] )
                return false;
        }
    return true;
}
int main()
{
    int pole[4][4];
    char key;

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            pole[i][j]=0;


        }


    spawn(pole);
    spawn(pole);

    while(true)
    {
        show(pole);
        if(lose(pole))
        {
            cout<<"You lose! New game? (r)/n";
            key=getch();
            if (key==0 || key==0xE0) key=getch();
            if(key=='r')
            {
                for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                {
                    pole[i][j]=0;
                }
                spawn(pole);
                spawn(pole);
            }
            else return 20;
        }
        key=getch();
        if (key==0 || key==0xE0) key=getch();
        switch(key)
        {
        case 72:
            up(pole);
            break;
        case 80:
            down(pole);
            break;
        case 75:
            left(pole);
            break;
        case 77:
            right(pole);
            break;
        case 'r':
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                {
                    pole[i][j]=0;
                }
            spawn(pole);
            spawn(pole);
            break;

        };
        system("cls");

    }
    //show(pole);
    cout<<endl;
    return 0;
}
