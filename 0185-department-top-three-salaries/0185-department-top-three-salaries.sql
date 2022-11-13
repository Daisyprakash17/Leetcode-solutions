# Write your MySQL query statement below
select  d.name as Department,e.name as Employee,e.Salary as Salary from Employee as e join Department as d
    on e.departmentId=d.id
    where  3> ( select count(distinct(e1.salary)) from Employee as e1
               where e1.departmentid=e.departmentid
               and
               e.salary<e1.salary
    
        
    )