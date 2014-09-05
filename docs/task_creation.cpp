/*
** File Name: task_creation.cpp
** Author:    Aditya Ramesh
** Date:      09/01/2014
** Contact:   _@adityaramesh.com
*/

int main()
{
	/*
	** Task tree.
	*/
	auto t = make_scoped(
		[] (auto x) {

		}, token,
		then(
			[] (auto x) {

			}, options,
			[] (auto x) {

			}, on_termination, options
		)
	);

	/*
	** Task tree with continuation.
	*/
	auto t = make_scoped(
		group(
			[] (auto x) {

			}, token,
			then(
				[] (auto x) {

				}, options,
				[] (auto x) {

				}, on_termination, options
			)
		),
		then(
			[] (auto x) {

			}, token, on_termination
		)
	);

	/*
	** Logical task expressions.
	*/
	auto t = make_scoped(
		group(
			[] (auto x) {
				// A
			}, token,
			then(
				[] (auto x) {
					// B
				}, options,
				[] (auto x) {
					// C
				}, on_termination, options
			)
		),
		then(
			[] (auto x) {
				// D
			}, token,
			[] (auto x) {
				// E
			}, token
		),
		(_1->_2->_1 && _2->_2)(
			[] (auto x) {
				// Runs after both tasks B and E complete
				// successfully.
			}
		)
	);
}
