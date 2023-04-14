#include <stdio.h>

#define MAXCANDIDATES 20 // �ִ� chessboard�� ũ��
#define NMAX 20 // �ִ� chessboard�� ũ��

/*c������ bool ���¸� ��������� �Ѵ�. �����ٸ� �׳� int�� �̿��ϵ��� ����.*/
typedef enum { false, true } bool; 

bool finished = false; 
int solution_count=0;

void process_solution(int a[], int k) 
{
	int i; // i�� �� �����Ѱ��� �𸣰ڴ�..

	solution_count++; // �ϳ��� Ǯ����.. (����� �� ã��.)
}

int is_a_solution(int a[], int k, int n)
{
	return (k == n); // �־��� �� ������� ��� ���Ҵ�-> �̼� ��.
}


void construct_candidates(int a[], int k, int n, int c[], int* ncandidates)
{
	int i, j;
	bool legal_move; // shall I move..?

	*ncandidates = 0;
	for (i = 1; i <= n; i++) { // �ϳ��� column���� row��� �Ⱦ��(��->�Ʒ� ����)
		legal_move = true;
		for (j = 1; j < k; j++) { // �ռ� ���Ҵ� Į������ �� ��ġ�� ���캸��. 
			if (abs((k)-j) == abs(i - a[j])) // �밢���� ��ġ�ϸ� �� �ǰ�..
				legal_move = false;
			if (i == a[j]) // ���� �࿡ ��ġ�ϸ� �� ��.
				legal_move = false;
		}
		if (legal_move == true) { // ��� ������ ����ߴٸ� 
			c[*ncandidates] = i; // �ϴ� �ϳ��� ��츦 �������ش�. i��°�� ��ġ�� ���.
			*ncandidates = *ncandidates + 1; // �׸��� ���� ��쵵 ������ ����.
		}
	}
}

void backtrack(int a[], int k, int n)
{
	int c[MAXCANDIDATES]; // �ӽ� ������ ��� �׸�
	int ncandidates; // �ӽ� ����� ��
	int i; // for iteration

	if (is_a_solution(a, k, n)) // ���� ��� ��ġ�ߴ��� ?
		process_solution(a, k); // �׷��ٸ� ����� �� ī��Ʈ���ֱ�.
	else {
		k = k + 1; // �� ��° Į���� �� ������. (1���� �����մϴ�.)
		construct_candidates(a, k, n, c, &ncandidates); // ���� Į������ ������ ��� ����� �� Ž���ϱ�
		for (i = 0; i < ncandidates; i++) {
			a[k] = c[i]; // �̸� ������ ��츦 �ϳ��� �������ϴ�.
			backtrack(a, k, n); // �� ����� ������Ѻ��ٸ�..
			if (finished) return; // ���� Ż���� �� �ִ� ������ �ִٸ� ������ ���ָ� �ȴ�.(���� �̼�����.)
		}
	}
}

void nqueens(int n) // ���� main�Լ���.. n�� ������ ũ�� (n*n)
{
	int a[NMAX];

	solution_count = 0; // �� ����� �� ī��Ʈ
	backtrack(a, 0, n); // ������ ù��° Į������.
	printf("n=%d solution_count=%d\n", n, solution_count); // ���� ��� ���
}

int main() {

	nqueens(14); // �Լ� ȣ�⸸ ���ݴϴ�.
	
	return 0;
}