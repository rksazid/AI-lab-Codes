#include <bits/stdc++.h>
#define db cout<<"hello"<<endl
using namespace std;


struct idx{
    int i,j;
    idx(int i,int j):i(i),j(j){}
};

vector<idx>eligible,check[20];

void checkEligible(int board[6][6]){
    eligible.clear();
    for(int i = 0;i<6;i++){
        for(int j = 5;j>=0;j--){
            if(board[j][i]==0){
                eligible.push_back(idx(j,i));
                break;
            }
        }
    }
}

void printEligible(){
    cout<<"eli : "<<endl;
    for(int i = 0;i<eligible.size();i++){
        cout<<eligible[i].i<<" "<<eligible[i].j<<endl;
    }
    cout<<endl;
}

char gridChar(int i) {
    switch(i) {
        case -1:
            return 'O';
        case 0:
            return ' ';
        case 1:
            return 'X';
    }
}

void draw(int b[6][6]) {
    for(int i  = 0; i<6 ; i++ ){
        printf("                                                 | %c | %c | %c | %c | %c | %c |\n",gridChar(b[i][0]),gridChar(b[i][1]),gridChar(b[i][2]),gridChar(b[i][3]),gridChar(b[i][4]),gridChar(b[i][5]));
        printf("                                                 ----+---+---+---+---+----\n");
    }
    printf("                                                   0   1   2   3   4   5  \n");
}

//Checking the winning conditions

int checkRow(int board[6][6]){
    int cnt = 0 ,w;
    for(int i = 0;i<6;i++){
        cnt=0;
        w=0;
        for(int j = 1;j<6;j++){
           if(board[i][j-1] == board[i][j] && board[i][j] != 0){
                cnt++;
           }else cnt=0;
           if(cnt>=3)w = board[i][j];
        }
        if(w != 0) {
            return w;
        }
    }
    return 0;
}

int checkCol(int board[6][6]){
    int cnt = 0 ,w;
    for(int i = 0;i<6;i++){
        cnt=0;
        w=0;
        for(int j = 1;j<6;j++){
           if(board[j-1][i] == board[j][i] && board[j][i] != 0){
                cnt++;
           }else cnt=0;
           if(cnt>=3)w = board[j][i];
        }
        if(w != 0) {
            return w;
        }
    }
    return 0;
}

void inputPData(){
    check[0].push_back(idx(2,0));
    check[0].push_back(idx(3,1));
    check[0].push_back(idx(4,2));
    check[0].push_back(idx(5,3));

    check[1].push_back(idx(1,0));
    check[1].push_back(idx(2,1));
    check[1].push_back(idx(3,2));
    check[1].push_back(idx(4,3));

    check[2].push_back(idx(2,1));
    check[2].push_back(idx(3,2));
    check[2].push_back(idx(4,3));
    check[2].push_back(idx(5,4));

    check[3].push_back(idx(0,0));
    check[3].push_back(idx(1,1));
    check[3].push_back(idx(2,2));
    check[3].push_back(idx(3,3));

    check[4].push_back(idx(1,1));
    check[4].push_back(idx(2,2));
    check[4].push_back(idx(3,3));
    check[4].push_back(idx(4,4));

    check[5].push_back(idx(2,2));
    check[5].push_back(idx(3,3));
    check[5].push_back(idx(4,4));
    check[5].push_back(idx(5,5));

    check[6].push_back(idx(0,1));
    check[6].push_back(idx(1,2));
    check[6].push_back(idx(2,3));
    check[6].push_back(idx(3,4));

    check[7].push_back(idx(1,2));
    check[7].push_back(idx(2,3));
    check[7].push_back(idx(3,4));
    check[7].push_back(idx(4,5));

    check[8].push_back(idx(0,2));
    check[8].push_back(idx(1,3));
    check[8].push_back(idx(2,4));
    check[8].push_back(idx(3,5));

    //

    check[9].push_back(idx(3,0));
    check[9].push_back(idx(2,1));
    check[9].push_back(idx(1,2));
    check[9].push_back(idx(0,3));

    check[10].push_back(idx(4,0));
    check[10].push_back(idx(3,1));
    check[10].push_back(idx(2,2));
    check[10].push_back(idx(1,3));

    check[11].push_back(idx(3,1));
    check[11].push_back(idx(2,2));
    check[11].push_back(idx(1,3));
    check[11].push_back(idx(0,4));

    check[12].push_back(idx(5,5));
    check[12].push_back(idx(4,1));
    check[12].push_back(idx(3,2));
    check[12].push_back(idx(2,3));

    check[13].push_back(idx(4,1));
    check[13].push_back(idx(3,2));
    check[13].push_back(idx(2,3));
    check[13].push_back(idx(1,4));

    check[14].push_back(idx(3,2));
    check[14].push_back(idx(2,3));
    check[14].push_back(idx(1,4));
    check[14].push_back(idx(0,5));

    check[15].push_back(idx(5,1));
    check[15].push_back(idx(4,2));
    check[15].push_back(idx(3,3));
    check[15].push_back(idx(2,4));

    check[16].push_back(idx(4,2));
    check[16].push_back(idx(3,3));
    check[16].push_back(idx(2,4));
    check[16].push_back(idx(1,5));

    check[17].push_back(idx(5,2));
    check[17].push_back(idx(4,3));
    check[17].push_back(idx(3,4));
    check[17].push_back(idx(2,5));
}


int checkPriDiag(int board[6][6]){
    int r,c,w;
    bool flag = false;
    for(int i = 0;i<18;i++){
        r = check[i][0].i;
        c = check[i][0].j;
        w = board[r][c];
        flag = true;
        for(int j = 1;j<4;j++){
            r = check[i][j].i;
            c = check[i][j].j;
            if(board[r][c] != w){
                flag = false;
                break;
            }
        }
        if(flag)return w;
    }
    return 0;
}


int win(int board[6][6]) {
    int winn = checkRow(board) + checkCol(board) + checkPriDiag(board);
    if(winn)
        return winn;
    else return 0;
}



int minimax(int board[6][6], int player) {
    //draw(board);
    //cout<<endl;
    checkEligible(board);
    //How is the position like for player (their turn) on board?
    int winner = win(board);
    if(winner != 0) {
        //cout<<winner<<endl;
        return winner*player;
    }
    int r,c;
    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    for(int i = 0; i < eligible.size(); ++i) {//For all moves,
        r = eligible[i].i;
        c = eligible[i].j;
        board[r][c] = player;//Try the move
        int thisScore = -minimax(board, player*-1);
        if(thisScore > score) {
            score = thisScore;
            move = i;
        }
        board[r][c] = 0;
        //checkEligible(board);
    }
    if(move == -1) return 0;
    return score;
}



void computerMove(int board[6][6]) {
    checkEligible(board);
    int move[2] = {-1,-1};
    int score = -2;
    bool flag = true;
    int r,c;
    for(int i = 0; i < eligible.size(); ++i) {
        r = eligible[i].i;
        c = eligible[i].j;

        board[r][c] = 1;
        int tempScore = -minimax(board, -1);
        board[r][c] = 0;
        checkEligible(board);
        if(tempScore > score) {
            score = tempScore;
            move[0] = r;
            move[1] = c;
        }
    }
    checkEligible(board);
    for(int i = 0; i < eligible.size(); ++i) {
            r = eligible[i].i;
            c = eligible[i].j;
            board[r][c] = 1;
            if(win(board)== 1){
                board[r][c]= 1;
                flag = false;
                break;
            }
            board[r][c] = 0;
    }
    if(flag){
        for(int i = 0; i < eligible.size(); ++i) {
            r = eligible[i].i;
            c = eligible[i].j;
            board[r][c] = -1;
            if(win(board)== -1){
                board[r][c]=1;
                flag = false;
                break;
            }
            board[r][c] = 0;
        }
    }
    if(flag)board[move[0]][move[1]] = 1;
}

int free(int m,int board[6][6]){
    int w;
    for(int i = 0 ;i<eligible.size();i++){
        if(eligible[i].j == m){
            //cout<<m<<"   ";
            if(board[eligible[i].i][m]==0){
                w=eligible[i].i;
                //cout<<w<<endl;
                return w;
            }
            else return -10;
        }
    }
    return -10;
}

void playerMove(int board[6][6]) {
    checkEligible(board);
    //printEligible();
    int move=0,tmp;
    do {
        printf("\n                                                    Input move ([0..5]): \n");
        cout<<"                                                             ";
        scanf("%d", &move);
        printf("\n");
        tmp = free(move,board);
        if(tmp==-10)
        {
            printf("Its Already Occupied !\n");
            move=9999999;
            continue;
        }

    } while (move >= 6 || move < 0);
    board[tmp][move] = -1;
   // draw(board);
}


void welcome(){
    cout<<"                             /***********************************************************/"<<endl;
    cout<<"                             /**                                                       **/"<<endl;
    cout<<"                             /**                 Welcome to the CHIPS GAME             **/"<<endl;
    cout<<"                             /**                                                       **/"<<endl;
    cout<<"                             /***********************************************************/"<<endl;
}



int main() {
    welcome();
    inputPData();
    int board[6][6] ;
    memset(board ,0, sizeof board);
    checkEligible(board);
    //computer squares are 1, player squares are -1.
    cout<<"                                                   Computer: X, You: O"<<endl;
    cout<<"                                                   Play 1st or 2nd ? (1-2) "<<endl;
    cout<<"                                                             ";
    int player=0;
    scanf("%d",&player);
    printf("\n");

    unsigned turn;
    for(turn = 0; turn < 36 && win(board) == 0; ++turn) {
        if((turn+player) % 2 == 0)
            computerMove(board);
        else {
            draw(board);
            playerMove(board);
        }
    }

    switch(win(board)) {
        case 0:
            draw(board);
            printf("                                             A draw. How droll.\n\n\n");
            break;
        case 1:
            draw(board);
            printf("\n                                             Alas! You lose. Better luck next time :)\n\n\n");
            break;
        case -1:
            draw(board);
            printf("\n                                             Congratulations ! You win.\n\n\n");
            break;
    }
}

