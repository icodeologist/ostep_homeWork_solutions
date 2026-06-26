### SYScalls for creation of process

== fork() == return a int
if we call it inside a process then the new child process always get 0
Calling fork() is the way the split the process and let the child process have its own task
We can differentiate using rc = fork() if conditionals
```
if rc == 0{
// child process 
}else if rc < 0 {
// fork has failed
}else {
// wait for the child process to finish -->
// then unblock the parent process and return -->
}
```


== wait() == Parent waiting for the child process to finish
== exec() == Used to run other programs inside a program
== signal() == to kill or other signals process listens to signal() syscalls if anything is fired



== PID == unique process identifier
