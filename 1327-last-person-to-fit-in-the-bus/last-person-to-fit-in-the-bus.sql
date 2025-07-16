# Write your MySQL query statement below
select person_name from(
    Select * , SUM(weight) over(order by turn) as weights from Queue
) as c
where c.weights<=1000
order by turn desc 
limit 1