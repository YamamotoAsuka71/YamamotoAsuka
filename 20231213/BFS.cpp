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
struct Routes {
    vector<Index> route;
};
vector<Routes> routes;
stack<Index> branch;

bool isFinished = false;


bool Direction(Index index,int routeNum)
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
        if(!routes[routeNum].route.empty())
        {
            for(int i = 0 ; i < routes[routeNum].route.size() ; i++)
            {
                if(routes[routeNum].route[i].x == index.x && routes[routeNum].route[i].y == index.y)
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

void RouteCopy(int routeNum,int counter)
{
    //cout<<"hukuseisuruyo"<<endl;
    if (routeNum+1 <= routes[routes.size()-counter].route.size()-1) {
        Routes sourceRoute = routes[routeNum];
        sourceRoute.route.pop_back();
        //cout<<"kokomadehukuseisitayo"<<sourceRoute.route.back().x<<","<<sourceRoute.route.back().y<<endl;
        routes.push_back(sourceRoute);
    }
    //cout<<"hukuseiowattayo"<<endl;
}

void Loop(int routeNum, int* shortestNum_)
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
    bool isStarted = false;

    //  
    

    if(data[routes[routeNum].route.back().y][routes[routeNum].route.back().x] == GOAL)
    {
        *shortestNum_ = routeNum;
        isFinished = true;
    }
    if(isFinished == false)
    {
        if(routes[routeNum].route.back().y < 7)
        {
            down.x = routes[routeNum].route.back().x;
            down.y = routes[routeNum].route.back().y + 1;
        }
        else
        {
            down.x = 9;
            down.y = 9;
        }
        if(routes[routeNum].route.back().y > 0)
        {
            up.x = routes[routeNum].route.back().x;
            up.y = routes[routeNum].route.back().y-1;
        }
        else
        {
            up.x = 9;
            up.y = 9;
        }
        if(routes[routeNum].route.back().x < 7)
        {
            right.x = routes[routeNum].route.back().x + 1;
            right.y = routes[routeNum].route.back().y;
        }
        else
        {
            right.x = 9;
            right.y = 9;
        }
        if(routes[routeNum].route.back().x > 0)
        {
            left.x = routes[routeNum].route.back().x - 1;
            left.y = routes[routeNum].route.back().y;
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
                    direction[DOWN] = Direction(down,routeNum);
                    break;
                case RIGHT:
                    //cout<<"migi"<<endl;
                    direction[RIGHT] = Direction(right,routeNum);
                    break;
                case LEFT:
                    //cout<<"hidari"<<endl;
                    direction[LEFT] = Direction(left,routeNum);
                    break;
                case UP:
                    //cout<<"ue"<<endl;
                    direction[UP] = Direction(up,routeNum);
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
        //  
        if(branchCount == 1)
        {
            for(int i = DOWN; i <= UP ; i++)
            {
                if(direction[i] == true)
                {
                    switch (i)
                    {
                        case DOWN:
                            routes[routeNum].route.push_back(down);
                            break;
                        case RIGHT:
                            routes[routeNum].route.push_back(right);
                            break;
                        case LEFT:
                            routes[routeNum].route.push_back(left);
                            break;
                        case UP:
                            routes[routeNum].route.push_back(up);
                            break;
                    }
                }
            }
            branchCount = 0;
        }
        //  
        else if(branchCount > 1)
        {
            int branchCounter = 0;
            for(int i = DOWN; i <= UP ; i++)
            {
                if(direction[i] == true)
                {
                    switch (i)
                    {
                        case DOWN:
                            //cout<<"tuikasuruyo"<<endl;
                            routes[routeNum].route.push_back(down);
                            //cout<<routes[routeNum].route.back().x<<","<<routes[routeNum].route.back().y<<endl;
                            branchCounter++;
                            break;
                        case RIGHT:
                            if(branchCounter==0)
                            {
                                //cout<<"tuikasuruyo"<<endl;
                                routes[routeNum].route.push_back(right);
                                //cout<<routes[routeNum].route.back().x<<","<<routes[routeNum].route.back().y<<endl;
                                branchCounter++;
                            }
                            else
                            {
                                //cout<<branchCounter<<"kaimenohukuseikaisi"<<endl;
                                RouteCopy(routeNum,branchCounter);
                                //cout<<"kaettekitayo"<<endl;
                                //cout<<routes.size()<<endl;
                                //cout<<routes.back().route.back().x<<","<<routes.back().route.back().y<<endl;
                                routes.back().route.push_back(right);
                                //cout<<routes.back().route.back().x<<","<<routes.back().route.back().y<<endl;
                                branchCounter++;
                            }
                            break;
                        case LEFT:
                            if(branchCounter==0)
                            {
                                //cout<<"tuikasuruyo"<<endl;
                                routes[routeNum].route.push_back(left);
                                //cout<<routes[routeNum].route.back().x<<","<<routes[routeNum].route.back().y<<endl;
                                branchCounter++;
                            }
                            else
                            {
                                //cout<<branchCounter<<"kaimenohukuseikaisi"<<endl;
                                RouteCopy(routeNum,branchCounter);
                                //cout<<"kaettekitayo"<<endl;
                                //cout<<routes.size()<<endl;
                                //cout<<routes.back().route.back().x<<","<<routes.back().route.back().y<<endl;
                                routes.back().route.push_back(left);
                                //cout<<routes.back().route.back().x<<","<<routes.back().route.back().y<<endl;
                                branchCounter++;
                            }
                            break;
                        case UP:
                            if(branchCounter==0)
                            {
                                //cout<<"tuikasuruyo"<<endl;
                                routes[routeNum].route.push_back(up);
                                //cout<<routes[routeNum].route.back().x<<","<<routes[routeNum].route.back().y<<endl;
                                branchCounter++;
                            }
                            else
                            {
                                //cout<<branchCounter<<"kaimenohukuseikaisi"<<endl;
                                RouteCopy(routeNum,branchCounter);
                                //cout<<"kaettekitayo"<<endl;
                                //cout<<routes.size()<<endl;
                                //cout<<routes.back().route.back().x<<","<<routes.back().route.back().y<<endl;
                                routes.back().route.push_back(up);
                                //cout<<routes.back().route.back().x<<","<<routes.back().route.back().y<<endl;
                                branchCounter++;
                            }
                            break;
                    }
                }
            }
            branchCount = 0;
        }
        else if(branchCount == 0)
        {
            //cout<<routeNum<<"wokesuyo"<<endl;
            routes.erase(routes.begin() + routeNum);
            routeNum--;
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
    Routes newRoutes;
    index.x = x;
    index.y = y;
    newRoutes.route.push_back(index); 
    routes.push_back(newRoutes);
    int shortestNum = 0;
    while(isFinished == false)
    {   
        for(int routeNum = 0 ; routeNum < routes.size() ; routeNum++)
        {
            //cout<<routes.size()<<"konomitigaaruyo"<<endl;
            //cout<<routes[routeNum].route.back().x<<","<<routes[routeNum].route.back().y<<"ga,atarasiimitidayo"<<endl;
            Loop(routeNum,&shortestNum);
        }
    }
    //cout << "end" << endl;
    for(int i = 0 ; i < routes[shortestNum].route.size() ; i++)
    {
        cout<<routes[shortestNum].route[i].x<<","<<routes[shortestNum].route[i].y<<endl;
    }
    //cout<<"finish"<<endl;
}