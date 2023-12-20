#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define ROAD 0
#define WALL 1
#define START 2
#define GOAL 3

#define DOWN 0
#define RIGHT 1
#define LEFT 2
#define UP 3

struct Index
{
    int x,y;
};
vector<Index> route;
vector<Index> pass;
stack<Index> branch;

bool isFinished = false;


bool Direction(Index index)
{
    int data[8][8] = {
                    {0,0,1,0,0,0,0,0},
                    {0,1,1,0,1,0,1,0},
                    {0,1,1,0,1,0,1,0},
                    {0,0,2,0,1,0,1,0},
                    {0,1,0,1,1,1,0,0},
                    {0,1,0,1,1,0,0,1},
                    {0,0,0,1,1,1,3,1},
                    {0,1,0,0,0,1,0,1}
                    };
    bool finished = false;
    if(index.x == 9 && index.y == 9)
    {
        //cout<<"hannigai"<<endl;
        return false;
    }
    else if(data[index.y][index.x] == ROAD)
    {
        //cout<<data[index.y][index.x]+" mitidayo"<<endl;
        if(!pass.empty())
        {
            for(int i = 0 ; i < pass.size() ; i++)
            {
                if(pass[i].x == index.x && pass[i].y == index.y)
                    finished = true;
            }
        }
    }
    else if(data[index.y][index.x] == WALL)
    {
        //cout<<"kabedattayo"<<endl;
        return false;
    }
    else if(data[index.y][index.x] == START)
    {
        //cout<<"hazimaridayo"<<endl;
        return false;
    }
    if(finished == true)
    {
        //cout<<"mitukattyata"<<endl;
        return false;
    }       
    else
    {
        //cout<<"atarasiiyo"<<endl;
        return true;
    }
}

void Loop(int x,int y,int *currentX,int *currentY)
{
    int data[8][8] = {
                    {0,0,1,0,0,0,0,0},
                    {0,1,1,0,1,0,1,0},
                    {0,1,1,0,1,0,1,0},
                    {0,0,2,0,1,0,1,0},
                    {0,1,0,1,1,1,0,0},
                    {0,1,0,1,1,0,0,1},
                    {0,0,0,1,1,1,3,1},
                    {0,1,0,0,0,1,0,1}
                    };
    Index index,down,right,left,up;
    index.x = x;
    index.y = y;
    bool isStarted = false;
    if(!pass.empty())
    {
        for(int i = 0 ; i < pass.size() ; i++)
        {
            if(pass[i].x == index.x && pass[i].y == index.y)
                isStarted = true;
        }
    }
    if(isStarted==false)
    {
        pass.push_back(index);
        route.push_back(index);
    }
    
    if(data[index.y][index.x] == GOAL)
    {
        isFinished = true;
    }
    if(isFinished == false)
    {
        if(y < 7)
        {
            down.x = x;
            down.y = y + 1;
        }
        else
        {
            down.x = 9;
            down.y = 9;
        }
        if(y > 0)
        {
            up.x = x;
            up.y = y-1;
        }
        else
        {
            up.x = 9;
            up.y = 9;
        }
        if(x < 7)
        {
            right.x = x + 1;
            right.y = y;
        }
        else
        {
            right.x = 9;
            right.y = 9;
        }
        if(x > 0)
        {
            left.x = x - 1;
            left.y = y;
        }
        else
        {
            left.x = 9;
            left.y = 9;
        }
        bool direction[4];
        for(int i = DOWN ; i <= UP ; i++)
        {
            switch (i)
            {
                case DOWN:
                    //cout<<"sita"<<endl;
                    direction[DOWN] = Direction(down);
                    break;
                case RIGHT:
                    //cout<<"migi"<<endl;
                    direction[RIGHT] = Direction(right);
                    break;
                case LEFT:
                    //cout<<"hidari"<<endl;
                    direction[LEFT] = Direction(left);
                    break;
                case UP:
                    //cout<<"ue"<<endl;
                    direction[UP] = Direction(up);
                    break;
            }
        }
        int branchCount = 0;
        for(int i = DOWN; i <= UP ; i++)
        {
            if(direction[i] == true)
            {
                branchCount++;
            }
        }
        //cout<<"bunnkiga"<<branchCount<<"attayo"<<endl;
        if(branchCount == 1)
        {
            for(int i = DOWN; i <= UP ; i++)
            {
                if(direction[i] == true)
                {
                    switch (i)
                    {
                        case DOWN:
                            *currentX = down.x;
                            *currentY = down.y;
                            break;
                        case RIGHT:
                            *currentX = right.x;
                            *currentY = right.y;
                            break;
                        case LEFT:
                            *currentX = left.x;
                            *currentY = left.y;
                            break;
                        case UP:
                            *currentX = up.x;
                            *currentY = up.y;
                            break;
                    }
                }
            }
            branchCount = 0;
        }
        else if(branchCount > 1)
        {
            for(int i = DOWN; i <= UP ; i++)
            {
                if(direction[i] == true)
                {
                    switch (i)
                    {
                        case DOWN:
                            branch.push(down);
                            break;
                        case RIGHT:
                            branch.push(right);
                            break;
                        case LEFT:
                            branch.push(left);
                            break;
                        case UP:
                            branch.push(up);
                            break;
                    }
                }
            }
            *currentX = branch.top().x;
            *currentY = branch.top().y;
            branchCount = 0;
        }
        else if(branchCount == 0)
        {
            if(!branch.empty())
            {
                //cout<<branch.top().x<<","<<branch.top().y<<"mousiyousitabunnkidayo"<<endl;
                bool isReturned = true;
                while(isReturned==true)
                {
                    if(route.back().x == branch.top().x && route.back().y == branch.top().y)
                    {
                        isReturned = false;
                    }
                    else
                    {
                        //cout<<route.back().x<<","<<route.back().y<<"kesuyo"<<endl;
                        route.pop_back();
                    }
                }
                branch.pop();
                //cout<<branch.top().x<<","<<branch.top().y<<"tuginobunnkidayo"<<endl;
                route.pop_back();
                //cout<<route.back().x<<","<<route.back().y<<"tugidayo"<<endl;
                *currentX = route.back().x;
                *currentY = route.back().y;
            }
        }
    }
}

int main()
{
    Index index;
    int data[8][8] = {
                    {0,0,1,0,0,0,0,0},
                    {0,1,1,0,1,0,1,0},
                    {0,1,1,0,1,0,1,0},
                    {0,0,2,0,1,0,1,0},
                    {0,1,0,1,1,1,0,0},
                    {0,1,0,1,1,0,0,1},
                    {0,0,0,1,1,1,3,1},
                    {0,1,0,0,0,1,0,1}
                    };
    int x = 2, y = 3;
    while(isFinished == false)
    {
        //cout<<x<<","<<y<<endl;
        Loop(x,y,&x,&y);
    }
    //cout << "end" << endl;
    for(int i = 0 ; i < route.size() ; i++)
    {
        cout<<route[i].x<<","<<route[i].y<<endl;
    }
    //cout<<"finish"<<endl;
}