# Write your MySQL query statement below


select distinct(p1.Email) from Person as p1 left join Person as p2
on p1.email=p2.email
where p1.id<>p2.id;