#Hw3 : Hello theads, 
That’s study on co-op.

Due date: 6/6 23:59 am (Late homework is **NOT** accepted), You should start working right now.

All of our homework would be verified on our server. (TAs will test your code on our machine) 
Also, this homework require a face-to-face demo (evening of 6/1 or 3).

##The goal of this homework:
**In this homework, we ask you to create a program to calculate a well-known transcendental number, the PI.**
PI=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034...

http://en.wikipedia.org/wiki/Pi

---

You need to use **multi-thread framework** and **C++** to implement the calculation. We suggest you to use **PThread** or **std::thread(C++11)** to complete this homework. Besides, there are many way/method/algorithem to calulate the PI. Please refer to my slides (./hw3-PI.pdf) and dig out more information on internet. 
(There are several link provided in the hw3-PI.pdf, please read them first.)

##Requirements:
Your program must divide the computation into multiple threads (at least 2 for computation). You may add additional thead to control their work or print out the data (a suggestion, not a requirement) Normaly, you will need to implement a class to handle the Big integer.

**[WARNING]** Except for the main thread, if you create **only ONE** thread to calculate PI, you gain **NO points** in this assignment.

---

**You need to complete your homework with ONE of following formations, each formation require different inputs.**

(Please refer to the slide and my announcement in the class)

**[TYPE 1]** Input **number of digit** directly:
Print out N digit of PI directly. //It is the best way, you may get full scores in the part I: CORRECTNESS

Execution: ./s1234567_pi.out [N digits, N < 1000] [M threads = How many thread should be creadted in your program]

Sample usage: ./s1234567_pi.out 10 2

Sample output: PI=3.1415926535 (35ms, calculate with 2 threads)

**[TYPE 2]** Input **time limitation** of calculation:
Contorl your computing time and output as many digits as possible. (gain 80% score)

Execution: ./s1234567_pi.out [Time(ms)] [M threads]

Sample usage: ./s1234567_pi.out 1000 4

Sample output: PI=3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102 (1024ms, calculate with 4 threads)

(**NOTE**: The number of digit is depend on your program)

**[TYPE 3]** Input **number of itration**:
Use some primitive and interactive solution (for example. the Monte-Carlo method) to solve this problem. Therefore, the iput should be the NUMBER of interation. (gain 70% score)

Execution: ./s1234567_pi.out [Iteration] [M threads]

Sample usage: ./s1234567_pi.out 100000 4

Sample output: **PI=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679 (100000 iteration, 2078ms, calculate with 4 threads)**

(**NOTE**: Please provide 100 digits directly in this TYPE)

##Score sheet:

**First of all, you need to use multiple-thread to accomplish your goal. Otherwise, you gain NO points.**
Also. make it **compilable**.

* (50 pts) CORRECTNESS of your calculation (with multiple thread).
* (10 pts) makes the number of thread in your program is controlable (by input).
* (10 pts) share common data and control the concurrent access wisely. (You may use mutex or semphore to achieve it.)
* ( 5 pts) print out the execution time.
* (10 pts) REPORT
* (15 pts) DEMO, we will ask you three questions about your code, usage of thread, blah blah blah...
* (+10 pts) Implemt your work with style, complex algorithm, extreamly high performace. (Please clarify it in your report)
* (+10 pts) Complete the task **without** using Big integer.
* (+10 pts) Provide the program, complete TYPE 1&2 simultaneity.

##Write a report:
You need to mention at least three things: 

(1) What is your creation? (in detail) *How to calcuate PI.* (Also, prepare a checklist for each requirement and bonus)

(2) How it works, demo it BOTH in text(commands) and screen snapshot. *the snapshot MUST work on your own account.*

(3) Convince me you should have additional points.

##Howto:
(In the following text, we assume your student ID is s1234567, please replace it with your correct student ID and follow the steps **exactly**!)

1. Clone your private repository of hw1 to your home directory on server or another suitable location from our organisation on [GitHub](https://github.com/YZU-CSE-CS305-Intro-to-OS)

2. After you start to deal with your homework, add a file **report_s1234567.md** as your report and **code_s1234567.cpp** as your program. Then, commit it. (Do not commit multiple copies of your work.)

3. Complete your program and write your report with Markdown.
*. Please commit your homework when you have progress.

4. Make sure you have complete the assignment and prepare a clear demo in your report. **Do it ON YOUR OWN and ON TIME.**

NOTE: You would get 0 point, if you don’t follow rules, especially on the filename and format of your work.
