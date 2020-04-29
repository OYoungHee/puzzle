#include<Bangtal.h>
#pragma comment(lib,"bangtal.lib")

SceneID scene1;
ObjectID button;
ObjectID p00, p01, p02,p03, p10,p11,p12,p13,p20, p21, p22,p23,p30,p31,p32,blank;

int boardx[4][4] =
{
 {0,150,300,450},
 {0,150,300,450},
 {0,150,300,450},
 {0,150,300,450}
};

int boardy[4][4] =
{
 {450, 450, 450,450},
 {300,300,300,300},
 {150,150,150,150},
 {0,0,0,0}
};

ObjectID board[4][4] =
{
 {p00, p01, p02,p03},
 {p10, p11,p12,p13},
 {p20,p21,p22,p23},
 {p30,p31,p32,blank}

};

ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown)
{
    ObjectID object = createObject(name, image);
    locateObject(object, scene, x, y);
    if (shown == true)
    {
        showObject(object);
    }
    return object;
}

void f(ObjectID m, ObjectID n,int x,int y)
{
    


    ObjectID temp = m;
    m = n;
    m = temp;
}


void mouseCallback(ObjectID object, int x, int y, MouseAction action)
{
    if (object == button)
        hideObject(button);


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (object == board[i][j] && object != blank)
            {
                if (board[i + 1][j] == blank)
                {
                    ObjectID temp = board[i][j];
                
                    locateObject(board[i + 1][j], scene1, boardx[i][j], boardy[i][j]);
                    locateObject(temp, scene1, boardx[i + 1][j], boardy[i + 1][j]);
                    board[i][j] = blank;
                    blank =temp;
                    

                    

                    
                }

                else if (board[i - 1][j] == blank)

                {
                    ObjectID temp = board[i][j];
                    locateObject(board[i - 1][j], scene1, boardx[i][j], boardy[i][j]);
                    locateObject(temp, scene1, boardx[i - 1][j], boardy[i - 1][j]);
                    
                    
                    board[i][j] = blank;
                    blank =temp;

                }

                else if (board[i][j + 1] == blank)
                {
                    ObjectID temp = board[i][j];
                    locateObject(board[i][j + 1], scene1, boardx[i][j], boardy[i][j]);
                    locateObject(temp, scene1, boardx[i][j + 1], boardy[i][j + 1]);
                    
                    board[i][j] = blank;
                    blank = temp;
                    

                }

                else if (board[i][j - 1] == blank)
                {
                    ObjectID temp = board[i][j];
                    locateObject(board[i][j - 1], scene1, boardx[i][j], boardy[i][j]);
                    locateObject(temp, scene1, boardx[i][j - 1], boardy[i][j - 1]);
                    
                    board[i][j] = blank;
                    blank = temp;

                }

            }

        }

    }

}


int main()
{

    setMouseCallback(mouseCallback);

    scene1 = createScene("scene1", "¹è°æ.jpg");
    board[0][0] = createObject("p00", "1.png", scene1, boardx[0][0], boardy[0][0], true);
    board[0][1] = createObject("p01", "2.png", scene1, boardx[0][1], boardy[0][1], true);
    board[0][2] = createObject("p02", "3.png", scene1, boardx[0][2], boardy[0][2], true);
    board[0][3] = createObject("p03", "4.png", scene1, boardx[0][3], boardy[0][3], true);
    board[1][0] = createObject("p10", "5.png", scene1, boardx[1][0], boardy[1][0], true);
    board[1][1] = createObject("p11", "6.png", scene1, boardx[1][1], boardy[1][1], true);
    board[1][2] = createObject("p12", "7.png", scene1, boardx[1][2], boardy[1][2], true);
    board[1][3] = createObject("p13", "8.png", scene1, boardx[1][3], boardy[1][3], true);
    board[2][0] = createObject("p20", "9.png", scene1, boardx[2][0], boardy[2][0], true);
    board[2][1] = createObject("p21", "10.png", scene1, boardx[2][1], boardy[2][1], true);
    board[2][2] = createObject("p22", "11.png", scene1, boardx[2][2], boardy[2][2], true);
    board[2][3] = createObject("p23", "12.png", scene1, boardx[2][3], boardy[2][3], true);
    board[3][0] = createObject("p30", "13.png", scene1, boardx[3][0], boardy[3][0], true);
    board[3][1] = createObject("p31", "14.png", scene1, boardx[3][1], boardy[3][1], true);
    board[3][2] = createObject("p32", "15.png", scene1, boardx[3][2], boardy[3][2], true);
    board[3][3] = createObject("blank", "16.png", scene1, boardx[3][3], boardy[3][3], false);
    button = createObject("button", "start.png", scene1, 300, 300, true);

    startGame(scene1);
}