# Write your MySQL query statement below
select E.name ,  B.bonus from Employee E left join Bonus B 
on E.empId = B.empId where bonus is NULL or bonus<1000