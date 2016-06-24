/* Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> [] */
class Solution {
public:
    void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string> &res) {
        if (num.size() == 0 && curNum == target) {
            res.push_back(out);
        }
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if (out.size() > 0) {
                addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
            } else {
                addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperatorsDFS(num, target, 0, 0, "", res);
        return res;
    }
};
/* ---------------------------------------------------- */
class Solution {
public:
long long  evalString(vector<string> num){
	vector<string> newNum;
	bool containProd = true;
	while (containProd){
		newNum.clear();
		for (int i = 0; i < num.size(); i++){
			if (num[i][0] == '*'){
				newNum.pop_back();
				newNum.push_back(to_string(stoll(num[i - 1]) * stoll(num[i + 1])));
				i++;
			}
			else{
				newNum.push_back(num[i]);
			}
		}
		if (newNum.size() == num.size()) containProd = false;
		num = newNum;
	}
	string res = num[0];
	for (int i = 1; i < num.size(); i++){
		if (num[i][0] == '+'){
			res = to_string(stoll(res) + stoll(num[i + 1]));
			i++;
		}
		else {
			res = to_string(stoll(res) - stoll(num[i + 1]));
			i++;
		}
	}
	return stoll(res);
}

void findSolution(string num, int target, vector<string> ress, vector<vector<string>>& res){
	if (num.size() == 0 && evalString(ress) == target){
		res.push_back(ress);
	}
	vector<string> ressBack = ress;
	for (int i = 1; i <= num.size(); i++){
		ress = ressBack;
		string cur = num.substr(0, i);
		if (cur.size() > 1 && cur[0] == '0') return;
		string next = num.substr(i);
		//cout << num << " " << cur << " " << next << endl;
		if (ress.size() > 0){
			ress.push_back("*");
			ress.push_back(cur);
			findSolution(next, target,ress, res);
			ress[ress.size() - 2] = "-";
			findSolution(next, target, ress, res);
			ress[ress.size() - 2] = "+";
			findSolution(next, target,ress, res);
		}
		else {
			ress.push_back(cur);
			findSolution(next, target,ress, res);
		}
	}
}

vector<string> addOperators(string num, int target) {
  vector<vector<string>> res;
	vector<string> ress;
	ress.clear();
	findSolution(num, target,ress, res);
  vector<string> output;
for (int i = 0; i < res.size(); i++){
    string s;
    for (int j = 0; j < res[i].size(); j++){
      s = s + res[i][j];
    }
    output.push_back(s);
  }
    return res;
}
};
