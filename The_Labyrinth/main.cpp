#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// STAGE 1 == EXPLORING. 
// STAGE 2 == GOING TO C. Only can be in this stage in case of dist(c,t) <= a;
// STAGE 3 == GOINT TO T





struct Position{
    int row;
    int column;
};

//Devulve la distancia de un punto a otro punto con una matriz de padres ya creada
//Nos ahorramos el BFS de nuevo.

int calcDist(vector<vector<Position>> fathers, Position C, Position T)
{
    Position prev = C;
    int dist = 0;

    while(true)
    {
        if(fathers[prev.row][prev.column].row == T.row &&
            fathers[prev.row][prev.column].column == T.column
        )
        {
            dist++;
            break;
        }
        prev = fathers[prev.row][prev.column];
        dist++;
    }

    return dist;
    
}

int main()
{
    int r; // number of rows.
    int c; // number of columns.
    int a; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
    cin >> r >> c >> a; cin.ignore();

    // This are used in case we are going to C or T;
    bool goForward = 1;

    Position tPosition = {-1,-1}; //T position for the first input;
    vector<string> map(r); //Map of the labyrinth
    string move; //RIGHT, LEFT, UP or DOWN

    // game loop
    while (1) {

        bool stage1 = true;
        bool stage2 = false;
        bool stage3 = false;

        int kr; // row where Rick is located.
        int kc; // column where Rick is located.
        cin >> kr >> kc; cin.ignore();
        
        for (int i = 0; i < r; i++) {
            // C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
            cin >> map[i]; cin.ignore();
        }

        if(tPosition.row == -1) tPosition = {kr, kc};

        
        queue<Position> frontier;
        Position current;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<vector<Position>> father(r, vector<Position>(c, {-1,-1}));
        
        Position start = {kr, kc};    
        frontier.push({kr,kc});
        visited[kr][kc] = true;  // La casilla en la que estamos es la visitada
        
        while(!frontier.empty())
        {
            current = frontier.front();
            frontier.pop();
            int kc = current.column;
            int kr = current.row;

            //Comprobamos si hay algún ? cercano
            bool isUnknown =
                (kc + 1 < c && map[kr][kc+1] == '?') ||
                (kc - 1 >= 0 && map[kr][kc-1] == '?') ||
                (kr + 1 < r && map[kr + 1][kc] == '?') ||
                (kr - 1 >= 0 && map[kr-1][kc] == '?');

            //We check if there is a cell containing the bomb.
            bool isTheGoal =
                (kc + 1 < c && map[kr][kc+1] == 'C') ||
                (kc - 1 >= 0 && map[kr][kc-1] == 'C') ||
                (kr + 1 < r && map[kr + 1][kc] == 'C') ||
                (kr - 1 >= 0 && map[kr-1][kc] == 'C');
            

            
                

            //Seguimos explorando.
            bool right = (kc+1 < c && map[kr][kc+1]=='.' && !visited[kr][kc+1]);
            bool down = (kr+1 < r && map[kr+1][kc]=='.' && !visited[kr+1][kc]);
            bool up = (kr-1 >= 0 && map[kr-1][kc]=='.' && !visited[kr-1][kc]);
            bool left = (kc-1 >= 0 && map[kr][kc-1]=='.' && !visited[kr][kc-1]);


            //Algoritmo BFS
            if(right)
            {
                visited[kr][kc+1]= true;
                frontier.push({kr,kc+1});
                father[kr][kc+1] = current;
            }
            if(left)
            {
                visited[kr][kc-1]=true;
                frontier.push({kr, kc-1});
                father[kr][kc-1] = current;
            }
            if(down)
            {
                visited[kr+1][kc]= true;
                frontier.push({kr+1,kc});
                father[kr+1][kc] = current;
            }
            if(up)
            {
                visited[kr-1][kc]= true;
                frontier.push({kr-1, kc});
                father[kr-1][kc] = current;
            }
        
        }

        std::cout << move << endl; 
    }
}