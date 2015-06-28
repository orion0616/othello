#include <iostream>
#include <vector>
#include "board2.h"
#include "player.h"

using namespace std;

//アルゴリズム同士の対戦
int main(){
    int n;
    cout << "テストアルゴリズムは先攻(2)or後攻(1)？" << endl;
    cin >> n;
    board b1;
    algo11 p1; //相手
    algo1 p2; //こいつの強さを測る
    if(n==2){
        p2.setColor(2);
        p1.setColor(1);
    }
    else{
        p2.setColor(1);
        p1.setColor(2);
    }


    if(n==2)
        p2.think(b1);

    while(b1.checkblank()>0 && b1.passcheck()==0){
        p1.think(b1);
        if(b1.checkblank()==0)
            break;
        p2.think(b1);
    }
    if(b1.eval(n)>b1.eval(2/n))
        cout << "テストアルゴリズムの勝ち" << endl;
    if(b1.eval(n)==b1.eval(2/n))
        cout << "引き分け" << endl;
    if(b1.eval(n)<b1.eval(2/n))
        cout << "テストアルゴリズムの負け" << endl;
}