#ifndef NODEMOVIMENTS_H
#define NODEMOVIMENTS_H

class NodeMoviments {
public:
	int& getValor() { return m_valor; }
	NodeMoviments* getNext() { return m_next; }
	void setValor(const int& valor) { m_valor = valor; }
	void setNext(NodeMoviments* next) { m_next = next; }
private:
	int m_valor;
	NodeMoviments* m_next;

};
#endif
