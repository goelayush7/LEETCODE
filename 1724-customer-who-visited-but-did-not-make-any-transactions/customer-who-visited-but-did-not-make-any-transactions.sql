# Write your MySQL query statement below


SELECT customer_id , Count(customer_id) as count_no_trans
FROM Visits 
WHERE visit_id NOT IN (SELECT visit_id FROM Transactions)
group by customer_id