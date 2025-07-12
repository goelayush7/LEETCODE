# Write your MySQL query statement below
select V.customer_id , SUM(IF(T.transaction_id IS NULL, 1, 0)) as count_no_trans from Visits V left join Transactions T 
on V.visit_id = T.visit_id
group by V.customer_id
having count_no_trans>0