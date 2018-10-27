/* You are given a data structure of employee information, which includes the
* employee's unique id, his importance value and his direct subordinates' id.
*
* For example, employee 1 is the leader of employee 2, and employee 2 is the
* leader of employee 3. They have importance value 15, 10 and 5, respectively.
* Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has
* [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is
* also a subordinate of employee 1, the relationship is not direct.
*
* Now given the employee information of a company, and an employee id, you need
* to return the total importance value of this employee and all his subordinates.
*
* Example 1:
* Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
* Output: 11
* Explanation:
* Employee 1 has importance value 5, and he has two direct subordinates: employee
* 2 and employee 3. They both have importance value 3. So the total importance
* value of employee 1 is 5 + 3 + 3 = 11.
* Note:
* One employee has at most one direct leader and may have several subordinates.
* The maximum number of employees won't exceed 2000.
*/

#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;

/**
* Employee info
*/
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

int _getImpDFS(unordered_map<int, Employee*>& employees, int id) {
	Employee* pEmp = employees[id];
	int ret = pEmp->importance;
	for (int i = 0; i < pEmp->subordinates.size(); i++)
		ret += _getImpDFS(employees, pEmp->subordinates[i]);
	return ret;
}

int getImportance(vector<Employee*> employees, int id) {

	unordered_map<int, Employee*> empHash;
	for (int i = 0; i < employees.size(); i++)
		empHash[employees[i]->id] = employees[i];

	return _getImpDFS(empHash, id);
}

int main()
{
	vector<Employee> employeeInfo = { {1, 5,{2, 3}},{2, 3,{}},{3, 3,{}} };
	vector<Employee*> employees = { &employeeInfo[0],&employeeInfo[1] ,&employeeInfo[2] };
	int ret = getImportance(employees, 1);
	int ans = 11;
	assert(ret == ans);
	return 0;
}
