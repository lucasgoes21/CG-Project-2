#include <iterator>
#include <iostream>
#include <vector>
#include <cmath>
#include "polygon.h"
#include "line.h"
#include "edgeTable.h"
#include "activeEdgeTable.h"



using std::vector;
Polygon::Polygon(bool showE, Color edgeC, bool fill, Color fillC,bool fill2, Color fillC2,vector<vector<int>> matriz):Primitive("Polygon"), showEdges(showE), edgeColor(edgeC), isFilled(fill), fillColor(fillC),isFilled2(fill2), fillColor2(fillC2),Rachura(matriz) {
	
}

void Polygon::draw(Screen &screen) const {
	if (listOfPoints.size() < 3) {
		std::cout << "Nao forma polígono. Menos de 3 vértices.\n";
        return;
	}
            
    // Desenha arestas se desejar
    if (isFilled)
        scanline(screen);
        
    if (showEdges) {
    	list<Point2D *>::const_iterator it;
    	it = listOfPoints.begin();
    	for (int i = 0; i < listOfPoints.size() - 1; i++, ++it) {
    		Point2D *pI = *it;
    		Point2D *pF = *(next(it));
    		
    		Line line = Line(*pI, *pF, edgeColor);
    		line.draw(screen);
		}
    	
    	it = prev(listOfPoints.end());
    	Point2D *pI = *it;
    	//std::cout << "I(" << pI->getX() << ", " << pI->getY() << ")\n";
    	it = listOfPoints.begin();
    	Point2D *pF = *it;
    	//std::cout << "I(" << pF->getX() << ", " << pF->getY() << ")\n";
    	Line line = Line(*pI, *pF, edgeColor);
        line.draw(screen);
        
        for (it = listOfPoints.begin(); it != listOfPoints.end(); ++it)
        	(*it)->draw(screen);
	}
}

void Polygon::addVertex(Point2D *p) {
	listOfPoints.push_back(p);
}

void Polygon::scanline (Screen & screen) const {
	EdgeTable ET(listOfPoints);
	
	ActiveEdgeTable AET;
	
	int y = ET.getYMin();

    // Laço principal
    while (y <= ET.getYMax()) {
        //# Move a lista y na ET para AET (ymin = y), mantendo a AET ordenada em x
        AET.extend(ET.getList(y));
        ET.clearList(y);
        AET.sort();

        
        
              
        // Desenhe os pixels do bloco na linha de varredura y, 
        // usando os pares de coordenadas x da AET (cada dois nós definem um bloco)
        double xI, xF;
        while (AET.getOneBlockLimits(&xI, &xF)) {
        	for (int x = round(xI); x <= floor(xF); x++){
        		
        		
        		if(Rachura[y%8][x%8] == 1){
        			screen.setPixel(x, y, fillColor);
				}

			}
        }
        cout << "paridade de " << y << " = " << AET.paridade() << "\n";
		 
        //Atualiza o valor de y para a próxima linha de varredura
        y = y + 1;
        
        // Remova as arestas que possuem ymax = y da AET
        AET.removeEdgesByYMax(y);
            
        // Para cada aresta na AET, atualize x = x + 1/m
        AET.updateXValues();
    }
}