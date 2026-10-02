#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Graph{
    public:
    using Vertex = std::size_t;

    //Constructor
    explicit Graph(std::size_t quantity, bool directed)
        : adjacency_(quantity), directed_(directed){}

    Vertex addVertex(){
        adjacency_.emplace_back();
        return adjacency_.size() - 1;
    }

    void addEdge(Vertex origin, Vertex destiny){
        adjacency_[origin].push_back(destiny);

        if(!directed_){
            adjacency_[destiny].push_back(origin);
        }
    }

    const std::vector<Vertex>& getNeighbors(Vertex node) const{
        return adjacency_[node];
    }

    std::vector<Vertex> bfs(Vertex origin, Vertex destiny) const{
        
        std::queue<Vertex> frontier;
        std::vector<bool> visited(adjacency_.size(), false);
        std::vector<Vertex> father(adjacency_.size());
        std::vector<Vertex> path;


        visited[0] = true;
        frontier.push(origin);

        while(!frontier.empty())
        {
            const auto current = frontier.front();
            frontier.pop();
            
            if(current == destiny){
                
                for(Vertex nodo = destiny;
                    nodo != origin;
                    nodo = father[nodo])
                {
                    path.push_back(nodo);
                }

                std::reverse(path.begin(), path.end());
                return path;
            }

            for(const auto neighbor: adjacency_[current])
            {
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    frontier.push(neighbor);
                    father[neighbor] = current;
                }
            }
            
        }
        return {};
    }


    private:
    std::vector<std::vector<Vertex>> adjacency_;
    bool directed_;
};

bool areAllVisited(std::vector<bool> v){
    for(auto is: v){
        if(!is) return false;
    }
    return true;
}

int main()
{
    int r; // number of rows.
    int c; // number of columns.
    int a; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
    cin >> r >> c >> a; cin.ignore();

    // game loop
    while (1) {
        int kr; // row where Rick is located.
        int kc; // column where Rick is located.
        std::vector<string> labyrinth;
        cin >> kr >> kc; cin.ignore();
        for (int i = 0; i < r; i++) {
            string row; // C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
            cin >> row; cin.ignore();
            labyrinth.push_back(row);
        }

        Graph graph = Graph(r*c, false);
        std::vector<bool> visited(4, false);
        int go_right_up = 0;

        //The solution I though is search the farest node known at the right, left and bottom

        while(areAllVisited(visited)){

            //right 
            if(!visited[0] && labyrinth[kr][go_right_up] == '#'){
                graph.addEdge(kr,go_right_up--);
                visited[0] = true;
            }

            if(!visited[1] && labyrinth[kr][go_right_up] == '#'){
                graph.addEdge(kr,go_right_up--);
                visited[1] = true;
            }

            if(!visited[0] && labyrinth[kr][go_right_up] == '#'){
                graph.addEdge(kr,go_right_up--);
                visited[0] = true;
            }

            if(!visited[0] && labyrinth[kr][go_right_up] == '#'){
                graph.addEdge(kr,go_right_up--);
                visited[0] = true;
            }
            
        }
        
        cout << "RIGHT" << endl; // Rick's next move (UP DOWN LEFT or RIGHT).
    }
}