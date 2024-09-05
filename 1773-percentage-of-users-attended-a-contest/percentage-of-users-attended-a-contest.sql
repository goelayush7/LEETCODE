# Write your MySQL query statement below

select contest_id ,
ROUND(COUNT(DISTINCT user_id) * 100 / (SELECT COUNT(user_id) FROM Users), 2) as percentage
from register 
group by contest_id 
order by percentage desc , contest_id 
