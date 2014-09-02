/*
** File Name: task_creation.cpp
** Author:    Aditya Ramesh
** Date:      09/01/2014
** Contact:   _@adityaramesh.com
*/

int main()
{
	// problem 1: come up with the right set of operator overloads to make
	// this work for lambdas, function objects, and function pointers.

	// problem 2: DFS vs BFS execution. Perhaps use the scheduler along with
	// the visitor pattern so that the scheduler can apply a predetermined
	// policy the schedule the task tree itself.
	auto t = make_scoped(
		[] (auto x) {

		} | options,
		then(
			[] (auto x) {

			} | options,
			[] (auto x) {

			} | options,
			[] (auto x) {

			} | on_termination | options
		),
		[] (auto x) {

		} | on_termination
	);
}
