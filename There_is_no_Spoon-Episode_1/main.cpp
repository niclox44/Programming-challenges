#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct Point{
    int x;
    int y;
};


int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    std::vector<string> lines;
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        lines.push_back(line);
    }

    struct Point node, nr, nb;


    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){

            if(lines[i][j] == '0'){

                int go_r = j+1;
                int go_b = i+1;

                nr.x = -1;
                nr.y = -1;
                nb.x = -1;
                nb.y = -1;

                while(go_r < width)
                {
                    if(lines[i][go_r] == '0') {
                        nr.x = go_r;
                        nr.y = i;
                        break;
                    }else{
                        go_r ++;
                    }

                }

                while(go_b < height){

                    if(lines[go_b][j] == '0') {
                        nb.y = go_b;
                        nb.x = j;
                        break;
                    }else{
                        go_b ++;
                    }
                }

                node.x = j;
                node.y = i;
                std::cout << node.x << " " << node.y << " " << nr.x << " " << nr.y << " " << nb.x << " " << nb.y << endl;
            }
            
        }
    }

    // Three coordinates: a node, its right neighbor, its bottom neighbor
    
}