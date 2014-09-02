/*
** File Name: task_creation.cpp
** Author:    Aditya Ramesh
** Date:      09/01/2014
** Contact:   _@adityaramesh.com
*/

int main()
{
	/*
	** Option 2. The desired type of resource management is declared at the
	** outermost scope, as it should be. We don't need to resort to
	** unreliable hacks in order to allocate the task.
	*/
	auto t = make_scoped(
		task(
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
