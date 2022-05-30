#include "matice.h"

void Matrix::scan_file(const char* filename)
{
	ifstream inFile;
	inFile.open(filename);
	int x;

	// Nactu si matici do vetsiho pole, aby pri kontrole pole v krajich nedoslo k erroru.
	inFile >> x;
	this->setRows(x + 2);
	inFile >> x;
	this->setCols(x + 2);

	char c;
	this->data = new int* [this->rows * this->cols];
	/// Naplnim matici '0'.
	for (int i = 0; i <= this->rows - 1; i++)
	{
		data[i] = new int[this->cols];
		for (int j = 0; j <= cols - 1; j++)
		{
			this->data[i][j] = '0';
			
		}
		
	}
	/// Naplnim matici krom okraju matici ze souboru.
	for (int i = 1; i <= this->rows - 2; i++)
	{


		for (int j = 1; j <= this->cols - 2; j++)
		{
			inFile >> c;

			this->data[i][j] = c;


		}

	}
	inFile.close();
}
bool Matrix::check_one_zero(int row, int col)
{
	if (this->data[row][col] == 49)
		return true;
	return false;
}
///
/// Dvemi smycky "for" se kontroluje matice dokud se bunka na dane pozici nerovna '1'. 
/// Do rady (queue) paru integeru se ukladaji souradnice bunek, ve kterych je '1' a nasledne se kontroluji sousedici bunky jestli se v nich nachazi '1'.
/// Proces se opakuje, dokud neskontroluji cely blok, pricemz se incrementuje pocet kontinentu o 1. 
/// Kazda bunka bloku se prepise po zkontrolovani, aby se nemuselo kontrolovat znova.
/// Smycka "while" kontroluje vsechny sousedici bunky, kdyz je sousedici bunky rovna '1', tak zkontroluje i sousedici bunky teto bunky.
int Matrix::get_num_of_continents()
{
	queue<pair<int, int>> verified;
	int matRows = this->getRows() - 2;
	int matCols = this->getCols() - 2;



	int continent = 0;
	for (int i = 1; i <= matRows + 1; i++)
	{
		for (int j = 1; j <= matCols + 1; j++)
		{	
			if (this->check_one_zero(i, j) )
			{	
				verified.push({ i,j });
				continent++;

				this->setValue(i, j, continent + 1);
				while (!verified.empty())
				{	
					pair<int, int> curr = verified.front();
					
					verified.pop();
					if (this->check_one_zero(curr.first + 1, curr.second) )
					{
						this->setValue(curr.first + 1, curr.second, continent + 1);
						verified.push({ curr.first + 1,curr.second });
					}

					if (this->check_one_zero(curr.first, curr.second + 1) )
					{
						this->setValue(curr.first, curr.second + 1, continent + 1);
						verified.push({ curr.first ,curr.second + 1 });
					}

					if (this->check_one_zero(curr.first - 1, curr.second) )
					{
						this->setValue(curr.first - 1, curr.second, continent + 1);
						verified.push({ curr.first - 1,curr.second });
					}

					if (this->check_one_zero(curr.first, curr.second - 1) )
					{
						this->setValue(curr.first, curr.second - 1, continent + 1);
						verified.push({ curr.first ,curr.second - 1 });
					}
					/* V pripade, ze beru bunky do diagonaly jako sousedici.
					if (this->check_one_zero(curr.first + 1, curr.second + 1) )
					{
						this->setValue(curr.first + 1, curr.second + 1, continent + 1);
						verified.push({ curr.first + 1 ,curr.second + 1 });
					}

					if (this->check_one_zero(curr.first + 1, curr.second - 1))
					{
						this->setValue(curr.first + 1, curr.second - 1, continent + 1);
						verified.push({ curr.first + 1 ,curr.second - 1 });
					}

					if (this->check_one_zero(curr.first - 1, curr.second + 1))
					{
						this->setValue(curr.first - 1, curr.second + 1, continent + 1);
						verified.push({ curr.first - 1 ,curr.second + 1 });
					}

					if (this->check_one_zero(curr.first - 1, curr.second - 1) )
					{
						this->setValue(curr.first - 1, curr.second - 1, continent + 1);
						verified.push({ curr.first - 1 ,curr.second - 1 });
					}*/
				}
			}
		}


	}
	return continent;
}
