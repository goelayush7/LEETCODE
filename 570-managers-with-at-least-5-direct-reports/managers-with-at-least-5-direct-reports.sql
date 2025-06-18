# Write your MySQL query statement below

Select E.name from Employee E join Employee E1
where E.id = E1.managerId 
group by E.id having Count(E.id)>=5