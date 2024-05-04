// 326627635 | adi.peisach@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[-, 2, 1]\n[2, -, 3]\n[1, 3, -]\n");
    g3 = g2 + g1;
    CHECK(g3.printGraph() == "[-, 2, 1]\n[2, -, 3]\n[1, 3, -]\n");
    ariel::Graph g4 = g1 + g3;
    CHECK(g4.printGraph() == "[-, 3, 1]\n[3, -, 4]\n[1, 4, -]\n");

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, -1, 7},
        {8, 0, 4},
        {-8, 1, 0}};
    g5.loadGraph(graph5);
    g1 += g5;
    CHECK(g1.printGraph() == "[-, X, 7]\n[9, -, 5]\n[-8, 2, -]\n");
}

TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    CHECK(g3.printGraph() == "[-, X, -1]\n[X, -, -1]\n[-1, -1, -]\n");
    ariel::Graph g4 = g1 - g3;
    CHECK(g4.printGraph() == g2.printGraph());

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, -1, 7},
        {8, 0, 4},
        {-8, 1, 0}};
    g5.loadGraph(graph5);
    g1 -= g5;
    CHECK(g1.printGraph() == "[-, 2, -7]\n[-7, -, -3]\n[8, X, -]\n");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 * g2;
    CHECK(g3.printGraph() == "[-, X, 2]\n[1, -, 1]\n[1, X, -]\n");
    g3 = g2 * g1;
    CHECK(g3.printGraph() == "[-, 1, 1]\n[X, -, X]\n[2, 1, -]\n");

    ariel::Graph g4;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 3},
        {4, 0, 5, 6},
        {7, 8, 0, 9},
        {10,11,12,0}};
    g4.loadGraph(graph1);
    ariel::Graph g5;
    vector<vector<int>> weightedGraph1 = {
        {0, 1, 1, 2},
        {3, 0, 5, 8},
        {13,21,0,34},
        {55,89,-1,0}};
    g5.loadGraph(weightedGraph1);
    ariel::Graph g6 = g4 * g5;
    CHECK(g6.printGraph() == "[-, 309, 2, 76]\n[395, -, -2, 178]\n[519, 808, -, 78]\n[189, 262, 65, -]\n");
    g6 = g5 * g4;
    CHECK(g6.printGraph() == "[-, 30, 29, 15]\n[115, -, 102, 54]\n[424, 387, -, 165]\n[349, 47, 555, -]\n");

    g1 *= g2;
    CHECK(g1.printGraph() == "[-, X, 2]\n[1, -, 1]\n[1, X, -]\n");
}

TEST_CASE("Test scalar operations") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 3},
        {4, 0, 5, 6},
        {7, 8, 0, 9},
        {10,11,12,0}};
    g3.loadGraph(graph1);
    ariel::Graph g4;
    vector<vector<int>> weightedGraph1 = {
        {0, 1, 1, 2},
        {3, 0, 5, 8},
        {13,21,0,34},
        {55,89,-1,0}};
    g4.loadGraph(weightedGraph1);

    ariel::Graph g5 = g1 + 10;
    CHECK(g5.printGraph() == "[-, 11, 10]\n[11, -, 11]\n[10, 11, -]\n");
    g5 = g3 + (-20);
    CHECK(g5.printGraph() == "[-, -19, -18, -17]\n[-16, -, -15, -14]\n[-13, -12, -, -11]\n[-10, -9, -8, -]\n");
    g5 += -1;
    CHECK(g5.printGraph() == "[-, -20, -19, -18]\n[-17, -, -16, -15]\n[-14, -13, -, -12]\n[-11, -10, -9, -]\n");

    g5 = g2 - 10;
    CHECK(g5.printGraph() == "[-, -9, -9]\n[-9, -, -8]\n[-9, -8, -]\n");
    g5 = g4 - (-2);
    CHECK(g5.printGraph() == "[-, 3, 3, 4]\n[5, -, 7, 10]\n[15, 23, -, 36]\n[57, 91, 1, -]\n");
    g5 -= 5;
    CHECK(g5.printGraph() == "[-, -2, -2, -1]\n[X, -, 2, 5]\n[10, 18, -, 31]\n[52, 86, -4, -]\n");

    g5 = g1 * 3;
    CHECK(g5.printGraph() == "[-, 11, 10]\n[11, -, 11]\n[10, 11, -]\n");
    g5 = g3 * (-2);
    CHECK(g5.printGraph() == "[-, -19, -18, -17]\n[-16, -, -15, -14]\n[-13, -12, -, -11]\n[-10, -9, -8, -]\n");
    g5 += -1;
    CHECK(g5.printGraph() == "[-, -20, -19, -18]\n[-17, -, -16, -15]\n[-14, -13, -, -12]\n[-11, -10, -9, -]\n");

    g5 = g2 - 10;
    CHECK(g5.printGraph() == "[-, -9, -9]\n[-9, -, -8]\n[-9, -8, -]\n");
    g5 = g4 - (-2);
    CHECK(g5.printGraph() == "[-, 3, 3, 4]\n[5, -, 7, 10]\n[15, 23, -, 36]\n[57, 91, 1, -]\n");
    g5 -= 5;
    CHECK(g5.printGraph() == "[-, -2, -2, -1]\n[X, -, 2, 5]\n[10, 18, -, 31]\n[52, 86, -4, -]\n");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {-3,2, 1, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
    CHECK_THROWS(g1 - g6);
}