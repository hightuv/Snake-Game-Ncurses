# ncurses를 이용한 snake game

c++, ncurses, ncursesw를 이용한 snakegame.

**실행방법**

src 폴더에서 다음을 수행한다.

    make
    ./snake

----------------

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


