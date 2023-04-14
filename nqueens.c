#include <stdio.h>

#define MAXCANDIDATES 20 // 최대 chessboard의 크기
#define NMAX 20 // 최대 chessboard의 크기

/*c에서는 bool 형태를 정의해줘야 한다. 귀찮다면 그냥 int를 이용하도록 하자.*/
typedef enum { false, true } bool; 

bool finished = false; 
int solution_count=0;

void process_solution(int a[], int k) 
{
	int i; // i는 왜 정의한건지 모르겠다..

	solution_count++; // 하나를 풀었다.. (경우의 수 찾음.)
}

int is_a_solution(int a[], int k, int n)
{
	return (k == n); // 주어진 퀸 개수대로 모두 놓았다-> 미션 완.
}


void construct_candidates(int a[], int k, int n, int c[], int* ncandidates)
{
	int i, j;
	bool legal_move; // shall I move..?

	*ncandidates = 0;
	for (i = 1; i <= n; i++) { // 하나의 column에서 row대로 훑어보기(위->아래 방향)
		legal_move = true;
		for (j = 1; j < k; j++) { // 앞서 보았던 칼럼들의 퀸 위치를 살펴보기. 
			if (abs((k)-j) == abs(i - a[j])) // 대각선에 위치하면 안 되고..
				legal_move = false;
			if (i == a[j]) // 같은 행에 위치하면 안 됨.
				legal_move = false;
		}
		if (legal_move == true) { // 모든 조건을 통과했다면 
			c[*ncandidates] = i; // 일단 하나의 경우를 생성해준다. i번째에 위치할 경우.
			*ncandidates = *ncandidates + 1; // 그리고 다음 경우도 건지러 간다.
		}
	}
}

void backtrack(int a[], int k, int n)
{
	int c[MAXCANDIDATES]; // 임시 경우들을 담는 그릇
	int ncandidates; // 임시 경우의 수
	int i; // for iteration

	if (is_a_solution(a, k, n)) // 퀸을 모두 배치했는지 ?
		process_solution(a, k); // 그렇다면 경우의 수 카운트해주기.
	else {
		k = k + 1; // 몇 번째 칼럼을 볼 것인지. (1부터 시작합니다.)
		construct_candidates(a, k, n, c, &ncandidates); // 현재 칼럼에서 가능한 모든 경우의 수 탐색하기
		for (i = 0; i < ncandidates; i++) {
			a[k] = c[i]; // 미리 봐놨던 경우를 하나씩 꺼내봅니다.
			backtrack(a, k, n); // 각 경우대로 진행시켜본다면..
			if (finished) return; // 먼저 탈출할 수 있는 조건이 있다면 설정을 해주면 된다.(아직 미설정됨.)
		}
	}
}

void nqueens(int n) // 거의 main함수급.. n은 보드의 크기 (n*n)
{
	int a[NMAX];

	solution_count = 0; // 총 경우의 수 카운트
	backtrack(a, 0, n); // 시작은 첫번째 칼럼부터.
	printf("n=%d solution_count=%d\n", n, solution_count); // 최종 결과 출력
}

int main() {

	nqueens(14); // 함수 호출만 해줍니다.
	
	return 0;
}