// Patrick Soga
// Section 2 Lab 1
// Week of 2 Sep 2019
#include <iostream>
using namespace std;

int main()
{
	int touchdowns, extraPts, fieldGoals, safeties;		// initialize types of points
	int total = 0;						// total points
	cout << "Number of touchdowns: ";
	cin >> touchdowns;
	cout << "Number of extra points: ";
	cin >> extraPts;
	cout << "Number of field goals: ";
	cin >> fieldGoals;
	cout << "Number of safeties: ";
	cin >> safeties;
							// total = sum of (# scores)*(pt value)
	total += (touchdowns*6 + extraPts*1 + fieldGoals*3 + safeties*2);
	cout << "Total score: " << total << endl;

	return 0;
}
