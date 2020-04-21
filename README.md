# LEX21-LPR-practice

LEX21 (Part A) and LEX22 (Part B) together are a practice run for the Lab Practical exam (LPR).  LPR is also split into two parts.

Remember that your goal is to demonstrate your ability to use all the tools we've discussed, as well as a sound and methodical approach to both developing software, ensuring its correctness and performance, and tracking down and fixing bugs.

Work on Part A now.  We'll give you Part B to practice on next lab session.

Here's a quick summary of what we expect you to showcase (we will NOT give you this list explicitly during the actual lab exam, but you can look it up here):
* git (on GitHub)
* Planning tool (ZenHub) - use for planning rather than collaboration in LPR since this is an individual activity
* Build tools (make)
* TDD/blackbox testing (CUnit)
* Software testing - whitebox testing (CUnit)
* Code Coverage (gcov)
* Compiler
* Performance tools (gprof, valgrind/callgrind)
* Debugging (gdb)
* Memory leaks (valgrind/memcheck)

Remember to check out the rubric in UBLearns!

## Part A: General Problem Description

Using a Test-Driven approach design and implement data structure(s) to model a simple "blocks-word" scenario:

 <ol type="a">
  <li>The world consists wooden blocks, a table, and a robotic arm.
  </li>

  <li>Each block has a distinct number printed on it.  If there are N
  blocks in the world then blocks are numbered 1 through N.
  </li>

  <li>A block that does not have a block on top of it is called "open".</li>

  <li>The table is always considered "open".</li>

  <li>The robotic arm can pick up any open block.</li>

  <li>The robotic arm can pick up only one block at a time.</li>

  <li>The robotic arm can place a block on the table.</li>

  <li>The robotic arm can place a block on an open block.</li>

  <li>The robotic arm cannot place a block on a block that is not open.</li>

  <li>Initially all blocks are on the table.</li>

  </ol>

## PART A: Specific Requirements
Write functions to create a blocks world, as follows:

  <ol type="a">
  <li><b><tt>create(N)</tt></b> creates a new world in which there are N blocks, all of
  which are on the table.
  </li>
  </ol>

  <p>Write functions to observe the world, as follows:</p>
  <ol type="i">
  <li><b><tt>onTable(m)</tt></b> is true if m is directly on the table, and false if m is on
  another block.  <tt>onTable(0)</tt> always returns false.  If m is not in the
  range 0 through N (inclusive) then the function call returns false.
  </li>

  <li><b><tt>open(m)</tt></b> is true if there is no block on m, false otherwise.
  <tt>open(0)</tt> always returns true.  If m is not in the range 0 through N
  (inclusive) then the function call returns false.
  </li>

  <li><b><tt>on(m)</tt></b> returns 0 if m is directly on the table, and n if m is directly
  on block n.  If m is not in the range 0 through N (inclusive) then the
  function call returns false <tt>on(m)</tt> returns m (i.e. an invalid block
  number).
  </li>

  <li><b><tt>above(m,n)</tt></b> returns true if m is directly on n, or if m is directly
  on x and x is above n. (In other words, <tt>above</tt> is the transitive
  closure of <tt>on</tt>).  <tt>above(m,n)</tt> returns false in any other case.
  </li>

  </ol>

  <p>Write a function to manipulate the world (using the robotic arm), as
  follows:
  </p>

<ol type="i">
  <li><b><tt>move(m,n),</tt></b> which moves the block numbered m onto the block
  numbered n (if n >= 1) or onto the table (if n == 0), but only if both
  m is open and n is open.  If either one (or both) of the blocks is not
  open then the function call has no effect.  Remember that the table is
  always open.  If either m or n (or both) is not in the range 0 through
  N (inclusive) then the function call has no effect.
  </li>
  </ol>

  <p>
  Write a main function which creates a world with 12 blocks, and
  creates three towers of blocks, one consisting of blocks 1, 2, and 3
  (where 1 is on the table, 2 is on 1, and 3 is on 2), a second
  consisting of blocks 4, 5, 6, and 7 (where 4 is on the table and 7 is
  on top), and a third consisting of blocks 8, 9, 10, 11, and 12 (with
  the analogous structure).
 
 ## PART A: Hints and Advice</h4></div>
  <div class="panel-body">

  <p><b>ADVICE</b> Obviously get as much done as you can on solving the problem, but
  keep in mind that it is more important to show mastery of the tools
  and techniques we've discussed than it is to just produce working                                                                                                                     
  code.  Make sure you write tests, measure the coverage of those tests,                                                                                                                
  have a makefile to manage creating both a test and a non-test                                                                                                                         
  executable file, use git effectively.  In part B you will demonstrate                                                                                                                 
  your facility with the debugger and the valgrind tool suite.                                                                                                                          
  </p>                                                                                                                                                                                  
                                                                                                                                                                                        
  <p><b>HINTS</b> Here are some ideas of data structures you can use to model the blocks world.  You do not have use either.</p>                                                        
  <ol type="i"><li> One possible approach is to use a linked list                                                                                                                       
  approach.  Implement a block as a struct with two fields: an int (its                                                                                                                 
  number) and a pointer (let’s call it “below”) to another block.  If                                                                                                                   
  “below” is null then the block is on the table.  A block is open if                                                                                                                   
  there is no block whose “below” link points to it.  Implement the                                                                                                                     
  world as a linked list of blocks.  To locate block number n search through                                                                                                            
  the list until the block with that number is found.</li>                                                                                                                              
                                                                                                                                                                                        
  <li>Another possible approach is to use an array-based approach:                                                                                                                      
  implement world with N blocks as an array in which block number n is                                                                                                                  
  in array[n].  The entry for array[n] is either 0 (in which case it is                                                                                                                 
  on the table) or it is k (0&lt;k&le;N, and n&ne;k), in which case                                                                                                                     
  block n is ‘on’ block k.  Block n is open if there is no block whose                                                                                                                  
  entry in the array is n. is link points to it.</li>                                                                                                                                   
  </ol>                                                                                                                                                                                 
  The array-based approach is probably the easier one.    
  
  ## Feedback
  Please give [feedback](https://docs.google.com/forms/d/e/1FAIpQLSfSl1aEdPL4wwYq5fFmbUkHpBG_1sYiuaIGTzpLyp7t8xg6qw/viewform?usp=sf_link)!
  
