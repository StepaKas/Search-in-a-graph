#pragma once
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
/// Tohle je trida matice, ve ktere se zpracovava pole.
class Matrix
{
private:
	int cols = 0;
	int rows = 0;
	int** data = nullptr;

public:
	/// Zada pocet rad matice
	void setRows(int rows) { this->rows = rows; }
	/// Ziska pocet rad
	int getRows() { return(this->rows); }
	/// Zada pocet sloupcu matice
	void setCols(int cols) { this->cols = cols; }
	/// Ziska pocet sloupcu
	int getCols() { return(this->cols); }
	/// Nastavi hodnoutu na konkretni pozici matice
	void setValue(int row, int col, int value) { this->data[row][col] = value; }
	/// Ziska hodnoutu na konkretni pozici matice
	int getValue(int row, int col) { return(this->data[row][col]); }
	/// Precte soubor a nacte matici
	void scan_file(const char* filename);
	/// Zjisti jestli je na dane pozici v matici hodnota '1'
	bool check_one_zero(int row, int col);
	/// Zjisti pocet kontinentu (bloku jednicek)
	int get_num_of_continents();
};