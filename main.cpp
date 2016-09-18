#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<iterator>
#include<cstdio>
#include<cstring>
using namespace std ;
class Sudoku
{
	public:
		map<int, bool> t;
		vector< vector<int> > m;
	
		Sudoku(const vector<vector<int> > matrix)
		{
			m = matrix;
			setTest();
		}

		void setTest()
		{
			for (int i = 0; i < 9; i++)
			{
				t[i+1] = false;
			}
		}

		bool checkTest()
		{
			map<int, bool>::iterator it;
			for (it = t.begin(); it != t.end(); it++)
			{
				if (it -> second == false) return false;
			}
			return true;
		}

		void print(){
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					cout << m[i][j] << " ";
				}
				cout << endl;
			}
		}
	
		bool checkRow(size_t n)
		{
			setTest();
			for (size_t i = 0; i < 9; i++)
			{
				t[m[n][i]] = true;
			}
			return checkTest();
		}

		bool checkCol(size_t n)
		{
			setTest();
			for (size_t i = 0; i < 9; i++)
			{
				t[m[i][n]] = true;
			}
			return checkTest();
		}

		//left upper corner
		bool checkSquare(size_t row, size_t checkCol)
		{
			setTest();
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					t[m[i][j]] = true;
				}
			}
			return checkTest();
		}	

		bool check()
		{	
			setTest();
			for (size_t i = 0; i < 9; i++)
			{
				if (!checkCol(i)) return false;
				if (!checkRow(i)) return false;
			}	

			
			for (size_t i = 0; i < 3; i++)
			{
				for(size_t j = 0; j < 3; j++)
				{
					if(!checkSquare(i*3,j*3)) return false;
				}
			}
			
			return true;
		}

		void checkSudoku()
		{
			if (check())
				cout << "TAK" << endl;
			else
				cout << "NIE" << endl; 
		}
};


int main(){

	int t ;
	cin >> t ;
	while( t ){
		vector<vector<int> > vB;
		for (int i = 0; i < 9; i++)
		{
			vector<int> vS;
			for (int j = 0; j < 9; j++)
			{
				int tmp;
				cin >> tmp;
				vS.push_back(tmp);
			}
			vB.push_back(vS);
		}
		
		Sudoku s(vB);
		//s.print();
		s.checkSudoku();
		//cout << endl;
		t-- ;
	}
	
	return 0 ;
}
