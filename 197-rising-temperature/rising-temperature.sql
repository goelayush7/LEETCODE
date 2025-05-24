# Write your MySQL query statement below

select W.id from Weather W join Weather B where DATE_ADD(B.recordDate, INTERVAL 1 DAY) = W.recordDate
 and W.temperature>B.temperature