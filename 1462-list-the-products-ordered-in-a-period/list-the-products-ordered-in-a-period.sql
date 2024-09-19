# Write your MySQL query statement below

select P.product_name , sum(O.unit)  as  unit from Products P join Orders O
on P.product_id = O.product_id where MONTH(O.order_date)=2 and year(O.order_date)=2020
group by P.product_id having sum(O.unit)>=100