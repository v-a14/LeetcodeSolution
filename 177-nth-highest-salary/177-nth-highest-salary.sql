CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set n = n-1;
  RETURN (
      select salary from employee 
      group by salary
      order by salary desc
      limit n, 1
      # Write your MySQL query statement below.
      
  );
END