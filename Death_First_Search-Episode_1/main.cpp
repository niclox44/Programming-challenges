#include <cstddef>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class Grafo {
    public:

        using Vertice = std::size_t;
        explicit Grafo(std::size_t cantidad, bool dirigido = false)
            : adyacencia_(cantidad), dirigido_(dirigido) {};

        Vertice agregarVertice(){
            adyacencia_.emplace_back();
            return adyacencia_.size() - 1;
        }

        void agregarArista(Vertice origen, Vertice destino){
            
            validar(origen);
            validar(destino);

            adyacencia_[origen].push_back(destino);

            if(!dirigido_ && origen != destino){
                adyacencia_[destino].push_back(origen);
            }
        }

        void eliminarArista(Vertice origen, Vertice destino){
            validar(origen);
            validar(destino);

            auto& vecinosOrigen = adyacencia_[origen]; 

            vecinosOrigen.erase(
                std::remove(vecinosOrigen.begin(), vecinosOrigen.end(), destino),
                vecinosOrigen.end()
            );

            if(!dirigido_ && origen != destino){
                auto& vecinosDestino = adyacencia_[destino]; 

                vecinosDestino.erase(
                    std::remove(vecinosDestino.begin(), vecinosDestino.end(), origen),
                    vecinosDestino.end()
                );
            }
        }

        const std::vector<Vertice>& vecinos(Vertice vertice) const{
            return adyacencia_[vertice];
        }

        std::vector<Vertice> bfs(Vertice inicio, Vertice destino) const //el metodo no puedo modificar las porpiedades del objeto
        {   
            validar(inicio);

            std::vector<bool> visitado(adyacencia_.size(), false);
            std::vector<Vertice> recorrido;
            std::queue<Vertice> pendientes;
            std::vector<Vertice> padre(adyacencia_.size());


            visitado[inicio] = true;
            pendientes.push(inicio);

            while(!pendientes.empty() ){
            
                const auto actual = pendientes.front();
                pendientes.pop();
                if(actual == destino){

                    //Entonces devolvemos el camino hasta este nodo
                    for(Vertice nodo = destino; 
                        nodo != inicio;
                        nodo = padre[nodo]
                    ){
                        recorrido.push_back(nodo);
                    }

                    recorrido.push_back(inicio);

                    std::reverse(recorrido.begin(), recorrido.end());
                    return recorrido;

                };

                for(const auto vecinos: adyacencia_[actual]){
                    if(!visitado[vecinos]){
                        visitado[vecinos] = true;
                        padre[vecinos] = actual;
                        pendientes.push(vecinos);
                    }
                }
            }

            return {};
        }
    private:

        std::vector<std::vector<Vertice>> adyacencia_;
        bool dirigido_;

        void validar(Vertice vertice) const {
            if(vertice >= adyacencia_.size()){
                throw std::out_of_range("El vertice no existe");
            }
        }

};

int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    std::vector<std::size_t> gateways; // the vector to keep the gateways indexes
    cin >> n >> l >> e; cin.ignore();

    Grafo graf = Grafo(n,false);

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;

        cin >> n1 >> n2; cin.ignore();

        graf.agregarArista(n1, n2);
    }

    
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        gateways.push_back(ei);
    }
    
    int si;// The index of the node on which the Bobnet agent is positioned this turn
    while (cin >> si) {
        
        std::vector<std::vector<size_t>> recorrido;
        std::vector<size_t> distancias;
        
        
            for(int i=0; i<gateways.size(); i++){
            
                recorrido.push_back(graf.bfs(si,gateways[i]));

                if(recorrido[i].size() == 0){
                    continue;
                }

                distancias.push_back(recorrido[i].size());
            }

            auto min = std::min_element(distancias.begin(), distancias.end());

            for(int i=0; i<gateways.size(); i++){
                if(recorrido[i].size() == *min){

                    auto n1 = recorrido[i][recorrido[i].size()-2];
                    auto n2 = recorrido[i][recorrido[i].size()-1];
                    cout << n1 << " " << n2 << endl;
                    graf.eliminarArista(n1, n2);

                    break;
                }
            }
        
    }
}