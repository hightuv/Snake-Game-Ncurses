# ncurses를 이용한 snake game

c++, ncurses, ncursesw를 이용한 snakegame.

**실행방법**

src 폴더에서 다음을 수행한다.

    make
    ./snake

----------------

## 개요

1. 총 4개의 맵이 존재한다.
2. snake의 조작은 방향키를 이용한다.
3. growth item 을 먹으면 snake body의 길이가 1 증가한다.
4. poison item 을 먹으면 snake body의 길이가 1 감소한다.
5. wall 에는 랜덤으로 gate 가 생성된다. 반드시 두개의 gate 만 존재한다.
6. scoreboard 의 승리조건을 만족하면 다음 stage 로 이동한다. stage4 를 클리어 하면 stage1 로 이동한다.


-------------------

## 전체 구조

* map
    - map1.txt
    - map2.txt
    - map3.txt
    - map4.txt

* src
    - Makefile
    - main.cpp
    - render.cpp
    - render.h
    - snake.cpp
    - snake.h
    - snakeMove.h

------------------------

## 구현 내용

map directory -  맵 정보 txt file.

src directory - snake 구현 소스코드

Makefile - make

main.cpp - snake 객체를 생성한다.

snake.cpp - 맨 처음 시작메뉴를 구성한다. 스테이지 선택후 render 객체를 생성해 입력받은 스테이지를 인자로 전달한다.

render.cpp - snake game 구현의 핵심 요소들이 존재한다. snakeWindow, scoreWindow 를 rendering 한다.

snakeMove.h - snake의 head와 body 위치정보를 갖고있다. body의 개수정보를 갖고있다. head와 body의 위치를 조작한다.

-----------------------

## 실행화면

![스크린샷, 2021-05-31 00-10-33](https://user-images.githubusercontent.com/39542757/120109515-b6c39380-c1a4-11eb-8e47-dacd69713b33.png)

![스크린샷, 2021-05-31 00-13-47](https://user-images.githubusercontent.com/39542757/120109613-19b52a80-c1a5-11eb-9e52-dc87a7ad7cc9.png)

![스크린샷, 2021-05-31 00-14-29](https://user-images.githubusercontent.com/39542757/120109625-2fc2eb00-c1a5-11eb-9702-490751efb6ff.png)

----------------------

## 기여자

- 김용후
- 박민서

