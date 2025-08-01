# Write your MySQL query statement below
select a.num as ConsecutiveNums from Logs a join Logs b on a.num = b.num join logs c on b.num = c.num
where a.id +1 = b.id  and b.id+1 = c.id
group by a.num 