
#include <stdio.h>
#include <stdlib.h>

#define width 80;
#define heigh 21;
#define end_score 21;

void ball_move();  // 1 - down_left, 2 - left, 3 - up_left, 4 - up_right, 5 -
                   // right, 6 - down_right
void ball_change_dir();
void rocket_move();
int score();
void restart();

struct ball {
    int x;
    int y;
    int dir;
} ball;

struct rocket {
    int left_y;
    int left_x;
    int right_y;
    int right_x;

} rocket;

int main() {
    int flag;  //флаг, который передается в функцию Андрея для контроля счета

    //тут должны быть функии отрисовки поля

    rocket_move();
    ball_move();
    ball_change_dir();
    flag = score();
    if (getchar == 'r') {
        restart();
    }
}

//функия описывает движение шарика в зависимости от направления
void ball_move() {
    switch (ball.dir) {
        case 4:
            ball.x++;
            ball.y--;
            break;
        case 3:
            ball.x--;
            ball.y--;
            break;
        case 6:
            ball.x++;
            ball.y++;
            break;
        case 1:
            ball.x--;
            ball.y++;
    }
}
/*функция для смены направления движения шарика при столкновении со стеной или ракеткой,
при движении влево или вправо при столкновении выбирается рандомное направление, чтобы
шарик не летал просто по прямой
 */
void ball_change_dir() {
    if ((ball.x == rocket.left_x) && ((ball.y <= rocket.left_y) && (ball.y >= rocket.left_y - 3))) {
        switch (ball.dir) {
            case 1:
                ball.dir = 6;
                break;
            case 2:
                ball.dir = rand() % 3 + 4;
                break;
            case 3:
                ball.dir = 4;
                break;
        }
    }
    if ((ball.x == rocket.left_x) && ((ball.y <= rocket.left_y) && (ball.y >= rocket.left_y - 3))) {
        switch (ball.dir) {
            case 6:
                ball.dir = 1;
                break;
            case 4:
                ball.dir = rand() % 3;
                break;
            case 5:
                ball.dir = 4;
                break;
        }
    }
    if (ball.y == 0 || ball.y == 80) {
        switch (ball.dir) {
            case 1:
                ball.dir = 3;
                break;
            case 3:
                ball.dir = 1;
                break;
            case 4:
                ball.dir = 6;
                break;
            case 6:
                ball.dir = 4;
                break;
        }
    }
}
/*функция принимает значение, которое вводит user_1/user_2 и перемещает ракетку
  на одну единицу вверх или вниз в диапазоне {1,17}.
*/
void rocket_move() {
    int user_1;
    int user_2;
    user_1 = getchar();
    switch (user_1) {
        case 'a':
            rocket.left_y++;
            break;
        case 'z':
            rocket.left_y--;
            break;
    }
    user_2 = getchar();
    switch (user_2) {
        case 'k':
            rocket.right_y++;
            break;
        case 'm':
            rocket.right_y--;
            break;
    }
}

int score() {
    if (ball.x > rocket.left_x) {
        ball.x = 39;
        ball.y = 10;
        ball.dir = 2;
        return 0;
    }
    if (ball.x == 21) {
        ball.x = 39;
        ball.y = 10;
        ball.dir = 5;
        return 1;
    }
    return 2;
}

void restart() { /*нужно обнулить счет и очистить поле*/ }
