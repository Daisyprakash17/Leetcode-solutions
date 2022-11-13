# Write your MySQL query statement below
select name from customer  as c1
    where c1.id not in (select id from customer as c2 where c2.referee_id=2)
    