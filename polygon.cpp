#include "polygon.h"
#include <cstring>

namespace PLGN{
    int Polygon::get_n() const{
        return n;
    }

    Polygon::Polygon(){
        n = 0;
        vertex = new Vertex[0];
    }

    Polygon::Polygon(Vertex v){
        n = 1;
        vertex = new Vertex[1];
        vertex[0] = v;
    }

    Polygon::Polygon(int n, Vertex * vertex){
        this->n = n;
        this->vertex = new Vertex[n];
        memcpy(this->vertex, vertex, n*sizeof(Vertex));
    }

    Polygon::~Polygon(){
        n = 0;
        delete[] vertex;
    }

    void Polygon::set_coordinates(int data_n, Vertex * data_vertex){
        this->~Polygon();
        n = data_n;
        this->vertex = new Vertex[n];
        memcpy(vertex, data_vertex, n*sizeof(Vertex));
    }

    Vertex Polygon::operator[](int i) const{
        if(i < n && i >= 0){
            return vertex[i];
        }
        else{
            throw std::invalid_argument("Incorrect data");
        }
    }

    Polygon operator+(const Polygon& p1, const Polygon& p2){
        Polygon polygon;
        polygon.n = p1.n + p2.n;
        polygon.vertex = new Vertex[polygon.n];
        memcpy(polygon.vertex, p1.vertex, p1.n*sizeof(Vertex));
        memcpy(polygon.vertex + p1.n, p2.vertex, p2.n*sizeof(Vertex));
        return polygon;
    }

    Polygon& operator+=(Polygon& p1, const Polygon& p2){
        Vertex* p = p1.vertex;
        int n = p1.n;
        p1.vertex = new Vertex[n + p2.n];
        memcpy(p1.vertex, p, n*sizeof(Vertex));
        memcpy(p1.vertex + n, p2.vertex, p2.n*sizeof(Vertex));
        p1.n = n + p2.n;
        delete[] p;
        return p1;
    }

    Vertex Polygon::operator*() const{
        if(n == 0){
            throw std::invalid_argument("Polygon is empty");
        }
        else{
            Polygon polygon = Polygon(n, vertex);

            for(int i(n-2); i>=0; --i){
                polygon.vertex[i].x = (float)((polygon.vertex[i].x + polygon.vertex[i+1].x * (0.0 + n-2 - i+1))/(1 + n-2 - i+1));
                polygon.vertex[i].y = (float)((polygon.vertex[i].y + polygon.vertex[i+1].y * (0.0 + n-2 - i+1))/(1 + n-2 - i+1));
            }
            return polygon.vertex[0];
        }
    }

    std::ostream& operator<<(std::ostream& os, const Polygon& polygon){
        os << "Number of vertex: " << polygon.n << "\n";
        for(int i(0); i<polygon.n; ++i){
            os << i+1 << ":  x = " << polygon.vertex[i].x << ";  y = " << polygon.vertex[i].y << "\n";
        }
        return os;
    }

    void Polygon::rotate(float x0, float y0, int fi){
        if(fi % 90 == 0){
            for(int i(0); i<n; ++i){
                float x, y;
                x = (float)(x0 + (vertex[i].x - x0)*cos(PI * fi/180) - (vertex[i].y - y0)*sin(PI * fi/180));
                y = (float)(y0 + (vertex[i].x - x0)*sin(PI * fi/180) + (vertex[i].y - y0)*cos(PI * fi/180));
                vertex[i].x = x;
                vertex[i].y = y;
            }
        }
        else{
            throw std::invalid_argument("Incorrect data");
        }
    }

    void Polygon::parallel_transfer(float x, float y){
        for(int i(0); i<n; ++i){
            vertex[i].x += x;
            vertex[i].y += y;
        }
    }
}
