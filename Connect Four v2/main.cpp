#include <iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
void printr(int arrP[5][5]);
bool won(int arr[5][5]);
int main()
{
    system("color 4e");
    cout << "\n\n\t\tConnect Four By Team \n\t\tMohammed AL-Sayed \n\t\tMohammed Ibraheem \n\t\tLoay Esam Alkashif\n\n\n";
    system("pause");
    system("cls");
again:
    int solveArray[5][5]=
    {
        {0,0,0,0,0},/*0*/
        {0,0,0,0,0},/*1*/
        {0,0,0,0,0},/*2*/
        {0,0,0,0,0},/*3*/
        {0,0,0,0,0} /*4*/
    };
//down
    bool TwoIsPlaying=false ;//Is player two playing
    bool TwoWon=false;//has player two won
    int inputSymbol = 0;
    int inputColumn=0;
    int occupationLevel[5]= {0,0,0,0,0};//into Stack
    printr(solveArray);
rtn:
    if(TwoIsPlaying)
    {
        cout <<"player two \n";
        TwoIsPlaying=false;
        TwoWon=true;
        inputSymbol=2;
    }
    else
    {
        cout <<"player one \n";
        inputSymbol=1;
        TwoIsPlaying=true;
        TwoWon=false;
    }
    errSelect:
    cout <<"Select Column to insert in 1 2 3 4 5 \n";
    inputColumn=getch()-48;
    if(inputColumn>5)goto errSelect;
    inputColumn-=1;

    if(occupationLevel[inputColumn]>=5){TwoIsPlaying=!TwoIsPlaying;TwoWon=!TwoWon;goto rtn;}
    solveArray[occupationLevel[inputColumn]][inputColumn]=inputSymbol;
    occupationLevel[inputColumn]+=1;
    system("cls");
    printr(solveArray);
    if(won(solveArray))
    {
        if(TwoWon)
        {
            cout <<"\nPlayer Two Won !! \n";
        }
        else
        {
            cout <<"Player one won ! \n";
        }
        int rtnr = 0;
        cout << "Play Again ? 1 -yes 2-No\n";
        cin>>rtnr;
        if(rtnr==1)
        {
            system("cls");
            goto again;
        }else{return 0;}
    }
    goto rtn;
    return 0;
}


void  printr(int arrP[5][5])
{
    char symbolArr[3]= {'\0','\x03','\x04'};
    char charArr[5][5];
    cout <<" \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n";
    cout<<" \xba 1 \xba 2 \xba 3 \xba 4 \xba 5 \xba"<<endl;
    cout <<" \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
    cout <<""<<endl;
    for (int i =4; i >=0; i--)///rows
    {
        for(int y =0; y<5; y++)///cells
        {
            charArr[i][y]=symbolArr[arrP[i][y]];
            cout<<" \xba "<<charArr[i][y];
        }
        cout<<" \xba";
        cout<<"\n \xba\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xba\n";
    }
cout <<endl;

}

bool won(int arr[5][5])
{
    ///check horizontal
    for (int i =0 ; i < 5 ; i++)
    {
        if (
            (arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][2]==arr[i][3] &&arr [i][3]!=0) ||
            (arr[i][1]==arr[i][2]&&  arr[i][2]==arr[i][3] && arr[i][3]==arr[i][4] && arr[i][4]!=0)
        )
        {
            return true;
        }
    }
    ///check vertical
    for (int i =0 ; i < 5 ; i++)
    {
        if (
            (arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[2][i]==arr[3][i] && arr[3][i]!=0) ||
            (arr[1][i]==arr[2][i] && arr[2][i]==arr[3][i] && arr[3][i]==arr[4][i]&&  arr[4][i]!=0)
        )
        {

            return true;
        }
    }
    ///check right diagonal
for(int j =0 ; j<2; j++)
    {
        for (int i =0 ; i<2; i++)
        {
            if(arr[j][i]==arr[j+1][i+1] && arr[j+1][i+1]==arr[j+2][i+2] &&arr[j+2][i+2]== arr[j+3][i+3] && arr[j+3][i+3]  !=0)
            {

                return true;
            }
        }
    }
    ///next block
        for(int j =4 ; j>=3; j--)
    {
        for (int i =3 ; i <= 4; i++)
        {
            if(arr[j][i]==arr[j-1][i-1] && arr[j-1][i-1]==arr[j-2][i-2] && arr[j-2][i-2]==arr[j-3][i-3] && arr[j-3][i-3]!=0)
            {
             return true;
            }
        }
    }
    ///check left diagonal
    for(int j =0 ; j<2; j++)
    {
        for (int i =3 ; i<=4; i++)
        {
            if(arr[j][i]==arr[j+1][i-1] && arr[j+1][i-1]==arr[j+2][i-2] &&arr[j+2][i-2]== arr[j+3][i-3] && arr[j+3][i-3]  !=0)
            {

                return true;
            }
        }
    }
    ///next block
    for(int j =4 ; j>=3; j--)
    {
        for (int i =0 ; i<=2; i++)
        {
            if(arr[j][i]==arr[j-1][i+1] && arr[j-1][i+1]==arr[j-2][i+2] &&arr[j-2][i+2]== arr[j-3][i+3] && arr[j-3][i+3]  !=0)
            {

                return true;
            }
        }
    }

    return false;
}
