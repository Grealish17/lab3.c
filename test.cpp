#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "polygon.h"
using namespace PLGN;

TEST_CASE( "class Polygon" ) {
    Vertex vertex1[1] = {{1.0, 2.0}};
    Polygon polygon1 = Polygon(1, vertex1);
    Vertex vertex2[1] = {{4.0, 3.0}};
    Polygon polygon2 = Polygon(1, vertex2);

    Polygon polygon = polygon1 + polygon2;
    REQUIRE(polygon.get_n() == 2);
    REQUIRE(fabs(polygon[0].x - 1.0) < 1e-5);
    REQUIRE(fabs(polygon[0].y - 2.0) < 1e-5);
    REQUIRE(fabs(polygon[1].x - 4.0) < 1e-5);
    REQUIRE(fabs(polygon[1].y - 3.0) < 1e-5);

    Vertex vertex3[2] = {{-3.0, -2.0}, {-5.0, -4.0}};
    Polygon polygon3 = Polygon(2, vertex3);
    polygon += polygon3;

    REQUIRE(polygon.get_n() == 4);
    REQUIRE(fabs(polygon[2].x - (-3.0)) < 1e-5);
    REQUIRE(fabs(polygon[2].y - (-2.0)) < 1e-5);
    REQUIRE(fabs(polygon[3].x - (-5.0)) < 1e-5);
    REQUIRE(fabs(polygon[3].y - (-4.0)) < 1e-5);

    Vertex v = {0.0, 0.0};
    polygon += v;

    REQUIRE(polygon.get_n() == 5);
    REQUIRE(fabs(polygon[4].x - 0.0) < 1e-5);
    REQUIRE(fabs(polygon[4].y - 0.0) < 1e-5);

    polygon.parallel_transfer(1.0, 1.0);

    REQUIRE(fabs(polygon[0].x - 2.0) < 1e-5);
    REQUIRE(fabs(polygon[0].y - 3.0) < 1e-5);
    REQUIRE(fabs(polygon[1].x - 5.0) < 1e-5);
    REQUIRE(fabs(polygon[1].y - 4.0) < 1e-5);
    REQUIRE(fabs(polygon[2].x - (-2.0)) < 1e-5);
    REQUIRE(fabs(polygon[2].y - (-1.0)) < 1e-5);
    REQUIRE(fabs(polygon[3].x - (-4.0)) < 1e-5);
    REQUIRE(fabs(polygon[3].y - (-3.0)) < 1e-5);
    REQUIRE(fabs(polygon[4].x - 1.0) < 1e-5);
    REQUIRE(fabs(polygon[4].y - 1.0) < 1e-5);

    REQUIRE(fabs((*polygon).x - 0.4) < 1e-5);
    REQUIRE(fabs((*polygon).y - 0.8) < 1e-5);

    polygon.rotate(0, 0, 90);

    REQUIRE(fabs(polygon[0].x - (-3.0)) < 1e-5);
    REQUIRE(fabs(polygon[0].y - 2.0) < 1e-5);
    REQUIRE(fabs(polygon[1].x - (-4.0)) < 1e-5);
    REQUIRE(fabs(polygon[1].y - 5.0) < 1e-5);
    REQUIRE(fabs(polygon[2].x - 1.0) < 1e-5);
    REQUIRE(fabs(polygon[2].y - (-2.0)) < 1e-5);
    REQUIRE(fabs(polygon[3].x - 3.0) < 1e-5);
    REQUIRE(fabs(polygon[3].y - (-4.0)) < 1e-5);
    REQUIRE(fabs(polygon[4].x - (-1.0)) < 1e-5);
    REQUIRE(fabs(polygon[4].y - 1.0) < 1e-5);

    Polygon polygon4 = polygon3;
    REQUIRE(polygon4.get_n() == 2);
    REQUIRE(fabs(polygon4[0].x - (-3.0)) < 1e-5);
    REQUIRE(fabs(polygon4[0].y - (-2.0)) < 1e-5);
    REQUIRE(fabs(polygon4[1].x - (-5.0)) < 1e-5);
    REQUIRE(fabs(polygon4[1].y - (-4.0)) < 1e-5);
}