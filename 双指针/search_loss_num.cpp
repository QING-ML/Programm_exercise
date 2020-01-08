#include <iostream>
#include <vector>
using namespace std;
vector<int> search_loss_number(int down_limit, int up_limit, int vector<int> A){
	int current_num = down_limit;
	vector<int> result;
	for(int i = 0; i < A.size(); i++){
		while(current_num != A[i]){
			result.push_back(current_num);
			urrent_num++;
		}
		current_num++;
	}
	while(current_num <= up_limit){
		result.push_back(current_num);
		current_num++;
	}
	return result;
}
