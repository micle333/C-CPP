#include <math.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

void key_stroke_proccesing(char const *player, char const *player2, int *right_rocket, int *left_rocket);
void reaction_ball_on_higt_or_ground(int const *ball_y, int *vek);
void reaction_ball_with_rocket(int const *ball_x, int const *ball_y, int const *left_rocket, int *vek);
void reaction_ball_with_rocketright(int const *ball_x, int const *ball_y, int const *right_rocket, int *vek);
void count_of_winner(int *ball_x, int *ball_y, int *left_score, int *right_score, int *vek);
void check_ball(int *vec, int *ball_x, int *ball_y);
void marker(int const *left_score, int const *right_score, int const *ball_x, int const *ball_y,
            int const *left_rocket, int const *right_rocket);

int main() {
    int ball_x = 40;
    int ball_y = 12;

    int left_score = 0;
    int right_score = 0;

    int left_rocket = 12;
    int right_rocket = 12;
    int winner_score = 21;
    int vek = 3;
    char player;
    char player2;


    initscr();			/* Start curses mode 		  */
    keypad(stdscr, 1); //разрешили возить стрелки
    noecho();           // не показывает введеные числа
    curs_set(0);
    nodelay(stdscr, 1);
    
    
    do 
    {   
        player = getch();     
        player2 = getch();         //player2 = getch();
        if (player == 'q' || player == 'Q' || player2 == 'q' || player2 == 'Q') {
            return 0;
        }
        //векторная логика для шарика
        check_ball(&vek, &ball_x, &ball_y);
        key_stroke_proccesing(&player, &player2, &right_rocket, &left_rocket);
        reaction_ball_on_higt_or_ground(&ball_y, &vek);
        reaction_ball_with_rocket(&ball_x, &ball_y, &left_rocket, &vek);
        reaction_ball_with_rocketright(&ball_x, &ball_y, &right_rocket, &vek);
        count_of_winner(&ball_x, &ball_y, &left_score, &right_score, &vek);
        marker(&left_score, &right_score, &ball_x, &ball_y, &left_rocket, &right_rocket);
        usleep(100000);
        refresh();
        
        //endwin();	

    } while ((left_score < winner_score) && (right_score < winner_score)); //27 - escape button
    
    left_score == winner_score
        ? printf("%s%d", "The Winner of game: Left Player. Final score: ", winner_score)
        : printf("%s%d", "The Winner of game: Right Player. Final score: ", winner_score);
    return 0;
}

void marker(int const *left_score, int const *right_score, int const *ball_x, int const *ball_y,
            int const *left_rocket, int const *right_rocket) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (j == 79){
               printf("\n");
            } else {
            if (i == 2 && j == 34) {
                printf("%2d", *left_score);
                j++;
            } else if (i == 2 && j == 44) {
                printf("%2d", *right_score);
                j++;
            } else if ((j == *ball_x) && (i == *ball_y)) {
                printf("*");
            } else if ((i == 0) || (i == 24)) {
                printf("-");
            } else if (j == 40) {
                printf("|");
            } else if (((j == 10) && (i == *left_rocket)) || ((j == 10) && (i == *left_rocket - 1)) ||
                       ((j == 10) && (i == *left_rocket + 1))) {
                printf("|");
            } else if (((j == 70) && (i == *right_rocket)) || ((j == 70) && (i == *right_rocket - 1)) ||
                       ((j == 70) && (i == *right_rocket + 1))) {
                printf("|");
            } else {
                printf(" ");
            }
            }

        }
        
    }
    //printf("\n%s\n", "Pong. A/Z and K/M - to move the rackets, Q - Quit");
}

void check_ball(int *vek, int *ball_x, int *ball_y) {
    switch (*vek) {
        case 1: {
            ++*ball_x;
            --*ball_y;
            break;
        }
        case 2: {
            ++*ball_x;
            ++*ball_y;
            break;
        }
        case 3: {
            --*ball_x;
            ++*ball_y;
            break;
        }
        case 4: {
            --*ball_x;
            --*ball_y;
            break;
        }
        case 6: {
            *ball_x -= 2;
            break;
        }
        case 7: {
            *ball_x += 2;
            break;
        }
        default:
            break;
    }
}

void key_stroke_proccesing(char const *player, char const *player2, int *right_rocket, int *left_rocket) {
    //отработка нажатия клавиш
    if ((*player == 'a' || *player == 'A') && *left_rocket > 2) {
        --*left_rocket;
    } else if ((*player == 'z' || *player == 'Z') && *left_rocket < 22) {
        ++*left_rocket;
    } else if ((*player == 'k' || *player == 'K') && *right_rocket > 2) {
        --*right_rocket;
    } else if ((*player == 'm' || *player == 'M') && *right_rocket < 22) {
        ++*right_rocket;
    }
    if ((*player2 == 'a' || *player2 == 'A') && *left_rocket > 2) {
        --*left_rocket;
    } else if ((*player2 == 'z' || *player2 == 'Z') && *left_rocket < 22) {
        ++*left_rocket;
    } else if ((*player2 == 'k' || *player2 == 'K') && *right_rocket > 2) {
        --*right_rocket;
    } else if ((*player2 == 'm' || *player2 == 'M') && *right_rocket < 22) {
        ++*right_rocket;
    }
}
void reaction_ball_on_higt_or_ground(int const *ball_y, int *vek) {
    //пересечения мячика с нижнем и верхем полем
    if (((*ball_y) == 24 || (*ball_y) == 1) && *vek == 1) {
        *vek = 2;
    } else if ((*ball_y == 23 || *ball_y == 1) && *vek == 2) {
        *vek = 1;
    } else if ((*ball_y == 23 || *ball_y == 1) && *vek == 3) {
        *vek = 4;
    } else if ((*ball_y == 23 || *ball_y == 1) && *vek == 4) {
        *vek = 3;
    }
}
void reaction_ball_with_rocket(int const *ball_x, int const *ball_y, int const *left_rocket, int *vek) {
    //пересечения шарика с левой рокеткой
    if ((*ball_x == 11) && ((*left_rocket - *ball_y == 1) || (*ball_y - *left_rocket == 1))) {
        if (*vek == 3)
            *vek = 2;
        else
            *vek = 1;
    } else if ((*ball_x == 11) && ((*left_rocket - *ball_y) == 0)) {
        *vek = 7;
    }
}

void reaction_ball_with_rocketright(int const *ball_x, int const *ball_y, int const *right_rocket, int *vek) {
    //пересечения шарика с правой рокеткой
    if ((*ball_x == 69) && ((*right_rocket - *ball_y == 1) || (*ball_y - *right_rocket == 1))) {
        if (*vek == 1)
            *vek = 4;
        else
            *vek = 3;
    } else if ((*ball_x == 69) && ((*right_rocket - *ball_y) == 0)) {
        *vek = 6;
    }
}

void count_of_winner(int *ball_x, int *ball_y, int *left_score, int *right_score, int *vek) {
    // Поодсчет счета
    if ((*ball_x > 72) || (*ball_x < 8)) {
        if (*ball_x >= 71) {
            ++*left_score;
        } else if (*ball_x <= 9) {
            ++*right_score;
        }
        ++*vek;
        if (*vek >= 5) *vek = 1;
        *ball_x = 40;
        *ball_y = 12;
    }
}