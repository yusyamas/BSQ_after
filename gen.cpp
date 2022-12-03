#include<bits/stdc++.h>
using namespace std;

struct gen {
	vector<int> rnd;
	string rule;
	int x;
	int y;
	string str;
	gen(){
		rnd.assign(3, 0);
		rule.assign(3, ' ');
		x = 0;
		y = 0;
	}
};

void set_rule_rnd(gen &state){
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
		state.rule[i] += state.rnd[i];
	}
}

void set_rule_size(gen &state, int type){
	srand((unsigned)time(NULL));
	if (type == 0){
		state.x = 1;
		state.y = 1;
	}else if (type == 1){
		state.x = 2 + rand() % (9 - 2 + 1);
		state.y = 2 + rand() % (9 - 2 + 1);
	}else if (type == 2){
		state.x = 10 + rand() % (99 - 10 + 1);
		state.y = 10 + rand() % (99 - 10 + 1);
	}else if (type == 3){
		state.x = 100 + rand() % (999 - 100 + 1);
		state.y = 100 + rand() % (999 - 100 + 1);
	}else if (type == 4){
		state.x = 1000 + rand() % (1200 - 1000 + 1);
		state.y = 1000 + rand() % (1200 - 1000 + 1);
	}
}

void make_str(gen &state, int type, int density){
	srand((unsigned)time(NULL));
	state.str = to_string(state.y) + state.rule + '\n';
	if (type == 0){
		state.rule[1] = state.rule[0];
	}else if (type == 1){
		state.rule[0] = state.rule[1];
	}
	for (int i = 0; i < state.y; i++) {
		for (int j = 0; j < state.x; j++) {
			if (rand() % 100 < density) {
				state.str += state.rule[1];
			}else {
				state.str += state.rule[0];
			}
		}
		state.str += '\n';
	}
}

void output(gen &state, char *filename){
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp, "%s", state.str.c_str());
	fclose(fp);
}

int	main(int argc, char **argv){
	gen state;
	set_rule_rnd(state);
	int type1 = atoi(argv[2]);
	int type2 = atoi(argv[3]);
	int density = atoi(argv[4]);
	set_rule_size(state, type1);
	make_str(state, type2, density);
	if (argv[1][0] == 'f') output(state, argv[5]);
	else printf("%s", state.str.c_str());
	return 0;
}
