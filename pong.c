
#include <stdio.h>

#define width 80;
#define heigh 21;
#define end_score 21;

void ball_move();// 1 - down_left, 2 - left, 3 - up_left, 4 - up_right, 5 - right, 6 - down_right 
void ball_change_dir();
void rocket_right(int);
void rocket_left(int);
int score(int);

struct ball
{
    int x;
    int y;
    int dir;
}ball;

struct rocket
{
    int left_y;
    int right_y;

}rocket;


int main() {



}

void ball_move() {
    switch(ball.dir) {	
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

void ball_change_dir(){


}


void rocket_left(int a) {

    switch (a) {
    case 'a':
        rocket.left_y ++;
        break;
    case 'z':
        rocket.left_y --;
        break;

    case 'k' :
        rocket.right_y ++;
        break;
    case 'm' :
        rocket.right_y --;
        break;
    }

}



