#include <iostream>
#include <vector>
#define DEPTH 4
using namespace std;

class player{
protected:
    int color;
public:
    void setColor(int x){color=x;};
    int getColor(){return color;};
    virtual void think(board& b) =0;
};

class algo1 : public player{
public:
    void think(board& b);
    int minimax(board b,int x,int y,int c,int d);
};

void algo1::think(board& b){
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){\
            board kari = b;
            if(kari.setDisc(i,j,color)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    int n = kouho.size();
    if(n==0){
        cout << "パスします" << endl;
        b.showBoard();
    }
    else{
        board kari = b;
        int max=minimax(kari,kouho[0][0],kouho[0][1],color,DEPTH);
        int num=0;
        for(int i=0;i<n;i++){
            if(minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH)>max){
                max = minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH);
                num = i;
            }
        }
        b.setDisc(kouho[num][0],kouho[num][1],color);
        b.showBoard();
    }
}

int algo1::minimax(board b, int x, int y, int c, int d){
    b.setDisc(x,y,c);
    if(d==0) return b.eval(color);
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,2/c)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    int best = -1000;
    for(int i=0; i<kouho.size(); i++){
        int val = minimax(b,kouho[i][0],kouho[i][1],2/c, d-1);
        if(c == color && best < val)  best =  val;
        if(c == 2/color && best <-val)  best = -val;
    }
    return best;
}


class algo11 : public player{
public:
    void think(board& b);
    int minimax(board b,int x,int y,int c,int d);
};

void algo11::think(board& b){
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,color)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    int n = kouho.size();
    if(n==0){
        cout << "パスします" << endl;
        b.showBoard();
    }
    else{
        board kari = b;
        int max=minimax(kari,kouho[0][0],kouho[0][1],color,DEPTH);
        int num=0;
        for(int i=0;i<n;i++){
            if(minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH)>max){
                max = minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH);
                num = i;
            }
        }
        b.setDisc(kouho[num][0],kouho[num][1],color);
        b.showBoard();
    }
}

int algo11::minimax(board b, int x, int y, int c, int d){
    b.setDisc(x,y,c);
    if(d==0 || b.checkblank()==0 || b.passcheck()==1) return b.eval(color);
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,2/c)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    if(kouho.size()==0){
        c = 2/c;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                board kari = b;
                if(kari.setDisc(i,j,2/c)==0){
                    if(kari.getDisc(i,j)!=0){
                        kouho.push_back(zahyo);
                        kouho[kouho.size()-1][0]=i;
                        kouho[kouho.size()-1][1]=j;
                    }
                }
            }
        }
    }
    int best = -1000;
    for(int i=0; i<kouho.size(); i++){
        int val = minimax(b,kouho[i][0],kouho[i][1],2/c, d-1);
        if(c == color && best < val)  best =  val;
        if(c == 2/color && best <-val)  best = -val;
    }
    return best;
}

class algo2 : public player{
public:
    void think(board& b);
    int minimax(board b,int x,int y,int c,int d);
};

void algo2::think(board& b){
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,color)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    int n = kouho.size();
    if(n==0){
        cout << "パスします" << endl;
        b.showBoard();
    }
    else{
        board kari = b;
        int max=minimax(kari,kouho[0][0],kouho[0][1],color,DEPTH);
        int num=0;
        for(int i=0;i<n;i++){
            if(minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH)>max){
                max = minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH);
                num = i;
            }
        }
        b.setDisc(kouho[num][0],kouho[num][1],color);
        b.showBoard();
    }
}

int algo2::minimax(board b, int x, int y, int c, int d){
    b.setDisc(x,y,c);
    if(d==0 || b.checkblank()==0) return b.eval2(color);
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,2/c)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    if(kouho.size()==0){
        c = 2/c;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                board kari = b;
                if(kari.setDisc(i,j,2/c)==0){
                    if(kari.getDisc(i,j)!=0){
                        kouho.push_back(zahyo);
                        kouho[kouho.size()-1][0]=i;
                        kouho[kouho.size()-1][1]=j;
                    }
                }
            }
        }
    }
    int best = -1000;
    for(int i=0; i<kouho.size(); i++){
        int val = minimax(b,kouho[i][0],kouho[i][1],2/c, d-1);
        if(c == color && best < val)  best =  val;
        if(c == 2/color && best <-val)  best = -val;
    }
    return best;
}

class algo33 : public player{
public:
    void think(board& b);
    int minimax(board b,int x,int y,int c,int d);
};

void algo33::think(board& b){
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,color)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    int n = kouho.size();
    if(n==0){
        cout << "パスします" << endl;
        b.showBoard();
    }
    else{
        board kari = b;
        int max=minimax(kari,kouho[0][0],kouho[0][1],color,DEPTH);
        int num=0;
        for(int i=0;i<n;i++){
            if(minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH)>max){
                max = minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH);
                num = i;
            }
        }
        b.setDisc(kouho[num][0],kouho[num][1],color);
        b.showBoard();
    }
}

int algo33::minimax(board b, int x, int y, int c, int d){
    b.setDisc(x,y,c);
    if((d==0 && b.checkblank()<20) || b.checkblank()==0) return b.eval(color);
    if(d==0 && b.checkblank()>=20) return b.eval2(color);
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,2/c)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    if(kouho.size()==0){
        c = 2/c;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                board kari = b;
                if(kari.setDisc(i,j,2/c)==0){
                    if(kari.getDisc(i,j)!=0){
                        kouho.push_back(zahyo);
                        kouho[kouho.size()-1][0]=i;
                        kouho[kouho.size()-1][1]=j;
                    }
                }
            }
        }
    }

    int best = -1000;
    for(int i=0; i<kouho.size(); i++){
        int val = minimax(b,kouho[i][0],kouho[i][1],2/c, d-1);
        if(c == color && best < val)  best =  val;
        if(c == 2/color && best <-val)  best = -val;
    }
    return best;
}
class algo3 : public player{
public:
    void think(board& b);
    int minimax(board b,int x,int y,int c,int d);
};

void algo3::think(board& b){
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,color)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    int n = kouho.size();
    if(n==0){
        cout << "パスします" << endl;
        b.showBoard();
    }
    else{
        board kari = b;
        int max=minimax(kari,kouho[0][0],kouho[0][1],color,DEPTH);
        int num=0;
        for(int i=0;i<n;i++){
            if(minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH)>max){
                max = minimax(kari,kouho[i][0],kouho[i][1],color,DEPTH);
                num = i;
            }
        }
        b.setDisc(kouho[num][0],kouho[num][1],color);
        b.showBoard();
    }
}

int algo3::minimax(board b, int x, int y, int c, int d){
    b.setDisc(x,y,c);
    if(d==0 && b.checkblank()<20) return b.eval(color);
    if(d==0 && b.checkblank()>=20) return b.eval2(color);
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,2/c)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    int best = -1000;
    for(int i=0; i<kouho.size(); i++){
        int val = minimax(b,kouho[i][0],kouho[i][1],2/c, d-1);
        if(c == color && best < val)  best =  val;
        if(c == 2/color && best <-val)  best = -val;
    }
    return best;
}

class algo4 : public player{
public:
    void think(board& b);
    int alphabeta(board b,int x,int y,int c,int d, int aplha, int beta);
};

void algo4::think(board& b){
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,color)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    int n = kouho.size();
    if(n==0){
        cout << "パスします" << endl;
        b.showBoard();
    }
    else{
        board kari = b;
        int max=alphabeta(kari,kouho[0][0],kouho[0][1],color,DEPTH+1,-1000,1000);
        int num=0;
        for(int i=0;i<n;i++){
            if(alphabeta(kari,kouho[i][0],kouho[i][1],color,DEPTH+1,-1000,1000)>max){
                max = alphabeta(kari,kouho[i][0],kouho[i][1],color,DEPTH+1,-1000,1000);
                num = i;
            }
        }
        b.setDisc(kouho[num][0],kouho[num][1],color);
        b.showBoard();
    }
}

int algo4::alphabeta(board b, int x, int y, int c, int d, int alpha, int beta){
    b.setDisc(x,y,c);
    if((d==0 && b.checkblank()<20)|| b.checkblank()==0)  return b.eval(color);
    if(d==0 && b.checkblank()>=20) return b.eval2(color);
    vector< vector<int> > kouho;
    vector<int> zahyo(2);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board kari = b;
            if(kari.setDisc(i,j,2/c)==0){
                if(kari.getDisc(i,j)!=0){
                    kouho.push_back(zahyo);
                    kouho[kouho.size()-1][0]=i;
                    kouho[kouho.size()-1][1]=j;
                }
            }
        }
    }
    if(kouho.size()==0){
        c =2/c;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                board kari = b;
                if(kari.setDisc(i,j,2/c)==0){
                    if(kari.getDisc(i,j)!=0){
                        kouho.push_back(zahyo);
                        kouho[kouho.size()-1][0]=i;
                        kouho[kouho.size()-1][1]=j;
                    }
                }
            }
        }
    }
    for(int i=0;(alpha < beta) && i<kouho.size(); i++){
        int val = alphabeta(b,kouho[i][0],kouho[i][1],2/c, d-1,alpha,beta);
        if(c == color && alpha < val){
            alpha =  val;
        }
        else if(c == 2/color && val < beta){
            beta = val;
        }
    }
    if(c == color)
        return alpha;
    else
        return beta;
}