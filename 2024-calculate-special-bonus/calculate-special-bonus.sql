# Write your MySQL query statement below
Select employee_id,IF(employee_id%2=1 and 
name NOT LIKE "M%",salary,0) as bonus
from Employees 
order by employee_id
