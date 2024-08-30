# Write your MySQL query statement below
select A.id from Weather A join Weather B 
where A.temperature>B.temperature and  DATEDIFF(A.recordDate,B.recordDate)=1