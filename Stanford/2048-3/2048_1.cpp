#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <conio.h>
#include "curses.h"
using namespace std;
#define N 4
// 格数
#define WIDTH 6
// 每格的长度
#define TARGET 16384
// 胜利条件
#define S_FAIL 0
#define S_WIN 1
#define S_NORMAL 2
#define S_QUIT 3
#define S_WAIT 5
#define S_SAVE 6
#define S_LOAD 7
// 游戏状态
#define DELAYSIZE 200
// 延迟时间单位ms
bool best_flag = false;

void initialize()
{
    initscr();
    // 初始化ncurses
    cbreak();
    // 按键不需要输入回车
    noecho();
    // 不显示按键
    curs_set(0);
    // 隐藏光标
    if (has_colors() == FALSE)
    {
        endwin();
        printf("You terminal does not support color\n");
        exit(1);
    }
    start_color(); //启动color机制
    {
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
        init_pair(7, COLOR_RED, COLOR_BLACK);
        init_pair(8, COLOR_WHITE, COLOR_BLACK);
        init_pair(9, COLOR_YELLOW, COLOR_WHITE);
        init_pair(10, COLOR_BLUE, COLOR_WHITE);
        init_pair(11, COLOR_MAGENTA, COLOR_WHITE);
        init_pair(12, COLOR_CYAN, COLOR_WHITE);
        init_pair(13, COLOR_RED, COLOR_WHITE);
        init_pair(14, COLOR_WHITE, COLOR_BLUE);
        init_pair(15, COLOR_GREEN, COLOR_BLUE);
        init_pair(16, COLOR_YELLOW, COLOR_BLUE);
        init_pair(17, COLOR_MAGENTA, COLOR_BLUE);
        init_pair(18, COLOR_CYAN, COLOR_BLUE);
        init_pair(19, COLOR_RED, COLOR_BLUE);
    }
    srand(time(NULL));
    // 随机数
}

void shutdown()
{
    // 清理ncurses
    endwin();
}

class firework
{
public:
    short color_table[8] =
        {
            COLOR_RED, COLOR_BLUE, COLOR_GREEN, COLOR_CYAN,
            COLOR_RED, COLOR_MAGENTA, COLOR_YELLOW, COLOR_WHITE};
    // 颜色表

    int boost()
    {
        time_t seed;
        int start, end, row, diff, flag, direction;
        short i;

        // #ifdef XCURSES
        //         Xinitscr(argc, argv);
        // #else

        // #endif
        initscr();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        noecho();
        //初始化
        if (has_colors())
            start_color();
        //启动color机制
        for (i = 0; i < 8; i++)
            init_pair(i, color_table[i], COLOR_BLACK);
        //初始化颜色表
        seed = time((time_t *)0);
        srand(seed);
        flag = 0;
        //初始化随机数
        clear();
        while (getch() == ERR) /* loop until a key is hit */
        {
            do
            {
                start = rand() % (COLS - 3);
                end = rand() % (COLS - 3);
                start = (start < 4) ? 4 : start;
                end = (end < 4) ? 4 : end;
                direction = (start > end) ? -1 : 1;
                diff = abs(start - end);

            } while (diff < 4 || diff >= LINES - 4);
            //随机起点和终点
            attrset(A_NORMAL);
            //恢复默认属性
            for (row = 0; row < diff; row++)
            {
                mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
                mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
                mvaddstr(LINES - row, row * direction + start,
                         (direction < 0) ? "\\" : "/");
                if (flag++)
                {
                    myrefresh();
                    erase();
                    flag = 0;
                }
            }
            if (flag++)
            {
                myrefresh();
                flag = 0;
            }
            mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
            mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
            explode(LINES - row, diff * direction + start);
            erase();
            mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
            mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
            myrefresh();
            // 绘制火花
        }

        endwin();
        //关闭ncurses
        return 0;
    }

    void explode(int row, int col)
    {
        erase();
        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
        mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
        mvaddstr(row, col, "-");
        myrefresh();

        --col;

        get_color();

        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
        mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
        mvaddstr(row - 1, col, "  -  ");
        mvaddstr(row - 0, col, " -+- ");
        mvaddstr(row + 1, col, "  -  ");
        myrefresh();

        --col;

        get_color();
        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
        mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
        mvaddstr(row - 2, col, "  ---  ");
        mvaddstr(row - 1, col, " -+++- ");
        mvaddstr(row - 0, col, " -+#+- ");
        mvaddstr(row + 1, col, " -+++- ");
        mvaddstr(row + 2, col, "  ---  ");
        myrefresh();

        get_color();
        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
        mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
        mvaddstr(row - 3, col, "  +  ");
        mvaddstr(row - 2, col, " +++ ");
        mvaddstr(row - 1, col, "++#++");
        mvaddstr(row - 0, col, "+# #+");
        mvaddstr(row + 1, col, "++#++");
        mvaddstr(row + 2, col, " +++ ");
        mvaddstr(row + 3, col, "  +  ");
        myrefresh();

        get_color();
        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
        mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
        mvaddstr(row - 3, col, "  +++  ");
        mvaddstr(row - 2, col, " +++++ ");
        mvaddstr(row - 1, col, "+++#+++");
        mvaddstr(row - 0, col, "++# #++");
        mvaddstr(row + 1, col, "+++#+++");
        mvaddstr(row + 2, col, " +++++ ");
        mvaddstr(row + 3, col, "  +++  ");
        myrefresh();

        get_color();
        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
        mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
        mvaddstr(row - 3, col, "   #   ");
        mvaddstr(row - 2, col, "  ###  ");
        mvaddstr(row - 1, col, " ## ## ");
        mvaddstr(row - 0, col, "##   ##");
        mvaddstr(row + 1, col, " ## ## ");
        mvaddstr(row + 2, col, "  ###  ");
        mvaddstr(row + 3, col, "   #   ");
        myrefresh();

        get_color();
        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
        mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");

        mvaddstr(row - 3, col, "       ");
        mvaddstr(row - 2, col, "   #   ");
        mvaddstr(row - 1, col, " ## ## ");
        mvaddstr(row - 0, col, " #   # ");
        mvaddstr(row + 1, col, " ## ## ");
        mvaddstr(row + 2, col, "   #   ");
        mvaddstr(row + 3, col, "       ");
        myrefresh();

        get_color();
        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "PRESS ANY KEY TO EXIT");
        mvprintw(3 * N + 8, (5 * (N)-1) / 2, " NEW BEST SCORE!!!");
        mvaddstr(row - 3, col, "   #   ");
        mvaddstr(row - 2, col, "  # #  ");
        mvaddstr(row - 1, col, " #   # ");
        mvaddstr(row + 0, col, "#     #");
        mvaddstr(row + 1, col, " #   # ");
        mvaddstr(row + 2, col, "  # #  ");
        mvaddstr(row + 3, col, "   #   ");
        myrefresh();
    }

    void myrefresh(void)
    {
        napms(DELAYSIZE);
        move(LINES - 1, COLS - 1);
        refresh();
        //刷新屏幕
    }

    void get_color(void)
    {
        chtype bold = (rand() % 2) ? A_BOLD : A_NORMAL;
        attrset(COLOR_PAIR(rand() % 8) | bold);
        //设置颜色
    }
};

class Game2048
{
public:
    Game2048() : status(S_WAIT)
    {
        setTestData();
        //设置随机数据
    }

    int getStatus() { return status; }

    void saveScore()
    //最高分机制
    {
        int bestscore;
        ifstream fin("scoreFile.dat");
        if (!fin.is_open())
        // 文件不存在
        {
            ofstream fout("scoreFile.dat");
            mvprintw(3 * N, 5 * N / 2 + 5, " NEW BEST SCORE: %d", score);
            mvprintw(2 * N + 6, (5 * (N)-1) / 2, " CONGRATULATIONS! PRESS R TO CONTINUE ");
            fout << score;
            fout.close();
            best_flag = true;
            return;
        }
        else
        // 文件存在
        {
            fin >> bestscore;
            fin.close();
            if (score >= bestscore)
            // 新的最高分
            {
                ofstream fout("scoreFile.dat");
                fout << score;
                mvprintw(3 * N, 5 * N / 2 + 5, " NEW BEST SCORE: %d", score);
                mvprintw(2 * N + 6, (5 * (N)-1) / 2, " CONGRATULATIONS! PRESS R TO CONTINUE ");
                fout.close();
                best_flag = true;
            }
            else
            {
                mvprintw(3 * N, 5 * N / 2 + 5, " BEST SCORE: %d", bestscore);
                mvprintw(2 * N + 6, (5 * (N)-1) / 2, "                  PRESS R TO CONTINUE ");
                best_flag = false;
            }
        }
        return;
    }

    void processInput()
    // 处理按键
    {
        char ch = getch();

        // 转化成大写
        if (ch >= 'a' && ch <= 'z')
        {
            ch -= 32;

            if (status == S_WAIT)
            {
                status = S_NORMAL;
            }
        }
        if (status == S_NORMAL)
        {
            bool updated = false;
            switch (ch)
            {
            case 'A':
                savedata();
                updated = moveLeft();
                break;
            case 'D':
                savedata();
                rotate();
                rotate();
                updated = moveLeft();
                rotate();
                rotate();
                break;
            case 'W':
                savedata();
                rotate();
                updated = moveLeft();
                rotate();
                rotate();
                rotate();
                break;
            case 'S':
                savedata();
                rotate();
                rotate();
                rotate();
                updated = moveLeft();
                rotate();
                break;
            case 'Z':
                readdata();
                //读取上一次数据
                break;
            default:
                break;
            }
            if (updated)
            {
                randNew();
                if (isOver())
                //游戏结束
                {
                    status = S_FAIL;
                }
            }
        }
        if (ch == 'Q')
        //退出游戏
        {
            status = S_QUIT;
        }
        else if (ch == 'R')
        //重新开始
        {
            restart();
        }
        else if (ch == 'M')
        {
            status = S_SAVE;
        }
        else if (ch == 'N')
        {
            status = S_LOAD;
        }
    }

    void savedata()
    //保存数据
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                lastboard[i][j] = data[i][j];
            }
        }
    }

    void readdata()
    //读取数据
    {
        score = lastscore;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                data[i][j] = lastboard[i][j];
            }
        }
    }

    void draw()
    // 绘制游戏界面
    {

        // 清理屏幕
        clear();
        if (status == S_SAVE)
        {
            saveplate();
            mvprintw(2 * N + 6, (5 * (N)-1) / 2, "SAVE SUCCESSFULLY");
            napms(DELAYSIZE);
            status = S_NORMAL;
        }
        else if (status == S_LOAD)
        {
            loadplate();
            mvprintw(2 * N + 6, (5 * (N)-1) / 2, "LOAD SUCCESSFULLY");
            napms(DELAYSIZE);
            status = S_NORMAL;
        }
        // 居中偏移
        const int offset = 20;
        for (int i = 0; i <= N; ++i)
        {
            for (int j = 0; j <= N; ++j)
            {
                // 相交点
                drawItem(i * 2, 1 + j * WIDTH + offset, '+');
                // 竖线
                if (i != N)
                {
                    drawItem(i * 2 + 1, 1 + j * WIDTH + offset, '|');
                }
                // 横线
                for (int k = 1; j != N && k < WIDTH; ++k)
                {
                    drawItem(i * 2, 1 + j * WIDTH + k + offset, '-');
                }
                // 每个格子里的数
                if (i != N && j != N)
                {
                    drawNum(i * 2 + 1, (j + 1) * WIDTH + offset, data[i][j]);
                }
            }
        }

        // 提示文字
        mvprintw(4 * N + 6, (5 * (N)-1) / 2, "W(UP),S(DOWN),A(LEFT),D(RIGHT)");
        mvprintw(4 * N + 8, (5 * (N)-1) / 2, "Z(REDO_ONCE),R(RESTART),Q(QUIT)");
        mvprintw(4 * N + 10, (5 * (N)-1) / 2, "M(LOAD),N(SAVE)");
        if (score)
        // 如果有分数
        {
            mvprintw(3 * N + 6, (5 * (N)-1) / 2, " SCORE: %d", score);
        }

        if (status == S_WIN)
        // 游戏胜利
        {
            mvprintw(2 * N + 6, (5 * (N)-1) / 2, "                  PRESS R TO CONTINUE ");
        }
        else if (status == S_FAIL)
        // 游戏失败
        {

            saveScore();

            mvprintw(2 * N + 6, (5 * (N)-1) / 2, "                  PRESS R TO CONTINUE ");
        }
    }

    void saveplate()
    {
        ofstream fout("Plate.dat");
        if (!fout.is_open())
        {
            loadplate();
            return;
        }
        fout << score << "\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                fout << data[i][j] << " ";
            }
        }
        mvprintw(2 * N + 6, (5 * (N)-1) / 2 - 10, "SAVE SUCCESSFULLY");
        fout.close();
    }

    void loadplate()
    {
        ifstream fin("Plate.dat");
        if (!fin.is_open())
        {
            mvprintw(2 * N + 6, (5 * (N)-1) / 2 - 10, "FAILED TO SAVE");
            return;
        }
        fin >> score;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                fin >> data[i][j];
            }
        }
        mvprintw(2 * N + 6, (5 * (N)-1) / 2 - 10, "LOAD SUCCESSFULLY");
        fin.close();
    }

    void setTestData()
    // 便于调试, 随时设置数据
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                data[i][j] = 2 << (rand() % 7);
                //给定随机数据
            }
        }
    }

    void setTestData_1()
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                data[i][j] = 2 << (i + j);
                //游戏开始，给定初始数据
            }
        }
    }

private:
    bool isOver()
    {

        for (int i = 0; i < N; i++) //横向检查
        {
            for (int j = 0; j < N - 1; j++)
            {
                if (data[i][j] == 0 || data[i][j] == data[i][j + 1]) //横向相邻项相等或某一项为空，游戏继续
                    return false;
            }
        }

        for (int j = 0; j < N; j++) //纵向检查
        {
            for (int i = 0; i < N - 1; i++)
            {
                if (data[i][j] == 0 || data[i][j] == data[i + 1][j]) //纵向相邻项相等或某一项为空，游戏继续
                    return false;
            }
        }

        return true; //其它情况游戏结束
    }

    bool moveLeft(bool redo = 0)
    // 向左边移动, 返回值表示盘面是否有发生变化
    {
        int tmp[N][N];
        for (int i = 0; i < N; ++i)
        {
            // 逐行处理
            // 如果两个数字一样，当前可写入的位置
            int currentWritePos = 0;
            int lastValue = 0;
            for (int j = 0; j < N; ++j)
            {
                tmp[i][j] = data[i][j];
                if (data[i][j] == 0)
                {
                    continue;
                }
                if (lastValue == 0)
                {
                    lastValue = data[i][j];
                }
                else
                {
                    if (lastValue == data[i][j])
                    {
                        data[i][currentWritePos] = lastValue * 2;
                        lastscore = score;
                        score += lastValue * 2;
                        lastValue = 0;
                        if (data[i][currentWritePos] == TARGET)
                        {
                            status = S_WIN;
                        }
                    }
                    else
                    {
                        data[i][currentWritePos] = lastValue;
                        lastValue = data[i][j];
                    }
                    ++currentWritePos;
                }
                data[i][j] = 0;
            }
            if (lastValue != 0)
            {
                data[i][currentWritePos] = lastValue;
            }
        }
        // 看是否发生了变化
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (data[i][j] != tmp[i][j])
                    return true;
            }
        }
        return false;
    }

    void rotate()
    // 矩阵逆时针旋转90度
    {
        int tmp[N][N] = {0};
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                tmp[i][j] = data[j][N - 1 - i];
            }
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                data[i][j] = tmp[i][j];
            }
        }
    }

    void restart()
    // 重新开始
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                data[i][j] = 0;
            }
        }
        randNew();
        randNew();
        status = S_NORMAL;
    }

    bool randNew()
    // 随机产生一个新的数字
    {
        vector<int> emptyPos;
        // 把空位置先存起来
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (data[i][j] == 0)
                {
                    emptyPos.push_back(i * N + j);
                }
            }
        }
        if (emptyPos.size() == 0)
        {
            return false;
        }
        // 随机找个空位置
        int value = emptyPos[rand() % emptyPos.size()];
        //伪随机百分之十的概率产生4
        int random = (rand() % (101));
        hit_flag = random >= possibility;
        if (hit_flag)
        {
            possibility = 90;
            data[value / N][value % N] = 4;
        }
        else
        {
            possibility -= 5;
            data[value / N][value % N] = 2;
        }
        return true;
    }

    void drawItem(int row, int col, char c, int type = 0)
    // 左上角为（0，0），在指定的位置画一个字符
    {
        move(row, col);
        attron(COLOR_PAIR(type + 1));
        addch(c);
        attroff(COLOR_PAIR(type + 1));
    }

    void drawNum(int row, int col, int num)
    // 游戏里的数字是右对齐，row, col是数字最后一位所在的位置
    {
        int type = 0;
        if (num == 2)
        {
            type = 1;
        }
        else if (num == 4)
        {
            type = 2;
        }
        else if (num == 8)
        {
            type = 3;
        }
        else if (num == 16)
        {
            type = 4;
        }
        else if (num == 32)
        {
            type = 5;
        }
        else if (num == 64)
        {
            type = 6;
        }
        else if (num == 128)
        {
            type = 7;
        }
        else if (num == 256)
        {
            type = 8;
        }
        else if (num == 512)
        {
            type = 9;
        }
        else if (num == 1024)
        {
            type = 10;
        }
        else if (num == 2048)
        {
            type = 11;
        }
        else if (num == 4096)
        {
            type = 12;
        }
        else if (num == 8192)
        {
            type = 13;
        }
        else if (num == 16384)
        {
            type = 14;
        }
        while (num > 0)
        {
            drawItem(row, col, num % 10 + '0', type);
            num /= 10;
            --col;
        }
    }

private:
    int data[N][N];
    int status;

    //计分功能
    int score = 0;
    int lastscore = 0;

    //伪随机功能
    int possibility = 90;
    bool hit_flag = 0;

    //撤回功能
    int lastboard[N][N];
};
int main()
{
    initialize();
    Game2048 game;
    game.draw();
    while (true)
    {
        if (!_kbhit())
        //非阻塞性等待按键
        {
            //无操作时自动刷新
            napms(DELAYSIZE);
            refresh();
            //很关键的refresh
            game.setTestData();
            game.draw();
            mvprintw(2 * N + 4, (5 * (N)-1) / 2, "PRESS R TO START");
        }
        else
        {
            game.setTestData_1();
            //按键事件
            break;
        }
    }
    do
    {
        game.draw();
        game.processInput();
        //游戏进行
    } while (S_QUIT != game.getStatus());
    if (best_flag)
    {
        firework fw;
        fw.boost();
        //达到最高分，放烟花庆祝
    }
    shutdown();
    return 0;
}

// g++ 2048_1.cpp pdcurses.a -I E:\cpp_project\Stanford\2048-3 -o 2048_1
// 用上面这个编译，然后出去运行exe
