# Write your MySQL query statement below
Select S.user_id ,IFNULL(ROUND(Sum(case when C.action="confirmed" then 1 else 0 end)/Count(C.user_id),2),0) as confirmation_rate
from Signups S left join Confirmations  C
on S.user_id = C.user_id
group by S.user_id