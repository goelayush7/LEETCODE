# Write your MySQL query statement below

select  SUBSTR(trans_date,1,7) as month,country,count(trans_date) as trans_count,
sum((case when state='approved' then 1 else 0 end)) as approved_count,
sum(amount) as trans_total_amount,
SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
 from Transactions
group by month,country
