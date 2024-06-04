#ifndef NODEFIGURA_H
#define NODEFIGURA_H
#include "Figura.h"

class NodeFigura {
public:
	NodeFigura() { m_nextFigura = NULL; };
	Figura& getFigura()   { return m_figura; };
	NodeFigura* getNext() { return m_nextFigura; }

	void setFigura(const Figura& fig) { m_figura = fig; }
	void setNext(NodeFigura* next)    { m_nextFigura = next; }

private:
	Figura m_figura;
	NodeFigura* m_nextFigura;
	
};

#endif