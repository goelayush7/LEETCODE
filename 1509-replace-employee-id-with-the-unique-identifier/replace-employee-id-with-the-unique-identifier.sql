# Write your MySQL query statement below
select EmployeeUNI.unique_id , Employees.Name from Employees left Join EmployeeUNI
on EmployeeUNI.id= Employees.id