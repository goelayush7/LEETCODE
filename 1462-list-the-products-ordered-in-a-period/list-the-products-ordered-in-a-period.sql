# Write your MySQL query statement below

select P.product_name , SUM(O.unit) as unit from Products P join Orders O on P.product_id = O.product_id 
where O.order_date like "2020-02%" 
group by product_name 
having unit>=100