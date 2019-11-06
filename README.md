# libpq_build

This is the solution for the given problem statement below:

Problem Statement: Please create a proof of concept in C++ for connecting to PostgreSQL database. Please note following:
1.  The project should be portable and must compile on Linux and Windows
2.  It should use CMake toolset for cross platform builds

Expectations from POC:
1.	A program, which when run, asks for:
    a.	PostgreSQL server IP address
    b.	Username
    c.	Password
2.	After reading the above three values, it should attempt to make a connection with the PostgreSQL database and print the result, that is, either “Connection Successful” or “Connection Failed”, along with the detailed error message that may have been received from the database.
3.	It then asks the user to input the SQL query to execute 
    a.	When given a SQL query,
      i.	it executes the query and prints the results in human readable format
      ii.	And asks for next query to be executed
    b.	When given a blank query,
      i.	the program should gracefully close the connection with DB and exit
4.	The code should be modular and extendable. For example, in future if any other DB support is required, it should be easy to do that without making a lot of changes in the existing code. 
5.	The complete project should be hosted on github.com, in a way that anyone could clone it and build it.
