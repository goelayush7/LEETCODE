# Write your MySQL query statement below
select EN.unique_id,E.name from Employees E left join EmployeeUNI EN 
on E.id = EN.id
