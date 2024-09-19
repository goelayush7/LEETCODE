# Write your MySQL query statement below
select E.unique_id , Em.name from Employees Em left join EmployeeUNI E
on Em.id=E.id