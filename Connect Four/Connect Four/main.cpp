#include <iostream>
#include<windows.h>
using namespace std;
void printr(int arrP[5][5]);
bool won(int arr[5][5]);
int main()
{
    cout << "Connect Four By Team Mohammed AL-Sayed and Mohammed Nabil\n";
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
    bool playerTwo=false ;//Is player two playing
    bool _playerTwo=false;//has player two won
    int inputSymbol = 0;
    int inputColumn=0;
    int occupationLevel[5]= {0,0,0,0,0};//into Stack
    printr(solveArray);
rtn:
    if(playerTwo)
    {
        cout <<"player two \n";
        playerTwo=false;
        _playerTwo=true;
    }
    else
    {
        cout <<"player one \n";
        _playerTwo=false;
    }
    cout <<"Select Column to insert in 1 2 3 4 \n";
    cin>>inputColumn;
    inputColumn-=1;
    cout <<"Select symbol 1 \x03 , 2 \x04,  3 \x05,  4 \x06  \n";
    cin>>inputSymbol;


    solveArray[occupationLevel[inputColumn]][inputColumn]=inputSymbol;
    occupationLevel[inputColumn]+=1;
    system("cls");
    printr(solveArray);
    if(won(solveArray))
    {
        if(_playerTwo)
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
        if(rtnr==1){system("cls");goto again;}
    }
    playerTwo=true;
    goto rtn;
    return 0;
}

void  printr(int arrP[5][5])
{
    char symbolArr[5]= {'\0','\x03','\x04','\x05','\x06'};
    char charArr[5][5];
    cout <<" \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n";
    cout<<" \xba 1 \xba 2 \xba 3 \xba 4 \xba "<<endl;
    cout <<" \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
    cout <<""<<endl;
    for (int i =4; i >=0; i--)
    {
        for(int y =0; y<5; y++)
        {
            charArr[i][y]=symbolArr[arrP[i][y]];
            cout<<" \xba "<<charArr[i][y];
        }
        cout<<"\n \xba\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xba\n";
    }
cout <<endl;

}

bool won(int arr[5][5])
{
    ///check horizontal
    for (int i =0 ; i < 5 ; i++)
    {
        if (
            arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][2]==arr[i][3] &&arr [i][3]!=0 ||
            arr[i][1]==arr[i][2]&&  arr[i][2]==arr[i][3] && arr[i][3]==arr[i][4] && arr[i][4]!=0
        )
        {
            return true;
        }
    }
    ///check vertical
    for (int i =0 ; i < 5 ; i++)
    {
        if (
            arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[2][i]==arr[3][i] && arr[3][i]!=0 ||
            arr[1][i]==arr[2][i] && arr[2][i]==arr[3][i] && arr[3][i]==arr[4][i]&&  arr[4][i]!=0
        )
        {

            return true;
        }
    }
    ///check right diagonal
    if(
        arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[2][2]==arr[3][3] && arr[3][3] !=0 ||
        arr[1][1]==arr[2][2] && arr[2][2]==arr[3][3] && arr[3][3] ==arr[4][4]&& arr[4][4]!=0
    )
    {

        return true;
    }
    ///check left diagonal
    if(
        arr[0][4]==arr[1][3] && arr[1][3]==arr[2][2] && arr[2][2]==arr[3][1] && arr[3][1]!=0 ||
        arr[1][3]==arr[2][2] && arr[2][2]==arr[3][1] && arr[3][1]==arr[4][0] &&arr[4][0]!=0
    )
    {

        return true;
    }
    return false;
}
