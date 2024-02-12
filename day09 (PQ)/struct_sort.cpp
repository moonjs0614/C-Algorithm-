#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Coord
{
	int row;
	int col;
	
	bool operator < (Coord right) const
	{
		// 1. row 내림차순
		if (row > right.row) return true;
		if (row < right.row) return false;

		// 2. col 오름차순
		if (col < right.col) return true;
		if (col > right.col) return false;
	}

	Coord operator+(const Coord right)
	{
		return { row + right.row, col + right.col };
	}
	Coord operator-(const Coord right)
	{
		return { row - right.row, col - right.col };
	}

};

//bool cmp(Coord left, Coord right)
//{
//	// 1. row 내림차순
//	if (left.row > right.row) return true;
//	if (left.row < right.row) return false;
//
//	// 2. col 오름차순
//	if (left.col < right.col) return true;
//	if (left.col > right.col) return false;
//	
//	return false;
//}

int main() {

	Coord coords[5] = { {1, 2}, {2, 3}, {2, 4}, {4, 3}, {4, 5} };

	Coord now = coords[0] - coords[1];
	cout << now.row << "," << now.col << endl;

	//sort(coords, coords + 5, cmp);
	sort(coords, coords + 5);
	int de = -1;


}