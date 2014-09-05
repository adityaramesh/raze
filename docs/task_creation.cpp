/*
** File Name: task_creation.cpp
** Author:    Aditya Ramesh
** Date:      09/01/2014
** Contact:   _@adityaramesh.com
*/

int main()
{
	/*
	** mutable_task_node
	** task_node
	** mutable_task_group
	** task_group
	**
	** A group encapsulates a forest of task nodes or task groups into a
	** higher-level group that can be used to express task relationships in
	** broader scopes.
	*/

	auto t = make_scoped(
		group(
			[] (auto x) {

			}, token,
			then(
				[] (auto x) {

				}, options,
				[] (auto x) {

				}, options,
				[] (auto x) {

				}, on_termination, options
			),
			[] (auto x) {

			}, token
		),
		then(
			[] (auto x) {
				//
			}
		)
	);
}
