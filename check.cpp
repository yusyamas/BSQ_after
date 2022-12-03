#include<bits/stdc++.h>
using namespace std;

struct s_grid{
    vector<char> rule;
    string buff;
    int strn;
    int x;
    int y;
    vector<vector<int>> grid;
    s_grid(){
        rule.resize(3);
    }
};

struct s_ans{
    int place;
    int place_x;
    int place_y;
    int len;
    bool flag;
    s_ans(){}
};

void rule_set(s_grid &panel, char **argv){
    panel.y = (int)strtol(argv[1], NULL, 10);
    for(int i = 0; i < 3; i++){
        panel.rule[i] = argv[2][i];
    }
}

int file_read(s_grid &panel){
    ifstream ifs("./test.txt");
    if (!ifs.is_open()){
        cerr << "fileopen失敗" << endl;
        return 0;
    }
    panel.buff = string(istreambuf_iterator<char>(ifs), 
        istreambuf_iterator<char>());
    panel.strn = panel.buff.size();
    return 1;
}

void grid_xy_check(s_grid &panel){
    panel.x = panel.strn / panel.y - 1;
}

void set_grid(s_grid &panel, s_ans &state){
    panel.grid = vector(panel.y, vector<int>(panel.x));
    state.place = -1;
    state.flag = true;
    for(int i = 0; i < panel.strn; i++){
        if (panel.buff[i] == '\n'){
            continue;
        }
        int di = i / (panel.x + 1);
        int dj = i % (panel.x + 1);
        if (state.place == -1 && panel.buff[i] == panel.rule[2]){
            state.place = di * panel.x + dj;
        }
        for(int c = 0; c < 3; c++){
            if (panel.rule[c] == panel.buff[i]){
                panel.grid[di][dj] = c;
                break;
            }
        }
    }
    if (state.place == -1){
        state.flag = false;
    }
}

void bsq_len_check(s_grid &panel, s_ans &state){
    state.len = 0;
    if (!state.flag)
        return;
    state.place_x = state.place % panel.x;
    state.place_y = state.place / panel.x;
    for(int i = state.place_x; i < panel.x; i++){
        if (panel.grid[state.place_y][i] == 2){
            state.len++;
        }else{
            break;
        }
    }
}

bool is_into_bsq(int i, int j, s_ans &state){
    if (!(state.place_x <= j && j < state.place_x + state.len))
        return false;
    if (!(state.place_y <= i && i < state.place_y + state.len))
        return false;
    return true;
}

bool grid_format_check(s_grid &panel, s_ans &state){
    for(int i = 0; i < panel.y; i++){
        for(int j = 0; j < panel.x; j++){
            if(state.flag && is_into_bsq(i, j, state)){
                if (panel.grid[i][j] != 2)
                    return false;
            }
            if(!state.flag || !is_into_bsq(i, j, state)){
                if (panel.grid[i][j] != 0 && panel.grid[i][j] != 1){
                    return false;
                }
            }
        }
    }
    return true;
}

//(di,dj)が埋められる場所ならtrue, そうでないならfalse
bool rule_check(s_grid &panel, int di, int dj){
    if (panel.grid[di][dj] == 0)
        return true;
    if (panel.grid[di][dj] == 2)
        return true;
    return false;
}

//(i.j)を左上、長さlenのSQがより良いBSQか判定 
//より良いbsqがあるならfalseを返す
bool check_bsq(s_grid &panel, int len, int i, int j){
    for(int di = i; di < i + len; di++){
        for(int dj = j; dj < j + len; dj++){
            if (!(di < panel.y) || !(dj < panel.x)){
                return true;
            }
            if (!rule_check(panel, di, dj)){
                return true;
            }
        }
    }
    return false;
}

bool check_ans_obstacle(s_grid &panel){
    for(int i = 0; i < panel.y; i++){
        for(int j = 0; j < panel.x; j++){
            if (panel.grid[i][j] != 1)
                return false;
        }
    }
    return true;
}

//全座標からのSQに本来のBSQより良いBSQが存在するか判定
//存在しないならtrue, 存在するならfalse
bool check_ans(s_grid &panel, s_ans &state){
    for(int i = 0; i < panel.y; i++){
        for(int j = 0; j < panel.x; j++){
            int place = panel.x * i + j;
            if (place < state.place){
                if (!check_bsq(panel, state.len, i, j))
                    return false;
            }else{
                if (!check_bsq(panel, state.len + 1, i, j))
                    return false;
            }
        }
    }
    return true;
}

int print_ans(int no){
    if (no == 0){
        printf("Accepted\n");
        return 0;
    }
    if (no == 1){
        printf("Wrong Answer\n");
        return 1;
    }
    return 1;
}

int main(int argc, char** argv){
    s_grid panel;
    rule_set(panel, argv);
    if (!file_read(panel))
        print_ans(1);
    grid_xy_check(panel);
    s_ans state;
    set_grid(panel, state);
    bsq_len_check(panel, state);
    if (!grid_format_check(panel, state))
        print_ans(1);
    if (check_ans(panel, state))
        return print_ans(0);
    else
        return print_ans(1);
    return 0;
}
