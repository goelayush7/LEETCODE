with cte as (
    select D.name as Department,E.name as Employee ,E.salary as salary,dense_rank() over(partition by D.id order by E.salary desc) as r
    from Employee e join Department D on E.departmentId = D.id
)
select Department , Employee ,Salary from cte 
where r <=3