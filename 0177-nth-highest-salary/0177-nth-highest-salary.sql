CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select max(salary) from Employee as e1 
    where N-1 <=(select count(distinct(salary)) from Employee as e2
                  where e1.salary<e2.salary and e1.id<>e2.id)
  );
END