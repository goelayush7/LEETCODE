WITH cte AS (
    SELECT 
        id,
        name,
        salary,
        departmentId,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary desc) AS rn
    FROM Employee
)
SELECT D.name as Department,C.name as Employee,C.salary
FROM cte C join Department  D
on C.departmentId = D.id
WHERE rn <= 3;
