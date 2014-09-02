<!--
  ** File Name: README.md
  ** Author:    Aditya Ramesh
  ** Date:      08/30/2014
  ** Contact:   _@adityaramesh.com
-->

# Advantages over TBB and Microsoft's Concurrency Runtime

- More efficient:
  - Task creation does not use dynamic allocation unless explicitly requested,
  even for sophisticated task trees containing continuations and logical
  dependencies between tasks.
  - Type information is exploited as much as possible to avoid doing redundant
  work during runtime.
    - No redundant internal synchronization.
    - When dynamic allocation is requested, only one block of memory is
    allocated, even for complex task trees.
  - Exceptions are only caught and marshaled when it is possible for the
  user-provided function to throw.

- Cleaner design:
  - Concise, unified syntax for tasks and task groups.
  - The library relies on generic lambdas: as a programmer, you should not need
  to remember and spell out types that the compiler can infer on its own.
  - `expected<T>` is used marshal exceptions.

# Disadvantages

- Does not current support Windows. I do not use Windows, so it's not practical
for me to support it right now.
