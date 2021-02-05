"""
날짜: 2021-02-05
작성자: 전태현

문제 풀이
처음에 문제를 읽었을 때는 인형을 pop시키는 최대 개수를 구하는 backtracking 문제인 줄 알았으나,
단순한 stack을 이용한 문제였다.

moves를 통해서 인형을 뽑으면 앞의 인형과 비교하여 같은 인형이면 pop시키는 방식으로 해결하였다. 
"""
def solution(board, moves):
    stack = []
    answer = 0
    for move in moves:
        for col in range(len(board)):
            if board[col][move-1] != 0:
                stack.append(board[col][move-1])
                board[col][move-1] = 0
                stack_size = len(stack)
                if (stack_size > 1) and (stack[stack_size-2] == stack[stack_size-1]):
                    stack.pop()
                    stack.pop()
                    answer+=2
                break
    return answer
