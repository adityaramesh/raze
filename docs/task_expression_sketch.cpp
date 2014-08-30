/*
** File Name: task_expression_sketch.cpp
** Author:    Aditya Ramesh
** Date:      08/30/2014
** Contact:   _@adityaramesh.com
*/

int main()
{
	auto t1 = make_task([](){

	}).on_success([](){

	}).on_success([](){

	});

	auto t2 = make_task([](){

	}).on_success([](){

	}).on_success([](){

	});

	auto t3 = make_task([](){

	}).on_success([](){

	}).on_success([](){

	});

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

	// Support this syntax for specifying abort_early for subexpressions. It
	// only makes sense for the entire expression tree to be associated with
	// a cancellation token, and this functionality is covered by
	// task_options.
	auto t4 = ((t1 && t2)[abort_early] || (t2 && t3))(
	[]() noexcept {
		//
	}, options);

	// This syntax allows the entire expression to be interpreted as "abort early".
	auto t4 = abort_early((t1 && t2) || (t2 && t3))(
	[]() noexcept {
		//
	}, options);

	// This allows for dynamically allocated tasks.
	auto t4 = abort_early((t1 && t2) || (t2 && t3))(
	[]() noexcept {
		//
	}, options).allocate();
}
