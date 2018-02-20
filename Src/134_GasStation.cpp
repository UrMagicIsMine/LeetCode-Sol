/* There are N gas stations along a circular route, where the
* amount of gas at station i is gas[i].
*
* You have a car with an unlimited gas tank and it costs cost[i]
* of gas to travel from station i to its next station (i+1). You
* begin the journey with an empty tank at one of the gas stations.
*
* Return the starting gas station's index if you can travel around
* the circuit once, otherwise return -1.
*
* Note:
* The solution is guaranteed to be unique.
*/
#include <vector>

using namespace std;

/*
*  Observation 1:  If the total amount of gas is larger than the total
*    cost. There must be a solution;
*  Observation 2:  tank(A) > 0, if A couldn't make it to B, then any station
*    between A and B couldn't make it to B neither; in this case, restart from B;
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

	int N = gas.size();
	int istation(0), tank(0), netgas(0);
	for (int i = 0; i < N; i++)
	{
		tank += gas[i] - cost[i];
		/* if tank < 0, not possible to make to the next station */
		if (tank < 0) {
			/* consider start from next station, tank need to be empty */
			tank = 0;
			istation = i + 1;
		}
		netgas += gas[i] - cost[i];
	}
	/* if net gas < 0, couldn't make a circular route */
	return netgas < 0 ? -1 : istation;
}

int main()
{
	vector<int> gas =  { 6, 1, 4, 3, 5 };
	vector<int> cost = { 3, 8, 2, 4, 2 };
	int ret = canCompleteCircuit(gas, cost);
	return 0;
}
