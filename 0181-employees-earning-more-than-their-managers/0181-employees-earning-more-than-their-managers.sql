# Write your MySQL query statement below
select a.name as employee from employee as a inner join employee as b on
a.managerId=b.id AND a.salary>b.salary