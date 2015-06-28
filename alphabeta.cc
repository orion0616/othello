int player4::aplhabeta(board b, int x, int y, int c, int d, int alpha, int beta){
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
    int select = 0;
    for(int i=0;(alpha < beta) && i<kouho.size(); i++){
        int val = alphabeta(b,kouho[i][0],kouho[i][1],2/c, d-1,alpha,beta);
        if(c == color && alpha < val){
            alpha =  val;
            select = i;
        }
        else if(c == 2/color && val < beta){
          beta = val;
          select = i;
        }
    }
    if(c == color)
        return alpha;
    else
        return beta;
}