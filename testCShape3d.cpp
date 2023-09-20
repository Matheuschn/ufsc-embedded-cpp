/*
 * file: testCShape3d.cpp
 *
 * Descricao: Programa de teste para a Classe.
 *
 * Saida do programa:
 *
 * Volume do paralelograma: 730.17 
 * Volume do cone: 5.12707
 * Volume do cilindro: 20.3575
 *
 *
 * Autor: Rob McGregor
 * Data: ??/??/??
 * 
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 29/05/2003
 *
 */
#include <iostream>
using namespace std;

template <typename T>
class CShape3d {
	public:
	virtual T volume() = 0;
	//virtual T volume(T &h, T &r) = 0;
};

template <typename T>
class CBox : public CShape3d<T> {
	protected:
		T h = 1, l = 1, c = 1; 
	public:
		CBox(T alt, T larg, T comp): h(alt), l(larg), c(comp){
		};
		T volume(){
			return (h*l*c);
		};
};

template <typename T>
class CCylinder: public CShape3d<T> {
	protected:
		T h, r; 
	public:
		CCylinder(T raio, T alt): h(alt), r(raio){
		};
		T volume(){
			return (h*r*r*3.141516);
		};
};

template <typename T>
class CCone : public CShape3d<T> {
	protected:
		T h, r; 
	public:
		CCone(T raio, T alt): h(alt), r(raio){
		};
		T volume(){
			return (h*(1.0/3.0)*r*r*3.141516);
		};
};

int main(){
	CShape3d<float>* shape;

	// Um ponteiro para CShape3d assume a forma de um CBox
	//
	shape = new CBox<float>(10.5f, 12.2f, 5.7f);
	cout << "Volume do paralelogramo: " << shape->volume() << endl;
	delete shape;

	// Um ponteiro para CShape3d assume a forma de um CCone

	shape = new CCone<float>(1.2f, 3.4f);
	cout << "Volume do cone: " << shape->volume() << endl;
	delete shape;

	// Um ponteiro para CShape3d assume a forma de um CCylinder
	//
	shape = new CCylinder<float>(1.2f, 4.5f);
	cout << "Volume do cilindro: " << shape->volume() << endl;
	delete shape;

	return 0;
}

