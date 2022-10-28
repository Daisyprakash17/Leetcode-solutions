# Write your MySQL query statement below
select d.name as Department,e.name as Employee,e.salary as Salary 
from employee as e 
left outer join 
department as d
on e.departmentid=d.id
where e.salary=(select max(e2.salary) from employee as e2
               where e.departmentid=e2.departmentid);