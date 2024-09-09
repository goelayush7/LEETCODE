# Write your MySQL query statement below


select distinct(L1.num) as ConsecutiveNums from Logs L1 join Logs L2 join Logs L3 where 
L1.id+1=L2.id and L2.id+1 = L3.id and L1.num=L2.num and L2.num=L3.num