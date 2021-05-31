#define _CRT_SECURE_NO_WARNINGS
#include<bangtal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
SceneID scene1, scene2, scene3, scene4, scene5;
ObjectID page1, page2, page3;
ObjectID startbutton, next1, next2, next3;
ObjectID ar[5], br[5], cr[5];
ObjectID al[5], bl[5], cl[5];
TimerID timer;
int count = 0;
int score = 0;


bool checked[5];

int arX[5] = { 1210, 805, 800, 890, 900
	
};

int alX[5] = { 580, 175, 170, 260, 270
	//틀린그림 좌표들
};

int aY[5] = { 40, 75, 274, 255, 200
	//틀린그림 좌표들
};

int brX[5] = { 1210, 805, 800, 890, 900
	//틀린그림 좌표들
};

int blX[5] = { 580, 175, 170, 260, 270
	//틀린그림 좌표들
};

int bY[5] = { 40, 75, 274, 255, 200
	//틀린그림 좌표들
};

int crX[5] = { 1210, 805, 800, 890, 900
	//틀린그림 좌표들
};

int clX[5] = { 580, 175, 170, 260, 270
	//틀린그림 좌표들
};

int cY[5] = { 40, 75, 274, 255, 200
	//틀린그림 좌표들
};
//틀린그림들의 좌표들
int radius[7] = { 54, 50, 60,30, 30, 50, 50 };

bool checkIn(int x, int y, int cx, int cy, int r) {
	return (x > cx - r && x<cx + r && y>cy - r && y < cy + r);
}


//타이머콜백함수
void timerCallback(TimerID timer)
{
	count++;
	setTimer(timer, 1.f);
	startTimer(timer);
}

//마우스콜백함수
void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startbutton) {
		enterScene(scene2);

		if (object == page1) {

			bool wrong = true;

			for (int i = 0; i < 5; i++) {

				if (checkIn(x, y, alX[i], aY[i], radius[i]) || checkIn(x, y, arX[i], aY[i], radius[i])) {

					showObject(al[i]);
					showObject(ar[i]);
					//찾은 경우에 checked[i]를 true로 변경
					checked[i] = true;
					wrong = false;
				}
			}
			if (wrong) {
				endGame();
			}
			else {
				// 모두 찾았는가를 저장하는 변수를 선언하기
				bool completed = true;
				if (object == next1) {
					enterScene(scene3);

					if (object == page2) {

						bool wrong = true;

						for (int i = 0; i < 5; i++) {

							if (checkIn(x, y, blX[i], bY[i], radius[i]) || checkIn(x, y, brX[i], bY[i], radius[i])) {

								showObject(bl[i]);
								showObject(br[i]);
								//찾은 경우에 checked[i]를 true로 변경
								checked[i] = true;
								wrong = false;
							}
						}
						if (wrong) {
							endGame();
						}
						else {
							// 모두 찾았는가를 저장하는 변수를 선언하기
							bool completed = true;
							if (object == next2) {
								enterScene(scene4);

								if (object == page3) {

									bool wrong = true;

									for (int i = 0; i < 5; i++) {

										if (checkIn(x, y, clX[i], cY[i], radius[i]) || checkIn(x, y, crX[i], cY[i], radius[i])) {

											showObject(cl[i]);
											showObject(cr[i]);
											//찾은 경우에 checked[i]를 true로 변경
											checked[i] = true;
											wrong = false;
										}
									}
									if (wrong) {
										endGame();
									}
									else {
										// 모두 찾았는가를 저장하는 변수를 선언하기
										bool completed = true;
										if (object == next3) {
											enterScene(scene5);
										}

										// 7개 중에서 하나라도 찾지 못한 것이 있으면 completed = false로 변경한다.
										// i는 0부터 7보다 작을 때까지 i를 1씩 증가시켜주는 반복문
										for (int i = 0; i < 5; i++) {
											// checked[i]가 false이면 completed를 false로 변경한다.
											if (checked[i] == false) {
												completed = false;
											}
										}
									}
								}
							}
							// 7개 중에서 하나라도 찾지 못한 것이 있으면 completed = false로 변경한다.
							// i는 0부터 7보다 작을 때까지 i를 1씩 증가시켜주는 반복문
							for (int i = 0; i < 5; i++) {
								// checked[i]가 false이면 completed를 false로 변경한다.
								if (checked[i] == false) {
									completed = false;
								}
							}
						}
					}
				}

			    // 7개 중에서 하나라도 찾지 못한 것이 있으면 completed = false로 변경한다.
				// i는 0부터 7보다 작을 때까지 i를 1씩 증가시켜주는 반복문




				for (int i = 0; i < 5; i++) {
					// checked[i]가 false이면 completed를 false로 변경한다.
					if (checked[i] == false) {
						completed = false;

					}



				}
			}
		}
	}
}




int main() {
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

	//scene 만들기
	scene1= createScene("게임설명", "게임설명창.png");
	scene2 = createScene("1p 경기화면", "배경.png");
	scene3 = createScene("2p 경기화면", "배경.png");
	scene4 = createScene("3p 경기화면", "배경.png");
	scene5 = createScene("점수판", "점수판배경.png");


	//게임시작버튼
	startbutton = createObject("startbutton.png");
	locateObject(startbutton, scene1, 0, 0);
	showObject(startbutton);



	//다음버튼
	next1 = createObject("next.png");
	locateObject(next1, scene2, 0, 0);
	showObject(next1);

	next2 = createObject("next.png");
	locateObject(next2, scene3, 0, 0);
	showObject(next2);

	next3 = createObject("next.png");
	locateObject(next3, scene4, 0, 0);
	showObject(next3);
	
	//함수 정의
	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);
	timer = createTimer(1.f);


	//틀린그림 경기판 설정
	page1 = createObject("pan1.png");
	locateObject(page1, scene2, 0, 0);
	showObject(page1);

	page2 = createObject("pan2.png");
	locateObject(page2, scene3, 0, 0);
	showObject(page2);

	page3 = createObject("pan3.png");
	locateObject(page3, scene4, 0, 0);
	showObject(page3);

	//별표표시
	for (int i = 0; i < 5; i++) {
		al[i] = createObject("star.png");
		locateObject(al[i], scene1, alX[i] - 25, aY[i] + 27);

		ar[i] = createObject("star.png");
		locateObject(ar[i], scene1, arX[i] - 25, aY[i] + 27);
	}

	for (int i = 0; i < 5; i++) {
		bl[i] = createObject("star.png");
		locateObject(bl[i], scene1, blX[i] - 25, bY[i] + 27);

		br[i] = createObject("star.png");
		locateObject(br[i], scene1, brX[i] - 25, bY[i] + 27);
	}

	for (int i = 0; i < 5; i++) {
		cl[i] = createObject("star.png");
		locateObject(cl[i], scene1, clX[i] - 25, cY[i] + 27);

		cr[i] = createObject("star.png");
		locateObject(cr[i], scene1, crX[i] - 25, cY[i] + 27);
	}


	srand(time(NULL));
	//겜시작
	startGame(scene1);
}