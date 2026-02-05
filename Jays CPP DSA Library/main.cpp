#include<iostream.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<dos.h> 
void main()
{
    clrscr();
    randomize();
    cout << "\t\t\t" << "WELCOME TO THE BATTLESHIP" << "\n\n";
    cout << "Type of Ships:     AA ; BBB ; CCCC ; DDDDD ; EEEEEE" << "\n\n";
    cout << "The rules are as usual, Defeat the Opponent to Win the Game" << "\n\n";
    cout << "Press any key to start............                          ";
    getch();
reset:
    clrscr();
    int o = 2, p = 2, T = 0, m, n, i, j, x = 0, y = 0;
    char a = 'A', b, c[11][21], d[11][21];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
            d[i][j] = ' ';
    }
next:
    (m == x) ? (m = ++x) : (m = x);
    (n == y) ? (n = ++y) : (n = y);
    x += 2;
    y += 2;
start:
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 21; j++)
        {
            c[i][j] = d[i][j];
        }
    }
    for (i = 0; i < 11; i++)
        c[i][20] = '|';
    for (i = 0; i < 21; i++)
        c[10][i] = '-';
    if (p == 7)
    {
        cout << "\n\n" << "Your fleet is ready.........";
        goto exit;
    }
    if (T == 0)
    {
        for (i = 0; i < o; i++)
            c[m][n + i] = a;
    move0:
        clrscr();
        cout << "\n\n\n" << "---------------------" << endl;
        for (i = 0; i < 11; i++)
        {
            for (j = 0; j < 21; j++)
            {
                cout << c[i][j];
            }
            cout << endl;
        }
        cout << "Press 'w a s d' to move the ship" << endl;
        cout << "Press 'c' to clear fleet" << endl;
        cout << "Press 'r' to rotate the ship" << endl;
        cout << "Press 'p' to place the ship            ";
        b = getche();
        if (b == 'p')
        {
            for (i = 0; i < 11; i++)
            {
                for (j = 0; j < 21; j++)
                {
                    d[i][j] = c[i][j];
                }
            }
            cout << "\n\n" << "Ship Placed.........";
            getch();
            p++;
            (o == 6) ? (o = p) : (o++);
            if (o == 2)
                a = 'A';
            if (o == 3)
                a = 'B';
            if (o == 4)
                a = 'C';
            if (o == 5)
                a = 'D';
            if (o == 6)
                a = 'E';
            goto next;
        }
        if (b == 'r')
        {
            if (m > 10 - o)
                goto start;
            else
            {
                T++;
                goto start;
            }
        }
        if (b == 'w')
        {
            if (m == 0)
                goto start;
            for (i = 0; i < o; i++)
            {
                if (c[m - 1][n + i] != ' ')
                    goto start;
                c[m][n + i] = ' ';
                c[m - 1][n + i] = a;
            }
            m--;
            goto move0;
        }
        if (b == 's')
        {
            if (m == 9)
                goto start;
            for (i = 0; i < o; i++)
            {
                if (c[m + 1][n + i] != ' ')
                    goto start;
                c[m][n + i] = ' ';
                c[m + 1][n + i] = a;
            }
            m++;
            goto move0;
        }
        if (b == 'a')
        {
            if (n == 0)
                goto start;
            for (i = 0; i < o; i++)
            {
                if (c[m][n + i - 1] != ' ')
                    goto start;
                c[m][n + i] = ' ';
                c[m][n + i - 1] = a;
            }
            n--;
            goto move0;
        }
        if (b == 'd')
        {
            if (n == 19 - o)
                goto start;
            for (i = o - 1; i >= 0; i--)
            {
                if (c[m][n + i + 1] != ' ')
                    goto start;
                c[m][n + i] = ' ';
                c[m][n + i + 1] = a;
            }
            n++;
            goto move0;
        }
        if (b == 'c')
            goto reset;
        else
            goto start;
    }
    if (T == 1)
    {
        for (i = 0; i < o; i++)
            c[m + i][n] = a;
    move1:
        clrscr();
        cout << "\n\n\n" << "---------------------" << endl;
        for (i = 0; i < 11; i++)
        {
            for (j = 0; j < 21; j++)
            {
                cout << c[i][j];
            }
            cout << endl;
        }
        cout << "Press 'w a s d' to move the ship" << endl;
        cout << "Press 'c' to clear fleet" << endl;
        cout << "Press 'r' to rotate the ship" << endl;
        cout << "Press 'p' to place the ship            ";
        b = getche();
        if (b == 'p')
        {
            for (i = 0; i < 11; i++)
            {
                for (j = 0; j < 21; j++)
                {
                    d[i][j] = c[i][j];
                }
            }
            cout << "\n\n" << "Ship Placed.........";
            getch();
            p++;
            (o == 6) ? (o = p) : (o++);
            if (o == 2)
                a = 'A';
            if (o == 3)
                a = 'B';
            if (o == 4)
                a = 'C';
            if (o == 5)
                a = 'D';
            if (o == 6)
                a = 'E';
            goto next;
        }
        if (b == 'r')
        {
            if (n > 19 - o)
                goto start;
            else
            {
                T--;
                goto start;
            }
        }
        if (b == 'w')
        {
            if (m == 0)
                goto start;
            for (i = 0; i < o; i++)
            {
                if (c[m + i - 1][n] != ' ')
                    goto start;
                c[m + i][n] = ' ';
                c[m + i - 1][n] = a;
            }
            m--;
            goto move1;
        }
        if (b == 's')
        {
            if (m == 10 - o)
                goto start;
            for (i = o - 1; i >= 0; i--)
            {
                if (c[m + i + 1][n] != ' ')
                    goto start;
                c[m + i][n] = ' ';
                c[m + i + 1][n] = a;
            }
            m++;
            goto move1;
        }
        if (b == 'a')
        {
            if (n == 0)
                goto start;
            for (i = 0; i < o; i++)
            {
                if (c[m + i][n - 1] != ' ')
                    goto start;
                c[m + i][n] = ' ';
                c[m + i][n - 1] = a;
            }
            n--;
            goto move1;
        }
        if (b == 'd')
        {
            if (n == 19)
                goto start;
            for (i = 0; i < o; i++)
            {
                if (c[m + i][n + 1] != ' ')
                    goto start;
                c[m + i][n] = ' ';
                c[m + i][n + 1] = a;
            }
            n++;
            goto move1;
        }
        if (b == 'c')
            goto reset;
    }
    else
        goto start;
exit:
    getch();
    /*                                    */
    int q, r, l, s;
    char e[11][21], f;
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 21; j++)
        {
            e[i][j] = ' ';
        }
    }
    for (i = 0; i < 11; i++)
        e[i][0] = '|';
    for (i = 0; i < 21; i++)
        e[10][i] = '-';
    f = 'A';
    l = 1;
Start:
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 21; j++)
        {
            c[i][j] = ' ';
        }
    }
    for (i = 0; i < 11; i++)
        c[i][0] = '|';
    for (i = 0; i < 21; i++)
        c[10][i] = '-';
position:
    l++;
    if (l == 2)
        f = 'A';
    if (l == 3)
        f = 'B';
    if (l == 4)
        f = 'C';
    if (l == 5)
        f = 'D';
    if (l == 6)
        f = 'E';
    s = random(2);
    q = random(10);
    r = random(20) + 1;
    if (s == 0)
    {
        for (i = 0; i < l; i++)
        {
            if (c[q][r + i] != ' ')
            {
                l = 1; goto Start;
            }
            c[q][r + i] = f;
        }
    }
    if (s == 1)
    {
        for (i = 0; i < l; i++)
        {
            if (c[q + i][r] != ' ')
            {
                l = 1; goto Start;
            }
            c[q + i][r] = f;
        }
    }
    if (l == 6)
        goto done;
    else
        goto position;
done:
    clrscr();
    char g, * quote[5] = { "LET","THE","BATTLE","BEGINS","  " };
    int C, D, A = 0, B = 1;
    int sum1, sum2, S1[5], S2[5];
    for (i = 0; i < 5; i++)
    {
        S1[i] = 0;
        S2[i] = 0;
    }
    e[0][1] = '@';
    for (i = 0; i < 5; i++)
    {
        cout << "\n\n\n" << "\t\t\t" << quote[i];
        delay(500);
    }
    delay(1000);
    /*                                  */
Game:
    clrscr();
    cout << "\n\n\n\n\n" << "---------------------				           ---------------------";
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 21; j++)
        {
            cout << d[i][j];
        }
        cout << "                                      ";
        for (j = 0; j < 21; j++)
        {
            cout << e[i][j];
        }
    }
    cout << endl;
    cout << "Press 'w a s d' to Move the Aim" << endl;
    cout << "Press 'g' to Adjust the Aim" << endl;
    cout << "Press 'f' to Fire on the Target" << endl;
    cout << "Press 'z' to Exit the Game      ";
    g = getche();
    if (g == 'w')
    {
        if (A == 0 || e[A - 1][B] != ' ')
            goto Game;
        else
        {
            e[A][B] = ' ';
            e[--A][B] = '@';
            goto Game;
        }
    }
    if (g == 's')
    {
        if (A == 9 || e[A + 1][B] != ' ')
            goto Game;
        else
        {
            e[A][B] = ' ';
            e[++A][B] = '@';
            goto Game;
        }
    }
    if (g == 'a')
    {
        if (B == 1 || e[A][B - 1] != ' ')
            goto Game;
        else
        {
            e[A][B] = ' ';
            e[A][--B] = '@';
            goto Game;
        }
    }
    if (g == 'd')
    {
        if (B == 19 || e[A][B + 1] != ' ')
            goto Game;
        else
        {
            e[A][B] = ' ';
            e[A][++B] = '@';
            goto Game;
        }
    }
    if (g == 'g')
    {
        e[A][B] = ' ';
    Adjust:
        A = random(10);
        B = random(19) + 1;
        if (e[A][B] != ' ')
            goto Adjust;
        else
            e[A][B] = '@';
        goto Game;
    }
    if (g == 'f')
    {
        if (c[A][B] == ' ')
            e[A][B] = '+';
        if (c[A][B] == 'A')
        {
            e[A][B] = 'x';
            S2[0]++;
        }
        if (c[A][B] == 'B')
        {
            e[A][B] = 'x';
            S2[1]++;
        }
        if (c[A][B] == 'C')
        {
            e[A][B] = 'x';
            S2[2]++;
        }
        if (c[A][B] == 'D')
        {
            e[A][B] = 'x';
            S2[3]++;
        }
        if (c[A][B] == 'E')
        {
            e[A][B] = 'x';
            S2[4]++;
        }
        cout << endl;
        if (S2[0] == 2)
        {
            S2[0] = 10;
            cout << endl << "A Type Ship drowned..........";
            delay(1000);
        }
        if (S2[1] == 3)
        {
            S2[1] = 10;
            cout << endl << "B Type Ship drowned..........";
            delay(1000);
        }
        if (S2[2] == 4)
        {
            S2[2] = 10;
            cout << endl << "C Type Ship drowned..........";
            delay(1000);
        }
        if (S2[3] == 5)
        {
            S2[3] = 10;
            cout << endl << "D Type Ship drowned..........";
            delay(1000);
        }
        if (S2[4] == 6)
        {
            S2[4] = 10;
            cout << endl << "E Type Ship drowned..........";
            delay(1000);
        }
        sum2 = 0;
        for (i = 0; i < 5; i++)
        {
            sum2 += S2[i];
        }
        if (sum2 == 50)
        {
            cout << "\n\n" << "!  @  #  $  %  ^  &  *  (  )";
            delay(2000);
            clrscr();
            gotoxy(30, 10);
            cout << "YOU WON THIS GAME !!!!!!!!!!!";
            goto Beach;
        }
        for (i = 0; i < 11; i++)
        {
            for (j = 0; j < 21; j++)
            {
                if (e[i][j] == ' ')
                {
                    A = i;
                    B = j;
                    goto JKL;
                }
            }
        }
    JKL:
        e[A][B] = '@';
        goto Opponent;
    }
    if (g == 'z')
        goto Beach;
    else
        goto Game;
    /*                           */
Opponent:
    clrscr();
    cout << "\n\n\n\n\n" << "---------------------				           ---------------------";
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 21; j++)
        {
            cout << d[i][j];
        }
        cout << "                                      ";
        for (j = 0; j < 21; j++)
        {
            cout << e[i][j];
        }
    }
    cout << endl;
    cout << "Opponent's Turn................";
    delay(1000);
again:
    C = random(10);
    D = random(19) + 1;
    if (d[C][D] == ' ')
    {
        d[C][D] = '+';
        goto Game;
    }
    if (d[C][D] == '+' || d[C][D] == 'x')
        goto again;
    if (d[C][D] == 'A')
    {
        d[C][D] = 'x';
        S1[0]++;
    }
    if (d[C][D] == 'B')
    {
        d[C][D] = 'x';
        S1[1]++;
    }
    if (d[C][D] == 'C')
    {
        d[C][D] = 'x';
        S1[2]++;
    }
    if (d[C][D] == 'D')
    {
        d[C][D] = 'x';
        S1[3]++;
    }
    if (d[C][D] == 'E')
    {
        d[C][D] = 'x';
        S1[4]++;
    }
    cout << endl;
    if (S1[0] == 2)
    {
        S1[0] = 10;
        cout << endl << "A Type Ship drowned..........";
        delay(1000);
    }
    if (S1[1] == 3)
    {
        S1[1] = 10;
        cout << endl << "B Type Ship drowned..........";
        delay(1000);
    }
    if (S1[2] == 4)
    {
        S1[2] = 10;
        cout << endl << "C Type Ship drowned..........";
        delay(1000);
    }
    if (S1[3] == 5)
    {
        S1[3] = 10;
        cout << endl << "D Type Ship drowned..........";
        delay(1000);
    }
    if (S1[4] == 6)
    {
        S1[4] = 10;
        cout << endl << "E Type Ship drowned..........";
        delay(1000);
    }
    sum1 = 0;
    for (i = 0; i < 5; i++)
    {
        sum1 += S1[i];
    }
    if (sum1 == 50)
    {
        cout << "\n\n" << "!  @  #  $  %  ^  &  *  (  )";
        delay(2000);
        clrscr();
        gotoxy(30, 10);
        cout << "COMPUTER WON THIS GAME !!!!!!!!!!!";
        goto Beach;
    }
    else
        goto Game;
    /*                   */
Beach:
    getch();
}