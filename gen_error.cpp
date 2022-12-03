#include<bits/stdc++.h>
using namespace std;

struct file {
    int x;
    int y;
    int n;
    vector<int> rnd;
	string rule;
    string second;
    vector<string> filenames;
    vector<FILE *> fp;
    file (){
        rnd.assign(3, 0);
        rule.resize(3);
    }
};

void input(file &state, char **argv){
    state.n = 16;
    state.x = (int)strtol(argv[1], NULL, 10);
    state.y = (int)strtol(argv[2], NULL, 10);
    state.filenames.resize(state.n);
    state.fp.resize(state.n);
    for(int i = 0; i < state.n; i++){
        state.filenames[i] = "./maperror/map";
        if (i < 10) state.filenames[i] += '0';
        state.filenames[i] += to_string(i);
        state.filenames[i] += ".txt";
    }
    for(int i = 0; i < state.n; i++){
        state.fp[i] = fopen(state.filenames[i].c_str(), "w");
    }
}

void set_first(file &state){
	srand((unsigned)time(NULL));
	int cn = 126 - 32 + 1;
	while(true){
		int flag = true;
		for (int i = 0; i < 3; i++){
			state.rnd[i] = rand() % cn;
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if (i != j && state.rnd[i] == state.rnd[j]){
					flag = false;
				}
			}
		}
		if (!flag) continue;
		else break;
	}
	for (int i = 0; i < 3; i++){
		state.rule[i] = ' ' + state.rnd[i];
	}
}

void set_second(file &state){
    srand((unsigned)time(NULL));
    int density = rand() % (state.y * 2);
    for (int i = 0; i < state.y; i++) {
		for (int j = 0; j < state.x; j++) {
			if (rand() % 100 < density) {
				state.second += ' ' + state.rnd[1];
			}else {
				state.second += ' ' + state.rnd[0];
			}
		}
		state.second += '\n';
	}
}

void which_one_case(file &state){
    string num = to_string(state.y);
    fprintf(state.fp[0], "%s%s\n", num.c_str(), state.rule.c_str());
    fprintf(state.fp[1], "%s", state.second.c_str());
}

void y_error_case(file &state){
    srand((unsigned)time(NULL));
    int digit = to_string(state.y).size();
    int add_num = rand() % 10;
    int num = state.y;
    while(num == state.y){
        num = rand() % (int)pow(10, digit);
    }
    string s_num = to_string(num);
    string s_add = to_string(add_num);
    string y_num = to_string(state.y);
    fprintf(state.fp[2], "%s%s\n%s", s_num.c_str(), state.rule.c_str(),
        state.second.c_str());
    fprintf(state.fp[3], "%s\n%s", state.rule.c_str(), state.second.c_str());
    fprintf(state.fp[4], "%s%s%s\n%s", s_add.c_str(), y_num.c_str(), state.rule.c_str(),
        state.second.c_str());
}

void first_char_case(file &state){
    string rule = state.rule;
    string y_num = to_string(state.y);
    for(int i = 5; i < 8; i++){
        rule.pop_back();
        if (i < 7){
            fprintf(state.fp[i], "%s%s\n%s", y_num.c_str(), rule.c_str(),
                state.second.c_str());
        }else{
            fprintf(state.fp[i], "%s\n%s", y_num.c_str(), state.second.c_str());
        }
    }
    char a = state.rule[0];
    char b = state.rule[1];
    vector<string> cover(4);
    cover[0] = a;
    cover[0] += a;
    cover[0] += b;
    cover[1] = a;
    cover[1] += b;
    cover[1] += b;
    cover[2] = a;
    cover[2] += b;
    cover[2] += a;
    cover[3] = a;
    cover[3] += a;
    cover[3] += a;
    for(int i = 0; i < 4; i++){
        fprintf(state.fp[i + 8], "%s%s\n%s", y_num.c_str(), cover[i].c_str(), 
            state.second.c_str());
    }
}

void other_case_1(file &state){
    string y_num = to_string(state.y);
    string other1;
    srand((unsigned)time(NULL));
    int density = rand() % (state.y * 2);
    for (int i = 0; i < state.y; i++) {
        int x = state.x;
        while(x <= 0 || x == state.x) x = state.x + rand() % 5 - 2; 
		for (int j = 0; j < x; j++) {
			if (rand() % 100 < density) {
				other1 += ' ' + state.rnd[1];
			}else {
				other1 += ' ' + state.rnd[0];
			}
		}
		other1 += '\n';
	}
    fprintf(state.fp[12], "%s%s\n%s", y_num.c_str(), state.rule.c_str(),
        other1.c_str());
}

string make_map(file &state, char a, char b){
    srand((unsigned)time(NULL));
    int density = rand() % (state.y * 2);
    string ret;
    for (int i = 0; i < state.y; i++) {
		for (int j = 0; j < state.x; j++) {
			if (rand() % 100 < density) {
				ret += ' ' + b;
			}else {
				ret += ' ' + a;
			}
		}
		ret += '\n';
	}
    return ret;
}

void other_case_2(file &state){
    string y_num = to_string(state.y);
    srand((unsigned)time(NULL));
    string s2 = make_map(state, state.rnd[0], state.rnd[2]);
    string s3 = make_map(state, state.rnd[2], state.rnd[1]);
    int cn = 126 - 32 + 1;
    vector<char> rule(2);
	while(true){
		int flag = true;
		for (int i = 0; i < 2; i++){
			rule[i] = rand() % cn;
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if (i != j && rule[i] == rule[j]){
					flag = false;
				}
			}
		}
		if (!flag) continue;
		else break;
	}
    string s4 = make_map(state, rule[0], rule[1]);
    fprintf(state.fp[13], "%s%s\n%s", y_num.c_str(), state.rule.c_str(),
        s2.c_str());
    fprintf(state.fp[14], "%s%s\n%s", y_num.c_str(), state.rule.c_str(),
        s3.c_str());
    fprintf(state.fp[15], "%s%s\n%s", y_num.c_str(), state.rule.c_str(),
        s4.c_str());
}

void file_close(file &state){
    for(int i = 0; i < state.n; i++){
        fclose(state.fp[i]);
    }
}

int main(int argc, char **argv){
    file state;
    input(state, argv);
    set_first(state);
    set_second(state);
    which_one_case(state);
    y_error_case(state);
    first_char_case(state);
    other_case_1(state);
    other_case_2(state);
    file_close(state);
    return 0;
}
