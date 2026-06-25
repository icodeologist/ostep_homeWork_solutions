##  My answers to the homework questions
1. Run process-run.py with the following flags: -l 5:100,5:100.
What should the CPU utilization be (e.g., the percent of time the
CPU is in use?) Why do you know this? Use the -c and -p flags to
see if you were right.
- ANS: 100% cpu utilization
      Because there are no I/O or network bound operation. Every instruction is executed by the CPU only
      Because after the process is created it has a address space(virtual memory for the process) where there is a entry point and os helps cpu find it. From there it is whether i/o bound or cpu bound instruction and since cpu is executing everything here its 100% cpu bound

2. Now run with these flags: ./process-run.py -l 4:100,1:0.
These flags specify one process with 4 instructions (all to use the
CPU), and one that simply issues an I/O and waits for it to be done.
How long does it take to complete both processes? Use -c and -p
to find out if you were right.
- ANS : Since 4 instruction which are CPU bound and 1 with I/O bound 
  4 + Making the i/o call +actual i/o run time + i/o done time
  if i/o operation takes 6 seconds then time will be 12

3. Switch the order of the processes: -l 1:0,4:100. What happens
now? Does switching the order matter? Why? (As always, use -c
and -p to see if you were right)
- ANS : CPU executes process A => i/o bound => waits for i/o OS sees this tells process B is ready. Process B(ready) => executes => process A (finishes) => cpu still does process B=> process B(finish) => mark done => check process A => mark done
- Yes . Cpu could be sitting idle or choose wrong process. So choosing depends on os and it matters(According to my current knowledge CPU is like main brain and cant waste its presence - CPU GODDD)

4.  We’ll now explore some of the other flags. One important flag is
-S, which determines how the system reacts when a process issues an I/O. With the flag set to SWITCH ON END, the system
will NOT switch to another process while one is doing I/O, instead waiting until the process is completely finished. What happens when you run the following two processes (-l 1:0,4:100
-c -S SWITCH ON END), one doing I/O and the other doing CPU
work?
- ANS : cpu runs process A => run io => blocked => wait till we finish this => process A finished => Process A (ready) => Run io_done => then switch to other process => execute and done
- so with the new flag SWITCH_ON_END cpu sits idle
- time => assuming the i/o takes 5 time units
- 1 run io + 1 to mark io done + 5 => 6
- 1 run cpu process + 4 executing time + 1 to mark it done => 6
- 12 = total time - I might be wrong 
- Actual answer : My answer was right but the time is entirely wrong
- What i thought was cpu first takes a time unit to start and end the process which is way to wrong. ONly when its i/o process it needs to notify hardware or drivers which are related to the process and they require extra time. For cpu bound process since we already all the instruction and cpu itself is going to do it extrac time of open or close wont matter. Only each unit is directly related to the instruction
- correct answer is run io (1) + 5 instruction to i/o drivers / hardware + run io_done(1) + cpu instruction(4)  => 11 time units  

5.  Now, run the same processes, but with the switching behavior set
to switch to another process whenever one is WAITING for I/O (-l
1:0,4:100 -c -S SWITCH ON IO). What happens now? Use -c
and -p to confirm that you are right.
- Now cpu never sits idle and instead of waiting it just execute the next process
- Time saved = waiting time (5) -> execute process B in that waiting period = 4 instruction complete  

6. One other important behavior is what to do when an I/O completes. With -I IO RUN LATER, when an I/O completes, the process that issued it is not necessarily run right away; rather, whatever was running at the time keeps running. What happens when
you run this combination of processes? (./process-run.py -l
3:0,5:100,5:100,5:100 -S SWITCH ON IO -c -p -I
IO RUN LATER) Are system resources being effectively utilized?
- SO we have 3 io instruction and we have 3 other processes which are cpu bound. So when the first instruction runs and its blocked cpu swtiches and completes all processes which makes the first io process to finish after everybody and then next instruction start from io process. This is not the proper utilization of the resource. Instead when the io process finished make cpu go back and let it start another and come back to do its cpu bound processes

7. Now run the same processes, but with -I IO RUN IMMEDIATE set,
which immediately runs the process that issued the I/O. How does
this behavior differ? Why might running a process that just completed an I/O again be a good idea?
- Instead of waiting every process to finish io bound gets immediately run_io_done and start the next io and continue to switch cpu bound process
- Way better the previous one and because now the resource is utilized and nothing that is done sits there just to get the confirmation of the cpu

8. Now run with some randomly generated processes using flags -s
1 -l 3:50,3:50 or -s 2 -l 3:50,3:50 or -s 3 -l 3:50,
3:50. See if you can predict how the trace will turn out. What happens when you use the flag -I IO RUN IMMEDIATE versus that
flag -I IO RUN LATER? What happens when you use the flag -S
SWITCH ON IO versus -S SWITCH ON END?
- Ans - So here we are running process list with each instruction being either cpu or i/o. 
-Each gives the same output but using flags does the expected behavior like SWTICHONEND switches at the end of all processes. 
- SO CPU is basically a dumb executer and OS is like orchestrator

