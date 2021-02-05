// 사용언어 : C++

// ******************************************************************

// 문제 : moves를 하나의 stack로 생각하며 풀이하였다.
// 날짜 : 2021/2/5
// 작성자 : 강조은
// 문제풀이 : 두개의 반복문을 사용하여 move의 값에 해당하는 열을 위에서부터 차례대로 검사하여 0이 아니면 stack에 push하는 방식으로 풀이하였다.

//******************************************************************

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int tmp = 0;
    stack <int> s;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] != 0) {
                if (!s.empty()) tmp = s.top();

                s.push(board[j][moves[i] - 1]);

                if (s.top() == tmp) {
                    s.pop();
                    s.pop();
                    answer+=2;
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}

