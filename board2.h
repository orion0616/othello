#include <iostream>
#include <vector>
#define SIZE 8
#define WHITE 1
#define BLACK 2
using namespace std;


class board{
private:
    int a[SIZE][SIZE];
public:
    board();
    bool passcheck();
    void showBoard(); //盤面を表示
    int getDisc(int x,int y){return a[x][y];}; //指定座標の石の色を出力
    int setDisc(int x,int y,int color); //石を置く
    int checkblank(); //盤面上の空白数を出す
    int eval(int color);//石の数で評価
    int eval2(int color);//盤面に重み付けをした上で評価
};

board::board(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            a[i][j]=0;
        }
    }
    a[SIZE/2-1][SIZE/2-1] = WHITE;
    a[SIZE/2-1][SIZE/2] = BLACK;
    a[SIZE/2][SIZE/2-1] = BLACK;
    a[SIZE/2][SIZE/2] = WHITE;
    showBoard();
}

bool board::passcheck(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = *this;
            if(kari.setDisc(i,j,1)==0 || kari.setDisc(i,j,2)==0){
                return 0;
            }
        }
    }
    return 1;
}

void board::showBoard(){
    cout << " ";
    for(int i=0;i<SIZE;i++)
        cout << i;
    cout << endl;
    for(int i=0;i<SIZE;i++){
        cout << i;
        for(int j=0;j<SIZE;j++){
            if(a[i][j]==0)
                cout << "-";
            if(a[i][j]==WHITE)
                cout << "w";
            if(a[i][j]==BLACK)
                cout << "b︎";
        }
        cout << endl;
    }
    cout << endl;
}


int board::setDisc(int x, int y, int color){
    if(x==100 && y==100){
        cout << "パスしました" << endl;
        showBoard();
        return 1;
    }
    if(a[x][y]!=0)
        return 1;
    int opp;
    if(color==WHITE)
        opp=BLACK;
    else
        opp=WHITE;
    int flag = 0;
    //左を変える
    if(a[x][y-1]==opp && y>1){
        for(int k=2;y-k>=0;k++){
            if(a[x][y-k]==opp)
                continue;
            if(a[x][y-k]==0)
                break;
            if(a[x][y-k]==color){
                for(int i=0;i<k;i++){
                    a[x][y-i]=color;
                    flag = 1;
                }
                break;
            }
        }
    }
    //右を変える
    if(a[x][y+1]==opp && y<SIZE-2){
        for(int k=2;y+k<=SIZE-1;k++){
            if(a[x][y+k]==opp)
                continue;
            if(a[x][y+k]==0)
                break;
            if(a[x][y+k]==color){
                for(int i=0;i<k;i++){
                    a[x][y+i]=color;
                    flag = 1;
                }
                break;
            }
        }
    }
    //上を変える
    if(a[x-1][y]==opp && x>1){
        for(int k=2;x-k>=0;k++){
            if(a[x-k][y]==opp)
                continue;
            if(a[x-k][y]==0)
                break;
            if(a[x-k][y]==color){
                for(int i=0;i<k;i++){
                    a[x-i][y]=color;
                    flag = 1;
                }
                break;
            }
        }
    }
    //下を変える
    if(a[x+1][y]==opp && x<SIZE-2){
        for(int k=2;x+k<=SIZE-1;k++){
            if(a[x+k][y]==opp)
                continue;
            if(a[x+k][y]==0)
                break;
            if(a[x+k][y]==color){
                for(int i=0;i<k;i++){
                    a[x+i][y]=color;
                    flag = 1;
                }
                break;
            }
        }
    }
    //左上を変える
    if(a[x-1][y-1]==opp && y>1 && x>1){
        for(int k=2;y-k>=0 && x-k>=0;k++){
            if(a[x-k][y-k]==opp)
                continue;
            if(a[x-k][y-k]==0)
                break;
            if(a[x-k][y-k]==color){
                for(int i=0;i<k;i++){
                    a[x-i][y-i]=color;
                    flag = 1;
                }
                break;
            }
        }
    }
    //左下を変える
    if(a[x+1][y-1]==opp && y>1 && x<SIZE-2){
        for(int k=2;y-k>=0 && x+k<=SIZE-1;k++){
            if(a[x+k][y-k]==opp)
                continue;
            if(a[x+k][y-k]==0)
                break;
            if(a[x+k][y-k]==color){
                for(int i=0;i<k;i++){
                    a[x+i][y-i]=color;
                    flag = 1;
                }
                break;
            }
        }
    }
    //右上を変える
    if(a[x-1][y+1]==opp && x>1 && y<SIZE-2){
        for(int k=2;x-k>=0 && y+k<=SIZE-1;k++){
            if(a[x-k][y+k]==opp)
                continue;
            if(a[x-k][y+k]==0)
                break;
            if(a[x-k][y+k]==color){
                for(int i=0;i<k;i++){
                    a[x-i][y+i]=color;
                    flag = 1;
                }
                break;
            }
        }
    }
    //右下を変える
    if(a[x+1][y+1]==opp && y<SIZE-2 && x<SIZE-2){
        for(int k=2;y+k<=SIZE-1 && x+k<=SIZE-1;k++){
            if(a[x+k][y+k]==opp)
                continue;
            if(a[x+k][y+k]==0)
                break;
            if(a[x+k][y+k]==color){
                for(int i=0;i<k;i++){
                    a[x+i][y+i]=color;
                    flag = 1;
                }
                break;
            }
        }
    }
    if(flag == 0)
        return 1;
    else
        return 0;
}

int board::checkblank(){
    int n=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(a[i][j]==0)
                n++;
        }
    }
    return n;
}

int board::eval(int color){
    int point=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(a[i][j]==color)
                point++;
        }
    }
    return point;
}

int board::eval2(int color){
    int point =0;
    for(int i=0; i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(a[i][j]==color){
                if((i==0 && j==0) || (i==0 && j==7) || (i==7 && j==0) || (i==7 && j==7))
                    point += 30;
                else if((i==0 && j==1) || (i==0 && j==6) || (i==1 && j==1) || (i==1 && j==7)
                    || (i==6 && j==0) || (i==6 && j==7) || (i==7 && j==1) || (i==7 && j==6))
                    point -= 12;
                else if((i==1 && j==1) || (i==1 && j==6) || (i==6 && j==1) || (i==6 && j==6))
                    point -= 15;
                else if(((i==0 || i==2 || i==5 || i==7) && (j==3 || j==4)) || ((i==3 || i==4)&&(j==0 || j==2 || j==3 || j==4 || j==5 || j==7)))
                    point--;
                else if(((i==1 || i==6) && (j==2 || j==3 || j==4 || j==5)) || ((i==2 || i==3 || i==4 || i==5)&&(j==1 || j==6)))
                    point -= 3;
            }
        }
    }
    return point;
}