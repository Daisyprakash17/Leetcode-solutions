# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE 
FROM Person 
WHERE  id NOT IN  (
    SELECT  id FROM ( SELECT MIN(id) as id, email FROM person GROUP BY email) AS temp
)
                  