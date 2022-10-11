#include <iostream>
#include <cmath>
#define PI 3.14159265

namespace PLGN{

    struct Vertex{
        float x;
        float y;
    };

    class Polygon{
    private:
        int n;
        Vertex* vertex;
    public:
        int get_n() const;

        Polygon();

        Polygon(float x, float y);

        Polygon(int n, Vertex * vertex);

        ~Polygon();

        void set_coordinates(int data_n, Vertex * data_vertex);

        Vertex operator[](int i) const;

        friend Polygon operator+(const Polygon& p1, const Polygon& p2);

        friend Polygon& operator+=(Polygon& p1, const Polygon& p2);

        friend Polygon& operator+=(Polygon& p1, const Vertex& v);

        void rotate(float x0, float y0, int fi);

        void parallel_transfer(float x, float y);

        Vertex operator*() const;

        friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon);
    };
}
