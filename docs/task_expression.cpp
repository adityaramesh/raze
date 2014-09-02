/*
** File Name: task_expression.cpp
** Author:    Aditya Ramesh
** Date:      08/30/2014
** Contact:   _@adityaramesh.com
*/

int main()
{
	auto t1 = make_scoped(
		[] (auto x) noexcept {

		} | options,
		[] (auto x) noexcept {

		} | options,
		[] (auto x) noexcept {

		} | on_termination
	);

	auto t2 = make_scoped(
		[] (auto x) noexcept {

		} | options,
		[] (auto x) noexcept {

		} | options,
		[] (auto x) noexcept {

		} | on_termination
	);

	auto t3 = make_scoped(
		[] (auto x) noexcept {

		} | options,
		[] (auto x) noexcept {

		} | options,
		[] (auto x) noexcept {

		} | on_termination
	);

	// Assumptions:
	// - Logical task expressions only store lvalue refs to tasks. So the
	// tasks must have been created earlier, and if the tasks go out of
	// scope before the task created from the logical task expression, bad
	// things will happen.
	// - Don't make abort_early the default. Unexpected behavior will result
	// in situations, say, where the programmer wants to run a task after at
	// least one task in a set finishes, but allow the new task to run
	// concurrently while the other tasks that have yet to be finished
	// continue to run.
	// - Note how the same task can appear in multiple subexpressions.
	// We must prepare for this with respect to synchronization.
	// - When a task expression tree is run, it should run each task that
	// appears in a subexpression. Here, also, we can make the assumption
	// that none of the tasks in the expression tree have already been
	// started or terminated.
	// - To abort early, use cancellation tokens.

	auto t4 = ((t1 && t2) || (t2 && t3)).
	make_scoped(
		[] (auto x) noexcept {
			//
		} | options,
		[] (auto x) noexcept {
			//
		} | options
	);
}
