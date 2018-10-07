#define _CRT_SECURE_NO_WARNINGS
#ifndef MATRIX_H 
#define MATRIX_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include<stdio.h>
#include <cmath>
#include <cstdlib>


using namespace std;

class CMatrix
{
	int rowsNumbers;
	int coloumnsNumbers;
	char matrixName[128];

public:
	double** matrix;
	enum MI {zeros,ones,eye,ran,value};
	CMatrix();
	CMatrix(const char* name, int rn, int cn, int initial, double initialvalue);
	CMatrix(double operand); // Matrix 1 x 1
	CMatrix(string s);
	CMatrix(CMatrix& m);
	CMatrix(CMatrix* m);
	~CMatrix();

	void setName(string name);
	string getName();
	string getstring();
	string getstring_();
	
	// Operators
	friend ostream& operator << (ostream& out, CMatrix& m);
	CMatrix& operator + (CMatrix& m);
	CMatrix& operator - (CMatrix& m);
	CMatrix& operator * (CMatrix& m);
	CMatrix& operator / (CMatrix& m);
	CMatrix& operator = (const CMatrix &other);

	// Operations 
	friend CMatrix& elementDivision(CMatrix &m, CMatrix &c);
	friend CMatrix& elementoperations(CMatrix m, CMatrix c, char op, bool precedence);
	CMatrix& getTranspose();
	CMatrix& GetCofactor();
	CMatrix& Inverse();
	double Determinant();

	// Mathematical Functions
	friend CMatrix sin(CMatrix& m);
	friend CMatrix cos(CMatrix& m);
	friend CMatrix tan(CMatrix& m);
	friend CMatrix cot(CMatrix& m);
	friend CMatrix sec(CMatrix& m);
	friend CMatrix csc(CMatrix& m);
	friend CMatrix sqrt(CMatrix& m);
	friend CMatrix operator ^ (CMatrix m, CMatrix n);
	CMatrix operator ^  (double n);

};
#endif
