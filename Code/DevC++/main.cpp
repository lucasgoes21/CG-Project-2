#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "screen.h"
#include "point2D.h"
#include "color.h"
#include "line.h"
#include "picture.h"
#include "circle.h"
#include "polygon.h"

using std::vector;
int main(int argc, char *argv[])
{
    /*Screen screen("Aula 3", BLACK, 700, 700);

    Point2D p3(350, 450);

    Picture p;
    
    // Telhado
    Line l1(Point2D(350, 50), Point2D(50, 250), RED);
    Line l2(Point2D(50, 250), Point2D(650, 250), RED);
    Line l3(Point2D(650, 250), Point2D(350, 50), RED);
        
    // Parede
    Line l4(Point2D(50, 250), Point2D(50, 650), GREEN);
    Line l5(Point2D(50, 650), Point2D(650, 650), GREEN);
    Line l6(Point2D(650, 650), Point2D(650, 250), GREEN);
        
    Circle circ(p3, 150, BLUE);
        
    // Insere primitivas na lista
    p.add(&l1);
    p.add(&l2);
    p.add(&l3);
    p.add(&l4);
    p.add(&l5);
    p.add(&l6);
    p.add(&circ);
        
    screen.run(p);*/
    
    // Aula - Preenchimento de Polígonos
    Screen screen2("Aula 4", BLACK, 702, 702);
    
    vector<vector<int>> matriz1 = {{0,0,0,0,1,0,0,0,0},
        						 {0,0,0,0,1,0,0,0,0},
        						 {0,0,0,1,1,1,0,0,0},
        						 {0,0,0,1,1,1,0,0,0},
        						 {1,1,1,1,1,1,1,1,1},
        						 {0,1,1,1,1,1,1,1,0},
        						 {0,0,0,1,1,1,0,0,0},
        						 {0,0,1,1,0,1,1,0,0}, 
        						 {0,0,1,0,0,0,1,0,0}};
    vector<vector<int>> matriz2 ={{0,0,0,0,1,0,0,0,0},
        						  {0,0,0,0,1,0,0,0,0},
        						  {0,0,0,0,1,0,0,0,0},
        						  {0,0,0,0,1,0,0,0,0},
        						  {1,1,1,1,1,1,1,1,1},
        						  {0,0,0,0,1,0,0,0,0},
        						  {0,0,0,0,1,0,0,0,0},
        						  {0,0,0,0,1,0,0,0,0},
        					      {0,0,0,0,1,0,0,0,0}};
    vector<vector<int>> matriz3={{0,0,0,0,1,0,0,0,0},
        						 {0,0,0,1,1,1,0,0,0},
        						 {0,0,0,1,1,1,0,0,0},
        						 {0,0,0,1,1,1,0,0,0},
        						 {0,0,0,1,1,1,0,0,0},
        						 {0,0,0,1,1,1,0,0,0},
        						 {0,0,1,1,1,1,1,0,0},
        						 {0,1,1,1,1,1,1,1,0},
        					     {1,1,1,1,1,1,1,1,1}};
	
    
        
    
    

	Polygon pol1(true, RED, true, WHITE,true, WHITE);
	Polygon pol2(true, RED, true, WHITE,true, WHITE, matriz2);
	Polygon pol3(true, RED, true, WHITE,true, WHITE, matriz3);
	
	Polygon pol4(true, RED, true, WHITE,true, WHITE);

	Point2D n1(3,3,GREEN);
	Point2D n2(53,3,GREEN);
	Point2D n3(103,3,GREEN);
	Point2D n4(3,53,GREEN);
	Point2D n5(53,53,GREEN);
	Point2D n6(103,53,GREEN);
	
	pol4.addVertex(&n1);
	pol4.addVertex(&n2);
	pol4.addVertex(&n3);
	pol4.addVertex(&n6);
	pol4.addVertex(&n5);
	pol4.addVertex(&n2);
	pol4.addVertex(&n1);
	pol4.addVertex(&n4);
	pol4.addVertex(&n5);
	
	
	Point2D p1(3,530,GREEN);
	Point2D p2(231,530,GREEN);
	Point2D p3(231,474,GREEN);
	Point2D p4(155,454,GREEN);
	Point2D p5(155,302,GREEN);
	Point2D p6(117,282,GREEN);
	Point2D p7(79,302,GREEN);
	Point2D p8(79,474,GREEN);
	Point2D p9(3,454,GREEN);	
	pol1.addVertex(&p1);
	pol1.addVertex(&p2);
	pol1.addVertex(&p3);
	pol1.addVertex(&p4);
	pol1.addVertex(&p5);
	pol1.addVertex(&p6);
	pol1.addVertex(&p7);
	pol1.addVertex(&p8);
	pol1.addVertex(&p9);
	
	Point2D a1(389,530,GREEN);
	Point2D a2(465,406,GREEN);
	Point2D a3(389,282,GREEN);
	Point2D a4(237,367,GREEN);
	Point2D a5(313,393,GREEN);
	Point2D a6(389,380,GREEN);
	pol2.addVertex(&a1);
	pol2.addVertex(&a2);
	pol2.addVertex(&a3);
	pol2.addVertex(&a4);
	pol2.addVertex(&a5);
	pol2.addVertex(&a6);
	
	Point2D b1(471,530,GREEN);
	Point2D b2(699,530,GREEN);
	Point2D b3(623,420,GREEN);
	Point2D b4(585,282,GREEN);
	Point2D b5(547,420,GREEN);
	pol3.addVertex(&b1);
	pol3.addVertex(&b2);
	pol3.addVertex(&b3);
	pol3.addVertex(&b4);
	pol3.addVertex(&b5);
	
	
	Picture h2;
	h2.add(&pol1);
	h2.add(&pol2);
	h2.add(&pol3);
	h2.add(&pol4);
	screen2.run(h2);

    return 0;
}
