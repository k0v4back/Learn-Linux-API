/*
 * The SIGCHLD signal is passed to the parent process 
 * whenever one of its child shuts down
 * By default, it is ignored, but we can intercept
 * it by installing  handler.
 * Inside this handler, you can make a call wait()
 * (or similar to it) to remove the "zombie" child process.
 */


