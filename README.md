<!--
  ** File Name: README.md
  ** Author:    Aditya Ramesh
  ** Date:      08/30/2014
  ** Contact:   _@adityaramesh.com
-->

# Advantages over TBB and Microsoft's Concurrency Runtime

- More efficient:
  - Task creation does not use dynamic allocation, even for sophisticated task
  expressions containing continuations and logical dependencies between tasks.
  - Tasks use less internal synchronization.
  - Exceptions are only caught and marshaled when it is possible for the
  user-provided function to throw.

- Cleaner design:
  - Supports generic lambdas.
  - Task expressions and notification groups support heterogeneous task types.
  - `expected<T>` is used marshal exceptions.

- Safer:
  - By default, `expected<T>` ensures that the state of object is read at least
  once prior to destruction. This helps prevent silent program errors.

# Disadvantages

- Does not current support Windows. I do not use Windows, so it's not practical
for me to support it right now.
