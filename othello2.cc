#include <iostream>
#include <vector>
#include "board2.h"
#include "player.h"

using namespace std;

int main(){
    int n;
    cout << "先攻の場合は2を、後攻の場合は1を入力してください" << endl;
    cin >> n;
    board b1;
    algo11 p1,npc;
    if(n==2){
        p1.setColor(2);
        npc.setColor(1);
    }
    else{
        p1.setColor(1);
        npc.setColor(2);
    }
    int x,y;
    cout << "試合を始めます。打ちたい座標を入力してください。" << endl;
    cout << "打つ場所がない場合は 100 100と入力してください。" << endl;

    if(n==2){
        cin >> x >> y;
        b1.setDisc(x,y,n);
        b1.showBoard();
    }

    while(b1.checkblank()>0 && b1.passcheck()==0){
        npc.think(b1);
        cout << "You:" << b1.eval(n) << " algorithm:" << b1.eval(2/n) << endl;
        if(b1.checkblank()==0)
            break;
        cout << "あなたの番です" << endl;
        cin >> x >> y;
        b1.setDisc(x,y,n);
        b1.showBoard();
        cout << b1.eval(n) << endl;
    }
    if(b1.eval(n)>b1.eval(2/n))
        cout << "You win!" << endl;
    if(b1.eval(n)==b1.eval(2/n))
        cout << "draw." << endl;
    if(b1.eval(n)<b1.eval(2/n))
        cout << "You lose." << endl;
}