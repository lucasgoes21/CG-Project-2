#include "activeEdgeTable.h"

// compara por X
bool compareX (const EdgeInfo * first, const EdgeInfo * second)
{
	return (first->getX() < second->getX());
}

void ActiveEdgeTable::extend(const list<EdgeInfo *> &edges) {
	AET.insert(AET.end(), edges.begin(), edges.end());
}

void ActiveEdgeTable::sort() {
	AET.sort(compareX);
	it = AET.begin();
}

bool ActiveEdgeTable::getOneBlockLimits(double *xI, double *xF) {
	if (it != AET.end()) {
		*xI = (*it)->getX();
		++it;
		*xF = (*it)->getX();
	    ++it;
	    
	    return true;
	}
	
	return false;
}

void ActiveEdgeTable::updateXValues() {
	for (it = AET.begin(); it != AET.end(); ++it) 
		(*it)->updateX();
}

void ActiveEdgeTable::removeEdgesByYMax(int yMax) {
	for (it = AET.begin(); it != AET.end(); ++it) {
		if ((*it)->getYMax() == yMax)
			AET.erase(it);
    }
}

void ActiveEdgeTable::print() const {
	list<EdgeInfo *>::const_iterator it2;
	
	for (it2 = AET.begin(); it2 != AET.end(); ++it2) {
		(*it2)->print();
    }
}

void ActiveEdgeTable::paridade() const {
	list <EdgeInfo *>::const_iterator it3;
	
	it3 = AET.begin();
	for(int i = 0; it3 != AET.end(); i++, it3++){
		if(i % 2 == 0) {
			printf("1 ");
		}
		else printf("0 ");
	}
	std::cout << "\n";
	
}