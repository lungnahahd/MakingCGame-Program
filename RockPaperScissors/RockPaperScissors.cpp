﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//main함수 위에다 만들지 않으면 식별자 인식 못하는 오류 발생
void PlayGameVer1()
{
	int presult = 0;
	int cresult = 0;


	while (true) {
		printf("가위 < 1 >, 바위 < 2 >, 보 < 3 > 중에 하나를 선택하세요! \n");
		Sleep(50);
		int player = 0;
		int com = 0;

		srand(time(NULL));
		com = rand() % 3 + 1;
		_getch();
		if (GetAsyncKeyState('1') & 0x8000) {
			player = 1;

		}
		else if (GetAsyncKeyState('2') & 0x8000) {
			player = 2;
		}
		else if (GetAsyncKeyState('3') & 0x8000) {
			player = 3;
		}
		else {
			player = 0;
		}
		if (player == 0) {
			srand(time(NULL));
			player = rand() % 3 + 1;
		}
		if (player == 1) {
			const char *showplayer = "가위";
			printf("플레이어 : %s \n", showplayer);
		}
		else if (player == 2) {
			const char *showplayer = "바위";
			printf("플레이어 : %s \n", showplayer);
		}
		else if (player == 3) {
			const char *showplayer = "보";
			printf("플레이어 : %s \n", showplayer);
		}
		if (com == 1) {
			const char *showcom = "가위";
			printf("컴퓨터 : %s \n", showcom);
		}
		else if (com == 2) {
			const char *showcom = "바위";
			printf("컴퓨터 : %s \n", showcom);
		}
		else if (com == 3) {
			const char* showcom = "보";
			printf("컴퓨터 : %s \n", showcom);
		}

		if (player == com) {
			printf("비겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
		}
		else if (player > com ) {
			if (player == 3 && com == 1) {
				cresult++;
				printf("졌습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
			}
			else {
				presult++;
				printf("이겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
			}
		
		}
		else {
			if (player == 1 && com == 3) {
				presult++;
				printf("이겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
			}
			else {
				cresult++;
				printf("졌습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
			}
		}

		if (presult == 3) {
			printf("승리하셨습니다. (%d : %d) \n", presult, cresult);
			break;
		}
		else if (cresult == 3) {
			printf("패배하셨습니다. (%d : %d) \n", presult, cresult);
			break;
		}


	}
}

//배열을 이용한 가위바위보 알고리즘
void PlayGameVer2() {
	char result[3][3] = { {0,1,2},{2,0,1},{1,2,0} };
	char showresult[3][10] = { "무","패","승" };
	int player = 0;
	int com = 0;
	int fresult = 0;
	srand(time(NULL));
	while (true) {
		printf("가위 < 1 >, 바위 < 2 >, 보 < 3 > 중에 하나를 선택하세요! \n");
		com = rand() % 3 + 1;
		_getch();
		if (GetAsyncKeyState('1') & 0x8000) {
			player = 1;

		}
		else if (GetAsyncKeyState('2') & 0x8000) {
			player = 2;
		}
		else if (GetAsyncKeyState('3') & 0x8000) {
			player = 3;
		}
		else {
			player = 0;
		}
		if (player == 0) {
			srand(time(NULL));
			player = rand() % 3 + 1;
		}
		fresult = result[player][com];
		printf("결과 : %s \n", showresult[fresult]);
	}

}

//구성 : 메인 화면 + 게임 화면 + 결과 화면
int main(void)
{
	
	
	PlayGameVer1();

	//PlayGameVer2();

	system("pause");
	return 0;
}
