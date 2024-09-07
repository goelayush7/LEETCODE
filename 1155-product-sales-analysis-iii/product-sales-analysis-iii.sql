# Write your MySQL query statement below

select sales.product_id,year as first_year,quantity,price from sales where (product_id,year) in
(select sales.product_id,min(year) as first_year from Sales Join Product on Sales.product_id = Product.product_id group by 
Sales.product_id)