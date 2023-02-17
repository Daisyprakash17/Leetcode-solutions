# Write your MySQL query statement below
select distinct(a.email)as email from person as a inner join person as b 
on a.id <> b.id AND a.email=b.email;