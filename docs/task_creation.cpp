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

		}, make_options(token),
		then(
			[] (auto x) {

			}, options,
			[] (auto x) {

			}, make_options(on_termination)
		)
	);

	/*
	** Task tree with continuation.
	*/
	auto t = make_scoped(
		group(
			[] (auto x) {

			}, make_options(token),
			then(
				[] (auto x) {

				}, options,
				[] (auto x) {

				}, make_options(on_termination)
			)
		),
		then(
			[] (auto x) {

			}, make_options(token, on_termination)
		)
	);

	/*
	** Logical task expressions. Reasoning behind supporting usage of tags
	** instead of addressing nodes via paths:
	**   - Paths can change easily due to changes in the source code.
	**   - IDs are much more concise.
	*/
	auto t = make_scoped(
		group<0>(
			[] (auto x) {
				// A
			}, make_options(token),
			then(
				[] (auto x) {
					// B
				}, make_options("B"_id),
				[] (auto x) {
					// C
				}, make_options(on_termination)
			)
		),
		then(
			[] (auto x) {
				// D
			}, make_options(token),
			[] (auto x) {
				// E
			}, make_options(token, "E"_id)
		),
		("B"_id && "E"_id)(
			[](auto x) {
				// Runs after both tasks B and E complete
				// successfully.
			}
		)
	);
}
